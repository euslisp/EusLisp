(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(deftest linear-interpolator
  (let* ((l (instance linear-interpolator :init))
         (p0 #f(1 2 3)) (t0 0.10)
         (p1 #f(3 4 5)) (t1 0.18))
    (send l :reset :position-list (list p0 p1 p0) :time-list (list t0 t1))
    (send l :start-interpolation)
    (do ((i 0 (+ i 0.02)))
        ((eps>= i t0))
        (send l :pass-time 0.02)
        (assert (eps-v= (send l :position) (midpoint (/ i t0) p0 p1)))
        (print (list i (send l :position) (midpoint (/ i t0) p0 p1)))
        )
    (do ((i t0 (+ i 0.02)))
        ((eps> i t1))
        (send l :pass-time 0.02)
        (assert (eps-v= (send l :position) (midpoint (/ (- i t0) (- t1 t0)) p1 p0)))
        (print (list i (send l :position) (midpoint (/ (- i t0) (- t1 t0)) p1 p0)))
        )
    (assert (null (send l :interpolatingp)))
    ))

(deftest minjerk-interpolator
  (let* ((l (instance minjerk-interpolator :init))
         (p0 #f(1 2 3)) (t0 0.10)
         (p1 #f(3 4 5)) (t1 0.18))
    (send l :reset :position-list (list p0 p1 p0) :time-list (list t0 t1))
    (send l :start-interpolation)
    (do ((i 0 (+ i 0.02)))
        ((eps> i t0))
        (send l :pass-time 0.02)
        )
    (assert (eps-v= (send l :position) p1))
    (print (list (send l :position) p1))
    ;;
    (do ((i t0 (+ i 0.02)))
        ((eps> i t1))
        (send l :pass-time 0.02)
        )
    (assert (eps-v= (send l :position) p0))
    (print (list (send l :position) p0))
    ;;
    (assert (null (send l :interpolatingp)))
    ))

;; copy from https://github.com/jsk-ros-pkg/euslib/blob/master/tests/test-virtual-interpolator.l
;; pos interpolation function
;;   sample : euslib/test/test-virtual-interpolator.l
(defun pos-list-interpolation
  (pos-list ;; (list pos_1 pos_2 ... pos_N), pos_i is float-vector
   time-list ;; (list dtime_1 dtime_2 ... dtime_{N-1}), dtime_i is time[s] between time at pos_{i+1} - pos_i
   dt ;; dt [s]
   &key (interpolator-class minjerk-interpolator)
        ((:interpolator ip) (instance interpolator-class :init))
        (initial-time 0.0) (neglect-first) (vel-vector-list) (acc-vector-list))
  (let* ((data-list) (tm-list) (vel-data-list) (acc-data-list))
    (send* ip :reset
           :position-list pos-list
           :time-list (let (r) (dolist (n time-list) (push (+ n (if r (car r) 0)) r)) (nreverse r)) ;; list of time[sec] from start for each control point
           (append
            (if vel-vector-list (list :vel-vector-list vel-vector-list))
            (if acc-vector-list (list :acc-vector-list acc-vector-list))))
    (send ip :start-interpolation)
    (while (send ip :interpolatingp)
      (push (if (send ip :interpolatingp)
                (+ initial-time (send ip :time))
              (+ dt (car tm-list))) tm-list)
      (send ip :pass-time dt)
      (push (send ip :position) data-list)
      (if (find-method ip :vel) (push (send ip :vel) vel-data-list))
      (if (find-method ip :acc) (push (send ip :acc) acc-data-list))
      )
    (append
     (list :data (if neglect-first (cdr (reverse data-list)) (reverse data-list))
           :time (if neglect-first (cdr (reverse tm-list)) (reverse tm-list)))
     (if (find-method ip :vel)
         (list :vel (if neglect-first (cdr (reverse vel-data-list)) (reverse vel-data-list))))
     (if (find-method ip :acc)
         (list :acc (if neglect-first (cdr (reverse acc-data-list)) (reverse acc-data-list))))
     )))

(defun test-interpolators
  (&optional (ip-class linear-interpolator) (mode))
  (let* ((dt 0.01) ;; step time [s]
         (time-len 1.0) ;; total time [s]
         (ret-list
          (apply
           #'pos-list-interpolation
           (list (float-vector 0.0) (float-vector 30.0) (float-vector 90.0) (float-vector -90.0) (float-vector 0.0))
           (list (round (/ time-len dt 4)) (round (/ time-len dt 4)) (round (/ time-len dt 4)) (round (/ time-len dt 4)))
           dt
           :interpolator-class ip-class
           (if mode
               (list :interpolator (let ((ip (instance ip-class :init :sec/step dt)))
                                     (send ip :mode mode)
                                     ip)))
           ))
         (ret-list2 (mapcar #'(lambda (x) (elt x 0)) (cadr (memq :data ret-list)))))
    ;; (unless (or (null x::*display*) (= x::*display* 0))
    ;;   (graph-view
    ;;    (list ret-list2)
    ;;    (cadr (memq :time ret-list))
    ;;    :title (format nil "~A interpolator" (send ip-class :name))
    ;;    :xlabel "time [s]" :keylist (list "")))
    (and
     (> (reduce #'(lambda (x y) (min x y)) ret-list2) (- -90 *epsilon*))
     (< (reduce #'(lambda (x y) (max x y)) ret-list2) (+ 90 *epsilon*)))
    ))

(deftest test-linear-interpolator ()
  (let ((res (test-interpolators linear-interpolator)))
    (assert res)))

(deftest test-minjerk-absolute-interpolator ()
  (let ((res (test-interpolators minjerk-interpolator)))
    (assert res)))

#|
(load "~/prog/euslib/jsk/gnuplotlib.l")
(setq r (pos-list-interpolation (list #f(0) #f(30) #f(90) #f(-90) #f(0)) (list 0.25 0.25 0.25 0.25) 0.01))
(setq r2 (mapcar #'(lambda (x) (elt x 0)) (cadr (memq :data r)))) (graph-view (list r2) (cadr (memq :time r))))
(graph-view (list r2) (cadr (memq :time r)))
(print r2)
(print (length r2))
|#

(run-all-tests)
(exit)
