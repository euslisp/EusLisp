;;;; linraphs.l
;;;  fitting process with LINearized newton-RAPHSon method.
;;;  H1.1.25  *MeR*
;;;
(eval-when (load)
	   (format t "Loading linraphs.o~%"))
(eval-when (eval)
	   (format t "Loading linraphs.l~%"))
(eval-when
 (compile)
 (defclass point2point-calib-sample
   :super camera-calib-sample
   :slots nil)
 (defclass line2line-calib-sample
   :super camera-calib-sample
   :slots (dudv dxdydz))
 (defclass segment2segment-calib-sample 
   :super camera-calib-sample
   :slots (otheruv otherxyz))
 )

(defclass camera-calib-coord-raphson
  :super camera-calib-coord
  :slots (many-samples
	  th-ps
	  3th-ps3
	  invertpos
	  previous-err
	  previous-th-wo
	  now-err
	  last-orient
	  ))

(defmethod point2point-calib-sample
  (:ccam-lineareq-vector-element-list
   (mat-i-wo uv0 rk)
   (let* ((iro
	   (v. (homo xyz) (matrix-row mat-i-wo 0)))
	  (niho
	   (v. (homo xyz) (matrix-row mat-i-wo 1)))
	  (toti
	   (v. (homo xyz) (matrix-row mat-i-wo 2)))
	  )
     (v+ (scale iro
		(v- uv0 uv))
	 (float-vector
	  (* (vector-x rk) niho)
	  (* (vector-y rk) toti)))
     ))
  (:ccam-lineareq-matrix-element-list
   (mat-i-wo uv0 rk)
   (let* ((u (vector-x uv))
	  (v (vector-y uv))
	  (u0 (vector-x uv0))
	  (v0 (vector-y uv0))
	  (k1 (vector-x rk))
	  (k2 (vector-y rk))
	  (vec-iroha
	   (float-vector 
	    (aref mat-i-wo 0 0)
	    (aref mat-i-wo 0 1)
	    (aref mat-i-wo 0 2)))
	  (vec-nihohe
	   (float-vector
	    (aref mat-i-wo 1 0)
	    (aref mat-i-wo 1 1)
	    (aref mat-i-wo 1 2)))
	  (vec-totiri
	   (float-vector
	    (aref mat-i-wo 2 0)
	    (aref mat-i-wo 2 1)
	    (aref mat-i-wo 2 2)))
	  )
     (list
      (v-
       (scale
	(- u u0)
	(concatenate
	 float-vector
	 (v* vec-iroha xyz)
	 (float-vector 1 0 0)
	 ))
       (scale
	k1
	(concatenate
	 float-vector
	 (v* vec-nihohe xyz)
	 (float-vector 0 1 0)
	 )))
      (v-
       (scale
	(- v v0)
	(concatenate
	 float-vector
	 (v* vec-iroha xyz)
	 (float-vector 1 0 0)
	 ))
       (scale
	k2
	(concatenate
	 float-vector
	 (v* vec-totiri xyz)
	 (float-vector 0 0 1)
	 )))      
      )))
  )
