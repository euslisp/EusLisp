;;
;; DO NOT EDIT THIS FILE
;; this file is automatically generated from euslisp+euslib version 
;;
;;
(defclass plus-2800-desk-object
  :super cascaded-link
  :slots (sensors
         handle0 handle1 handle2 handle3
         ))
(defmethod plus-2800-desk-object
  (:init
   (&rest args &key (name "plus-2800-desk") (pos (float-vector 0 0 0)) (rot (unit-matrix 3)) &allow-other-keys)
   (let (c bc
         blink0
                 )
     (send-super* :init :name name args)

     ;; definition of link

     ;; definition of :plus-2800-desk-bodyset2
     (setq bc (list
       (instance faceset :init :faces (list
         (instance face :init :vertices (list (float-vector 600.0 1400.0 705.0) (float-vector -600.0 1400.0 705.0) (float-vector -600.0 -1400.0 705.0) (float-vector 600.0 -1400.0 705.0)))
         (instance face :init :vertices (list (float-vector -600.0 1400.0 665.0) (float-vector 600.0 1400.0 665.0) (float-vector 600.0 -1400.0 665.0) (float-vector -600.0 -1400.0 665.0)))
         (instance face :init :vertices (list (float-vector 600.0 1400.0 705.0) (float-vector 600.0 1400.0 665.0) (float-vector -600.0 1400.0 665.0) (float-vector -600.0 1400.0 705.0)))
         (instance face :init :vertices (list (float-vector 600.0 -1400.0 705.0) (float-vector 600.0 -1400.0 665.0) (float-vector 600.0 1400.0 665.0) (float-vector 600.0 1400.0 705.0)))
         (instance face :init :vertices (list (float-vector -600.0 -1400.0 705.0) (float-vector -600.0 -1400.0 665.0) (float-vector 600.0 -1400.0 665.0) (float-vector 600.0 -1400.0 705.0)))
         (instance face :init :vertices (list (float-vector -600.0 1400.0 705.0) (float-vector -600.0 1400.0 665.0) (float-vector -600.0 -1400.0 665.0) (float-vector -600.0 -1400.0 705.0)))
       ))
       (instance faceset :init :faces (list
         (instance face :init :vertices (list (float-vector 534.641 1230.0 665.0) (float-vector 540.0 1250.0 665.0) (float-vector 534.641 1270.0 665.0) (float-vector 520.0 1284.64 665.0) (float-vector 500.0 1290.0 665.0) (float-vector 480.0 1284.64 665.0) (float-vector 465.359 1270.0 665.0) (float-vector 460.0 1250.0 665.0) (float-vector 465.359 1230.0 665.0) (float-vector 480.0 1215.36 665.0) (float-vector 500.0 1210.0 665.0) (float-vector 520.0 1215.36 665.0)))
         (instance face :init :vertices (list (float-vector 540.0 1250.0 0.0) (float-vector 534.641 1230.0 0.0) (float-vector 520.0 1215.36 0.0) (float-vector 500.0 1210.0 0.0) (float-vector 480.0 1215.36 0.0) (float-vector 465.359 1230.0 0.0) (float-vector 460.0 1250.0 0.0) (float-vector 465.359 1270.0 0.0) (float-vector 480.0 1284.64 0.0) (float-vector 500.0 1290.0 0.0) (float-vector 520.0 1284.64 0.0) (float-vector 534.641 1270.0 0.0)))
         (instance face :init :vertices (list (float-vector 534.641 1230.0 665.0) (float-vector 534.641 1230.0 0.0) (float-vector 540.0 1250.0 0.0) (float-vector 540.0 1250.0 665.0)))
         (instance face :init :vertices (list (float-vector 520.0 1215.36 665.0) (float-vector 520.0 1215.36 0.0) (float-vector 534.641 1230.0 0.0) (float-vector 534.641 1230.0 665.0)))
         (instance face :init :vertices (list (float-vector 500.0 1210.0 665.0) (float-vector 500.0 1210.0 0.0) (float-vector 520.0 1215.36 0.0) (float-vector 520.0 1215.36 665.0)))
         (instance face :init :vertices (list (float-vector 480.0 1215.36 665.0) (float-vector 480.0 1215.36 0.0) (float-vector 500.0 1210.0 0.0) (float-vector 500.0 1210.0 665.0)))
         (instance face :init :vertices (list (float-vector 465.359 1230.0 665.0) (float-vector 465.359 1230.0 0.0) (float-vector 480.0 1215.36 0.0) (float-vector 480.0 1215.36 665.0)))
         (instance face :init :vertices (list (float-vector 460.0 1250.0 665.0) (float-vector 460.0 1250.0 0.0) (float-vector 465.359 1230.0 0.0) (float-vector 465.359 1230.0 665.0)))
         (instance face :init :vertices (list (float-vector 465.359 1270.0 665.0) (float-vector 465.359 1270.0 0.0) (float-vector 460.0 1250.0 0.0) (float-vector 460.0 1250.0 665.0)))
         (instance face :init :vertices (list (float-vector 480.0 1284.64 665.0) (float-vector 480.0 1284.64 0.0) (float-vector 465.359 1270.0 0.0) (float-vector 465.359 1270.0 665.0)))
         (instance face :init :vertices (list (float-vector 500.0 1290.0 665.0) (float-vector 500.0 1290.0 0.0) (float-vector 480.0 1284.64 0.0) (float-vector 480.0 1284.64 665.0)))
         (instance face :init :vertices (list (float-vector 520.0 1284.64 665.0) (float-vector 520.0 1284.64 0.0) (float-vector 500.0 1290.0 0.0) (float-vector 500.0 1290.0 665.0)))
         (instance face :init :vertices (list (float-vector 534.641 1270.0 665.0) (float-vector 534.641 1270.0 0.0) (float-vector 520.0 1284.64 0.0) (float-vector 520.0 1284.64 665.0)))
         (instance face :init :vertices (list (float-vector 540.0 1250.0 665.0) (float-vector 540.0 1250.0 0.0) (float-vector 534.641 1270.0 0.0) (float-vector 534.641 1270.0 665.0)))
       ))
       (instance faceset :init :faces (list
         (instance face :init :vertices (list (float-vector -465.359 1230.0 665.0) (float-vector -460.0 1250.0 665.0) (float-vector -465.359 1270.0 665.0) (float-vector -480.0 1284.64 665.0) (float-vector -500.0 1290.0 665.0) (float-vector -520.0 1284.64 665.0) (float-vector -534.641 1270.0 665.0) (float-vector -540.0 1250.0 665.0) (float-vector -534.641 1230.0 665.0) (float-vector -520.0 1215.36 665.0) (float-vector -500.0 1210.0 665.0) (float-vector -480.0 1215.36 665.0)))
         (instance face :init :vertices (list (float-vector -460.0 1250.0 0.0) (float-vector -465.359 1230.0 0.0) (float-vector -480.0 1215.36 0.0) (float-vector -500.0 1210.0 0.0) (float-vector -520.0 1215.36 0.0) (float-vector -534.641 1230.0 0.0) (float-vector -540.0 1250.0 0.0) (float-vector -534.641 1270.0 0.0) (float-vector -520.0 1284.64 0.0) (float-vector -500.0 1290.0 0.0) (float-vector -480.0 1284.64 0.0) (float-vector -465.359 1270.0 0.0)))
         (instance face :init :vertices (list (float-vector -465.359 1230.0 665.0) (float-vector -465.359 1230.0 0.0) (float-vector -460.0 1250.0 0.0) (float-vector -460.0 1250.0 665.0)))
         (instance face :init :vertices (list (float-vector -480.0 1215.36 665.0) (float-vector -480.0 1215.36 0.0) (float-vector -465.359 1230.0 0.0) (float-vector -465.359 1230.0 665.0)))
         (instance face :init :vertices (list (float-vector -500.0 1210.0 665.0) (float-vector -500.0 1210.0 0.0) (float-vector -480.0 1215.36 0.0) (float-vector -480.0 1215.36 665.0)))
         (instance face :init :vertices (list (float-vector -520.0 1215.36 665.0) (float-vector -520.0 1215.36 0.0) (float-vector -500.0 1210.0 0.0) (float-vector -500.0 1210.0 665.0)))
         (instance face :init :vertices (list (float-vector -534.641 1230.0 665.0) (float-vector -534.641 1230.0 0.0) (float-vector -520.0 1215.36 0.0) (float-vector -520.0 1215.36 665.0)))
         (instance face :init :vertices (list (float-vector -540.0 1250.0 665.0) (float-vector -540.0 1250.0 0.0) (float-vector -534.641 1230.0 0.0) (float-vector -534.641 1230.0 665.0)))
         (instance face :init :vertices (list (float-vector -534.641 1270.0 665.0) (float-vector -534.641 1270.0 0.0) (float-vector -540.0 1250.0 0.0) (float-vector -540.0 1250.0 665.0)))
         (instance face :init :vertices (list (float-vector -520.0 1284.64 665.0) (float-vector -520.0 1284.64 0.0) (float-vector -534.641 1270.0 0.0) (float-vector -534.641 1270.0 665.0)))
         (instance face :init :vertices (list (float-vector -500.0 1290.0 665.0) (float-vector -500.0 1290.0 0.0) (float-vector -520.0 1284.64 0.0) (float-vector -520.0 1284.64 665.0)))
         (instance face :init :vertices (list (float-vector -480.0 1284.64 665.0) (float-vector -480.0 1284.64 0.0) (float-vector -500.0 1290.0 0.0) (float-vector -500.0 1290.0 665.0)))
         (instance face :init :vertices (list (float-vector -465.359 1270.0 665.0) (float-vector -465.359 1270.0 0.0) (float-vector -480.0 1284.64 0.0) (float-vector -480.0 1284.64 665.0)))
         (instance face :init :vertices (list (float-vector -460.0 1250.0 665.0) (float-vector -460.0 1250.0 0.0) (float-vector -465.359 1270.0 0.0) (float-vector -465.359 1270.0 665.0)))
       ))
       (instance faceset :init :faces (list
         (instance face :init :vertices (list (float-vector -465.359 -1270.0 665.0) (float-vector -460.0 -1250.0 665.0) (float-vector -465.359 -1230.0 665.0) (float-vector -480.0 -1215.36 665.0) (float-vector -500.0 -1210.0 665.0) (float-vector -520.0 -1215.36 665.0) (float-vector -534.641 -1230.0 665.0) (float-vector -540.0 -1250.0 665.0) (float-vector -534.641 -1270.0 665.0) (float-vector -520.0 -1284.64 665.0) (float-vector -500.0 -1290.0 665.0) (float-vector -480.0 -1284.64 665.0)))
         (instance face :init :vertices (list (float-vector -460.0 -1250.0 0.0) (float-vector -465.359 -1270.0 0.0) (float-vector -480.0 -1284.64 0.0) (float-vector -500.0 -1290.0 0.0) (float-vector -520.0 -1284.64 0.0) (float-vector -534.641 -1270.0 0.0) (float-vector -540.0 -1250.0 0.0) (float-vector -534.641 -1230.0 0.0) (float-vector -520.0 -1215.36 0.0) (float-vector -500.0 -1210.0 0.0) (float-vector -480.0 -1215.36 0.0) (float-vector -465.359 -1230.0 0.0)))
         (instance face :init :vertices (list (float-vector -465.359 -1270.0 665.0) (float-vector -465.359 -1270.0 0.0) (float-vector -460.0 -1250.0 0.0) (float-vector -460.0 -1250.0 665.0)))
         (instance face :init :vertices (list (float-vector -480.0 -1284.64 665.0) (float-vector -480.0 -1284.64 0.0) (float-vector -465.359 -1270.0 0.0) (float-vector -465.359 -1270.0 665.0)))
         (instance face :init :vertices (list (float-vector -500.0 -1290.0 665.0) (float-vector -500.0 -1290.0 0.0) (float-vector -480.0 -1284.64 0.0) (float-vector -480.0 -1284.64 665.0)))
         (instance face :init :vertices (list (float-vector -520.0 -1284.64 665.0) (float-vector -520.0 -1284.64 0.0) (float-vector -500.0 -1290.0 0.0) (float-vector -500.0 -1290.0 665.0)))
         (instance face :init :vertices (list (float-vector -534.641 -1270.0 665.0) (float-vector -534.641 -1270.0 0.0) (float-vector -520.0 -1284.64 0.0) (float-vector -520.0 -1284.64 665.0)))
         (instance face :init :vertices (list (float-vector -540.0 -1250.0 665.0) (float-vector -540.0 -1250.0 0.0) (float-vector -534.641 -1270.0 0.0) (float-vector -534.641 -1270.0 665.0)))
         (instance face :init :vertices (list (float-vector -534.641 -1230.0 665.0) (float-vector -534.641 -1230.0 0.0) (float-vector -540.0 -1250.0 0.0) (float-vector -540.0 -1250.0 665.0)))
         (instance face :init :vertices (list (float-vector -520.0 -1215.36 665.0) (float-vector -520.0 -1215.36 0.0) (float-vector -534.641 -1230.0 0.0) (float-vector -534.641 -1230.0 665.0)))
         (instance face :init :vertices (list (float-vector -500.0 -1210.0 665.0) (float-vector -500.0 -1210.0 0.0) (float-vector -520.0 -1215.36 0.0) (float-vector -520.0 -1215.36 665.0)))
         (instance face :init :vertices (list (float-vector -480.0 -1215.36 665.0) (float-vector -480.0 -1215.36 0.0) (float-vector -500.0 -1210.0 0.0) (float-vector -500.0 -1210.0 665.0)))
         (instance face :init :vertices (list (float-vector -465.359 -1230.0 665.0) (float-vector -465.359 -1230.0 0.0) (float-vector -480.0 -1215.36 0.0) (float-vector -480.0 -1215.36 665.0)))
         (instance face :init :vertices (list (float-vector -460.0 -1250.0 665.0) (float-vector -460.0 -1250.0 0.0) (float-vector -465.359 -1230.0 0.0) (float-vector -465.359 -1230.0 665.0)))
       ))
       (instance faceset :init :faces (list
         (instance face :init :vertices (list (float-vector 534.641 -1270.0 665.0) (float-vector 540.0 -1250.0 665.0) (float-vector 534.641 -1230.0 665.0) (float-vector 520.0 -1215.36 665.0) (float-vector 500.0 -1210.0 665.0) (float-vector 480.0 -1215.36 665.0) (float-vector 465.359 -1230.0 665.0) (float-vector 460.0 -1250.0 665.0) (float-vector 465.359 -1270.0 665.0) (float-vector 480.0 -1284.64 665.0) (float-vector 500.0 -1290.0 665.0) (float-vector 520.0 -1284.64 665.0)))
         (instance face :init :vertices (list (float-vector 540.0 -1250.0 0.0) (float-vector 534.641 -1270.0 0.0) (float-vector 520.0 -1284.64 0.0) (float-vector 500.0 -1290.0 0.0) (float-vector 480.0 -1284.64 0.0) (float-vector 465.359 -1270.0 0.0) (float-vector 460.0 -1250.0 0.0) (float-vector 465.359 -1230.0 0.0) (float-vector 480.0 -1215.36 0.0) (float-vector 500.0 -1210.0 0.0) (float-vector 520.0 -1215.36 0.0) (float-vector 534.641 -1230.0 0.0)))
         (instance face :init :vertices (list (float-vector 534.641 -1270.0 665.0) (float-vector 534.641 -1270.0 0.0) (float-vector 540.0 -1250.0 0.0) (float-vector 540.0 -1250.0 665.0)))
         (instance face :init :vertices (list (float-vector 520.0 -1284.64 665.0) (float-vector 520.0 -1284.64 0.0) (float-vector 534.641 -1270.0 0.0) (float-vector 534.641 -1270.0 665.0)))
         (instance face :init :vertices (list (float-vector 500.0 -1290.0 665.0) (float-vector 500.0 -1290.0 0.0) (float-vector 520.0 -1284.64 0.0) (float-vector 520.0 -1284.64 665.0)))
         (instance face :init :vertices (list (float-vector 480.0 -1284.64 665.0) (float-vector 480.0 -1284.64 0.0) (float-vector 500.0 -1290.0 0.0) (float-vector 500.0 -1290.0 665.0)))
         (instance face :init :vertices (list (float-vector 465.359 -1270.0 665.0) (float-vector 465.359 -1270.0 0.0) (float-vector 480.0 -1284.64 0.0) (float-vector 480.0 -1284.64 665.0)))
         (instance face :init :vertices (list (float-vector 460.0 -1250.0 665.0) (float-vector 460.0 -1250.0 0.0) (float-vector 465.359 -1270.0 0.0) (float-vector 465.359 -1270.0 665.0)))
         (instance face :init :vertices (list (float-vector 465.359 -1230.0 665.0) (float-vector 465.359 -1230.0 0.0) (float-vector 460.0 -1250.0 0.0) (float-vector 460.0 -1250.0 665.0)))
         (instance face :init :vertices (list (float-vector 480.0 -1215.36 665.0) (float-vector 480.0 -1215.36 0.0) (float-vector 465.359 -1230.0 0.0) (float-vector 465.359 -1230.0 665.0)))
         (instance face :init :vertices (list (float-vector 500.0 -1210.0 665.0) (float-vector 500.0 -1210.0 0.0) (float-vector 480.0 -1215.36 0.0) (float-vector 480.0 -1215.36 665.0)))
         (instance face :init :vertices (list (float-vector 520.0 -1215.36 665.0) (float-vector 520.0 -1215.36 0.0) (float-vector 500.0 -1210.0 0.0) (float-vector 500.0 -1210.0 665.0)))
         (instance face :init :vertices (list (float-vector 534.641 -1230.0 665.0) (float-vector 534.641 -1230.0 0.0) (float-vector 520.0 -1215.36 0.0) (float-vector 520.0 -1215.36 665.0)))
         (instance face :init :vertices (list (float-vector 540.0 -1250.0 665.0) (float-vector 540.0 -1250.0 0.0) (float-vector 534.641 -1230.0 0.0) (float-vector 534.641 -1230.0 665.0)))
       ))
       ))
     (dolist (b (cdr bc)) (send (car bc) :assoc b))
     (send (elt bc 0) :set-color :white)
     (send (elt bc 1) :set-color :white)
     (send (elt bc 2) :set-color :white)
     (send (elt bc 3) :set-color :white)
     (send (elt bc 4) :set-color :white)
     (setq blink0 (instance bodyset-link :init (make-cascoords) :bodies bc :name :plus-2800-desk-bodyset2 :weight 1 :centroid (float-vector 0.0 0.0 0.0) :inertia-tensor #2f((1.0 0.0 0.0) (0.0 1.0 0.0) (0.0 0.0 1.0))))

     ;; definition of assoc
     (send self :assoc blink0)

     ;; definition of end-coords

     ;; definition of joint


     ;; definition of :handle
     (setq handle0 (make-cascoords :pos (float-vector -600.0 300.0 665.0) :rot #2f((1.0 2.465190e-32 -2.449213e-16) (-2.449213e-16 2.220446e-16 -1.0) (2.465190e-32 1.0 2.220446e-16)) :name "handle-l"))
     (send self :assoc handle0)
     (setq handle1 (make-cascoords :pos (float-vector -600.0 -300.0 665.0) :rot #2f((1.0 -7.498304e-33 6.842278e-49) (6.842278e-49 2.220446e-16 1.0) (-7.498304e-33 -1.0 2.220446e-16)) :name "handle-r"))
     (send self :assoc handle1)
     (setq handle2 (make-cascoords :pos (float-vector 600.0 -300.0 665.0) :rot #2f((-1.0 1.232595e-32 1.224606e-16) (1.224606e-16 2.220446e-16 1.0) (-1.232595e-32 1.0 -2.220446e-16)) :name "handle-l"))
     (send self :assoc handle2)
     (setq handle3 (make-cascoords :pos (float-vector 600.0 300.0 665.0) :rot #2f((-1.0 1.232595e-32 -1.224606e-16) (1.224606e-16 2.220446e-16 -1.0) (1.232595e-32 -1.0 -2.220446e-16)) :name "handle-r"))
     (send self :assoc handle3)

     ;; init-ending 
     (setq links (list blink0))
     (setq joint-list (list))
     (send self :init-ending)
     (send self :move-to (make-coords :pos pos :rot rot))
     (send-all links :worldcoords)

     self))
  (:cameras (&rest args)
   (forward-message-to-all (list) args))

  (:handle () (list  handle0 handle1 handle2 handle3))
  (:handle-handle-l () handle0)
  (:handle-handle-r () handle1)
  (:handle-handle-l () handle2)
  (:handle-handle-r () handle3)
  (:attention () (list ))
  (:button () (list ))
  )

(defun plus-2800-desk (&rest args) (instance* plus-2800-desk-object :init args))
;; (format *error-output* "(instance plus-2800-desk-object :init) for generating model~%")