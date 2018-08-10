;; test code for robot usage

(require :unittest "lib/llib/unittest.l")
(init-unit-test)

(load "irteus/demo/sample-robot-model.l")
(unless (boundp '*robot*)
  (setq *robot* (instance sample-robot :init)))

(deftest test-properties
  ;; accessor of links
  (assert (send *robot* :links) (format nil "links accessor"))
  ;; accessor of limb links
  (dolist (l '(:rarm :larm :rleg :lleg :head :torso))
    (assert (send *robot* l :links) (format nil "limb links accessor")))
  ;; accessor of joint-list
  (assert (send *robot* :joint-list) (format nil "joint-list accessor"))
  ;; accessor of limb joint-list
  (dolist (l '(:rarm :larm :rleg :lleg :head :torso))
    (assert (send *robot* l :joint-list) (format nil "limb joint-list accessor")))
  ;; accessor of link
  (dolist (l (send *robot* :links))
    (assert (send *robot* :link (send l :name)) (format nil "link accessor (~18A)" (send l :name))))
  ;; accessor of joint
  (dolist (j (send *robot* :joint-list))
    (assert (send *robot* :joint (send j :name)) (format nil "joint accessor (~18A)" (send j :name))))
  ;; accessor of end-coords
  (dolist (l '(:rarm :larm :rleg :lleg :head))
    (assert (send *robot* l :end-coords) (format nil "end-coords accessor (~8A)" l)))
  ;; accessor of mass properties
  (dolist (l (send *robot* :links))
    (assert (and (numberp (send l :weight)) (vectorp (l . acentroid)) (arrayp (send l :inertia-tensor)))
            (format nil "link mass properties accessor (~18A)" (send l :name))))
  ;; accessor of joint
  (dolist (j (send *robot* :joint-list))
    (assert (and (send j :min-angle) (send j :max-angle) (send j :max-joint-velocity) (send j :max-joint-torque))
            (format nil "joint properties accessor (~18A)" (send j :name))))
  ;; accessor of sensors
  (dolist (sensor-type '(:camera :force-sensor :imu-sensor))
    (assert (send *robot* (read-from-string (format nil "~As" sensor-type)))
            (format nil "~As accessor" sensor-type)))
  ;; accessor of limb sensors
  (assert (send *robot* :head :cameras) (format nil "limb :cameras accessor"))
  (assert (send *robot* :torso :imu-sensors) (format nil "limb :imu-sensors accessor"))
  (dolist (l '(:rarm :larm :rleg :lleg))
    (assert (send *robot* l :force-sensors)) (format nil "limb :force-sensors accessor"))
  ;; accessor of sensor
  (dolist (sensor-type '(:camera :force-sensor :imu-sensor))
    (dolist (sen (send *robot* (read-from-string (format nil "~As" sensor-type))))
      (assert (send *robot* sensor-type (send sen :name))
              (format nil "~A accessor" sensor-type))))
  )

(deftest test-lookat
  (let ((ret) (gaze-dir) (target-dir))
    (dolist (yaw (list -150 150))
      (dolist (target (list #f(-100 -200 350) #f(0 -200 350) #f(200 -200 350)
                            #f(200 0 350)
                            #f(200 200 350) #f(0 200 350) #f(-100 200 350)))
        (send *robot* :head :neck-p :joint-angle 0)
        (send *robot* :head :neck-y :joint-angle yaw)
        ;;(send *irtviewer* :draw-objects)
        (setq ret (send *robot* :head :look-at target :debug-view t))
        (setq gaze-dir (matrix-column (send *robot* :head :end-coords :worldrot) 2))
        (setq target-dir (normalize-vector (v- target (send *robot* :head :end-coords :worldpos))))
        (format t "ret = ~A, (v. gaze-dir target-dir) = ~A~%" ret (v. gaze-dir target-dir))
        (assert (and ret (> (v. gaze-dir target-dir) 0.9)) "look-at-ik failed")
        ))
    ))

(deftest test-camera-ray-screen-point-1
  (let (cam obj scp ray odp)
    (setq cam
          (make-camera-from-param :pwidth 640 :pheight 360
                                  :fx 400 :fy 300
                                  :cx 300 :cy 150 :name "camtest"
                                  :create-viewer nil))
    ;; move camera
    (send cam :translate #f(100 100 100) :world)
    (send cam :rotate 1.25 :x :world)
    (send cam :rotate 0.25 :y :world)
    (send cam :rotate 0.75 :z :world)

    (setq obj (make-cube 10 10 10 :pos #f(100 100 200)))

    ;;(objects (list cam obj))
    (format t ";; camera location ~A~%" (send cam :worldpos))
    (format t ";; object location ~A~%" obj)
    (setq scp (send cam :screen-point (send obj :worldpos)))
    (format t ";; screen point ~A~%" scp)
    (setq ray (send cam :ray (elt scp 0) (elt scp 1)))
    (format t ";; ray to the point ~A~%" ray)
    ;; object position relative to camera
    (setq obp (send cam :inverse-transform-vector (send obj :worldpos)))
    (format t ";; object location wrt camera ~A~%" obp)
    ;; object postition using ray
    (setq obr (v+ (send cam :worldpos) (scale (norm obp) ray)))
    (format t ";; object location from :ray ~A~%" obr)


    (assert (eps-v= obr (send obj :worldpos)) "check :ray and :screen-point")
    ))

(deftest test-camera-ray-screen-point-2
  (let (cam obj scp ray odp)

    (setq cam (send *robot* :camera "left-camera"))
    (setq obj (make-cube 10 10 10 :pos #f(300 130 400)))

    ;;(objects (list cam obj))
    (format t ";; camera location ~A~%" (send cam :worldpos))
    (format t ";; object location ~A~%" obj)
    (setq scp (send cam :screen-point (send obj :worldpos)))
    (format t ";; screen point ~A~%" scp)
    (setq ray (send cam :ray (elt scp 0) (elt scp 1)))
    (format t ";; ray to the point ~A~%" ray)
    ;; object position relative to camera
    (setq obp (send cam :inverse-transform-vector (send obj :worldpos)))
    (format t ";; object location wrt camera ~A~%" obp)
    ;; object postition using ray
    (setq obr (v+ (send cam :worldpos) (scale (norm obp) ray)))
    (format t ";; object location from :ray ~A~%" obr)


    (assert (eps-v= obr (send obj :worldpos)) "check :ray and :screen-point")
    ))

(deftest test-camera-image-1 ()
  (let (img w h (num 0))
#|
    (load "irteus/demo/sample-camera-model.l")
    (sample-get-camera-image-1)
;    (do-until-key
;     (send (*cam* . img-viewer) :viewsurface :flush)
;     (send *cam* :draw-objects (list *obj*))
;     (x::window-main-one)
;    )
    (setq img (send *cam* :get-image))
    (setq w (send *cam* :width)
          h (send *cam* :height))
    (dotimes (x w)
      (dotimes (y h)
        (if (> (send img :pixel x y) 100)
            (format t "~x " (send img :pixel x y)))
        (if (> (send img :pixel x y) 100)
            (incf num))))
    (format t ";; number of non black pixels ~A~%" num)
    ;;(assert (not (eq num 0)) "get-image retuns black image")
|#
    ))

(deftest test-camera-image-2 ()
  (let (img w h (num 0))
#|
    (load "irteus/demo/sample-camera-model.l")
    (sample-get-camera-image-2)
    (setq img (send *camera-model* :get-image))
    (setq w (send *camera-model* :width)
          h (send *camera-model* :height))
    (dotimes (x w)
      (dotimes (y h)
        (if (> (send img :pixel x y) 100)
            (incf num))))
    (format t ";; number of non black pixels ~A~%" num)
    ;;(assert (not (eq num 0)) "get-image retuns black image")
|#
    ))


(run-all-tests)
(exit)