(defmethod segment2segment-calib-sample
  (:ccam-lineareq-vector-element-list
   (mat-i-wo uv0 rk)
   (let* ((dudv (v- otheruv uv))
	  (u (vector-x uv))
	  (v (vector-y uv))
	  (du (vector-x dudv))
	  (dv (vector-y dudv))
	  (k1 (vector-x rk))
	  (k2 (vector-y rk))
	  (duvdvu
	   (- (* du (- v (vector-y uv0)))
	      (* dv (- u (vector-x uv0)))))
	  (homo1 (homo xyz))
	  (homo2 (homo otherxyz))
	  (i-to1 (transform mat-i-wo homo1))
	  (i-to2 (transform mat-i-wo homo2))	  
	  (iro1
	   (vector-x i-to1))
	  (niho1
	   (vector-y i-to1))
	  (toti1
	   (vector-z i-to1))
	  (iro2
	   (vector-x i-to2))
	  (niho2
	   (vector-y i-to2))
	  (toti2
	   (vector-z i-to2))	  
	  (vv1
	   (+ (* dv k1 niho1)
	      (- (* du k2 toti1))
	      (* duvdvu iro1)))
	  (vv2
	   (+ (* dv k1 niho2)
	      (- (* du k2 toti2))
	      (* duvdvu iro2))))     
     (float-vector (- vv1)  (- vv2)) ))
  (:ccam-lineareq-matrix-element-list
   (mat-i-wo uv0 rk)
   (let* ((k1 (vector-x rk))
	  (k2 (vector-y rk))
	  (u (vector-x uv))
	  (v (vector-y uv))
	  (dudv (v- otheruv uv))
	  (du (vector-x dudv))
	  (dv (vector-y dudv))
	  (duvdvu
	   (- (* du (- v (vector-y uv0)))
	      (* dv (- u (vector-x uv0)))))	  
	  (vec-iroha
	   (float-vector 
	    (aref mat-i-wo 0 0)
	    (aref mat-i-wo 0 1)
	    (aref mat-i-wo 0 2)))
	  (vec-nihohe
	   (float-vector
	    (aref mat-i-wo 1 0)
	    (aref mat-i-wo 1 1)
	    (aref mat-i-wo 1 2)))
	  (vec-totiri
	   (float-vector
	    (aref mat-i-wo 2 0)
	    (aref mat-i-wo 2 1)
	    (aref mat-i-wo 2 2)))	  
	  (vectorcel1
	   (v* vec-iroha xyz))
	  (vectorcel2
	   (v* vec-nihohe xyz))
	  (vectorcel3
	   (v* vec-totiri xyz))
	  (vec100 (float-vector 1 0 0))
	  (vec010 (float-vector 0 1 0))
	  (vec001 (float-vector 0 0 1))
	  (vec-a1
	   (concatenate float-vector 
			vectorcel1 vec100))
	  (vec-b1
	   (concatenate float-vector
			vectorcel2 vec010))
	  (vec-c1
	   (concatenate float-vector
			vectorcel3 vec001))
	  vec-a2 vec-b2 vec-c2)
     (v* vec-iroha otherxyz vectorcel1)
     (v* vec-nihohe otherxyz vectorcel2)     
     (v* vec-totiri otherxyz vectorcel3)
     (setq vec-a2
	   (concatenate float-vector
			vectorcel1 vec100))
     (setq vec-b2
	   (concatenate float-vector
			vectorcel2 vec010))
     (setq vec-c2
	   (concatenate float-vector
			vectorcel3 vec001))
     (list
      (v+ 
       (v-
	(scale (* dv k1) vec-b1 vec-b1)
	(scale (* du k2) vec-c1 vec-c1)
	vec-b1
	)
       (scale duvdvu vec-a1 vec-a1)
       vec-a1
       )
      (v+ 
       (v-
	(scale (* dv k1) vec-b2 vec-b2)
	(scale (* du k2) vec-c2 vec-c2)
	vec-b2
	)
       (scale duvdvu vec-a2 vec-a2)
       vec-a2
       ))))
  )

