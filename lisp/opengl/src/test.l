;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/test.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $
;;; test.l -- eus + OpenGL test program with eta3

(proclaim '(special eta3))

(eval-when (load eval)
  (progn
    (load "/usr/local/eus/robot/eta3/eta3build.l")
    (send eta3 :set-coords)
    (load "view")
    ))

;;;
;;; scene definition
;;;

;; 3D lines -- these lines are drawn in 3D model coordinate space.
;;             GL_DEPTH_TEST is enabled while these lines are drawn.
(defvar *line1* (list (float-vector 0 -800 500) (float-vector 0 800 500)))
(defvar *line2* (list (float-vector -800 0 500) (float-vector 800 0 500)))
(defvar *line3* (list (float-vector 0 -1500 0) (float-vector 0 1500 0)))
(defvar *line4* (list (float-vector -1500 0 0) (float-vector 1500 0 0)))

;; 2D lines -- these lines are drawn in 2D screen coordinate space.
;;             left upper corner is to be point (0,0).
(defvar *line21* (list (float-vector 225 205) (float-vector 225 245)))
(defvar *line22* (list (float-vector 205 225) (float-vector 245 225)))

;; some objects...
;;
;;      create some objects to construct the scene.
;;      these are put into *scene* list, which we later
;;      pass onto gldraw function.
;;
(defvar *obj1* (let ((c (make-cube 200 100 100))) 
		 (send c :translate #f(500 500 0))))

(defvar *obj2* (let ((g (make-gdome (make-icosahedron 100)))) 
		 (send g :translate (float-vector 0 -600 50))))

(defvar *obj3* (let ((g (make-cylinder 50 70)))
		 (send g :translate (float-vector 400 -400 25))))

;; and their colors
;;
;;     these stuff also apper in *scene* list,
;;     changing drawing attribute as gldraw traverse *scene* list.
;;
;;     in GL, color of a surface in the scene,
;;       and that of lines/points is handled differently.

;; color of eta3 (eta3) -- yellow (not really)
(defvar *eta3-color* 
  (let ((c (instantiate colormaterial)))
    (setf 
     (colormaterial-ambient c) (float-vector 0.7 0.7 0.3 1)
     (colormaterial-diffuse c) (float-vector 0.5 0.4 0.2 1)
     (colormaterial-specular c) (float-vector 0.3 0.4 0 1)
     (colormaterial-emission c) (float-vector 0.2 0.1 0 1)
     (colormaterial-shininess c) 20)
    c))

;; color for *obj1* (cube) -- brick
(defvar *obj1-color*
  (let ((c (instantiate colormaterial)))
    (setf
     (colormaterial-ambient c) (float-vector 1 0.3 0 1)
     (colormaterial-diffuse c) (float-vector 0.6 0.2 0 1)
     (colormaterial-specular c) (float-vector 1 0.3 0 1)
     (colormaterial-emission c) (float-vector 1 0.2 0 1)
     (colormaterial-shininess c) 30)
    c))

;; color for *obj2* (gdome) -- blue
(defvar *obj2-color*
  (let ((c (instantiate colormaterial)))
    (setf
     (colormaterial-ambient c) (float-vector 0 1 0.3 1)
     (colormaterial-diffuse c) (float-vector 0.4 0 0.6 1)
     (colormaterial-specular c) (float-vector 1 1 1 1)
     (colormaterial-emission c) (float-vector 1 1 1 1)
     (colormaterial-shininess c) 60)
    c))

;; color for *obj3* (cylinder) -- green
(defvar *obj3-color*
  (let ((c (instantiate colormaterial)))
    (setf
     (colormaterial-ambient c) (float-vector 0 1 0.3 1)
     (colormaterial-diffuse c) (float-vector 0.4 0.6 0 1)
     (colormaterial-specular c) (float-vector 0 1 0.3 1)
     (colormaterial-emission c) (float-vector 0 1 0.3 1)
     (colormaterial-shininess c) 60)
    c))

;; define color of lines & points -- red
(defvar *linecolor1*
  (let ((c (instantiate linecolor)))
    (setf
     (linecolor-color c) (float-vector 1 0 0 0))
    c))

(defvar *linecolor2*
  (let ((c (instantiate linecolor)))
    (setf
     (linecolor-color c) (float-vector 1 1 1 0))
    c))


;;;
;;; the scene list.
;;;
;;;  any list to be handed over to the gldraw function.
;;;
;;;  gldraw function traverses this list from head to tail,
;;;  executing drawing primitives to underlying OpenGL layer.
;;;
;;;  gldraw is simply a minor extention to the draw function.
;;;
(defvar *scene* 
  (list *eta3-color* eta3 *linecolor1* *line1* *line2* *line3* *line4* 
	*obj1-color* *obj1* *obj2-color* *obj2* *obj3-color* *obj3*
	*linecolor2* *line21* *line22*))


;;;
;;; test functions
;;;

;; view positions...
(defun pos1 ()
  (send *viewing* :look #f(1300 -1500 800)))

(defun pos2 ()
  (send *viewing* :look #f(700 -1000 800)))

(defun pos3 ()
  (send *viewing* :look #f(700 -1000 600)))

(defun test1 ()
  (dotimes (x 20)
	   (send eta3 :translate #f(0 3 3) :world)
	   (gldraw *scene*)))

(defun test2 ()
  (dotimes (x 20)
	   (send eta3 :translate #f(0 -3 -3) :world)
	   (gldraw *scene*)))

(defun test3 ()
  (send eta3 :open-fingers 80)
  (gldraw *scene*))

(defun test4 ()
  (send eta3 :close-fingers)
  (gldraw *scene*))

(defun test5 ()
  (dotimes (height 50)
	   (send *viewing* :look 
		 (float-vector 1500 -500 (* 30 (- height 10)))
		 (float-vector -500 0 0))
	   (gldraw *scene*)))

;; round trip tour around the scene
(defun test6 ()
  (do ((angle 0 (incf angle 2)))
      ((>= angle 360) nil)
      (let* ((rad (/ (* pi angle) 180))
	     (d 1500)
	     (x (* d (cos rad)))
	     (y (* d (sin rad))))
	(send *viewing* :look 
	      (float-vector x y 700)
	      (float-vector -500 0 0))
	(gldraw *scene*))))

;; fix eta3 position
(defun config (j0 j1 j2 j3 j4 j5)
  (send eta3 :config (float-vector j0 j1 j2 j3 j4 j5)))

;; let eta3 take home position
(defun reset-config ()
  (send eta3 :config (float-vector 0 0.0 -pi/2 pi/2 0 -pi/2)))

;; test movement of one joint
(defun test-axis (axis inc)
  (let ((conf (coerce (send eta3 :config) cons)))
    (dotimes (i 3)
	     (incf (elt conf axis) (* inc (/ pi 180)))
	     (apply #'config conf)
	     (gldraw *scene*))))

;; joint movement test
(defun test-c ()
  (dolist (axis '(0 1 2 3 4 5))
	  (print axis)
	  (test-axis axis 1)
	  (test-axis axis -1)))

;; make the gdome rotate
(defun test-g ()
  (dotimes (i 90)
	   (send *obj2* :rotate (/ pi 60) #f(0 1 1))
	   (gldraw *scene*)))

;; make many things rotate
(defun test-r ()
  (dotimes (i 90)
	   (send eta3 :rotate (/ pi 360) #f(1 1 0))	;<- watch out for maxangles
	   (send eta3 :open-fingers (if (> i 90) -0.5 0.5))
	   (send *obj1* :rotate (/ pi 60) #f(0 1 1))
	   (send *obj2* :rotate (/ pi 60) #f(1 1 0))
	   (send *obj3* :rotate (/ pi 60) #f(1 0 1))
	   (gldraw *scene*)))


#| example -- some test sequence.

(progn
  (reset-config)
  (send eta3 :close-fingers)
  (send eta3 :set-coords)
  (pos1)
  (test2)
  (pos2)
  (test6)
  (test1)
  (pos2)
  (test-r))

|#
