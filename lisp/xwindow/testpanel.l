(in-package "X")

(require :Xdecl "Xdecl.l")
(require :xcanvas "Xcanvas.l")
(require :xtext "Xtext.l")
(require :xscroll "Xscroll.l")
(require :xpanel "Xpanel.l")
(require :xmenu "Xmenu.l")
(require :xitem "Xitem.l")
;(require :xcolors "Xcolors.l")
;(require :xpixmap "Xpixmap.l")


(defclass testPanel :super panel
	:slots (quit joy choi sli xmenu))
(defmethod testPanel
 (:create (&rest args)
    (send-super* :create :width 200 :height 300 args)
    (send-super :create-item button-item "quit" self :quit)
    (send-super :create-item choice-item "choice" self :choice
		:choices '("A" "B" "C"))
    (send-super :create-item slider-item "slider" self :slider
		:span 70)
    (send-super :create-item joystick-item "joy" self :joy
		:return t)
    (setq xmenu (instance menu-panel :create))
    (send xmenu :create-item button-item "aho" self :men)
    (send-super :create-item menu-button-item "baka" nil nil :menu xmenu
		:border-width 2)
    self)
 (:men (&rest mesg) (print mesg))
 (:choice (obj c) (format t ";choice: ~S ~d~%" obj c))
 (:slider (obj val) (format t ";slider: ~S ~s~%" obj val))
 (:joy (obj x y) (format t ";joy: ~S ~s ~s~%" obj x y))
 )

