;; test code for irteus/irtdyna.l, irtmodel.l, and irtrobot.l using robot model

(require :unittest "lib/llib/unittest.l")
(init-unit-test)

(load "irteus/demo/sample-robot-model.l")
(load "irteus/demo/sample-arm-model.l")
(load "irteus/demo/sample-multidof-arm-model.l")
(load "irteus/demo/special-joints.l")
(unless (boundp '*sample-robot*)
  (setq *sample-robot* (instance sample-robot :init))
  (unless (or (null x::*display*) (= x::*display* 0))
    (objects (list *sample-robot*))))
(unless (boundp '*sarm-robot*)
  (setq *sarm-robot* (instance sample-multidof-arm-robot :init)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; common test codes
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; test zmp
(defun test-zmp-comomn
  (robot &key ((:viewer vw) (if (boundp '*irtviewer*) *irtviewer*)))
  (unless (or (null x::*display*) (= x::*display* 0))
    (objects (list robot)))
  (every
   #'identity
   (mapcar #'(lambda (leg)
               (let ((zmp-cog-p))
                 (send robot :newcoords (make-coords))
                 (send robot :reset-pose)
                 (send robot :fix-leg-to-coords (make-coords) '(:rleg :lleg))
                 (send robot :calc-zmp)
                 (unless (or (null x::*display*) (= x::*display* 0))
                   (send vw :look-all))
                 (send robot :move-centroid-on-foot leg '(:rleg :lleg))
                 (unless (or (null x::*display*) (= x::*display* 0))
                   (send vw :look-all))
                 ;; if angle-vector and root-coords are updated, zmp does not equal to cog because inertia term exists
                 (push (not (eps= (norm (subseq (v- (send robot :centroid) (send robot :calc-zmp)) 0 2)) 0.0)) zmp-cog-p)
                 (send robot :calc-zmp)
                 ;; if angle-vector and root-coords are updated twice, zmp should equal to cog
                 (push (eps= (norm (subseq (v- (send robot :centroid) (send robot :calc-zmp)) 0 2)) 0.0) zmp-cog-p)
                 (every #'identity zmp-cog-p)))
           '(:rleg :lleg :both))))

(defun init-pose-torque-tests
  (robot)
  (mapcar #'(lambda (jnt)
              (send jnt :joint-angle
                    (min (max 0.0 (send jnt :min-angle)) (send jnt :max-angle))))
          (send robot :joint-list)))

(defun max-angle-with-inf-check-torque-tests
  (jnt)
  (if (and (eq *inf* (send jnt :max-angle)) (derivedp jnt rotational-joint)) 90 (send jnt :max-angle)))

(defun min-angle-with-inf-check-torque-tests
  (jnt)
  (if (and (eq *-inf* (send jnt :min-angle)) (derivedp jnt rotational-joint)) -90 (send jnt :min-angle)))

;; check torque comparing toroques from links weights with torques from :torque-vector
;; however, currently robots start torque check from initial-pose (all joints are 0) so that yaw joints are not checked.
(defun test-torque-from-its-own-weight-common
  (robot &key ((:viewer vw) (if (boundp '*irtviewer*) *irtviewer*)) (debug-view))
  (init-pose-torque-tests robot)
  (unless (or (null x::*display*) (= x::*display* 0))
    (objects (list robot)))
  (labels ((check-torque-for-one-joint
            (jnt ja)
            (init-pose-torque-tests robot)
            (send jnt :joint-angle ja)
            (unless (or (null x::*display*) (= x::*display* 0))
              (send vw :draw-objects))
            (send robot :weight) ;; for calculating c-til and m-til
            (let* ((weight-force (scale (* 0.001 (send (send jnt :child-link) :get :m-til))
                                        (scale -0.001 *g-vec*)))
                   (torque-from-link-weight
                    (v.
                     ;; axis to convert link-weight-moment -> joint torque
                     (normalize-vector (send (send (send jnt :parent-link :copy-worldcoords)
                                                   :transform (jnt . default-coords))
                                             :rotate-vector
                                             (case (jnt . axis)
                                               (:x (float-vector 1 0 0)) (:-x (float-vector -1 0 0))
                                               (:y (float-vector 0 1 0)) (:-y (float-vector 0 -1 0))
                                               (:z (float-vector 0 0 1)) (:-z (float-vector 0 0 -1))
                                               (t (jnt . axis)))))
                     ;; moment caused by link weight
                     (if (derivedp jnt rotational-joint)
                         (v*
                          (scale 0.001 (v- (send (send jnt :child-link) :get :c-til) (send jnt :child-link :worldpos)))
                          weight-force)
                       weight-force)
                     ))
                   (torque-from-method
                    (elt (send robot :torque-vector
                               :force-list (list (float-vector 0 0 0))
                               :moment-list (list (float-vector 0 0 0))
                               :target-coords (list (send robot :head :end-coords)))
                         (if (find-method robot :actuators) (send jnt :servo :no) (position jnt (send robot :joint-list)))))
                   (torque-diff (+ torque-from-link-weight torque-from-method)))
              (unless (eps= torque-diff 0.0)
                (if debug-view
                    (format t ";; diff ~7,3f[Nm] is too large!! <- torque(weight) ~7,3f [Nm] - torque(method) ~7,3f[Nm] (~A)~%"
                            torque-from-link-weight torque-from-method torque-diff (send jnt :name))))
              (eps= torque-diff 0.0))))
    (every #'identity
           (mapcar #'(lambda (jnt)
                       (every #'identity
                              (mapcar #'(lambda (ang) (check-torque-for-one-joint jnt ang))
                                      (if (> (max-angle-with-inf-check-torque-tests jnt) 0 (min-angle-with-inf-check-torque-tests jnt))
                                          (list (max-angle-with-inf-check-torque-tests jnt) 0 (min-angle-with-inf-check-torque-tests jnt))
                                        (list (max-angle-with-inf-check-torque-tests jnt) (min-angle-with-inf-check-torque-tests jnt)))
                                      )))
                   (send robot :joint-list)))
    ))

;; check torque comparing toroques from ext-force with torques from :torque-vector
;; however, currently robots start torque check from initial-pose (all joints are 0) so that yaw joints are not checked.
(defun test-torque-from-ext-force-common
  (robot &key ((:viewer vw) (if (boundp '*irtviewer*) *irtviewer*)) (debug-view))
  (init-pose-torque-tests robot)
  (unless (or (null x::*display*) (= x::*display* 0))
    (objects (list robot)))
  (labels ((check-torque-for-one-joint
            (jnt ja)
            (init-pose-torque-tests robot)
            (send jnt :joint-angle ja)
            (unless (or (null x::*display*) (= x::*display* 0))
              (send vw :draw-objects))
            (send robot :weight) ;; for calculating c-til and m-til
            (let* ((ax ;; axis to convert link-weight-moment -> joint torque
                    (normalize-vector (send (send (send jnt :parent-link :copy-worldcoords)
                                                  :transform (jnt . default-coords))
                                            :rotate-vector
                                            (case (jnt . axis)
                                              (:x (float-vector 1 0 0)) (:-x (float-vector -1 0 0))
                                              (:y (float-vector 0 1 0)) (:-y (float-vector 0 -1 0))
                                              (:z (float-vector 0 0 1)) (:-z (float-vector 0 0 -1))
                                              (t (jnt . axis))))))
                   (mt (make-cascoords
                        :coords
                        (send (send jnt :child-link :copy-worldcoords)
                              :translate (scale 100 (v* #f(0 0 1) ax)) :world)))
                   (ff #f(0 0 -50))
                   (diff-torque-from-force
                    (v. ax
                        ;; moment caused by link weight
                        (if (derivedp jnt rotational-joint)
                            (scale -1 (v* (scale 1e-3 (v- (send mt :worldpos) (send jnt :child-link :worldpos))) ff))
                          (scale -1 ff)))))
              (send (send jnt :child-link) :assoc mt)
              (let* ((idx (if (find-method robot :actuators) (send jnt :servo :no) (position jnt (send robot :joint-list))))
                     (diff-torque-from-method
                      (- (elt (send robot :torque-vector :force-list (list ff) :moment-list (list (float-vector 0 0 0)) :target-coords (list mt)) idx)
                         (elt (send robot :torque-vector :force-list (list (float-vector 0 0 0)) :moment-list (list (float-vector 0 0 0)) :target-coords (list (send robot :head :end-coords))) idx)))
                     (torque-diff (- diff-torque-from-force diff-torque-from-method)))
                (unless (eps= torque-diff 0.0)
                  (if debug-view
                      (format t ";; diff ~7,3f[Nm] is too large!! <- torque(weight) ~7,3f [Nm] - torque(method) ~7,3f[Nm] (~A, ~A)~%"
                              torque-diff diff-torque-from-force diff-torque-from-method (send jnt :name) (send jnt :joint-angle))))
                (send (send jnt :child-link) :dissoc mt)
                (eps= torque-diff 0.0)))))
    (every #'identity
           (mapcar #'(lambda (jnt)
                       (every #'identity
                              (mapcar #'(lambda (ang) (check-torque-for-one-joint jnt ang))
                                      (if (> (max-angle-with-inf-check-torque-tests jnt) 0 (min-angle-with-inf-check-torque-tests jnt))
                                          (list (max-angle-with-inf-check-torque-tests jnt) 0 (min-angle-with-inf-check-torque-tests jnt))
                                        (list (max-angle-with-inf-check-torque-tests jnt) (min-angle-with-inf-check-torque-tests jnt)))
                                      )))
                   (send robot :joint-list)))
    ))

;; sample mobile robot
(defclass sample-mobile-robot
  :super robot-model
  :slots (wheel-l wheel-r end-coords))

(defmethod sample-mobile-robot
  (:init 
   (&rest args)
   (let (c body-base body-wheel-l body-wheel-r)
     (send-super* :init args)
     (setq body-base (make-cylinder 50 150))
     (send body-base :locate #f(150 0 200))
     (setq body-base (body+ (make-cylinder 200 200) body-base))
     (send body-base :locate #f(0 0 100))
     (send body-base :set-color :seagreen)
     (setq body-base (instance bodyset-link :init (make-cascoords)
			       :bodies (list body-base) :name :body))

     (setq body-wheel-l (instance bodyset-link :init (make-cascoords)
				  :bodies (list (make-cylinder 140 30))
				  :name :wheel-l))
     (send body-wheel-l :rotate -pi/2 :x)
     (send body-wheel-l :locate #f(0 -140 -200))
     (send-all (send body-wheel-l :bodies) :set-color :red)

     (setq body-wheel-r (instance bodyset-link :init (make-cascoords)
				  :bodies (list (make-cylinder 140 30))
				  :name :wheel-r))
     (send body-wheel-r :rotate -pi/2 :x)
     (send body-wheel-r :locate #f(0 -140 200))
     (send-all (send body-wheel-r :bodies) :set-color :red)

     (send self :assoc body-base)

     (send body-base :assoc (setq end-coords (make-cascoords :pos #f(10 0 0))))
     (send body-base :assoc body-wheel-l)
     (send body-base :assoc body-wheel-r)
     
     (setq wheel-l (instance rotational-joint :init :name :wheel-l
			     :child-link body-wheel-l :parent-link body-base
			     :axis :z
			     :min *-inf* :max *inf*))
     (setq wheel-r (instance rotational-joint :init :name :wheel-r
			     :child-link body-wheel-r :parent-link body-base
			     :axis :z
			     :min *-inf* :max *inf*))
     
     (setq links (list body-base body-wheel-l body-wheel-r))
     (setq joint-list (list wheel-l wheel-r))
     (send self :init-ending)
     self))
  (:wheel-l (&rest args) (forward-message-to wheel-l args))
  (:wheel-r (&rest args) (forward-message-to wheel-r args))
  (:end-coords (&rest args) (forward-message-to end-coords args))
  (:reset-pose ())
  )

;; check for wheel-joint and omniwheel-joint
(defun test-joint-for-mobile-robot-common
  (&rest args
	 &key (robot-class) (wheel-class) (use-wholebody) (debug-view :no-message)
	 &allow-other-keys)
  (setq *ground* (make-cube 3000 3000 10))
  (send *ground* :set-color :skyblue)
  (setq *robot* (instance robot-class :init))
  (send *robot* :reset-pose)
  (if (eq robot-class sarmclass)
      (send *robot* :angle-vector #f(0.0 0.0 90.0 0.0 90.0 90.0 0.0 0.0)))
  (send *robot* :newcoords (make-coords))
  (unless (or (null x::*display*) (= x::*display* 0))
    (objects (list *robot* *ground*)))
  (let ((robot-link-list
         (if use-wholebody
             (send *robot* :link-list (send *robot* :end-coords :parent)))))
    (with-append-root-joint
     (link-list-with-virtual-link *robot* robot-link-list :joint-class wheel-class)
     (send* *robot* :inverse-kinematics
            (make-cascoords :pos #f(1500 -1500 0) :rpy (float-vector pi 0 0))
            :link-list (car link-list-with-virtual-link)
            :move-target (send *robot* :end-coords)
            :debug-view debug-view
            args))
    ))

;; sample robot for sphere-joint and 6dof-joint check
(defclass sample-multidof-joint-robot
  :super cascaded-link
  :slots (end-coords))

(defmethod sample-multidof-joint-robot
  (:init
   (&rest args &key (joint-class sphere-joint) (child-init-coords (make-coords)) &allow-other-keys)
   (send-super* :init args)
   (let* ((b1 (make-gdome (make-icosahedron 30)))
	  (b2 (body+ (make-cylinder 10 100)
		     (send (make-cube 20 5 10) :locate #f(15 0 95))))
	  (l1 (instance bodyset-link :init (make-cascoords) :bodies (list b1) :name :root))
	  (l2 (instance bodyset-link :init (make-cascoords) :bodies (list b2) :name :bar)))
     (send l2 :newcoords child-init-coords)
     (let ((j (instance joint-class :init
			:parent-link l1 :child-link l2
                        :max-joint-velocity (float-vector *inf* *inf* *inf* *inf* *inf* *inf*))))
       (setq links (list l1 l2))
       (setq joint-list (list j))
       (setq end-coords (make-cascoords :coords
					(send (send l2 :copy-worldcoords) :translate #f(0 0 100))))
       (send self :assoc l1)
       (send l1 :assoc l2)
       (send l2 :assoc end-coords)
       (send self :init-ending)
       self)))
  (:end-coords (&rest args) (forward-message-to end-coords args))
  (:joint (&rest args) (forward-message-to (car joint-list) args))
  )

;; check computation of orientation of 6dof-joint and sphere-joint
;; check diff between end-coords after FK and IK
(defun test-orientation-of-joint-class-common
  (joint-class)
  (setq *robot* (instance sample-multidof-joint-robot :init :joint-class joint-class
		      :child-init-coords (make-coords :pos #f(100 200 300) :rpy (list (deg2rad 10) (deg2rad 20) (deg2rad 30)))))
  (unless (or (null x::*display*) (= x::*display* 0))
    (objects (list *robot* (send *robot* :end-coords))))
  (let ((div 100.0) (max-dif-pos 0.0) (max-dif-rot 0.0) (range 90)
	(ja (send *robot* :joint :joint-angle))
	(ec (send *robot* :end-coords :copy-worldcoords))
	(cc (send *robot* :joint :child-link :copy-worldcoords)))
    (dotimes (i 600)
      (let ((prev-ec ec) (prev-ja ja) (prev-cc cc)
	    (dd (* range (sin (/ i div)))))
	;; calc next joint-angle
	(setq ja (let ((tmp-ja (instantiate float-vector (send *robot* :joint :joint-dof))))
		   (dotimes (i (send *robot* :joint :joint-dof))
		     (setf (elt tmp-ja i) dd))
		   tmp-ja))

       (send *robot* :joint :joint-angle ja)
       (setq ec (send *robot* :end-coords :copy-worldcoords))
       (setq cc (send *robot* :joint :child-link :copy-worldcoords))
       (send *robot* :joint :joint-angle prev-ja)
       (with-difference-position-and-rotation
	(dp dr (send *robot* :end-coords) ec)
	(send *robot* :inverse-kinematics-loop dp dr
	      :link-list (send *robot* :link-list (send *robot* :end-coords :parent))
	      :union-link-list (send *robot* :link-list (send *robot* :end-coords :parent))
	      :move-target (send *robot* :end-coords)
              :avoid-nspace-gain 0.0 :avoid-weight-gain 0.0
	      ;; ease limitation of inverse-kinematics-loop
	      :thre 0 :rthre 0 :p-limit 1000 :r-limit 1000
              ))
       (setq calc-ec (send *robot* :end-coords :copy-worldcoords))
       (if (> (norm (send ec :difference-position calc-ec)) max-dif-pos)
	   (setq max-dif-pos (norm (send ec :difference-position calc-ec))))
       (if (> (norm (send ec :difference-rotation calc-ec)) max-dif-rot)
	   (setq max-dif-rot (norm (send ec :difference-rotation calc-ec))))

       (unless (or (null x::*display*) (= x::*display* 0))
         (send *irtviewer* :draw-objects :flush nil)
         (send ec :draw-on :flush nil :size 400)
         (send calc-ec :draw-on :flush nil :color #f(1 0 0))
         (send *irtviewer* :viewer :flush))
       ))
    (list max-dif-pos max-dif-rot)))

(defun test-zero-orientation-of-joint-class-common
  (joint-class)
  "Check zero setting for orientation of 6dof-joint and sphere-joint.
   If zero vector is set as :joint-angle :relative t, worldrot should not change."
  ;; Initialize
  (setq *robot* (instance sample-multidof-joint-robot :init :joint-class joint-class
                          :child-init-coords (make-coords :pos #f(100 200 300) :rpy (list (deg2rad 10) (deg2rad 20) (deg2rad 30)))))
  (unless (or (null x::*display*) (= x::*display* 0))
    (objects (list *robot*)))
  (if (= (length (send *robot* :angle-vector)) 3)
      (send *robot* :angle-vector #f(15.1 -25.2 35.3))
    (send *robot* :angle-vector #f(20.0 -30.0 40.0 15.1 -25.2 35.3)))
  (let ((rot1) (rot2))
    ;; Rot before :joint-angle :relative t setting
    (setq rot1 (copy-object (send (send (car (send *robot* :joint-list)) :child-link) :worldrot)))
    (send (car (send *robot* :joint-list)) :joint-angle (if (= (length (send *robot* :angle-vector)) 3)
                                                            (float-vector 0 0 0)
                                                          (float-vector 0 0 0 0 0 0))
          :relative t)
    ;; Rot after :joint-angle :relative t setting
    (setq rot2 (copy-object (send (send (car (send *robot* :joint-list)) :child-link) :worldrot)))
    ;;(print (array-entity (m- rot1 rot2)))
    ;; rot1 and rot2 should be same, otherwise it is numerical error.
    (eps= (norm (array-entity (m- rot1 rot2))) 0.0 1e-20)
    ))

;; test :cog-convergence-check
(defun test-cog-convergence-check-common
  (robot)
  (send robot :reset-pose)
  (send robot :fix-leg-to-coords (make-coords))
  (and (send robot :move-centroid-on-foot :both '(:rleg :lleg) :centroid-thre 10)
       (send robot :move-centroid-on-foot :both '(:rleg :lleg) :centroid-thre #'(lambda (diff) (> 10 (norm diff))))
       (send robot :move-centroid-on-foot :both '(:rleg :lleg) :centroid-thre #f(10 10)))
  )

;; test ik fail log
(defun test-load-ik-fail-log-common
  (robot ik-function)
  (labels ((find-log-files
            (log-directory)
            (remove-if-not #'(lambda (x) (substringp (format nil "~A-" (send (class robot) :name)) x)) (directory log-directory))))
    (let* ((log-directory (format nil "/tmp/irtmodel-ik-~A" (unix::getpid)))
           (prev-log-files))
      (unix:system (format nil "rm -f ~A/*" log-directory)) ;; clear log file
      (setq prev-log-files (find-log-files log-directory))
      (funcall ik-function robot)
      (let ((new-log-file ;; find latest log
             (car (remove-if #'(lambda (x) (member x prev-log-files :test #'string=)) (find-log-files log-directory)))))
        ;; ik log execution
        (progn (load (format nil "~A/~A" log-directory new-log-file))(ik-setup)(null-output (ik-check)))
        (unix:system (format nil "rm -f ~A/*" log-directory)) ;; clear log file
        t))))

(defun test-load-ik-fail-log-rarm-ik-common
  (robot)
  (test-load-ik-fail-log-common
   robot
   #'(lambda (robot)
       (send robot :newcoords (make-coords))
       (send robot :rarm :move-end-pos #f(10000 0 0) :world :debug-view :no-message)))
  )

(defun test-load-ik-fail-log-dual-arm-ik-common
  (robot)
  (test-load-ik-fail-log-common
   robot
   #'(lambda (robot)
       (unless (or (null x::*display*) (= x::*display* 0))
         (objects (list robot)))
       (send robot :newcoords (make-coords))
       (send robot :inverse-kinematics
             (mapcar #'(lambda (x) (send (send robot x :end-coords :copy-worldcoords) :translate #f(10000 0 0) :world)) '(:rarm :larm))
             :move-target (mapcar #'(lambda (x) (send robot x :end-coords)) '(:rarm :larm))
             :link-list (mapcar #'(lambda (x) (send robot :link-list (send robot x :end-coords :parent))) '(:rarm :larm))
             :debug-view :no-message)))
  )

(defun test-load-ik-fail-log-assoc-ik-common
  (robot)
  (test-load-ik-fail-log-common
   robot
   #'(lambda (robot)
       (send robot :newcoords (make-coords))
       (send robot :reset-pose)
       (let ((b (make-cylinder 10 250)))
         (send b :move-coords (send robot :larm :end-coords) (send b :worldcoords))
         (unless (or (null x::*display*) (= x::*display* 0))
           (objects (list robot b)))
         (let ((c (make-cascoords :pos (send b :transform-vector (float-vector 0 0 250)))))
           (send b :assoc c)
           (send (send robot :larm :end-coords :parent) :assoc b)
           (send robot :larm :move-end-pos #f(10000 0 0) :world :rotation-axis nil :move-target c :debug-view :no-message)
           (send (send robot :larm :end-coords :parent) :dissoc b)
           (send b :dissoc c)
           )))
   ))

(defun test-ik-fail-log-with-dump-command-args-common
  (robot)
  (let ((log-directory (format nil "/tmp/irtmodel-ik-~A" (unix::getpid))) (ret))
    (labels ((test-ik-with-log
              (target-pos dump-command)
              (unix:system (format nil "rm -f /tmp/irtmodel-ik-~A/*" (unix::getpid)))
              (send robot :reset-pose)
              (send robot :newcoords (make-coords))
              (send robot :rarm :move-end-pos target-pos :world :debug-view :no-message :stop 10 :dump-command dump-command)))
      ;; dump-command nil => no log files are generated.
      (test-ik-with-log #f(10 0 0) nil)
      (push (not (find-if #'(lambda (x) (substringp ".l" x)) (directory log-directory))) ret)
      (test-ik-with-log #f(10000 0 0) nil)
      (push (not (find-if #'(lambda (x) (substringp ".l" x)) (directory log-directory))) ret)
      ;; dump-command :fail-only => log files are generated only if ik fail.
      (test-ik-with-log #f(10 0 0) :fail-only)
      (push (not (find-if #'(lambda (x) (substringp ".l" x)) (directory log-directory))) ret)
      (test-ik-with-log #f(10000 0 0) :fail-only)
      (push (find-if #'(lambda (x) (substringp ".l" x)) (directory log-directory)) ret)
      ;; dump-command t => log files are generated always.
      (test-ik-with-log #f(10 0 0) t)
      (push (find-if #'(lambda (x) (substringp ".l" x)) (directory log-directory)) ret)
      (test-ik-with-log #f(10000 0 0) t)
      (push (find-if #'(lambda (x) (substringp ".l" x)) (directory log-directory)) ret)
      ;; return
      (unix:system (format nil "rm -f /tmp/irtmodel-ik-~A/*" (unix::getpid)))
      (reverse ret)
      )))

(defun test-load-ik-debug-information-log-common
  (dump-command &key (debug-view t))
  (labels ((find-log-files
            (log-directory robot)
            (remove-if-not #'(lambda (x) (substringp (format nil "~A-" (send (class robot) :name)) x)) (directory log-directory))))
    (let* ((robot (instance sample-legged-robot-with-interlocking-joints :init))
           (log-directory (format nil "/tmp/irtmodel-ik-~A" (unix::getpid)))
           (prev-log-files (find-log-files log-directory robot)))
      (unix:system (format nil "rm -f ~A/*" log-directory)) ;; clear log file
      ;; Initialize poses
      (send robot :rleg :angle-vector #f(0.0 0.0 -40.0 40.0 40.0 -40.0 0.0))
      (send robot :lleg :angle-vector #f(0.0 0.0 -40.0 40.0 40.0 -40.0 0.0))
      (send robot :fix-leg-to-coords (make-coords))
      ;; IK
      (send robot :move-centroid-on-foot :both '(:rleg :lleg) :dump-command dump-command :target-centroid-pos (float-vector 20 0 0))
      ;; Chceck log
      (let* ((new-log-files (remove-if #'(lambda (x) (member x prev-log-files :test #'string=)) (find-log-files log-directory robot)))
             (new-log-file ;; find latest log
              (car new-log-files))
             (ret t))
        ;; ik log load
        (when dump-command
          (mapcar #'(lambda (lf) (load (format nil "~A/~A" log-directory lf))) new-log-files)
          (when (eq dump-command :always-with-debug-log)
            (setq ret (and (numberp *ik-loop*)
                           (not (cdr (assoc :target-0 *ik-target-error*)))
                           (not (cdr (assoc :target-1 *ik-target-error*)))
                           (not (cdr (assoc :centroid *ik-target-error*)))
                           (not (cdr (assoc :additional-0 *ik-target-error*)))))
            ))
        (if debug-view (format t ";; files ~A~%" new-log-files))
        (prog1
            (case
             dump-command
             ((t :always)
              (and (not (find-if #'(lambda (x) (substringp "debug-log.l" x)) new-log-files))
                   (find-if #'(lambda (x) (substringp "success.l" x)) new-log-files)))
             (:always-with-debug-log
              (and ret
                   (find-if #'(lambda (x) (substringp "debug-log.l" x)) new-log-files)
                   (find-if #'(lambda (x) (substringp "success.l" x)) new-log-files)))
             (nil
              (= (length new-log-files) 0))))
        (unix:system (format nil "rm -f ~A/*" log-directory)) ;; clear log file
        t))))

;; check torque calculation comparing methods to calculate ext-force and ext-moment and robot root-link configuration
(defun draw-objects-torque
  (robot tq)
  (when (not (or (null x::*display*) (= x::*display* 0)))
    (send *irtviewer* :draw-objects :flush nil)
    (send (send (car (send robot :links)) :worldcoords) :draw-on :flush nil :color #f(0 1 1))
    (send robot :draw-torque (send *irtviewer* :viewer) :torque-vector tq)
    (send *irtviewer* :viewer :viewsurface :flush))
  )

(defun test-calc-torque-from-motion-list
  (robot
   motion-list ;; robot state list
   target-coords ;; contact coords
   &key (static-p nil) (dt 0.005)
        (calc-torque-mode :tq-without-ext-wrench))
  (unless (or (null x::*display*) (= x::*display* 0))
    (objects (list robot)))
  (let* ((tq-list-without-ext-wrench
          (mapcar #'(lambda (rs)
                      (send robot :angle-vector (cadr (memq :angle-vector rs)))
                      (send robot :move-coords (cadr (memq :root-coords rs)) (send (car (send robot :links)) :copy-worldcoords))
                      (let* ((tq-without-ext-wrench (send robot :calc-torque :calc-statics-p static-p :dt dt))
                             (wr (send robot :calc-contact-wrenches-from-total-wrench
                                       (send-all target-coords :worldpos)
                                       :total-wrench (concatenate float-vector (send (car (send robot :links)) :force) (send (car (send robot :links)) :moment)))))
                        (if (eq calc-torque-mode :tq-without-ext-wrench)
                            (draw-objects-torque robot tq-without-ext-wrench))
                        (append
                         rs
                         (list :tq-without-ext-wrench tq-without-ext-wrench
                               :root-wrench (list (copy-object (send (car (send robot :links)) :force))
                                                  (v- (send (car (send robot :links)) :moment) (v* (scale 1e-3 (send (car (send robot :links)) :worldpos)) (send (car (send robot :links)) :force)))) ;; moment is around root-link
                               :target-coords-wrench wr)
                         )))
                  motion-list)))
    (case calc-torque-mode
      (:tq-without-ext-wrench tq-list-without-ext-wrench)
      (:tq-with-ext-wrench-1
       (mapcar #'(lambda (rs-tql)
                   (send robot :angle-vector (cadr (memq :angle-vector rs-tql)))
                   (send robot :move-coords (cadr (memq :root-coords rs-tql)) (send (car (send robot :links)) :copy-worldcoords))
                   (let* ((ret-tq
                           (v- (cadr (memq :tq-without-ext-wrench rs-tql))
                               (send robot :calc-torque-from-ext-wrenches ;; J^T f
                                     :force-list (car (cadr (memq :target-coords-wrench rs-tql))) :moment-list (cadr (cadr (memq :target-coords-wrench rs-tql)))
                                     :target-coords target-coords))))
                     (draw-objects-torque robot ret-tq)
                     (append rs-tql (list :tq-with-ext-wrench-1 ret-tq))))
               tq-list-without-ext-wrench))
      (:tq-with-ext-wrench-2
       (mapcar
        #'(lambda (rs-tql)
            (send robot :angle-vector (cadr (memq :angle-vector rs-tql)))
            (send robot :move-coords (cadr (memq :root-coords rs-tql)) (send (car (send robot :links)) :copy-worldcoords))
            (let* ((ret-tq
                    (send robot :calc-torque
                          :calc-statics-p static-p :dt dt
                          :force-list (car (cadr (memq :target-coords-wrench rs-tql)))
                          :moment-list (cadr (cadr (memq :target-coords-wrench rs-tql)))
                          :target-coords target-coords)))
              (draw-objects-torque robot ret-tq)
              (append rs-tql (list :tq-with-ext-wrench-2 ret-tq))
              ))
        tq-list-without-ext-wrench))
      )))

;;   functions to generate motion list for sample-multidof-arm-robot
(defun gen-motion-list-with-root-link-motion-for-sample-multidof-arm-robot
  (robot
   &key (max-idx 361) (fix-pos (float-vector 0 0 0)) (fix-rpy (list 0 0 0)) (fix-root))
  (let ((motion-list))
    (send robot :init-pose)
    (if fix-root (send robot :newcoords (make-coords :pos fix-pos :rpy fix-rpy)))
    (unless (or (null x::*display*) (= x::*display* 0))
      (objects (list robot)))
    (dotimes (i max-idx)
      (let ((ang (* 90 (sin (deg2rad i)))))
        (send-all (send robot :joint-list) :joint-angle ang)
        (unless fix-root
          (send robot :move-coords (make-coords :rpy fix-rpy :pos fix-pos)
                (send (send (send robot :rarm :end-coords) :copy-worldcoords) :rotate pi :y)))
        (push (list :angle-vector (send robot :angle-vector)
                    :root-coords (send (car (send robot :links)) :copy-worldcoords))
              motion-list)
        ))
    (reverse motion-list)))

(defun gen-motion-list-with-root-link-motion-for-sample-multidof-arm-robot2
  (robot
   &key (max-idx 361) (fix-pos (float-vector 0 0 0)) (fix-rpy (list 0 0 0)) (fix-root))
  (let ((motion-list))
    (send robot :init-pose)
    (if fix-root (send robot :newcoords (make-coords :pos fix-pos :rpy fix-rpy)))
    (unless (or (null x::*display*) (= x::*display* 0))
      (objects (list robot)))
    (dotimes (i max-idx)
      (let ((ang (* 45 (sin (deg2rad i)))))
        (send robot :angle-vector (list (- ang) (* 2 ang) (- ang)))
        (unless fix-root
          (send robot :move-coords
                (send (make-coords :rpy fix-rpy :pos fix-pos) :rotate pi :y)
                (send robot :rarm :end-coords)))
        (push (list :angle-vector (send robot :angle-vector)
                    :root-coords (send (car (send robot :links)) :copy-worldcoords))
              motion-list)
        ))
    (reverse motion-list)))

(defun gen-motion-list-with-root-link-motion-for-sample-multidof-arm-robot3
  (robot
   &key (max-idx 361) (fix-pos (float-vector 0 0 0)) (fix-rpy (list 0 0 0)) (fix-root))
  (let ((motion-list))
    (send robot :init-pose)
    (if fix-root (send robot :newcoords (make-coords :pos fix-pos :rpy fix-rpy)))
    (unless (or (null x::*display*) (= x::*display* 0))
      (objects (list robot)))
    (dotimes (i max-idx)
      (let ((ang (* 45 (sin (deg2rad i)))))
        (send-all (send robot :joint-list) :joint-angle ang)
        (unless fix-root
          (send robot :move-coords
                (send (make-coords :rpy fix-rpy :pos fix-pos) :rotate pi :y)
                (send robot :rarm :end-coords)))
        (push (list :angle-vector (send robot :angle-vector)
                    :root-coords (send (car (send robot :links)) :copy-worldcoords))
              motion-list)
        ))
    (reverse motion-list)))

;;   calc torque tests for sample-multidof-arm-robot
(defun test-calc-torque-wrench-for-sample-multidof-arm-robot
  (&key (static-p nil) (axis-order (list :z :y :x)) (max-idx 361)
        (fix-pos (float-vector 0 0 0)) (fix-rpy (list 0 0 0)) (dt 0.005)
        (calc-torque-mode :tq-without-ext-wrench)
        (gen-motion-list-func #'gen-motion-list-with-root-link-motion-for-sample-multidof-arm-robot))
  (let* ((tmp-sample-arm-robot (instance sample-multidof-arm-robot :init :axis-order axis-order))
         (motion-list
          (funcall gen-motion-list-func
                   tmp-sample-arm-robot :max-idx max-idx :fix-pos fix-pos :fix-rpy fix-rpy
                   :fix-root (if (eq calc-torque-mode :tq-without-ext-wrench) t nil))))
    (mapcar #'(lambda (x)
                (list :root-wrench
                      (if (eq calc-torque-mode :tq-without-ext-wrench)
                          (cadr (memq :root-wrench x))
                        (mapcar #'car (cadr (memq :target-coords-wrench x))))
                      :torque (cadr (memq calc-torque-mode x))))
            (test-calc-torque-from-motion-list
             tmp-sample-arm-robot motion-list (list (send tmp-sample-arm-robot :rarm :end-coords))
             :static-p static-p :dt dt :calc-torque-mode calc-torque-mode))))

;;   functions to generate motion list for sample-robot
(defun gen-motion-list-with-root-link-motion-for-sample-robot
  (robot &key (fix-pos (float-vector 0 0 0)) (fix-rpy (list 0 0 0)) (max-idx 181))
  (let ((motion-list))
    (send robot :reset-pose)
    (send robot :fix-leg-to-coords (make-coords :pos fix-pos :rpy fix-rpy))
    (unless (or (null x::*display*) (= x::*display* 0))
      (objects (list robot)))
    (dotimes (i max-idx)
      (let ((ang (sin (deg2rad (* 2 i)))))
        (send robot :move-centroid-on-foot
              :both '(:rleg :lleg)
              :target-centroid-pos (v+ fix-pos (scale 45 (float-vector ang ang 0))))
        ;;(send *irtviewer* :draw-objects)
        (push (list :angle-vector (send robot :angle-vector)
                    :root-coords (send (car (send robot :links)) :copy-worldcoords))
              motion-list)
        ))
    (reverse motion-list)))

;;   calc torque tests for sample-robot
(defun test-calc-torque-wrench-for-sample-robot
  (&key (static-p nil) (fix-pos (float-vector 0 0 0)) (fix-rpy (list 0 0 0)) (dt 0.005) (max-idx 181)
        (calc-torque-mode :tq-with-ext-wrench-1))
  (let ((motion-list
         (gen-motion-list-with-root-link-motion-for-sample-robot
          *sample-robot* :fix-pos fix-pos :fix-rpy fix-rpy :max-idx max-idx)))
    (mapcar #'(lambda (x)
                (list :torque (cadr (memq calc-torque-mode x))))
            (test-calc-torque-from-motion-list
             *sample-robot* motion-list (mapcar #'(lambda (l) (send *sample-robot* l :end-coords)) '(:rleg :lleg))
             :static-p static-p :dt dt :calc-torque-mode calc-torque-mode))))

;;  all calc torque test for sample-multidof-arm-robot
(defun test-all-for-sample-multidof-arm-robot
  (&key (static-p nil) (max-idx 50) (fix-pos (float-vector 0 0 0)) (fix-rpy (list 0 0 0))
        (dt 0.005)
        (org-axis (list :x :z :-y)))
  (let* ((reverse-axis
          (mapcar #'(lambda (x) (case x (:y :-y) (:-y :y) (t x))) (reverse org-axis)))
         (ret))
    (format t ";; test sample-multidof-arm-robot : static-p ~A, fix-pos ~A, fix-rpy ~A~%" static-p fix-pos fix-rpy)
    (dolist (gen-motion-list-func (list #'gen-motion-list-with-root-link-motion-for-sample-multidof-arm-robot
                                        #'gen-motion-list-with-root-link-motion-for-sample-multidof-arm-robot2
                                        #'gen-motion-list-with-root-link-motion-for-sample-multidof-arm-robot3))
      (let* ((ret-without-ext-wrench
              (test-calc-torque-wrench-for-sample-multidof-arm-robot
               :gen-motion-list-func gen-motion-list-func
               :static-p static-p :axis-order org-axis
               :max-idx max-idx :fix-pos fix-pos :fix-rpy fix-rpy :dt dt
               :calc-torque-mode :tq-without-ext-wrench))
             (ret-with-ext-wrench-1
              (test-calc-torque-wrench-for-sample-multidof-arm-robot
               :gen-motion-list-func gen-motion-list-func
               :static-p static-p :axis-order reverse-axis
               :max-idx max-idx :fix-pos fix-pos :fix-rpy fix-rpy :dt dt
               :calc-torque-mode :tq-with-ext-wrench-1))
             (ret-with-ext-wrench-2
              (test-calc-torque-wrench-for-sample-multidof-arm-robot
               :gen-motion-list-func gen-motion-list-func
               :static-p static-p :axis-order reverse-axis
               :max-idx max-idx :fix-pos fix-pos :fix-rpy fix-rpy :dt dt
               :calc-torque-mode :tq-with-ext-wrench-2)))
        (labels ((check-diff-with-axis-orders
                  (tq1 tq2)
                  (let ((ret))
                    (dotimes (i (length tq1))
                      (push (- (elt tq2 (- (length tq1) i 1)) (elt tq1 i)) ret))
                    ))
                 (check-diff-wrench
                  (wr1 wr2)
                  (list (distance (car wr1) (car wr2)) (distance (cadr wr1) (cadr wr2)))))
          (let ((check-results
                 (list
                  (every #'identity (mapcar #'(lambda (x y) (every #'(lambda (x) (eps= x 0.0)) (check-diff-with-axis-orders (cadr (memq :torque x)) (cadr (memq :torque y))))) ret-without-ext-wrench ret-with-ext-wrench-1))
                  (every #'identity (mapcar #'(lambda (x y) (every #'(lambda (x) (eps= x 0.0)) (check-diff-wrench (cadr (memq :root-wrench x)) (cadr (memq :root-wrench y))))) ret-without-ext-wrench ret-with-ext-wrench-1))
                  (every #'identity (mapcar #'(lambda (x y) (every #'(lambda (x) (eps= x 0.0)) (check-diff-with-axis-orders (cadr (memq :torque x)) (cadr (memq :torque y))))) ret-with-ext-wrench-1 ret-with-ext-wrench-2))
                  (every #'identity (mapcar #'(lambda (x y) (every #'(lambda (x) (eps= x 0.0)) (check-diff-wrench (cadr (memq :root-wrench x)) (cadr (memq :root-wrench y))))) ret-with-ext-wrench-1 ret-with-ext-wrench-2))
                  )))
            (format t ";; ~A~%" (cadr gen-motion-list-func))
            (format t ";;   tq (root fix, without ext wrench)         vs tq (root floating, with ext wrench 1)     -> ~A~%" (car check-results))
            (format t ";;   wrench (root fix, without ext wrench)     vs wrench (root floating, with ext wrench 1) -> ~A~%" (cadr check-results))
            (format t ";;   tq (root floating, with ext wrench 1)     vs tq (root floating, with ext wrench 2)     -> ~A~%" (caddr check-results))
            (format t ";;   wrench (root floating, with ext wrench 1) vs wrench (root floating, with ext wrench 2) -> ~A~%" (cadddr check-results))
            (push (every #'identity check-results) ret)))))
    (every #'identity ret)))

;;  all calc torque test for sample-robot
(defun test-all-for-sample-robot
  (&key (static-p nil) (max-idx 50) (fix-pos (float-vector 0 0 0))
        (dt 0.005))
  (let* ((ret-with-ext-wrench-1
          (test-calc-torque-wrench-for-sample-robot
           :static-p static-p :max-idx max-idx :fix-pos fix-pos :dt dt
           :calc-torque-mode :tq-with-ext-wrench-1))
         (ret-with-ext-wrench-2
          (test-calc-torque-wrench-for-sample-robot
           :static-p static-p :max-idx max-idx :fix-pos fix-pos :dt dt
           :calc-torque-mode :tq-with-ext-wrench-1)))
    (labels ((check-diff-with-axis-orders
              (tq1 tq2)
              (let ((ret))
                (dotimes (i (length tq1))
                  (push (- (elt tq2 (- (length tq1) i 1)) (elt tq1 i)) ret))
                ))
             (check-diff-wrench
              (wr1 wr2)
              (list (distance (car wr1) (car wr2)) (distance (cadr wr1) (cadr wr2)))))
      ;; check
      (let ((check-results
             (list
              (every #'identity (mapcar #'(lambda (x y) (every #'(lambda (x) (eps= x 0.0)) (check-diff-with-axis-orders (cadr (memq :torque x)) (cadr (memq :torque y))))) ret-with-ext-wrench-1 ret-with-ext-wrench-2))
              )))
        (format t ";;   tq (root floating, with ext wrench 1)     vs tq (root floating, with ext wrench 2)     -> ~A~%" (car check-results))
        (every #'identity check-results)
        ))))

;; test for collision check
(defun test-self-collision-check-IK
  ()
  (defmethod sample-robot
    (:collision-check-pairs
     (&key ((:links ls) (list (car (send self :links))
                              (elt (send self :rarm :links) 2)
                              (elt (send self :rarm :links) 3))))
     (send-super :collision-check-pairs :links ls)))
  (labels ((test-ik
            (check-collision)
            (send *sample-robot* :reset-pose)
            (send *sample-robot* :fix-leg-to-coords (make-coords))
            (send *sample-robot* :rarm :move-end-pos #f(50 300 0) :world :rotation-axis nil :check-collision check-collision :warnp nil)))
    (prog1
        (and (test-ik nil) (not (test-ik t)))
      (defmethod sample-robot
        (:collision-check-pairs
         (&key ((:links ls) (cons (car links) (all-child-links (car links)))))
         (send-super :collision-check-pairs :links ls)))
      )
    ))

;; test for fullbody look at
(defun fullbody-ik-with-look-at (robot &key (debug-view :no-message))
  (let (result av)
    ;; (send robot :reset-pose) ;; fixed robot has more joint on neck
    (setq av (send robot :angle-vector))
    (replace av #f(0.0 0.0 0.0 0.0 10.0 20.0 0.0 -20.0 10.0 0.0 0.0 10.0 20.0 0.0 -20.0 10.0 0.0 0.0 0.0 0.0 -15.0 30.0 -15.0 0.0 0.0 0.0 -15.0 30.0 -15.0 0.0))
    (send robot :angle-vector av)
    ;;
    (send robot :legs :move-end-pos (float-vector 0 0 50))
    (send robot :fix-leg-to-coords (make-coords))
    ;(send robot :head :neck-y :joint-angle 180)
    (send robot :update-descendants) ;; update all bodies
    (objects (list robot))
    (setq result
          (send robot :fullbody-inverse-kinematics
                (list (make-coords :pos #f(0 -300 600))
                      (make-coords :pos #f(0 300 600))
                      (send robot :rleg :end-coords :copy-worldcoords)
                      (send robot :lleg :end-coords :copy-worldcoords))
                :move-target (mapcar #'(lambda (x)
                                         (send robot x :end-coords))
                                     (list :rarm :larm :rleg :lleg))
                :link-list (mapcar #'(lambda (x)
                                       (send robot :link-list (send robot x :end-coords :parent)))
                                   (list :rarm :larm :rleg :lleg))
                :rotation-axis (list nil nil t t)
                :look-at-target t
                :debug-view debug-view))
    result))

;; test for static balance point
(defun fullbody-ik-with-forces (robot &key (debug-view :no-message))
  (send robot :newcoords (make-coords))
  (send robot :reset-pose)
  (send robot :fix-leg-to-coords (make-coords))
  (send robot :legs :move-end-pos (float-vector 0 0 50))
  (send robot :fix-leg-to-coords (make-coords))
  (objects (list robot))
  (let* ((centroid-thre 10)
         (result
          (send robot :fullbody-inverse-kinematics
                (list (send robot :rleg :end-coords :copy-worldcoords)
                      (send robot :lleg :end-coords :copy-worldcoords)
                      (make-coords :pos #f(150 -300 600))
                      (make-coords :pos #f(150 300 600)))
                :move-target (mapcar #'(lambda (x)
                                         (send robot x :end-coords))
                                     (list :rleg :lleg :rarm :larm))
                :link-list (mapcar #'(lambda (x)
                                       (send robot :link-list (send robot x :end-coords :parent)))
                                   (list :rleg :lleg :rarm :larm))
                :centroid-thre centroid-thre
                :centroid-offset-func #'(lambda () (send robot :calc-static-balance-point :force-list (list #f(10 20 0) #f(25 20 0))))
                :debug-view debug-view)))
    (and result
         (> centroid-thre (distance (apply #'midpoint 0.5 (send robot :legs :end-coords :worldpos))
                                    (send robot :calc-static-balance-point :force-list (list #f(10 20 0) #f(25 20 0))))))
    ))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; unit tests
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(deftest test-irtdyna-samplerobot
  (assert (test-zmp-comomn *sample-robot*))
  (assert (test-torque-from-its-own-weight-common *sample-robot*))
  (assert (test-torque-from-ext-force-common *sample-robot*)))

(deftest test-cog-convergence-check
  (assert (test-cog-convergence-check-common *sample-robot*)))

(deftest test-joint-for-mobile-robot
  (assert
   (test-joint-for-mobile-robot-common
    :robot-class sample-mobile-robot :wheel-class omniwheel-joint))
  (assert
   (test-joint-for-mobile-robot-common
    :robot-class sarmclass :wheel-class omniwheel-joint
    :translation-axis :z))
  (assert
   (test-joint-for-mobile-robot-common
    :robot-class sarmclass :wheel-class omniwheel-joint
    :use-wholebody t)))

(deftest test-orientation-of-joint-class
  (assert
   (let ((ret (test-orientation-of-joint-class-common sphere-joint)))
     (and
      (> 0.01 (elt ret 0))
      (> (deg2rad 1e-2) (elt ret 1)))))
  (assert
   (let ((ret (test-orientation-of-joint-class-common 6dof-joint)))
     (and
      (> 0.05 (elt ret 0))
      (> (deg2rad 1e-2) (elt ret 1))))))

(deftest test-zero-orientation-of-joint-class
  (assert
   (test-zero-orientation-of-joint-class-common sphere-joint))
  (assert
   (test-zero-orientation-of-joint-class-common 6dof-joint)))

(deftest test-load-ik-fail-log-rarm-ik-for-sample-robot
  (assert (test-load-ik-fail-log-rarm-ik-common *sample-robot*)))

(deftest test-load-ik-fail-log-rarm-ik-for-sample-multidof-joint-robot
  (assert (test-load-ik-fail-log-rarm-ik-common *sarm-robot*)))

(deftest test-load-ik-fail-log-assoc-ik-for-sample-robot
  (assert (test-load-ik-fail-log-assoc-ik-common *sample-robot*)))

(deftest test-load-ik-fail-log-dual-arm-ik-for-sample-robot
  (assert (test-load-ik-fail-log-dual-arm-ik-common *sample-robot*)))

(deftest test-ik-fail-log-with-dump-command-args-for-sample-robot
  (assert (every #'identity (test-ik-fail-log-with-dump-command-args-common *sample-robot*))))

(deftest test-load-ik-debug-information-log
  (assert (every #'identity
                 (mapcar #'(lambda (dc) (test-load-ik-debug-information-log-common dc)) '(t :always :always-with-debug-log nil)))))

(deftest test-all-for-arm-robot-static-1
  (assert
   (test-all-for-sample-multidof-arm-robot :static-p t :fix-pos #f(0 0 0))))
(deftest test-all-for-sample-multidof-arm-robot-static-2
  (assert
   (test-all-for-sample-multidof-arm-robot :static-p t :fix-pos #f(100 200 300) :fix-rpy (list (deg2rad 10) (deg2rad 30) (deg2rad 60)))))
(deftest test-all-for-sample-robot-static-1
  (assert
   (test-all-for-sample-robot :static-p t :fix-pos #f(0 0 0))))
(deftest test-all-for-sample-robot-static-2
  (assert
   (test-all-for-sample-robot :static-p t :fix-pos #f(100 200 300))))

(deftest test-self-collision-check-IK-test
  (assert
   (test-self-collision-check-IK)))

(deftest test-fullbody-ik-with-forces-samplerobot
  (assert
   (fullbody-ik-with-forces *sample-robot*)))

(deftest test-fullbody-ik-draw-param-check-samplerobot
  (dotimes (i 5) (send *sample-robot* :move-centroid-on-foot :both '(:rleg :lleg)))
  (assert
   (not (> (length (send *sample-robot* :get :ik-draw-on-params)) 0))))

(deftest test-fullbody-ik-with-look-at
  (let (robot l1 l2 l3 j1 j2 j3)
    ;; normal test
    (setq robot (instance sample-robot :init))
    (assert
     (fullbody-ik-with-look-at robot))
    ;; change robot
    ;; extend head link head :end-coords is assoced to not the leaf of the link treee
    (setq l1 (instance bodyset-link :init (make-cascoords) :bodies (list (make-cube 3 10 10))))
    (setq l2 (instance bodyset-link :init (make-cascoords) :bodies (list (make-cube 3 10 10))))
    (setq l3 (instance bodyset-link :init (make-cascoords) :bodies (list (make-cube 3 80 10))))
    (send l1 :locate (send (send robot :head :end-coords) :transform-vector #f(-20 0 -5)) :world)
    (send l2 :locate (send l1 :transform-vector #f(5 0 0)) :world)
    (send l3 :locate (send l2 :transform-vector #f(5 0 0)) :world)
    (send l1 :assoc l2)
    (send l2 :assoc l3)
    (send (send robot :head :end-coords :parent) :assoc l1)
    (setq (robot . links) (append (robot . links) (list l1 l2 l3)))
    (setq (robot . head) (append (robot . head) (list l1 l2 l3)))
    (setq j1 (instance rotational-joint :init :name :j1 :parent-link (send robot :head :end-coords :parent) :child-link l1 :axis :z :min -100 :max 100))
    (setq j2 (instance rotational-joint :init :name :j2 :parent-link l1 :child-link l2 :axis :x :min -100 :max 100))
    (setq j3 (instance rotational-joint :init :name :j3 :parent-link l2 :child-link l3 :axis :y :min -100 :max 100))
    (setq (robot . joint-list) (append (robot . joint-list) (list j1 j2 j3)))
    (send robot :init-ending)
    (send (send robot :head :end-coords :parent) :dissoc (send robot :head :end-coords))
    ;;(send l2 :assoc (send robot :head :end-coords))
    (send (send robot :head :root-link) :assoc (send robot :head :end-coords))
    (send robot :head :neck-y :min-angle  -45)
    (send robot :head :neck-y :max-angle   45)
    (send robot :head :neck-p :min-angle -135)
    (send robot :head :neck-p :max-angle -175)
    (assert
     (fullbody-ik-with-look-at robot :debug-view nil))
    ))


;; Test calling calc-walk-pattern-from-footstep-list N times
;;   This test is for bug reported in https://github.com/euslisp/jskeus/issues/286.
(deftest test-samplerobot-walk-pattern-Ntimes
  (let ((av-list) (cog0) (cog1) (cog2))
    ;; case 0 : side step with initialize and with :init-pose-function
    (send *sample-robot* :reset-pose)
    (send *sample-robot* :fix-leg-to-coords (make-coords))
    (setq av-list (send *sample-robot* :calc-walk-pattern-from-footstep-list
                        (list (make-coords :coords (send *sample-robot* :rleg :end-coords :copy-worldcoords) :name :rleg)
                              (make-coords :coords (send (send *sample-robot* :lleg :end-coords :copy-worldcoords) :translate (float-vector 0 100 0)) :name :lleg)
                              (make-coords :coords (send (send *sample-robot* :rleg :end-coords :copy-worldcoords) :translate (float-vector 0 100 0)) :name :rleg))))
    (setq cog0 (cadr (memq :cog (car av-list))))
    ;; case 1 : side step with initialize but without :init-pose-function
    (send *sample-robot* :reset-pose)
    (send *sample-robot* :fix-leg-to-coords (make-coords))
    (setq av-list (send *sample-robot* :calc-walk-pattern-from-footstep-list
                        (list (make-coords :coords (send *sample-robot* :rleg :end-coords :copy-worldcoords) :name :rleg)
                              (make-coords :coords (send (send *sample-robot* :lleg :end-coords :copy-worldcoords) :translate (float-vector 0 100 0)) :name :lleg)
                              (make-coords :coords (send (send *sample-robot* :rleg :end-coords :copy-worldcoords) :translate (float-vector 0 100 0)) :name :rleg))
                        :init-pose-function #'(lambda ())))
    (setq cog1 (cadr (memq :cog (car av-list))))
    ;; case 2 : side step without initialize and with :init-pose-function
    (setq av-list (send *sample-robot* :calc-walk-pattern-from-footstep-list
                        (list (make-coords :coords (send *sample-robot* :rleg :end-coords :copy-worldcoords) :name :rleg)
                              (make-coords :coords (send (send *sample-robot* :lleg :end-coords :copy-worldcoords) :translate (float-vector 0 100 0)) :name :lleg)
                              (make-coords :coords (send (send *sample-robot* :rleg :end-coords :copy-worldcoords) :translate (float-vector 0 100 0)) :name :rleg))))
    (setq cog2 (cadr (memq :cog (car av-list))))
    (assert (eps= (elt cog0 1) (elt cog1 1) 1.5) (format nil "cog: ~A ~A" cog0 cog1))
    (assert (eps= (elt cog0 1) (- (elt cog2 1) 100) 1.5) (format nil "cog: ~A ~A" cog0 cog2))
    ))

(deftest test-samplerobot-static-balance-point
  (let* ((tmp-robot (instance sample-robot :init))
         (sbp1 (send tmp-robot :calc-static-balance-point))
         (sbp2 (send tmp-robot :calc-static-balance-point)))
    (assert (every #'null (mapcar #'(lambda (x) (and (> x 0) (< x 0))) (concatenate cons sbp1))) "Check nan of sbp1")
    (assert (every #'null (mapcar #'(lambda (x) (and (> x 0) (< x 0))) (concatenate cons sbp2))) "Check nan of sbp2")
    (assert (eps-v= sbp1 sbp2) "Check equality of sbp1 and sbp2")
    ))

(deftest test-calc-grasp-matrix
  (let* ((size (1+ (random 10)))
         (contact-points (mapcar #'(lambda (x) (random-vector)) (make-list size)))
         (contact-rots (mapcar #'(lambda (x) (rpy-matrix (deg2rad (- (random 180.0) 90.0)) (deg2rad (- (random 180.0) 90.0)) (deg2rad (- (random 180.0) 90.0))))
                               (make-list size)))
         (world-force-list (mapcar #'(lambda (x) (random-vector)) (make-list size)))
         (world-moment-list (mapcar #'(lambda (x) (random-vector)) (make-list size)))
         (local-force-list (mapcar #'(lambda (f r) (transform (transpose r) f)) world-force-list contact-rots))
         (local-moment-list (mapcar #'(lambda (n r) (transform (transpose r) n)) world-moment-list contact-rots)))
    (warn ";; test-grasp-matrix size = ~A~%" size)
    (let ((ret1
           ;; Direct calculation
           (concatenate float-vector
                        (reduce #'v+ world-force-list :initial-value (float-vector 0 0 0))
                        (v+
                         (reduce #'v+ (mapcar #'(lambda (p f) (v* (scale 1e-3 p) f)) contact-points world-force-list)
                                 :initial-value (float-vector 0 0 0))
                         (reduce #'v+ world-moment-list :initial-value (float-vector 0 0 0)))))
          (ret2
           ;; World grasp matrix
           (transform
            (send *sample-robot* :calc-grasp-matrix contact-points)
            (apply
             #'concatenate
             float-vector
             (flatten
              (mapcar #'(lambda (f m) (list f m)) world-force-list world-moment-list)))))
          (ret3
           ;; Local grasp matrix
           (transform
            (send *sample-robot* :calc-grasp-matrix contact-points :contact-rots contact-rots)
            (apply
             #'concatenate
             float-vector
             (flatten
              (mapcar #'(lambda (f m) (list f m)) local-force-list local-moment-list))))))
      (and (eps-v= ret1 ret2) (eps-v= ret1 ret3))
      )))

(deftest test-torque-with-root-joint
  (let* ((torque-without-root-joint (send *sample-robot* :calc-torque :calc-statics-p t))
         (torque-with-root-joint
          (with-append-root-joint
           (link-list-with-robot-6dof *sample-robot* (list (cdr (send *sample-robot* :links)))
                                      :joint-class 6dof-joint)
           (send *sample-robot* :calc-torque :calc-statics-p t)
           )))
    (assert (eps-v= torque-without-root-joint torque-with-root-joint))
    ))

;; Test for with-append-root-joint
(deftest test-with-append-root-joint
  (let* ((mt (send *sample-robot* :rarm :end-coords))
         (ll (send *sample-robot* :link-list (send mt :parent))))
    (with-append-root-joint
     (link-list-with-robot-6dof *sample-robot* ll :joint-class 6dof-joint)
     (assert
      (equal
       (append (list (car (send *sample-robot* :links))) ll)
       (car link-list-with-robot-6dof))
      "Test single link-list without root-link")))
  (let* ((mt (list (send *sample-robot* :rarm :end-coords) (send *sample-robot* :lleg :end-coords)))
         (ll (mapcar #'(lambda (tmt) (send *sample-robot* :link-list (send tmt :parent))) mt)))
    (with-append-root-joint
     (link-list-with-robot-6dof *sample-robot* ll :joint-class 6dof-joint)
     (assert
      (equal
       (mapcar #'(lambda (l) (append (list (car (send *sample-robot* :links))) l)) ll)
       link-list-with-robot-6dof)
      "Test multiple link-list without root-link")))
  (let* ((root-move-target
          (make-cascoords :coords (send (car (send *sample-robot* :links)) :copy-worldcoords)
                          :parent (car (send *sample-robot* :links))))
         (mt (list root-move-target (send *sample-robot* :larm :end-coords) (send *sample-robot* :rleg :end-coords)))
         (ll (mapcar #'(lambda (c) (send *sample-robot* :link-list (send c :parent))) mt)))
    (with-append-root-joint
     (link-list-with-robot-6dof *sample-robot* ll :joint-class 6dof-joint)
     (let ((ret
            (equal
             (mapcar #'(lambda (l) (append (list (car (send *sample-robot* :links))) l)) ll)
             link-list-with-robot-6dof)))
       (send (send root-move-target :parent) :dissoc root-move-target)
       (assert ret "Test multiple link-list with root-link"))))
  (send *sample-robot* :reset-pose)
  (send *sample-robot* :newcoords (make-coords))
  (let* ((root-move-target
          (make-cascoords :coords (send (car (send *sample-robot* :links)) :copy-worldcoords)
                          :parent (car (send *sample-robot* :links))))
         (mt (list root-move-target (send *sample-robot* :lleg :end-coords) (send *sample-robot* :rleg :end-coords)))
         (ll (mapcar #'(lambda (c) (send *sample-robot* :link-list (send c :parent))) mt)))
    (let ((ret (send *sample-robot* :fullbody-inverse-kinematics
                     (send-all mt :copy-worldcoords)
                     :translation-axis (list :xy t t) ;; root-link XY positions are used for COG jacobian
                     :move-target mt :link-list ll)))
      (send (send root-move-target :parent) :dissoc root-move-target)
      (assert ret "Test multiple link-list with root-link and IK"))))

;; test to check https://github.com/euslisp/jskeus/issues/459 issue
(deftest test-sample-robot-collision-avoidance-link-pair-from-link-list
  (send *sample-robot* :collision-avoidance-link-pair-from-link-list
        (send *sample-robot* :link-list
              (send (send *sample-robot* :rarm :end-coords) :parent)
              (send (send *sample-robot* :rarm :wrist-y) :child-link)))
  (send *sample-robot* :collision-avoidance-link-pair-from-link-list
        (send *sample-robot* :link-list
              (send (send *sample-robot* :rarm :end-coords) :parent)
              (send (send *sample-robot* :rarm :elbow-p) :child-link)))
  (assert t)
  )

;; Check :cog-translation-axis dimension bug
(deftest test-cog-translation-axis-dim
  (unwind-protect
      (progn
        ;; Method overwrite to get method argument for checking
        (unless (assoc :inverse-kinematics-loop-org (send cascaded-link :methods))
          (rplaca (assoc :inverse-kinematics-loop (send cascaded-link :methods)) :inverse-kinematics-loop-org))
        (defmethod cascaded-link
          (:inverse-kinematics-loop
           (dif-pos dif-rot &rest args &key ik-args &allow-other-keys)
           (send self :put :tmp-ik-args ik-args) ;; Store ik-args just for this testing.
           (send* self :inverse-kinematics-loop-org dif-pos dif-rot :ik-args ik-args args)))
        ;; Testing
        (mapcar #'(lambda (caxis caxis-dim)
                    (assert
                     (let ((ik-ret)
                           (ik-target-axis-dim (send *sample-robot* :calc-target-axis-dimension (list t t) (list t t)))) ;; rotation-axis (list t t) and translation-axis (list t t) => dim = 12
                       ;; Call :fullbody-inverse-kinematics
                       (send *sample-robot* :reset-pose)
                       (send *sample-robot* :newcoords (make-coords))
                       (setq ik-ret
                             (send *sample-robot* :fullbody-inverse-kinematics
                                   (list (send *sample-robot* :rleg :end-coords :copy-worldcoords) (send *sample-robot* :lleg :end-coords :copy-worldcoords))
                                   :move-target (list (send *sample-robot* :rleg :end-coords) (send *sample-robot* :lleg :end-coords))
                                   :link-list (mapcar #'(lambda (x) (send *sample-robot* :link-list (send x :parent))) (list (send *sample-robot* :rleg :end-coords) (send *sample-robot* :lleg :end-coords)))
                                   :target-centroid-pos (send *sample-robot* :centroid)
                                   :cog-translation-axis caxis))
                       (and ik-ret
                            (= (cadr (memq :dim (send *sample-robot* :get :tmp-ik-args)))
                               (+ ik-target-axis-dim caxis-dim)
                               )))
                     (format nil ";; Check COG axis dim (:cog-translation-axis = ~A should be dim = ~A)" caxis caxis-dim)))
                (list t :z :xz nil) ;; :cog-translation-axis
                (list 3 2 1 0) ;; Desired axis dimension
                ))
    ;; Revert method overwrite
    (defmethod cascaded-link
      (:inverse-kinematics-loop
       (dif-pos dif-rot &rest args &key ik-args &allow-other-keys)
       (send* self :inverse-kinematics-loop-org dif-pos dif-rot :ik-args ik-args args)))
    ))

(run-all-tests)
(exit 0)
