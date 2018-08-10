;; rendering.l
;; Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>

(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(deftest transpose-image ()
  (setq *test-img-path* (format nil "~A/irteus/test/pr2.png" *eusdir*))
  (assert (probe-file *test-img-path*) "test image pr2.png is not found")
  (assert (setq *img* (read-image-file *test-img-path*)) "failed to read-image-file pr2.png")
  (assert (> (send (send *img* :monochromize) :brightest-pixel) 0.0)
          "nothing is drawn in image")
  (setq *src-img* (copy-object *img*))
  (gl::transpose-image-rows *img*)
  (assert (not (string= (send *src-img* :entity) (send *img* :entity)))
          "transpose-image-rows must change entity from original image")
  (gl::transpose-image-rows *img*)
  (assert (string= (send *src-img* :entity) (send *img* :entity))
          "image transposed twice must be the same as original image")
)

(run-all-tests)
(exit)

