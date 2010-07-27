;---------------------
; file name is notify.l
;----------------------
;; routines to control the interaction with input from the notifier
;; 
;; In order to deal with events from sunview, the following protocol
;; must be observed:
;;   sunview notifies the lisp program of events through calling event
;;   procs.  These event procs should do very little work, perhaps just
;;   setting a switch value or two.  If an event proc wants to do anything
;;   substantial, it should set *notify-command* to an appropriate (non-nil)
;;   value, and possibly also set *notify-value* to something, 
;;   and then it should call notify-stop before returning.  
;;   The two routines below notice when *notify-command* has been changed
;;   and call the user supplied routine passing *notify-command* and
;;   *notify-value.
;;
;; The purpose of this is to ensure that the notifier needn't be called
;; recursively.   
;;
;(in-package :sunview :nicknames '(:sv) :use '(:lisp :excl))
;(export '(notify-start-loop notify-dispatch-step
;			    *notify-command*
;			    *notify-value*))
;(provide :notify)

(defvar *notify-command* nil)
(defvar *notify-value*   nil)
(defvar *notify-countdown* 10)


(defun notify-start-loop (handle-command-fcn)
   ;; loop forever, awaiting events and dispatching to the appropriate
   ;; user defined function to handle commands.
  (while t
    (setq *notify-command* nil)
    (notify_start)	; process input until a notify-stop is done
    (if *notify-command*
	(funcall handle-command-fcn *notify-command* *notify-value*))))

(defun notify-dispatch-step (handle-command-fcn rate-of-calling)
   ;; if it is time to check for an event, do so and then handle
   ;; any event that may have occured.
   ;; the rate-of-calling argument says how often to check for events
   ;;
   (cond ((<= (setq *notify-countdown* (1- *notify-countdown*)) 0)
	  (setq *notify-command* nil)
	  (notify_dispatch)	; do one notification
	  (setq *notify-countdown* rate-of-calling)
	  (if *notify-command*
	      (funcall handle-command-fcn 
		       *notify-command* 
		       *notify-value*)))))

