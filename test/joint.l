;; test code for joint
;; setup sample robot

(require :unittest "lib/llib/unittest.l")
(init-unit-test)

(defclass 2dof-robot
  :super robot-model
  :slots (end-coords l1 l2 l3 j1 j2))
(defmethod 2dof-robot
  (:init ()
         (send-super :init)
         (setq l3 (send self :make-link (make-cube 40 40 80) #f(0 0 40) :red 'l3))
         (setq end-coords (make-cascoords :pos #f(0 0 80)))
         (send l3 :assoc end-coords)
         (send l3 :locate #f(0 0 10))
         ;;
         (setq l2 (send self :make-link (make-cube 60 60 10) #f(0 0 5) :blue 'l2))
         (send l2 :assoc l3)
         (send l2 :locate #f(0 0 80))
         ;;
         (setq l1 (send self :make-link (body+ (make-cube 30 20 80 :pos #f(0 0 40))
                                               (make-cube 300 300 2)) #f(0 0 0) :white 'l1))
         (send l1 :assoc l2)
         (setq j1 (instance rotational-joint :init :parent-link l1 :child-link l2 :axis :z
                            :min -90.0 :max 90.0)
               j2 (instance rotational-joint :init :parent-link l2 :child-link l3 :axis :y
                            :min -60.0 :max 60.0))
         ;;
         (setq links (list l1 l2 l3) joint-list (list j1 j2))
     (send self :init-ending)
     self)
  (:make-link (b off color name)
     (send b :locate off) (send b :set-color color)
     (instance bodyset-link :init (make-cascoords) :bodies (list b) :name name))
  ;;
  (:j1 (&rest args) (forward-message-to j1 args))
  (:j2 (&rest args) (forward-message-to j2 args))
  (:end-coords (&rest args) (forward-message-to end-coords args))
  )

(setq *robot* (instance 2dof-robot :init))
(objects (list *robot*))

;; min-max
(deftest test-min-max
  (let ((j1 (send *robot* :j1))
        (j2 (send *robot* :j2)))
    (do ((x (send j1 :min-angle) (+ x 10)))
        ((> x (send j1 :max-angle)))
      (do ((y (send j2 :min-angle) (+ y 10)))
          ((> y (send j2 :max-angle)))
        (send *robot* :angle-vector (float-vector x y))
        (assert (= (send j1 :joint-angle) x) (format nil "check joint value for ~A match (= ~A ~A)" (send j1 :name) (send j1 :joint-angle) x))
        (assert (= (send j2 :joint-angle) y) (format nil "check joint value for ~A match (= ~A ~A)" (send j2 :name) (send j2 :joint-angle) y))
        (send *irtviewer* :draw-objects)
        ))
    ))

(deftest test-min-max-exceed
  (let ((j1 (send *robot* :j1))
        (j2 (send *robot* :j2))
        x y)
    ;;
    (dotimes (i 100)
      (setq x (+ (random (- (send j1 :max-angle) (send j1 :min-angle))) (send j1 :min-angle))
            y (+ (random (- (send j2 :max-angle) (send j2 :min-angle))) (send j2 :min-angle)))

      (if (= (random 2) 1)
          (incf x (+ (random x)))
        (incf y (+ (random y))))
      ;;
      (send *robot* :angle-vector (float-vector x y))
      (setq x (send j1 :joint-angle)
            y (send j2 :joint-angle))
      ;;
      (cond ((< x (send j1 :min-angle)) ;; x is too small
             (assert (= (send j1 :min-angle) x) (format nil "check joint value for ~A match (= ~A ~A) (joint-angle:~A min-angle:~A)" (send j1 :name) (send j1 :min-angle) x (send j1 :joint-angle) (send j1 :min-angle))))
            ((> x (send j1 :max-angle)) ;; x is too big
             (assert (= (send j1 :max-angle) x) (format nil "check joint value for ~A match (= ~A ~A) (joint-angle:~A max-angle:~A)" (send j1 :name) (send j1 :max-angle) x (send j1 :joint-angle) (send j1 :max-angle))))
            (t
             (assert (= (send j1 :joint-angle) x) (format nil "check joint value for ~A match (= ~A ~A)" (send j1 :name) (send j1 :joint-angle) x))))

      (cond ((< y (send j2 :min-angle)) ;; y is too small
             (assert (= (send j2 :min-angle) y) (format nil "check joint value for ~A match (= ~A ~A) (joint-angle:~A min-angle:~A)" (send j2 :name) (send j2 :min-angle) y (send j2 :joint-angle) (send j2 :min-angle))))
            ((> y (send j2 :max-angle)) ;; y is too big
             (assert (= (send j2 :max-angle) y) (format nil "check joint value for ~A match (= ~A ~A) (joint-angle:~A max-angle:~A)" (send j2 :name) (send j2 :max-angle) y (send j2 :joint-angle) (send j2 :max-angle))))
            (t
             (assert (= (send j2 :joint-angle) y) (format nil "check joint value for ~A match (= ~A ~A)" (send j2 :name) (send j2 :joint-angle) y))))
      ;;
      (send *irtviewer* :draw-objects)
      )
    ))

;; min-max-table
(deftest test-min-max-table
  (let* ((j1 (send *robot* :j1))
         (j2 (send *robot* :j2))
         (j1-min-max-table (make-matrix 3 (round (+ 1 (- (send j2 :max-angle) (send j2 :min-angle))))))
         (j2-min-max-table (make-matrix 3 (round (+ 1 (- (send j1 :max-angle) (send j1 :min-angle))))))
         (j1-org-min-angle (send j1 :min-angle)) (j2-org-min-angle (send j2 :min-angle))
         (j1-org-max-angle (send j1 :max-angle)) (j2-org-max-angle (send j2 :max-angle))
         min-max-table-view
         x y)

    ;; set min-max-table
    ;; j1-hash
    (mapcar #'(lambda (self-joint target-joint j-min-max-table)
                (do ((i (round (send target-joint :min-angle)) (+ i 1))) ((> i (round (send target-joint :max-angle))))
                    (setf (aref j-min-max-table 0 (round (- i (send target-joint :min-angle)))) i)
                    (setf (aref j-min-max-table 1 (round (- i (send target-joint :min-angle))))
                          (- (+ (min (* (/ (send self-joint :max-angle) (send target-joint :max-angle)) i)
                                     (* -1 (/ (send self-joint :max-angle) (send target-joint :max-angle)) i))
                                (send self-joint :max-angle))))
                    (setf (aref j-min-max-table 2 (round (- i (send target-joint :min-angle))))
                          (- (aref j-min-max-table 1 (round (- i (send target-joint :min-angle))))))
                    )
                (send self-joint :joint-min-max-table j-min-max-table)
                (send self-joint :joint-min-max-target target-joint))
            (list j1 j2)
            (list j2 j1)
            (list j1-min-max-table j2-min-max-table))

    ;; display min-max table if needed
    (unless (or (null x::*display*) (= x::*display* 0))
      (setq min-max-table-view
            (instance x::panel :create
                      :width  (round (- j1-org-max-angle j1-org-min-angle))
                      :height (round (- j2-org-max-angle j2-org-min-angle))
                      :atitle "min-max-table-view"))
      ;;
      (do ((x j1-org-min-angle (+ x 1)))
          ((> x j1-org-max-angle))
        (do ((y j2-org-min-angle (+ y 1)))
            ((> y j2-org-max-angle))
          (let* ((j1-min-max (cons (aref j1-min-max-table 1 (round (- y j2-org-min-angle))) (aref j1-min-max-table 2 (round (- y j2-org-min-angle))))) ;; j1-min-max-table is functoin of j2
                 (j2-min-max (cons (aref j2-min-max-table 1 (round (- x j1-org-min-angle))) (aref j2-min-max-table 2 (round (- x j1-org-min-angle)))))
                 (j1-min (car j1-min-max))
                 (j1-max (cdr j1-min-max))
                 (j2-min (car j2-min-max))
                 (j2-max (cdr j2-min-max)))
            (cond ((and (<= j1-min x j1-max)
                        (<= j2-min y j2-max)) ;; ok
                   (send min-max-table-view :color #xffffff)
                   (send min-max-table-view :draw-line (float-vector (+ x j1-org-max-angle) (+ y j2-org-max-angle)) (float-vector (+ x j1-org-max-angle) (+ y j2-org-max-angle)))
                   ;;
                   )
                  ((and (or (< x j1-min) (< j1-max x))
                        (or (< y j2-min) (< j2-max y))) ;; vaiolated ok
                   (send min-max-table-view :color #x000000)
                   (send min-max-table-view :draw-line (float-vector (+ x j1-org-max-angle) (+ y j2-org-max-angle)) (float-vector (+ x j1-org-max-angle) (+ y j2-org-max-angle)))
                   )
                  (t
                   ;; ??
                   ))
            )))
      (send min-max-table-view :flush)
      );; display
    ;; do test
    (let ((ret t))
      (dotimes (i (round (* (- j1-org-max-angle j1-org-min-angle) (- j2-org-max-angle j2-org-min-angle))))
        (setq x (round (+ (random (- j1-org-max-angle j1-org-min-angle)) j1-org-min-angle))
              y (round (+ (random (- j2-org-max-angle j2-org-min-angle)) j2-org-min-angle)))
        ;;
        (send *robot* :angle-vector (float-vector x y))
        ;;
        ;; check if x-y with in the limit
        (unless (eq (and (= x (send j1 :joint-angle)) (= y (send j2 :joint-angle))) ;; check if :anlge-vector did not modify value
                    (<= (abs y) (- 90 (abs x)))) ;; ground truth
          (if min-max-table-view
              (format t ";; Is (~A ~A) safe posture? ~A ~A~%" x y (and (= x (send j1 :joint-angle)) (= y (send j2 :joint-angle))) (<= (abs y) (- 90 (abs x))))))
        ;; check in view
        (cond ((and (= x (send j1 :joint-angle)) (= y (send j2 :joint-angle))) ;; with i nlimit
               (if min-max-table-view
                   (send min-max-table-view :color #x0000ff)))
              (t ;; out of limit
               (if min-max-table-view (format t ";; out of limit ~A -> ~A~%" (float-vector x y) (send *robot* :angle-vector)))
               (let* ((j1-max-angle
                       (+ (min (* (/ j1-org-max-angle j2-org-max-angle) (send j2 :joint-angle))
                               (* -1 (/ j1-org-max-angle j2-org-max-angle) (send j2 :joint-angle)))
                          j1-org-max-angle))
                      (j1-min-angle
                       (- j1-max-angle))
                      (j2-max-angle
                       (+ (min (* (/ j2-org-max-angle j1-org-max-angle) (send j1 :joint-angle))
                               (* -1 (/ j2-org-max-angle j1-org-max-angle) (send j1 :joint-angle)))
                          j2-org-max-angle))
                      (j2-min-angle
                       (- j2-max-angle)))
                 (setq ret
                       (and ret
                            (and (or (< (- j1-min-angle *epsilon*) (send j1 :joint-angle) (+ j1-min-angle *epsilon*))
                                     (< (- j1-max-angle *epsilon*) (send j1 :joint-angle) (+ j1-max-angle *epsilon*)))
                                 (or (< (- j2-min-angle *epsilon*) (send j2 :joint-angle) (+ j2-min-angle *epsilon*))
                                     (< (- j2-max-angle *epsilon*) (send j2 :joint-angle) (+ j2-max-angle *epsilon*))))
                            )))
               (when min-max-table-view
                 (send min-max-table-view :color #xff0000)
                 (send min-max-table-view :draw-line
                       (float-vector (- x j1-org-min-angle) (- y j2-org-min-angle))
                       (v- (send *robot* :angle-vector) (float-vector j1-org-min-angle j2-org-min-angle))))))
        (when min-max-table-view
          (send min-max-table-view :draw-line (float-vector (- x j1-org-min-angle) (- y j2-org-min-angle)) (float-vector (- x j1-org-min-angle) (- y j2-org-min-angle)))
          (send min-max-table-view :flush)
          ))
      (assert ret ";; check min-max violation")
      )
    ;;
    ;; restore
    (mapcar #'(lambda (j)
                (setq (j . joint-min-max-table) nil)
                (setq (j . joint-min-max-target) nil))
            (send *robot* :joint-list))
    ))

(defun check-link-collision-for-joint-min-max-table
  (robot link0 link1 joint0 joint1
   &key (margin 0.0) ;; margin [deg] is margin angle from collision-based min-angle and max-angle
        (debug-view nil))
  (let ((col-ret) (non-col-ret))
    (mapcar #'(lambda (self-joint target-joint)
                (do ((self-ja (get self-joint :org-min-angle) (+ 1 self-ja))) ((> self-ja (get self-joint :org-max-angle)))
                    (send robot :init-pose)
                    (send self-joint :joint-angle self-ja)
                    (mapcar #'(lambda (org-minmax minmax)
                                ;; non-col-ret : No collision check
                                ;;   If joint-min-max-table works and joint-angle is limited adequately, link0 and link1 do not collide each other.
                                (null-output (send target-joint :joint-angle (get target-joint org-minmax)))
                                (push (pqp-collision-check link0 link1) non-col-ret)
                                (when (and debug-view (= (pqp-collision-check link0 link1) 1))
                                  (objects (list link0 link1))
                                  (let ((tmp (pqp-collision-distance link0 link1)))
                                    (send (cadr tmp) :draw-on :flush nil :size 50)
                                    (send (caddr tmp) :draw-on :flush t :size 50))
                                  (read-line))
                                ;; col-ret : Collision check
                                ;;   If joint-min-max-table works and joint-angle is violated, link0 and link1 collide each other.
                                (unless (eps= (float (send target-joint :joint-angle)) (get target-joint org-minmax))
                                  (let ((org-table (send target-joint :joint-min-max-table)))
                                    (setq (target-joint . joint-min-max-table) nil) ;; force violation by removing joint-min-max-table tempolarily
                                    (send target-joint minmax (get target-joint org-minmax))
                                    (let ((ja
                                           (if (eq minmax :min-angle)
                                               (+ -1 (- margin) (get target-joint org-minmax))
                                             (+ 1 margin (get target-joint org-minmax)))))
                                      (when (if (eq minmax :min-angle)
                                                (> (+ -1 (- margin) (get target-joint org-minmax)) (get target-joint org-minmax))
                                              (< (+ 1 margin (get target-joint org-minmax)) (get target-joint org-minmax)))
                                        (null-output (send target-joint :joint-angle ja))
                                        (push (pqp-collision-check link0 link1) col-ret)))
                                    (send target-joint :joint-min-max-table org-table)
                                    )))
                            '(:org-min-angle :org-max-angle)
                            '(:min-angle :max-angle))))
            (list joint0 joint1)
            (list joint1 joint0))
    ;;(print non-col-ret)
    ;;(print col-ret)
    (list (every #'(lambda (x) (= x 0)) non-col-ret)
          (every #'(lambda (x) (= x 1)) col-ret))
    ))

(defun test-make-joint-min-max-table-common
  (&key (margin 0)) ;; [deg]
  (dolist (j (send *robot* :joint-list))
    (send j :put :org-max-angle (send j :max-angle))
    (send j :put :org-min-angle (send j :min-angle)))
  (send *robot* :self-collision-check)
  (send *robot* :make-joint-min-max-table
        (send (send *robot* :j1) :parent-link) (send (send *robot* :j2) :child-link) (send *robot* :j1) (send *robot* :j2)
        :margin margin)
  (unless (or (null x::*display*) (= x::*display* 0))
    (send *robot* :plot-joint-min-max-table (send *robot* :j1) (send *robot* :j2))
    ";; plot joint-min-max-table")
  (prog1
      (every #'identity (check-link-collision-for-joint-min-max-table
                         *robot* (send (send *robot* :j1) :parent-link) (send (send *robot* :j2) :child-link) (send *robot* :j1) (send *robot* :j2)
                         :margin margin))
    ;; restore
    (mapcar #'(lambda (j)
                (setq (j . joint-min-max-table) nil)
                (setq (j . joint-min-max-target) nil))
            (send *robot* :joint-list))
    ))

(deftest test-make-joint-min-max-table-margin-0deg
  (assert (test-make-joint-min-max-table-common :margin 0)))

(deftest test-make-joint-min-max-table-margin-5deg
  (assert (test-make-joint-min-max-table-common :margin 5)))

(run-all-tests)
(exit)