(defmethod camera-calib-coord-raphson
  (:init (file) ;identical to "raphson.l"
	 (send-super :init :file file)
	 (setq many-samples samplist)
	 ;; (setq uv0 (float-vector 100 100))
	 ;; (setq rk (float-vector 100 -100))
	 ;; (send self :set-th-wo (float-vector 0 0 0  100 0 0))
	 self)
  (:set-th-wo  ;identical to "raphson.l"
   (f)
   (setq th-ps (float-vector (elt f 0)
			     (elt f 1)
			     (elt f 2)))
   (setq invertpos (float-vector (elt f 3)
				(elt f 4)
				(elt f 5)))
   (let* ((th (elt th-ps 0))
	  (fi (elt th-ps 1))
	  (ps (elt th-ps 2))
	  (sth (sin th))
	  (cth (cos th))
	  (sfi (sin fi))
	  (cfi (cos fi))
	  (sps (sin ps))
	  (cps (cos ps)))
     (setq 3th-ps3
	   (float-vector sth cth sfi cfi sps cps))
     )
   (list th-ps invertpos))  
  (:cal-camera-param  ;identical to "raphson.l"
   () (send-super :cal-camera-param)
   (send self :th-wo-frp))  
  (:th-wo-frp ;identical to "raphson.l"
   ()
   (let* ((he (aref rot 2 1))
	  (ni (aref rot 0 1))
	  (ho (aref rot 1 1))
	  (ha (aref rot 2 0))
	  (ri (aref rot 2 2))
	  (fi (asin-mer he))
	  (cfi (cos fi))
	  (sth (- (/ ni cfi)))
	  (cth (/ ho cfi))
	  (th
	   (cond ((< sth 0.0)
		  (- (acos-mer cth)))
		 (t
		  (acos-mer cth))))
	  (sps (- (/ ha cfi)))
	  (cps (/ ri cfi))
	  (ps
	   (cond ((< sps 0.0)
		  (- (acos-mer cps)))
		 (t
		  (acos-mer cps))))
	  (nu-wo
	   (scale -1.0
		  (transform
		   (transpose rot)
		   pos))))
     (send self :set-th-wo
	   (concatenate float-vector (float-vector th fi ps) nu-wo))
     ))  
  (:setup-by-other-camera  ; identical to "raphson.l"
   (cam)
   (send-super :setup-by-other-camera cam)
   (send self :th-wo-frp)
   )  
  (:make-mat-i-wo
   ()
   (make-matrix-from-cvector
    (matrix-row rot 0)
    (matrix-row rot 1)    
    (matrix-row rot 2)
    invertpos))
  (:raphson-primitive
   ()
   (let* ((mat-i-wo (send self :make-mat-i-wo))
   	  (matrix-work (send self :ccam-lineareq-matrix mat-i-wo))
	  (vector-work (send self :ccam-lineareq-vector mat-i-wo))
	  (as (m* matrix-work (transpose matrix-work)))
	  (bs (transform matrix-work vector-work))
	  (x (simultaneous-equation as bs))
	  (o1 (aref x 0))
	  (o2 (aref x 1))
	  (o3 (aref x 2))
	  (dnu (aref x 3))
	  (dru (elt x 4))
	  (dwo (aref x 5))
	  dr)
     (v+ invertpos (float-vector dnu dru dwo) invertpos)
     (setq dr
	   (make-matrix-from-rvector 
	    (float-vector 1 (- o3) o2)
	    (float-vector o3 1 (- o1))
	    (float-vector (- o2) o1 1)))
     (format t "linear dx~s ~%" x)
     (authorized-normalize (m* dr rot rot))
     ))
  (:raphson
   ()
   (send self :raphson-primitive)
   (scale -1.0 (transform rot invertpos pos) pos)
   (send self :th-wo-frp)
   
   (format t "linear ..> sqrt err ~s~%" 
	   (send self :now-err-frp)))
  (:ccam-lineareq-matrix
   (mat-i-wo)
   (apply #'make-matrix-from-cvector 
	  (apply #'append
		 (mapcar
		  #'(lambda (s)
		      (send s :ccam-lineareq-matrix-element-list
			    mat-i-wo
			    uv0 rk))
		  many-samples))))
  (:ccam-lineareq-vector
   (mat-i-wo)
   (apply #'concatenate
	  float-vector
	  (mapcar
	   #'(lambda (s)
	       (send s :ccam-lineareq-vector-element-list
		     mat-i-wo
		     uv0 rk)) many-samples))
   )
  (:now-err-frp
   ()
   (let* ((sq-err 0.0))
     (dolist (x many-samples)
	     (setq sq-err (+ sq-err (send x :ccam-err-primitive
					 (send self :make-mat-i-wo)
					 uv0 rk)))
	     )
     (setq now-err sq-err)))
  )

(defun authorized-normalize (r)
  (let* ((r1 (matrix-row r 0))
	 (r2 (matrix-row r 1))
	 (r3 (normalize-vector (v* r1 r2))))
    (v* r3 (normalize-vector r1) r2)
    (v* r2 r3 r1)
    (replace-matrix r (make-matrix-from-rvector r1 r2 r3))))
;;(defun authorized-normalize (r) r)

(eval-when (load eval)
	   (format t "linraphs.l read completed. ~%")
	   )

;;;
;;;  methods appended by miya
;;;

(defmethod point2point-calib-sample
  (:err-allowance
   ()
   4.0)
  )

(defmethod segment2segment-calib-sample
  (:err-allowance
   ()
   8.0)
  )

(defmethod camera-calib-coord-raphson
  (:converge
   ()
   (let ((error-allowance 0.0)
	 (backup-rot (copy-object rot))
	 (backup-invertpos (copy-object invertpos)))
     (dolist (sample many-samples)
	     (inc error-allowance (send sample :err-allowance)))
     (setq now-err (send self :now-err-frp))
     (loop
      (replace-matrix backup-rot rot)
      (replace backup-invertpos invertpos)
      (setq previous-err now-err)
      (send self :raphson-primitive)
      (setq now-err (send self :now-err-frp))
      (format t "error is ~s~%" now-err)
      (when (>= now-err previous-err) (return)))
     (replace-matrix rot backup-rot)
     (replace invertpos backup-invertpos)
     (setq now-err previous-err)
     (scale -1.0 (transform rot invertpos pos) pos)
     (send self :th-wo-frp)
     (send self :reconstruct-transform34)
     (if (< now-err error-allowance)
	 (progn
	   (format t "Converged. err/allowance: ~s/~s ~%"
		   now-err error-allowance)
	   t)
       (progn
	 (format t "Could't converge well. Sorry. err/allowance: ~s/~s ~%"
		 now-err error-allowance)
	 nil))))
  )

(eval-when (load eval)
	   (format t "...Done~%"))

