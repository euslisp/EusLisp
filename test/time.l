;; time.l
;; Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>

(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(deftest test-date-time

  (setq d (instance calendar-time :make
           :year 2015 :month 8 :day 16
           :hour 18 :minute 39 :second 58
            :micro 746342))

  (setq d-add1 (send d :add
                 (instance interval-time :make
                  :hour 2 :minute 3 :second 4 :micro 300)))
  (assert (and (eq (send d-add1 :hour)
                   (+ (send d :hour) 2))
               (eq (send d-add1 :minute)
                   (+ (send d :minute) 4))
               (eq (send d-add1 :second)
                   (mod (+ (send d :second) 4) 60))
               (eq (send d-add1 :micro)
                   (+ (send d :micro) 300))))

  (setq d-add2 (send d :add
                 (instance interval-time :make
                  :hour 2 :minute 3 :second 4 :micro 3000000)))
  (assert (and (eq (send d-add2 :hour)
                   (+ (send d :hour) 2))
               (eq (send d-add2 :minute)
                   (+ (send d :minute) 4))
               (eq (send d-add2 :second)
                   (mod (+ (send d :second) 4 3) 60))
               (eq (send d-add2 :micro)
                   (send d :micro))))

  (setq d-sub1 (send d :subtract
                 (instance interval-time :make
                  :hour 2 :minute 3 :second 4 :micro 300)))
  (assert (and (eq (send d-sub1 :hour)
                   (- (send d :hour) 2))
               (eq (send d-sub1 :minute)
                   (- (send d :minute) 3))
               (eq (send d-sub1 :second)
                   (- (send d :second) 4))
               (eq (send d-sub1 :micro)
                   (- (send d :micro) 300))))

  (setq d-sub2 (send d :subtract
                 (instance interval-time :make
                  :hour 2 :minute 3 :second 4 :micro 3000000)))
  (assert (and (eq (send d-sub2 :hour)
                   (- (send d :hour) 2))
               (eq (send d-sub2 :minute)
                   (- (send d :minute) 3))
               (eq (send d-sub2 :second)
                   (- (send d :second) 4 3))
               (eq (send d-sub2 :micro)
                   (send d :micro))))

)

(eval-when (load eval)
  (run-all-tests)
  (exit))
;; end of time.l
