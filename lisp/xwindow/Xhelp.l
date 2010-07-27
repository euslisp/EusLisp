(list "@(#)$Id: Xhelp.l,v 1.1.1.1 2003/11/20 07:46:35 eus Exp $")
(defclass HelpPanel :super panel
	:slots (help-button quit-button close-button help-text help-stream
		help-win confirm-win))

(defmethod HelpPanel
 (:create (&rest args)
    (send-super* :create :width 380 :height 300 :font font-courb14
		 :event-mask '(:configure)
		 args)
    (setq help-button
	  (send self :create-item button-item "help" self :help))
    (setq quit-button
	  (send self :create-item button-item "quit" self :quit))
    (setq close-button
	  (send self :create-item button-item "close" self :close))
    (setq help-text
	  (send self :create-item text-item "help:" self :help
		:columns 30 :font font-courb14))
    (setq help-win
	  (instance TextWindow :create
		:parent self
		:width 365 :height 220
		:map nil
		:notify-object self
		:notify-method :help))
    (setq help-stream (make-textwindow-stream help-win))
    (send self :locate-item help-win)
    (setq confirm-win (instance confirmPanel :create :map nil))
    (help:load-help (format nil "~a/doc/latex/euslisp.hlp" *eusdir*))
    self)
)

(defmethod HelpPanel
 (:close (event) (send self :delete))
 (:help (event)
    (let ((item (read-from-string (send help-text :getstring))))
	(send help-win :clear)
        (help item nil help-stream)
        nil))
 )

