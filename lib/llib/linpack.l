;
(unless (find-package "LINPACK")
   (make-package "LINPACK" :nicknames '("LP" "LIN")))
(in-package "LINPACK")
(export '(ssvdc pseudo-inverse sgedi sgesl))

(defparameter linpack
	 (load-foreign "/usr/local/eus/clib/linpackref.o"
		:ld-option
		   "-L/usr/local/lib -llinpack -lF77 -lm -lc"
		:symbol-output "euslinpack"
		:symbol-file "euslinpack"
		))
(unix:unlink "euslinpack")

(defforeign fortran-sgeco linpack "_sgeco_" () :integer)
(defforeign fortran-sgefa linpack "_sgefa_" () :integer)
(defforeign fortran-sgesl linpack "_sgesl_" () :integer)
(defforeign fortran-sgedi linpack "_sgedi_" () :integer)
(defforeign fortran-spoco linpack "_spoco_" () :integer)
(defforeign fortran-spofa linpack "_spofa_" () :integer)
(defforeign fortran-sposl linpack "_sposl_" () :integer)
(defforeign fortran-spodi linpack "_spodi_" () :integer)
(defforeign fortran-sppco linpack "_sppco_" () :integer)
(defforeign fortran-sppfa linpack "_sppfa_" () :integer)
(defforeign fortran-sppsl linpack "_sppsl_" () :integer)
(defforeign fortran-sppdi linpack "_sppdi_" () :integer)
(defforeign fortran-spbco linpack "_spbco_" () :integer)
(defforeign fortran-spbfa linpack "_spbfa_" () :integer)
(defforeign fortran-spbsl linpack "_spbsl_" () :integer)
(defforeign fortran-spbdi linpack "_spbdi_" () :integer)
(defforeign fortran-ssico linpack "_ssico_" () :integer)
(defforeign fortran-ssifa linpack "_ssifa_" () :integer)
(defforeign fortran-ssisl linpack "_ssisl_" () :integer)
(defforeign fortran-ssidi linpack "_ssidi_" () :integer)
(defforeign fortran-sspco linpack "_sspco_" () :integer)
(defforeign fortran-sspfa linpack "_sspfa_" () :integer)
(defforeign fortran-sspsl linpack "_sspsl_" () :integer)
(defforeign fortran-sspdi linpack "_sspdi_" () :integer)
(defforeign fortran-chico linpack "_chico_" () :integer)
(defforeign fortran-chifa linpack "_chifa_" () :integer)
(defforeign fortran-chisl linpack "_chisl_" () :integer)
(defforeign fortran-chidi linpack "_chidi_" () :integer)
(defforeign fortran-chpco linpack "_chpco_" () :integer)
(defforeign fortran-chpfa linpack "_chpfa_" () :integer)
(defforeign fortran-chpsl linpack "_chpsl_" () :integer)
(defforeign fortran-chpdi linpack "_chpdi_" () :integer)
(defforeign fortran-strco linpack "_strco_" () :integer)
(defforeign fortran-strsl linpack "_strsl_" () :integer)
(defforeign fortran-strdi linpack "_strdi_" () :integer)
(defforeign fortran-sgtsl linpack "_sgtsl_" () :integer)
(defforeign fortran-sptsl linpack "_sptsl_" () :integer)
(defforeign fortran-schdc linpack "_schdc_" () :integer)
(defforeign fortran-sqrdc linpack "_sqrdc_" () :integer)
(defforeign fortran-sqrsl linpack "_sqrsl_" () :integer)
(defforeign fortran-schud linpack "_schud_" () :integer)
(defforeign fortran-schdd linpack "_schdd_" () :integer)
(defforeign fortran-schex linpack "_schex_" () :integer)
(defforeign fortran-ssvdc linpack "_ssvdc_" () :integer)
;(defforeign fortran-sgemv linpack "_sgemv_" () :integer)
;(defforeign fortran-sgemm linpack "_sgemm_" () :integer)


(defun sgesl (a b)	; a is a matrix; b is a float-vector
			; b is destroyed to return answer
   (let ((at (transpose a))
	 (lda (integer-vector (length b)))
	 (n (integer-vector (length b)))
	 (ipvt (instantiate integer-vector (length b)))
	 (rcond (float-vector 0))
	 (z (instantiate integer-vector (length b))))
     (fortran-sgeco (at . entity) lda n ipvt rcond z)
     (fortran-sgesl (at . entity) lda n ipvt b #i(0))
     b))

(defun sgedi (a b)	; a is a matrix; b is a float-vector
			; b is destroyed to return answer
   (let ((at (transpose a))
	 (lda (integer-vector (length b)))
	 (n (integer-vector (length b)))
	 (ipvt (instantiate integer-vector (length b)))
	 (det (instantiate integer-vector 2))
	 (rcond (float-vector 0))
	 (work (instantiate integer-vector (length b))))
     (fortran-sgeco (at . entity) lda n ipvt rcond z)
     (fortran-sgedi (at . entity) lda n ipvt det work #i(11))
     (list (transpose at) (+ (* 10.0 (aref det 0)) (aref det 1))])))
  

(defun ssvdc (mat)
  (let* ((nn (array-dimension mat 0))
	 (pp (array-dimension mat 1))
	 (x (transpose mat))
	 (ldu (integer-vector nn))
	 (ldx (integer-vector nn))
	 (ldv (integer-vector pp))
	 (n (integer-vector nn))
	 (p (integer-vector pp))
	 (size (min (1+ nn) pp))
	 (s (make-array size :element-type :float))
	 (e (make-array pp   :element-type :float))
	 (u (make-array (list nn nn)  :element-type :float))
	 (v (make-array (list pp pp)  :element-type :float))
	 (work (make-array nn :element-type :float))
	 (job (integer-vector 11))
	 (info (integer-vector 0)) )
	 
   (fortran-ssvdc (array-entity x)		;x
		  ldx				;ldx
		  n
		  p
		  s
		  e
		  (array-entity u)
		  ldu
		  (array-entity v)
		  ldv
		  work
		  job info)
    (list (elt info 0) u s v)))

(defun pseudo-inverse (mat)
  "(mat) : mat can have more colums than rows."
  (let (mat-ssvdc u s v (j 0) v1d u1)
    (setq mat-ssvdc (ssvdc mat))
    (setq u (second mat-ssvdc))
    (setq s (third mat-ssvdc))
    (setq v (fourth mat-ssvdc))
    (while (> (elt s j) 0.0001)
      (push (scale (/ 1 (elt s j)) (matrix-column v j)) v1d)
      (setq j (1+ j)))
    (setq v1d (reverse v1d))
    (setq v1d (apply 'matrix v1d))
    (setq v1d (transpose v1d))
    (setq j (1- j))
    (while (>= j 0)
      (push (matrix-column u j) u1)
      (setq j (1- j)))
    (setq u1 (apply 'matrix u1))
    (m* v1d u1)))

(defun ssvdc-test ()
   (let (y1 y2 y3 y4 y)
	(setq y1 #f(0. 0. 1. -25. 15.0))
	(setq y2 #f(0. 0. 1. -25. -15. 0.))
	(setq y3 #f(0. 0. 1. 25. -15. 0.)) 
	(setq y4 #f(0. 0. 1. 25. 15. 0.))
	(setq y (matrix y1 y2 y3 y4))
	(ssvdc y)))

(defun pseudo-inverse-test ()
   (let (y1 y2 y3 y4 y x)
	(setq y1 #f(0. 0. 1. -25. 15.0))
	(setq y2 #f(0. 0. 1. -25. -15. 0.))
	(setq y3 #f(0. 0. 1. 25. -15. 0.)) 
	(setq y4 #f(0. 0. 1. 25. 15. 0.))
	(setq y (matrix y1 y2 y3 y4))
	(pseudo-inverse y)))

(defun random-matrix (m n &optional (r 1.0) &aux mat)
   (setq mat (make-matrix m n))
   (dotimes (i m)
      (dotimes (j n)
	 (setf (aref mat i j) (- (random (* 2.0 r)) r))
      ))
   mat)

(in-package "USER")
(use-package "LINPACK")
