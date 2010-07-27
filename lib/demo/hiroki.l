(defvar *level* 1)

(defun random-choice (choices)
   (let ((r (random 1.0)))
      (dolist (cho choices)
	  (if (< r (first cho)) (return-from random-choice (second cho))))
      (second (car (last choices)))))

(defun random-int (&optional (lvl *level*))
   (case lvl
	((0 1) (+ 2 (random 10)))
	(2 (+ 6 (random 9)))
	(3 (+ 10 (random 15)))
	(4 (+ 20 (random 30)))
	(5 (+ 30 (random 40)))
	(6 (+ 30 (random 60)))
	(7 (+ 50 (random 80)))
	(t (+ 100 (random 100)))))

(defun make-quiz ()
   (let (num1 num2 op)
      (if (< *level* 4)
          (setq op (random-choice '((0.7 +) (0.85 -) (0.96 *) (1.0 /))))
          (setq op (random-choice '((0.5 +) (0.75 -) (0.9 *) (1.0 /)))) )
      (cond ((eq op '*)
		(setq num1 (random-int (- *level* 1))
		      num2 (if (< *level* 5)
			       (1+ (random 9))
				(1+ (random 20)))) )
	    ((eq op '/) 
		(case *level*
		  ((1 2 3) (setq num2 (+ 1 (random 9)))
			   (setq num1 (* num2 (random-int (1- *level*)))) )
		  ((4 5) (setq num1 (random-int (1- *level*)))
			 (setq num2 (+ 2 (random 9))))
		  (t     (setq num1 (random-int)
				num2 (+ 3 (random 15))))) )
	    ((eq op '-) (setq num1 (random-int) num2 (1+ (random num1))))
	    (t (setq num1 (random-int) num2 (random-int))))
      (list op num1 num2)))

(defun hiroki (&optional (level 1) (count 100))
   (setq *level* level)
   (let ((eof (cons nil nil))
	 (total-time 0) (total-quiz 0))
     (dotimes (k count)
      (let ((wrong 0) (correct 0))
        (dotimes (i 8)
         (let ((quiz (make-quiz)) (time1 (unix::gettimeofday))
		time2  ans answer time)
          (format t "~%~s ~s ~s ="  (cadr quiz) (car quiz) (caddr quiz))
	  (finish-output)
	  (tagbody
		again
		 (setq ans (read t nil eof))
		 (when (eq ans eof)
		     (format t "You solved ~d problems in ~d seconds,
~f seconds per one problem in average.~%" total-quiz total-time
			(/ (float total-time) total-quiz))
		     (return-from hiroki t))
		 (when (not (numberp ans))
	    	      (format t "number?~%")
		      (go again))
		  (setq time2 (unix::gettimeofday))
		  (setq answer (eval quiz))
		  (when (not (equal ans answer))
			(format t "Wrong, try again.~%")
			(incf wrong)
			(go again))
		(setq time (- (car time2) (car time1)))
		(incf total-time time)
		(format t "Correct!  time=~d sec. ~%" time)
		(incf correct)
		(incf total-quiz))) )
       (if (< (/ (float wrong) (float correct)) 0.15)
	   (progn 
	        (format t "You solved ~d problems in ~d seconds,
~f seconds per one problem in average.~%" total-quiz total-time
			(/ (float total-time) total-quiz))
		(format t "Congratulations!  You are going up to the next level: ~d~%"
		        (incf *level*))
		(format t "You may take rest. When ready, hit Enter~%")
		(dotimes (j 10) (format t "~d " *level*))
		(format t "~%")
		(read-line)
		(read-line)) 
	   (format t "Stay on the same level.~%"))
 ))
))

(defclass anzan :super x:panel
	  :slots (entry-panel quiz-panel score-panel level-choice msg-panel
		  history-panel history-stream
		  quiz ans quiz-at-this-level
		  correct wrong total-quiz total-correct total-wrong
		  total-time time
		  time1 time2) )

(defmethod anzan
 (:create (&rest args)
    (send-super* :create :width 200 :height 400 :item-height 30 
		args)
    (setq *level* 1)
    (setq *random-state* (coerce (unix::gettimeofday) integer-vector))
    (setq quiz-panel
	 (instance x::number-display :create :parent self
		:y 0 :columns 7 :rows 1 :font x::font-courb24) )
;    (setq entry-panel (instance x::number-display-key :create :y 33 :parent self))
    (setq entry-panel (instance x::number-input :create :parent self
				:x (+ 30 (send quiz-panel :width)) :columns 3
				:font x::font-courb24))
    (setq msg-panel (instance x::characterWindow :create :parent self
			:font x:font-timesb18 :rows 1 :columns 15
			:border-width 0 :x 10 :y 32))
    (setq history-panel (instance x:textwindow :create :parent self
		:x 0 :y 50 :height 70
		:event-mask '(:button)
		:font x::font-cour10 
		:rows 10 :columns 30 ))
    (setq history-stream (x::make-textwindow-stream history-panel))
    (send self :font x::font-courb24)
    (send self :string (+ 8 (send quiz-panel :width)) 25 "=")
    (send self :font x::font-timesb12)
    (setq x::next-y 150)
    (setq level-choice
       (send self :create-item
		x:choice-item "Level" self :level
		 :choices '(" 1 " " 2 "  " 3 "  " 4 " " 5 " " 6 ")
		 :button-size 10
		 :font x:font-courb12) )
    (send self :create-item x:bitmap-button-item "quit.xbm" self :quit)
    (send self :create-item x:bitmap-button-item "clr.xbm" self :clear-scores)
    (setq score-panel
	 (instance x::number-display :create :parent self
		 :columns 5 :rows 8  :x 100 :y 250 :font x::font-timesb14))
    (send self :string 10 263 "         time")
    (send self :string 10 279 " average time")
    (send self :string 10 295 "   total time")
    (send self :string 10 311 "aver tot time")
    (send self :string 10 327 "      correct")
    (send self :string 10 343 "        wrong")
    (send self :string 10 359 "total correct")
    (send self :string 10 375 "total   wrong")
    (send self :clear-scores)
    (send self :next-quiz)
    (send self :print-scores)
    self)
 (:clear-scores (&optional event)
    (setq wrong 0 correct 0 total-time 0 time 0
	  total-correct 0 total-wrong 0 quiz-at-this-level 0
	  total-quiz 0)
    (send self :print-scores)
    self)
 (:level (&rest x)
    (setq *level* (1+ (cadr x))) 
    (format t "new level=~d~%" *level*)
    (setq quiz-at-this-level 0)
    (setq correct 0 wrong 0 time 0)
    (send self :print-scores)
    (send self :next-quiz)
    )
 (:print-msg (m)
    (send msg-panel :clear-lines 0 1)
    (send msg-panel :put-line 0 0 m))
 (:enter-number (evnt)
    (setq ans (send entry-panel :value))
    (format history-stream "~s ~s ~s = ~s " 
		(second quiz) (first quiz) (third quiz) ans)
    (setq time2 (- (car (unix::gettimeofday)) time1) )
    (cond ((= (eval quiz) ans)
	   (incf correct) (incf total-correct)
	   (incf time time2) (incf total-time time2)
	   (send self :print-msg "Correct")
	   (format history-stream "Correct ")
	   (send self :print-scores)
	   (send self :next-quiz))
	  (t (incf wrong) (incf total-wrong)
	   (send self :print-msg "Wrong")
	   (format history-stream "Wrong")
	   (send self :print-scores))
	  )
    (format history-stream " ~a sec.~%" time2)
    (send entry-panel :clear-value)
    self)
 (:print-scores ()
    (send level-choice :value (1- *level*))
    (send score-panel :clear-lines 0 8)
    (send score-panel :put-line 0 0 (format nil "~8d" time))
    (send score-panel :put-line 1 0
		(format nil "~8f" (/ (float time) quiz-at-this-level)))
    (send score-panel :put-line 2 0 (format nil "~8d" total-time))
    (send score-panel :put-line 3 0
		 (format nil "~8f" (/ (float total-time) total-quiz)))
    (send score-panel :put-line 4 0 (format nil "~8d" correct))
    (send score-panel :put-line 5 0 (format nil "~8d" wrong))
    (send score-panel :put-line 6 0 (format nil "~8d" total-correct))
    (send score-panel :put-line 7 0 (format nil "~8d" total-wrong))
    self)
 (:next-quiz (&optional x)
    (setq quiz (make-quiz))
    (incf total-quiz) (incf quiz-at-this-level)
    (when (and (> quiz-at-this-level 10)
		(< (/ (float wrong) quiz-at-this-level) 0.12))
	(setq x (min 6 (1+ *level*)))
	(when (> x *level*)
	   (setq *level* x)
	   (send self :level :choice (1- *level*))))
    (send quiz-panel :clear-lines 0 1)
    (send quiz-panel :put-line 0 0
	 (format nil "~s ~s ~s" (second quiz) (first quiz) (third quiz)))
    (setq time1 (car (unix::gettimeofday)))
    )
)

    
(setq anzan1 (instance anzan :create))



