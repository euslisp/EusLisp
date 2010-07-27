(defmacro to-unity (var maxvar)
  ;; Convert var to be from -1 to 1
  ;; ?? Typing.  Is coerce the right thing?  Don't want a rational here.
  `(- (/ (float ,var )
         (float ,maxvar))
      0.5))


(defun make-mandel-10 ()
  ;; Brute-force Mandelbrot thing.  No complex numbers!
  ;; This version has hard-wired assumptions, and looks like the C.
  (declare (optimize (speed 3)
                     (safety 0)))
 (let ((image (make-array '(10 10)
                     :element-type :bit :initial-element 0))
              ;; image components set to 0 if in, 1 if not: different
              ;; than make-mandel!
       (x 0.0)
       (y 0.0))
      (declare (type float x y))
      (dotimes (xindex 10)
        (dotimes (yindex 10)
          (setf x (the float (to-unity xindex 10))
                y (the float (to-unity yindex 10)))
          (dotimes (i 100)
            ;; z = x + iy => z * z = x*x +2ixy - y*y =>
            ;; Re(z^2) =X^2 -y^2, Im(z^2) = 2xy
            (setq x (the float (+ x (* x x) (- (* y y))))
                  y (the float (+ y (* 2.0 x y))))
            (if (or (>= (the float (abs x)) 2.0)
                    (>= (the float (abs y)) 2.0))
                (progn
                  (setf (aref image xindex yindex) 1)
                  (return nil))))))
      t))

;On A Sun4/65, with Sun cc, no optimization, and Allegro CL "3.1.13.1
;[Sun4] (0/0/0)"  I get:
;
;    kahlo* time ./mandel
;            0.1 real    0.0 user        0.0 sys
;
;and
;
;    <cl> (time (make-mandel-10))
;    cpu time (non-gc) 1683 msec user, 0 msec system
;    cpu time (gc)     250 msec user, 0 msec system
;    cpu time (total)  1933 msec user, 0 msec system
;    real time  2610 msec


;; In EusLisp on Sparc330
;	average of 10 executions
;	interpreted	8396.68 milisec
;	compiled	433.42 milisec
