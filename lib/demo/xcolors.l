
(defvar cm nil)
(defvar *print-color-name* nil)

(defun change-root-color (color-name)
  (if *print-color-name*  (print color-name))
  (send cm :store 0 (string color-name))
  (xflush))

(defun next-color-name (s)
   (prog* ((eof (cons nil nil))
	   (cname (read-line s nil eof)))
     next
	(if (eql cname eof)
	    (return-from next-color-name nil))
	(setq cname (read-from-string
			 (concatenate string "(" cname ")")))
	(if (= (length cname) 4)
	    (return-from next-color-name (elt cname 3)))
        (setq cname (read-line s nil eof))
	(go next)
	cname))

(defun cycle-color (&optional (skip 0) (interval 300))
   (prog (s c)
      again
        (setq s (open "/usr/lib/X11/rgb.txt"))
	(while (> skip 0) (next-color-name s) (dec skip))
	(setq skip 0)
      more
	(setq c (next-color-name s))
	(when (null c) (close s) (go again))
	(change-root-color c)
	(unix:sleep interval)
	(go more)))

(defun cycle-root-color (skip interval)
      (setq cm (instance colormap :init nil 0 1))
      (send x:root :background (aref (send cm :pixels) 0))
      (cycle-color skip interval)) 

(defun cycle-root-color-top (&rest argv)
   (unless (unix:getenv "DISPLAY")
	(warn "no DISPLAY is setenv'ed~%")
	(unix:exit 1))
   (cond ((not (zerop (setq x:disp (x:OpenDisplay 0))))
	  (setq x:*defaultGC* (instance gcontext :create))
	  (setq x:Root (instantiate Xwindow))
	  (setq (x:Root . drawable) (x:defaultrootwindow x:disp))
	  (setq x:screen (x:defaultscreenofdisplay x:disp))
	  (setq x:visual (x:defaultvisualofscreen x:screen))
	  (setq *whitegc* (instance gcontext :create))
	  (send *whitegc* :foreback 0 1)
	  (setq *blackgc* (instance gcontext :create))
	  (send *blackgc* :foreback 1 0)
	  (warn "connected to Xserver DISPLAY=~A~%"
			 (unix:getenv "DISPLAY")))
	(t (warn "can't connect to Xserver")
	   (unix:exit 2)))
   (let ((interval 60) (skip 0))
      (when (> (length argv) 1)
         (setq interval (read-from-string (elt argv 1))) )
      (when (> (length argv) 2)
	 (setq skip (read-from-string (elt argv 2))))
      (cycle-root-color skip interval)))


