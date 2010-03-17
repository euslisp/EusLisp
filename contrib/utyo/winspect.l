; 稲葉です。
; 
; ウィンドウベースのinspector(winspect.l)をお送りします。
; 
; destroy,hide,update,redisplayなどのボタンをつけました。
; destroyは子どもまで殺します。
; hideはそのウィンドウだけ見えないようにします。
; updateは変数の値を変えたあとに再表示するためのものです。
; redisplayはhideしたものをもう一度甦らせます。
; 
; 使い方としては、ある変数aを(winspect a)したあと、表示されている部分で
; さらにinspectしたいところをマウスで示した後、inspectボタンを押して順次
; たどっていゆき、奥深くにある除いてみたい要素の値を表示するウィンドウを
; 用意します。覗いてみたい箇所が複数あればそれらも表示させます。
; そして、それら以外をhideボタンで見えなくします。おお元の親も消して構い
; ません。winspect-redisplayですべてが甦るからです。
; 
; 次に、アプリケーションプログラムのなかで、のぞいている箇所がどのように
; 変化するかを見るには、アプリケーションのなかの覗きたいところに、
; (winspect)を挿入して、アプリケーションプログラムを走らせます。
; そうすると、(winspect)が呼ばれるたびに、ウィンドウの表示がアップデート
; されますから、どのようになっているかを調べることが容易になります。
;
;;;
;;;		Window-based Inspecter 1990.2.2
;;;					by M.Inaba and T.Matsui
;;;
;;;	(winspect variable)
;;;	or
;;;	(winspect) -> update the display like "Update" button
;;;
;;;	(winspect-redisplay)
;;;	(winspect-destroy)
;;;
;;;    Usage:
;;;(1) Interactive inspecting
;;;	eusview$ (setq a (make-cube 10 20 30))
;;;	eusview$ (winspect a)
;;;	Select slot's line by mouse in textsw.
;;;	Push "Inspect" button.
;;;
;;;(2) Value monitoring
;;;	The name of global variable 'a is memorized. If you update
;;;	the value of a, such as
;;;	eusview$ (setq a (make-cube 100 100 100))
;;;	and call winspect again like
;;;	eusview$ (winspect)
;;;	then the display in all of the inspect windows updated.
;;;
;;;(3) Slot value editing function
;;;	Select slot in a textsw, for example 'pos' of 'a'.
;;;	Set a form in the text item like, '#f(100 100 100).
;;;	then the value of (a . pos) is changed to #f(100 100 100).
;;;
;;;(4) Window destroy
;;;	Select "Destroy" button for destroying self and its children.
;;;	Send-all *winspect-windows* :destroy or
;;;	Call (winspect-destroy) for destroying all.
;;;
;;;(5) Window display control
;;;	Select "Hide" button for shadowing the window.
;;;	Select "Redisplay" button for redisplaying it and its children.
;;;
(format t "(winspect variable)~%")
;;;
(defvar *winspect-windows*)
(defmacro winspect (&optional sym)
  `(cond
    ((null ,sym)
     (send-all *winspect-windows* :button-update))
    (t
     (push 
      (instance class-inspect :init ',sym)
      *winspect-windows*))))
(defmacro winspect-destroy (&optional sym)
  `(let
       (w)
     (cond
      ((null ,sym)
       (send-all *winspect-windows* :destroy))
      ((setq w (remove-winspect ',sym))
       (send w :dstroy)))))
(defmacro winspect-redisplay (&optional sym)
  `(let
       (w)
     (cond
      ((null ,sym)
       (send-all *winspect-windows* :button-redisplay))
      ((setq w (find-winspect ',sym))
       (send w :button-redisplay)))))
(defun find-winspect (sym)
  (dolist (w *winspect-windows* nil)
	  (when (equal sym (w . parent-index))
		(return-from find-winspect w))))
(defun remove-winspect (sym)
  (when (setq sym (find-winspect sym))
	(setq *winspect-windows* (remove sym *winspect-windows*))
	sym))
(defun truncate-string (str len)
   (if (> (length str) len) (subseq str 0 len) str))

(defun inspect2 (obj &optional (line-length 50))
  (let ( ;(*print-structure* t) (*print-circle* t)
	(*print-length* 10)
	klass rlist len)
    (cond ((numberp obj) obj)
	  ((vectorp obj)
	   (dotimes (i (length obj))
		    (push (list i (truncate-string
				   (prin1-to-string (aref obj i))
				   line-length))
			  rlist)) )
	  ((consp obj)
	   (setq len (length obj))
	   (dotimes (i len)
		    (push (list i (truncate-string
				   (prin1-to-string (pop obj))
				   line-length)) rlist)))
	  (t	;not a vector
	   (setq vars (metaclass-vars (setq klass  (class obj))))
	   (dotimes (i (length vars))
		    (push (list (svref vars i)
				(truncate-string
				 (prin1-to-string (slot obj klass i))
				 line-length))
			  rlist))))
    (nreverse rlist)))
;;;
(defclass class-inspect :super sunview-frame
  :slots (textsw panel
		 parent-index
		 target-object
		 slot-value-list
		 children
		 hidden-flag
		 textsw-first-line
		 textsw-insertion-point))
(defmethod class-inspect
  (:select-slot-and-value
   (&optional (i (send textsw :insertion-point)))
   (let ((contents (send textsw :get-contents)))
     (while (and (>= i 0) (< i (length contents)))
       (if (memq
	    (elt contents i)
	    '(13 10))
	   (return-from :select-slot-and-value
			(assoc
			 (read-from-string (subseq contents i) nil "")
			 slot-value-list)))
       (if (<= i 0)
	   (return-from :select-slot-and-value
			(elt slot-value-list 0)))
       (setq i (1- i)))))
  (:button-inspect
   (&optional item event)
   (let ((slot-value (send self :select-slot-and-value))
	 ins)
;;;     (print slot-value)
     (if (null slot-value) (return-from :button-inspect nil))
     (setq ins
	   (instance class-inspect :init
		     (list self (car slot-value))
		     (float-vector (send self :x)
				   (+ 2 (send self :y) (send self :height)))))
     (push ins children)
     ))
  (:text-set
   (&optional value item event)
   (let ((v (eval (read-from-string value)))
	 (slot-value (send self :select-slot-and-value))
	 slot)
     (print slot-value)
     (print target-object)
     (cond
      ((null slot-value))
      ((and (numberp (setq slot (car slot-value)))
	    (or (vectorp target-object)
		(consp target-object)))
       (setf (elt target-object slot) v))
      (t (setslot target-object (class target-object) slot v)))))
  (:window-title
   ()
   (cond
    ((null parent-index))
    ((symbolp parent-index) parent-index)
    (t (cons (send (car parent-index) :window-title) (cdr parent-index)))))
  (:describe-obj
   (obj)
   (when (not hidden-flag)
	 (send self :title (format nil "~s" (send self :window-title)))
	 (setq textsw-first-line (send textsw :first-line))
	 (setq textsw-insertion-point (send textsw :insertion-point))
	 (send textsw :reset)
	 (setq slot-value-list (inspect2 obj))
	 (send textsw :show nil)
	 (dolist (x slot-value-list)
		 (send textsw :insert (string (car x)))
		 (send textsw :insert "	=	")
		 (send textsw :insert (cadr x))
		 (send textsw :insert "
"))
	 (send textsw :insertion-point textsw-insertion-point)
	 (send textsw :first-line 0)
	 (send textsw :scroll textsw-first-line)
	 (send textsw :show t)))
  (:button-update
   (&optional item event)
   (send self :describe-obj
	 (send self :target-object parent-index))
   #+xview
   (send textsw :height (* 16 (length slot-value-list)))
   #+xview
   (send self :fit)
   (send-all children :button-update)
   )
  (:button-destroy
   (&optional item event)
   (send self :destroy))
  (:button-hide
   (&optional item event)
   (send self :show nil)
   (setq hidden-flag t)
   )
  (:button-redisplay
   (&optional item event)
   (send self :show t)
   (setq hidden-flag nil)
   (send-all children :button-redisplay)
   )
  (:target-object
   (&optional (index parent-index)) ; index = object, symbol, (parent slot)
   (cond
    ((symbolp index) (setq target-object (symbol-value index)))
    ((atom index) index)
    (t
     (let ((par-object (send (car index) :target-object))
	   (slot (cadr index)))
       (cond
	((and (numberp slot)
	      (or (vectorp par-object)
		  (consp par-object)))
	 (setq target-object (elt par-object slot)))
	(t (setq target-object
		 (slot par-object (class par-object) slot))))))))
  (:parent-index
   (&optional inx)
   (if inx (setq parent-index inx) parent-index))
  (:remove-child (c)
		  (setq children (remove c children)))
  (:destroy ()
	    (send-all children :destroy)
	    (setq children nil)
	    (cond
	     ((symbolp parent-index)
	      (remove-winspect parent-index))
	     (t
	      (send (car parent-index) :remove-child self)))
	    ;;;	    (send textsw :erase 0 (send textsw :length))
	    (send textsw :reset)
	    (send-super :destroy)
	    )
  (:init
   (par &optional (pos #f(350 0)))
   (setq parent-index par)
   (send-super :init nil
	       :title
	       (format nil "~s" (send self :window-title))
	       :x (elt pos 0) :y (elt pos 1) :width 700)
   #+xview
   (setq panel (instance sunview-panel :init self
			 :col-max 5 :width 800
			 :scrollbar nil
			 :item-size 16
			 :font "lucidasans-bold-12"))
   #+sunview
   (setq panel (instance sunview-panel :init self
			 :col-max 5 :width 800
			 :scrollbar nil
			 :item-size 16
			 :font
			 "/usr/lib/fonts/fixedwidthfonts/screen.b.12"))
   (send panel :create-button :button-inspect :title "Inspect")
   (send panel :create-button :button-update :title "Update" :item-col 1)
   (send panel :create-button :button-destroy
	 :title "Destroy" :item-col 2)
   (send panel :create-button :button-hide
	 :title "Hide" :item-col 3)
   (send panel :create-button :button-redisplay
	 :title "Redisplay" :item-col 4)
   (send panel :create-text :text-set :title "Change slot value:"
	 :item-col 0 :length 60)
   (send panel :fit-height)
   #+xview
   (setq textsw (instance sunview-textsw :init self
			  :x 0 :below panel :width 800))
   #+sunview
   (setq textsw (send self :create-subwindow sunview-textsw
		      :x 0 :below panel :width 800))
   #+sunview
   (send self :button-update)
   #+sunview
   (send textsw :height (* 16 (length slot-value-list)))
   (send self :show t)
   self)
  )

