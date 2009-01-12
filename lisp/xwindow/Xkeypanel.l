;; Xkeypanel.l
;; (c)1996 Toshihiro Matsui, Electrotechnical Laboratory
;;
(list "@(#)$Id$")
(in-package "X")

(defclass number-display :super CharacterWindow :slots (value value-string))

(defmethod number-display 
 (:create (&rest args &key (font font-courb18) (rows 1) (columns 12)
		      &allow-other-keys)
    (send-super* :create  :font font :rows rows :columns columns args)
    (setq value 0)
    self)
 (:value-string (s)	;right justfied print
    (send self :clear-lines 0 1) ;clear the 0th line
    (send self :put-line 0 (- win-col-max (length s)) s)) 
 (:value (&optional (v))
    (if v
	(progn
           (setq value v)
           (setq value-string 
	         (if (floatp value)
		     (format nil "~2,3g" value)
	   	     (format nil "~d" value)) )
	   (send self :value-string value-string) ) )
     value)
)

(defclass number-input :super number-display :slots (digits))

(defmethod number-input
 (:create (&rest args )
    (send-super* :create :width 160 :height 110 
		 :item-width 25 :item-height 20
		 :event-mask '(:key :button)
		 args) )
 (:clear-value (&rest args)
    (setq value 0
	  digits (copy-seq "0"))  
    (send-super :value value)
    self)
 (:value (&optional digits)
    (when digits 
       (setq value (read-from-string digits))
       (send-super :value-string digits))
    value)
 (:enter-digit (n)
    (cond ((= value n 0) )
	  ((= value 0) (setq digits (format nil "~d" n)))
 	  (t (setq digits (concatenate string digits (format nil "~d" n))))
	  )
    (send self :value digits))
 (:decimal-point (evnt)
    (cond ((member #\. digits) (x:bell x:*display* 1) (xflush))
 	  (t (setq digits (concatenate string digits ".")))
	  )
    (send self :value digits))
 (:delete-last-digit ()
    (cond ((= (length digits) 1) (setq digits (copy-seq "0")))
 	  (t (setq digits (subseq digits 0 (1- (length digits)))))
	  )
    (send self :value digits))
 (:keyEnter (ch &optional evnt)
    (cond ((digit-char-p ch)  (send self :enter-digit (- ch #\0)))
	  ((member ch '(#\return #\newline)) (send parent :enter-number evnt))
	  ((eql ch 3) (send parent :abort))		;^C
	  ((eql ch 21) (send self :clear-value))	;^U
	  ((member ch '(#\backspace #\delete))
	   (send self :delete-last-digit))
	  (t (bell *display* 1)) ) )
 (:keypress (event)
    (if (= (lookupstring event charbuf 1 0 0) 1)
	 (send self :keyEnter (char charbuf 0) event)))
  )



(defclass number-display-key :super panel
		:slots (numdisp digits value))

(defmethod number-display-key
 (:create (&rest args )
    (send-super* :create :width 160 :height 110 
		 :item-width 25 :item-height 20
		 :event-mask '(:key :button)
		 args)
    (setq numdisp (instance number-display :create :x 0 :y 0
			:width 160 :height 25 :parent self))
    (setq next-y 30)
    (send self :create-item
	   x:bitmap-button-item "key0.xbm"
		 self (list :enter-digit 0))
    (send self :create-item
	   x:bitmap-button-item "key1.xbm"
		 self (list :enter-digit 1))
    (send self :create-item
	   x:bitmap-button-item "key2.xbm"
		 self (list :enter-digit 2))
    (send self :create-item
	   x:bitmap-button-item "key3.xbm"
		 self (list :enter-digit 3))
    (send self :create-item
	   x:bitmap-button-item "key4.xbm"
		 self (list :enter-digit 4))
    (send self :create-item
	   x:bitmap-button-item "key5.xbm"
		 self (list :enter-digit 5))
    (send self :create-item
	   x:bitmap-button-item "key6.xbm"
		 self (list :enter-digit 6))
    (send self :create-item
	   x:bitmap-button-item "key7.xbm"
		 self (list :enter-digit 7))
    (send self :create-item
	   x:bitmap-button-item "key8.xbm"
		 self (list :enter-digit 8))
    (send self :create-item
	   x:bitmap-button-item "key9.xbm"
		 self (list :enter-digit 9))
    (send self :create-item
	   x:bitmap-button-item "keyclr.xbm"
		 self :clear-value)
    (send self :create-item
	   x:bitmap-button-item "keyenter.xbm"
		 parent :enter-number)
    (send self :create-item
	   x:bitmap-button-item "keyend.xbm"
		 self :quit)
    (send self :clear-value)
    self)
)


(defclass calculator :super panel
		:slots (numdisp value op memory digits))


(defmethod calculator
 (:create (&rest args)
    (send-super* :create :width 160 :height 155  :item-width 30 args)
    (setq numdisp (instance number-display :create :x 0 :y 0
			:width 160 :height 25 :parent self))
    (setq value 0 memory 0 op nil digits (copy-seq "0"))
    (setq next-y 30)
    (send self :create-item
	   x:bitmap-button-item "key0.xbm"
		 self (list :enter-number 0))
    (send self :create-item
	   x:bitmap-button-item "key1.xbm"
		 self (list :enter-number 1))
    (send self :create-item
	   x:bitmap-button-item "key2.xbm"
		 self (list :enter-number 2))
    (send self :create-item
	   x:bitmap-button-item "key3.xbm"
		 self (list :enter-number 3))
    (send self :create-item
	   x:bitmap-button-item "key4.xbm"
		 self (list :enter-number 4))
    (send self :create-item
	   x:bitmap-button-item "key5.xbm"
		 self (list :enter-number 5))
    (send self :create-item
	   x:bitmap-button-item "key6.xbm"
		 self (list :enter-number 6))
    (send self :create-item
	   x:bitmap-button-item "key7.xbm"
		 self (list :enter-number 7))
    (send self :create-item
	   x:bitmap-button-item "key8.xbm"
		 self (list :enter-number 8))
    (send self :create-item
	   x:bitmap-button-item "key9.xbm"
		 self (list :enter-number 9))
    (send self :create-item
	   x:bitmap-button-item "keydot.xbm"
		 self :decimal-point)
    (send self :create-item
	   x:bitmap-button-item "key-.xbm"
		 self (list :binary-op '-))
    (send self :create-item
	   x:bitmap-button-item "key+.xbm"
		 self (list :binary-op '+))
    (send self :create-item
	   x:bitmap-button-item "keyx.xbm"
		 self (list :binary-op '*))
    (send self :create-item
	   x:bitmap-button-item "keydiv.xbm"
		 self (list :binary-op '/))
    (send self :create-item
	   x:bitmap-button-item "keysqrt.xbm"
		 self (list :unary-op 'sqrt))
    (send self :create-item
	   x:bitmap-button-item "key=.xbm"
		 self (list :binary-op '=))
    (send self :create-item
	   x:bitmap-button-item "keyclr.xbm"
		 self :clear)
    (send self :create-item
	   x:bitmap-button-item "keyend.xbm"
		 self :quit)
    self))

(defmethod calculator 
 (:clear (&rest args)
    (when (equal value 0) (setq memory 0 op nil))
    (setq value 0
	  digits (copy-seq "0"))  
    (send numdisp :value value)
    self)
 (:enter-number (n)
    (cond ((= value n 0) )
	  ((= value 0) (setq digits (format nil "~d" n)))
 	  (t (setq digits (concatenate string digits (format nil "~d" n))))
	  )
    (send self :value))
 (:decimal-point (evnt)
    (cond ((member #\. digits) (x:bell x:*display* 1) (xflush))
 	  (t (setq digits (concatenate string digits ".")))
	  )
    (send self :value))
 (:unary-op (k)
    (case k
      (sqrt (setq value (sqrt value)))
      (log (setq value (log value)))
      (t (print '?)))
    (setq digits (format nil "~a" value))
    (send numdisp :value value)
    self)
 (:binary-op (k)
    (print (list memory op value))
    (case op
      (+ (setq memory (+ value memory)))
      (- (setq memory (- memory value)))
      (* (setq memory (* value memory)))
      (/ (setq memory (/ memory value)))
      (t (setq memory value) (print '?)))
    (setq value 0 digits (copy-seq "0"))
    (send numdisp :value memory)
    (setq op k)
    self)
)


