Received: by etlcom.etl.junet (5.51/6.3Junet-1.0)
	id AA06610; Wed, 5 Jul 89 13:58:12 JST
Received: from ccutrd by titcca.cc.titech.junet (5.61/6.4J.1)
	id AA03186; Wed, 5 Jul 89 13:54:32 +0900
Received: from jsk by ccut.cc.u-tokyo.ac.jp (5.61/6.4J.5-ut1.25)
	id AA21674; Wed, 5 Jul 89 14:00:52 +0900
Received: from lepus.jsk.u-tokyo.junet (lepus.ARPA) by jsk.jsk.u-tokyo.junet (1.00/6.3Junet-1.0)
	id AA00369; Wed, 5 Jul 89 22:54:54 jst
Received: by lepus.jsk.u-tokyo.junet (3.2/6.3Junet-1.0)
	id AA00283; Sat, 5 Aug 89 13:57:15 JST
Date: Sat, 5 Aug 89 13:57:15 JST
From: fujii@jsk.u-tokyo.junet (Fujii Makoto)
Return-Path: <fujii@jsk.u-tokyo.junet>
Message-Id: <8908050457.AA00283@lepus.jsk.u-tokyo.junet>
To: matsui@etlcom.etl.junet
Subject: camera-calibration
Status: R

  >>Almost all the user's files were lost.
それはご愁傷様です。こちらでもbackupを心がけているのですが、平和が続い
ているとついおろそかになってしまいます。
東京大学工学系研究科 機械工学専攻 井上・稲葉研究室修士2年の 藤井誠です。
稲葉先生から、calibrationのプログラムを送るようにいわれました。
(これを送ったところ返ってきました。)
送るファイルは、データファイル、Newton-Raphson法による収束計算のプログ
ラム(raphson.l)、これを線形化したもの(linraphs.l)、の3つです。
プログラムはかなり長いのですが、"kokokara" と "kokomade" にはさまれた
部分です。 

ーーーーーーーーデータファイル cwcalibyrs.dats ここから kokokara ーーーー
#s (segment2segment-calib-sample
    xyz #f(9.05437 -21.5794 -.6449555)
    otherxyz #f(9.05434 29.4207 -.644985)
    uv #f(164.000 165.000)
    otheruv #f(176.000 159.000))
#s (segment2segment-calib-sample
    xyz #f(9.05434 29.4206 -.644985)
    otherxyz #f(9.05434 29.4207 50.3550)
    uv #f(196.000 129.000)
    otheruv #f(196.000 117.000))
#s (segment2segment-calib-sample
    xyz #f(9.05437 -21.5794 -.644955)
    otherxyz #f(9.05437 -21.5793 50.3550)
    uv #f(143.000 136.000)
    otheruv #f(144.000 151.000))
#s (segment2segment-calib-sample
    xyz #f(-41.9456 4.58354 76.5177)
    otherxyz #f(-41.9456 -21.5794 50.3548)
    uv #f(138.000 47.0000)
    otheruv #f(129.000 60.0000))
#s (point2point-calib-sample
    xyz #f(-4.94565 4.58357 76.5177)
    uv #f(160.000 60.0000))
#s (point2point-calib-sample
    xyz #f(-41.9456 -21.5794 -.645153)
    uv #f(116.000 146.000))
#s (point2point-calib-sample
    xyz #f(9.05434 29.4207 50.3550)
    uv #f(196.000 91.0000))

ーーーーーーーーデータファイル cwcalibyrs.dats ここまで kokomade ーーーー
ーーーーーーーーraphson.l ここから kokokara ーーーー
;;;; raphson.l
;;; fitting process with Newton-Raphson method to minimize square
;;; root error.
;;; S63.12.  *MeR*
;;;
(eval-when (load)
	   (format t "Loading raphson.o~%"))
(eval-when (eval)
	   (format t "Loading raphson.l~%"))
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

(defun m+ (m1 m2)
  (let* ((m (copy-object m1)))
    (setq (m . entity)
	  (v+ (m1 . entity) (m2 . entity))
	  )
    m))
(defun nm+ (m1 m2 result)
  (v+ (m1 . entity) (m2 . entity) (result . entity))
  result)
(defun m- (m1 m2)
  (let* ((m (copy-object m2)))
    (setq (m . entity)
	  (v- (m1 . entity) (m2 . entity))
	  )
    m))
(defun nm- (m1 m2 result)
  (v- (m1 . entity) (m2 . entity) (result . entity))
  result)
(defun scale-matrix-mer (s m)
  (let* ((mr (copy-object m)))
    (setq (mr . entity) 
	  (scale s (m . entity)))
    mr))
(defun nscale-matrix-mer (s m result)
  (scale s (m . entity) (result . entity))
  result)
(defun expand2matrix (v1 v2)
  (m* (make-matrix-from-cvector v1)
      (make-matrix-from-rvector v2)))

(defun homo (xyz)
  (concatenate float-vector xyz #f(1.0)))
(defmethod point2point-calib-sample
  (:a (mat-i-wo)
      (v. (homo xyz) (matrix-row mat-i-wo 0)))
  (:b (mat-i-wo)
      (v. (homo xyz) (matrix-row mat-i-wo 1)))
  (:c (mat-i-wo)
      (v. (homo xyz) (matrix-row mat-i-wo 2)))
  (:vector-da
   (mat-diroha)
   (concatenate float-vector
		(transform mat-diroha xyz)
		(float-vector 1 0 0)))
  (:vector-db
   (mat-dnihohe)
   (concatenate float-vector
		(transform mat-dnihohe xyz)
		(float-vector 0 1 0)))
  (:vector-dc
   (mat-dtotiri)
   (concatenate float-vector
		(transform mat-dtotiri xyz)
		(float-vector 0 0 1)))
  (:matrix-dd-abc
   (mat-dd)
   (let* ((ddth-ddps (transform mat-dd xyz))
	  (dthth (elt ddth-ddps 0))
	  (dfith (elt ddth-ddps 1))
	  (dpsth (elt ddth-ddps 2))
	  (dfifi (elt ddth-ddps 3))
	  (dpsfi (elt ddth-ddps 4))
	  (dpsps (elt ddth-ddps 5)))
     (make-matrix-from-cvector
      (float-vector dthth dfith dpsth 0 0 0)
      (float-vector dfith dfifi dpsfi 0 0 0)
      (float-vector dpsth dpsfi dpsps 0 0 0)
      (float-vector 0     0     0     0 0 0)
      (float-vector 0     0     0     0 0 0)
      (float-vector 0     0     0     0 0 0)))
   )
  (:ccam-dvector-ddmatrix-primitive
   (mat-i-wo
    mat-diroha mat-dnihohe mat-dtotiri
    mat-dd-iroha mat-dd-nihohe mat-dd-totiri
    uv0 rk)
   (let* ((vectorgomi1 (float-vector 0 0 0 0 0 0))
	  (vectrogomi2 (float-vector 0 0 0 0 0 0))
	  (matrixgomi1 (unit-matrix 6))
	  (matrixgomi2 (unit-matrix 6))
	  dvector 
	  dd-matrix
	  (k1 (vector-x rk))
	  (k2 (vector-y rk))
	  ;
	  (u0 (vector-x uv0))
	  (v0 (vector-y uv0))
	  ;
	  (u1 (vector-x uv))
	  (v1 (vector-y uv))
	  (a (send self :a mat-i-wo))
	  (b (send self :b mat-i-wo))
	  (c (send self :c mat-i-wo))
	  ;;;;
	  (vec-da (send self :vector-da mat-diroha))
	  (vec-db (send self :vector-db mat-dnihohe))
	  (vec-dc (send self :vector-dc mat-dtotiri))
	  ;;;;
	  (mat-dd-a (send self :matrix-dd-abc mat-dd-iroha))
	  (mat-dd-b (send self :matrix-dd-abc mat-dd-nihohe))
	  (mat-dd-c (send self :matrix-dd-abc mat-dd-totiri))
	  ;;;;
	  (ainv (/ 1.0 a))
	  (ainv2 (sqr ainv))
	  (ainv3 (* ainv ainv2))
	  ;;
	  (kak1 (* ainv b))
	  (kak2 (* ainv c))
	  ;;
	  (vec-dkak1 (scale ainv (v- vec-db (scale (* ainv b) vec-da))))
	  (vec-dkak2 (scale ainv (v- vec-dc (scale (* ainv c) vec-da))))
	  ;;
	  (mat-da-db (expand2matrix vec-da vec-db ))
	  (mat-da-dc (expand2matrix vec-da vec-dc))	  
	  ;;	  
	  (mat-dd-kak1
	   (scale-matrix-mer
	    (- ainv2)
	    (nm+ 
	     (m- (nscale-matrix-mer b
				    mat-dd-a
				    matrixgomi1)
		 (nscale-matrix-mer (* 2.0 b ainv)
				    (expand2matrix vec-da vec-da)
				    matrixgomi2))
	     (nm+ (nm+ mat-da-db
		       (transpose mat-da-db)
		       matrixgomi1)
		  (nscale-matrix-mer a
				     mat-dd-b
				     matrixgomi2)
		  matrixgomi2)
	     matrixgomi1)))
	  (mat-dd-kak2
	   (scale-matrix-mer
	    (- ainv2)
	    (nm+ 
	     (m- (nscale-matrix-mer c
				    mat-dd-a
				    matrixgomi1)
		 (nscale-matrix-mer (* 2.0 c ainv)
				    (expand2matrix vec-da vec-da)
				    matrixgomi2))
	     (nm+
	      (nm+ mat-da-dc
		   (transpose mat-da-dc)
		   matrixgomi1)
	      (nscale-matrix-mer a
				mat-dd-c
				matrixgomi2)
	      matrixgomi2)
	     matrixgomi1)))
	  ;;
	  (delta-u (+ (* kak1 k1) u0 (- u1)))
	  (delta-v (+ (* kak2 k2) v0 (- v1)))
	  ;;
	  (ddelta-us (scale (* 2.0 delta-u k1)
			    vec-dkak1))
	  (ddelta-vs (scale (* 2.0 delta-v k2)
			    vec-dkak2))
	  (dd-delta-us
	   (m+ 
	    (nscale-matrix-mer
	     (* 2.0 k1 delta-u)
	     mat-dd-kak1
	     matrixgomi1)
	    (nscale-matrix-mer
	     (* 2.0 k1 k1)
	     (expand2matrix vec-dkak1 vec-dkak1)
	     matrixgomi1)))
	  (dd-delta-vs
	   (m+
	    (nscale-matrix-mer
	     (* 2.0 k2 delta-v)
	     mat-dd-kak2
	     matrixgomi1)
	    (nscale-matrix-mer
	     (* 2.0 k2 k2)
	     (expand2matrix vec-dkak2 vec-dkak2)
	     matrixgomi1)))
	  )
     (setq dvector (v+ ddelta-us ddelta-vs vectorgomi1))
     (setq dd-matrix (nm+ dd-delta-us dd-delta-vs matrixgomi1))
     (list dvector dd-matrix (+ (sqr delta-u) (sqr delta-v)))
     ))
  )
(defmethod segment2segment-calib-sample
  (:a (mat-i-wo xx)
      (v. (homo xx) (matrix-row mat-i-wo 0)))
  (:b (mat-i-wo xx)
      (v. (homo xx) (matrix-row mat-i-wo 1)))
  (:c (mat-i-wo xx)
      (v. (homo xx) (matrix-row mat-i-wo 2)))
  (:vector-da
   (mat-diroha xx)
   (concatenate float-vector
		(transform mat-diroha xx)
		(float-vector 1 0 0)))
  (:vector-db
   (mat-dnihohe xx)
   (concatenate float-vector
		(transform mat-dnihohe xx)
		(float-vector 0 1 0)))
  (:vector-dc
   (mat-dtotiri xx)
   (concatenate float-vector
		(transform mat-dtotiri xx)
		(float-vector 0 0 1)))
  (:matrix-dd-abc
   (mat-dd xx)
   (let* ((ddth-ddps (transform mat-dd xx))
	  (dthth (elt ddth-ddps 0))
	  (dfith (elt ddth-ddps 1))
	  (dpsth (elt ddth-ddps 2))
	  (dfifi (elt ddth-ddps 3))
	  (dpsfi (elt ddth-ddps 4))
	  (dpsps (elt ddth-ddps 5)))
     (make-matrix-from-cvector
      (float-vector dthth dfith dpsth 0 0 0)
      (float-vector dfith dfifi dpsfi 0 0 0)
      (float-vector dpsth dpsfi dpsps 0 0 0)
      (float-vector 0     0     0     0 0 0)
      (float-vector 0     0     0     0 0 0)
      (float-vector 0     0     0     0 0 0)))
   )
  
  (:ccam-dvector-ddmatrix-primitive
   (mat-i-wo
    mat-diroha mat-dnihohe mat-dtotiri
    mat-dd-iroha mat-dd-nihohe mat-dd-totiri
    uv0 rk)
   (let* ((vectorgomi1 (float-vector 0 0 0 0 0 0))
	  (vectorgomi2 (float-vector 0 0 0 0 0 0))
	  (matrixgomi1 (unit-matrix 6))
	  (matrixgomi2 (unit-matrix 6))
	  dvector
	  dd-matrix
	  (k1 (vector-x rk))
	  (k2 (vector-y rk))
	  ;;
	  (u0 (vector-x uv0))
	  (v0 (vector-y uv0))
	  ;;
	  (u1 (vector-x uv))
	  (v1 (vector-y uv))
	  (u2 (vector-x otheruv))
	  (v2 (vector-y otheruv))
	  ;;
	  (a1 (send self :a mat-i-wo xyz))
	  (b1 (send self :b mat-i-wo xyz))
	  (c1 (send self :c mat-i-wo xyz))
	  ;;
	  (a2 (send self :a mat-i-wo otherxyz))
	  (b2 (send self :b mat-i-wo otherxyz))
	  (c2 (send self :c mat-i-wo otherxyz))
	  ;;;;
	  (vec-da1 (send self :vector-da mat-diroha xyz))
	  (vec-da2 (send self :vector-da mat-diroha otherxyz))
	  ;;
	  (vec-db1 (send self :vector-db mat-dnihohe xyz))
	  (vec-db2 (send self :vector-db mat-dnihohe otherxyz))
	  ;;
	  (vec-dc1 (send self :vector-dc mat-dtotiri xyz))
	  (vec-dc2 (send self :vector-dc mat-dtotiri otherxyz))
	  ;;;;
	  (mat-dd-a1 (send self :matrix-dd-abc mat-dd-iroha xyz))
	  (mat-dd-b1 (send self :matrix-dd-abc mat-dd-nihohe xyz))
	  (mat-dd-c1 (send self :matrix-dd-abc mat-dd-totiri xyz))
	  ;;
	  (mat-dd-a2 (send self :matrix-dd-abc mat-dd-iroha otherxyz))
	  (mat-dd-b2 (send self :matrix-dd-abc mat-dd-nihohe otherxyz))
	  (mat-dd-c2 (send self :matrix-dd-abc mat-dd-totiri otherxyz))	  
	  ;;;;
	  (a1inv (/ 1.0 a1))
	  (a1inv2 (sqr a1inv))
	  (a1inv3 (* a1inv a1inv2))
	  ;;
	  (a2inv (/ 1.0 a2))
	  (a2inv2 (sqr a2inv))
	  (a2inv3 (* a2inv a2inv2))	  
	  ;;
	  (kak1-1 (* a1inv b1))
	  (kak2-1 (* a1inv c1))
	  (kak1-2 (* a2inv b2))
	  (kak2-2 (* a2inv c2))
	  ;;
	  (vec-dkak1-1 (scale a1inv (v- vec-db1 (scale (* a1inv b1) vec-da1 vectorgomi1)
					vectorgomi1)))
	  (vec-dkak1-2 (scale a2inv (v- vec-db2 (scale (* a2inv b2) vec-da2 vectorgomi1)
					vectorgomi1)))
	  ;;
	  (vec-dkak2-1 (scale a1inv (v- vec-dc1 (scale (* a1inv c1) vec-da1 vectorgomi1)
					vectorgomi1)))
	  (vec-dkak2-2 (scale a2inv (v- vec-dc2 (scale (* a2inv c2) vec-da2 vectorgomi1)
					vectorgomi1)))
	  ;;
	  (mat-da1-db1 (expand2matrix vec-da1 vec-db1))
	  (mat-da2-db2 (expand2matrix vec-da2 vec-db2))
	  (mat-da1-dc1 (expand2matrix vec-da1 vec-dc1))
	  (mat-da2-dc2 (expand2matrix vec-da2 vec-dc2))
	  ;;;
	  (mat-dd-kak1-1
	   (scale-matrix-mer
	    (- a1inv2)
	    (nm+ 
	     (m- (nscale-matrix-mer b1
				    mat-dd-a1
				    matrixgomi1)
		 (nscale-matrix-mer (* 2.0 b1 a1inv)
				    (expand2matrix vec-da1 vec-da1)
				    matrixgomi2))
	     (nm+
	      (nm+ mat-da1-db1
		   (transpose mat-da1-db1)
		   matrixgomi1)
	      (nscale-matrix-mer a1
				 mat-dd-b1
				 matrixgomi2)
	      matrixgomi2)
	     matrixgomi1)))
	  (mat-dd-kak2-1
	   (scale-matrix-mer
	    (- a1inv2)
	    (nm+ 
	     (m- (nscale-matrix-mer c1
				    mat-dd-a1
				    matrixgomi1)
		 (nscale-matrix-mer (* 2.0 c1 a1inv)
				    (expand2matrix vec-da1 vec-da1)
				    matrixgomi2))
	     (nm+
	      (nm+ mat-da1-dc1
		   (transpose mat-da1-dc1)
		   matrixgomi1)
	      (nscale-matrix-mer a1
				 mat-dd-c1
				 matrixgomi2)
	      matrixgomi2)
	     matrixgomi1)))
	  ;;
	  (mat-dd-kak1-2
	   (scale-matrix-mer
	    (- a2inv2)
	    (nm+ 
	     (m- (nscale-matrix-mer b2
				    mat-dd-a2
				    matrixgomi1)
		 (nscale-matrix-mer (* 2.0 b2 a2inv)
				    (expand2matrix vec-da2 vec-da2)
				    matrixgomi2))
	     (nm+
	      (nm+ mat-da2-db2
		   (transpose mat-da2-db2)
		   matrixgomi1)
	      (nscale-matrix-mer a2
				 mat-dd-b2
				 matrixgomi2)
	      matrixgomi2)
	     matrixgomi1)))
	  (mat-dd-kak2-2
	   (scale-matrix-mer
	    (- a2inv2)
	    (nm+ 
	     (m- (nscale-matrix-mer c2
				    mat-dd-a2
				    matrixgomi1)
		 (nscale-matrix-mer (* 2.0 c2 a2inv)
				    (expand2matrix vec-da2 vec-da2)
				    matrixgomi2))
	     (nm+
	      (nm+ mat-da2-dc2
		   (transpose mat-da2-dc2)
		   matrixgomi1)
	      (nscale-matrix-mer a2
				 mat-dd-c2
				 matrixgomi2)
	      matrixgomi2)
	     matrixgomi1)))
	  ;;
	  (du (- u2 u1))
	  (dv (- v2 v1))
	  (dudvs (/ 1.0 (+ (sqr du) (sqr dv))))
	  (lc (* dv k1))
	  (mc (- (* du k2)))
	  (nc (- (* du (- v1 v0)) (* dv (- u1 u0))))
	  (derrc-sp (+ (* lc kak1-1) (* mc kak2-1) nc))
	  (derrc-ep (+ (* lc kak1-2) (* mc kak2-2) nc))
	  ;;;;
	  (sq-dist-err-sp
	   (* dudvs (sqr derrc-sp)))
	  (sq-dist-err-ep
	   (* dudvs (sqr derrc-ep)))
	  ;;
	  (dvec-kak1kak2-sp (v+ (scale lc vec-dkak1-1 vectorgomi1)
				(scale mc vec-dkak2-1 vectorgomi2)))
	  (dvec-kak1kak2-ep (v+ (scale lc vec-dkak1-2 vectorgomi1)
				(scale mc vec-dkak2-2 vectorgomi2)))
	  ;;
	  (dvec-sq-dist-err-sp
	   (scale (* 2.0 dudvs derrc-sp)
		  dvec-kak1kak2-sp))
	  (dvec-sq-dist-err-ep
	   (scale (* 2.0 dudvs derrc-ep)
		  dvec-kak1kak2-ep))
	  ;;;;
	  (ddmat-sq-dist-err-sp
	   (scale-matrix-mer
	    (* 2.0 dudvs)
	    (nm+
	     (expand2matrix dvec-kak1kak2-sp
			    dvec-kak1kak2-sp)
	     (nscale-matrix-mer
	      derrc-sp
	      (nm+ (nscale-matrix-mer
		    lc mat-dd-kak1-1 matrixgomi1)
		   (nscale-matrix-mer
		    mc mat-dd-kak2-1 matrixgomi2)
		   matrixgomi1)
	      matrixgomi1)
	     matrixgomi1)))
	  (ddmat-sq-dist-err-ep
	   (scale-matrix-mer
	    (* 2.0 dudvs)
	    (nm+
	     (expand2matrix dvec-kak1kak2-ep
			    dvec-kak1kak2-ep)
	     (nscale-matrix-mer
	      derrc-ep
	      (nm+ (nscale-matrix-mer
		    lc mat-dd-kak1-2 matrixgomi1)
		   (nscale-matrix-mer
		    mc mat-dd-kak2-2 matrixgomi2)
		   matrixgomi1)
	      matrixgomi1)
	     matrixgomi1)))
	  )
     (setq dvector (v+ dvec-sq-dist-err-sp dvec-sq-dist-err-ep vectorgomi1))
     (setq dd-matrix (nm+ ddmat-sq-dist-err-sp ddmat-sq-dist-err-ep matrixgomi1))
     (list dvector dd-matrix (+ sq-dist-err-sp sq-dist-err-ep))
     ))
  )

(defmethod camera-calib-coord-raphson
  (:init (file)
	 (send-super :init :file file)
	 (setq many-samples samplist)
	 ;; (setq uv0 (float-vector 100 100))
	 ;; (setq rk (float-vector 100 -100))
	 ;; (send self :set-th-wo (float-vector 0 0 0  100 0 0))
	 self)
  (:set-th-wo
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
  (:raphson
   ()
   (let* ((sth (elt 3th-ps3 0))
	  (cth (elt 3th-ps3 1))
	  (sfi (elt 3th-ps3 2))
	  (cfi (elt 3th-ps3 3))
	  (sps (elt 3th-ps3 4))
	  (cps (elt 3th-ps3 5))
	  (i (- (* cps cth) (* sth sfi sps)))
	  (ro (+ (* cps sth) (* cth sfi sps)))
	  (ha (- (* cfi sps)))
	  (ni (- (* sth cfi)))
	  (ho (* cth cfi))
	  (he sfi)
	  (to (+ (* cth sps) (* sth sfi cps)))
	  (ti (- (* sth sps) (* cth sfi cps)))
	  (ri (* cfi cps))
	  (nu (vector-x invertpos))
	  (ru (vector-y invertpos))
	  (wo (vector-z invertpos))
	  ;;
	  (mat-i-wo
	   (make-matrix-from-rvector
	    (float-vector i ro ha nu)
	    (float-vector ni ho he ru)
	    (float-vector to ti ri wo)))
	  ;;;;
	  (mat-diroha
	   (make-matrix-from-cvector
	    (float-vector (- (+ (* cps sth) (* cth sfi sps)))
			 (- (* sth cfi sps))
			 (- (+ (* sps cth) (* sth sfi cps))))
	    (float-vector (- (* cps cth) (* sth sfi sps))
			 (* cth cfi sps)
			 (- (* cth sfi cps) (* sps sth)))
	    (float-vector 0
			 (* sfi sps)
			 (- (* cfi cps)))))
	  ;;
	  (mat-dnihohe
	   (make-matrix-from-cvector
	    (float-vector (- (* cth cfi))
			 (* sth sfi)
			 0)
	    (float-vector (- (* sth cfi))
			 (- (* cth sfi))
			 0)
	    (float-vector 0
			 cfi
			 0)))
	  ;;
	  (mat-dtotiri
	   (make-matrix-from-cvector
	    (float-vector (- (* cth sfi cps) (* sth sps))
			 (* sth cfi cps)
			 (- (* cth cps) (* sth sfi sps)))
	    (float-vector (+ (* cth sps) (* sth sfi cps))
			 (- (* cth cfi cps))
			 (+ (* sth cps) (* cth sfi sps)))
	    (float-vector 0
			 (- (* sfi cps))
			 (- (* cfi sps)))))
	  ;;;;
	  (mat-dd-i-ha
	   (make-matrix-from-cvector
	    (float-vector (- i)
			 (- (* cth cfi sps))
			 (- (* sps sth) (* cth sfi cps))
			 (* sth sfi sps)
			 (- (* sth cfi cps))
			 (- i))
	    
	    (float-vector (- ro)
			 (- (* sth cfi sps))
			 (- (+ (* sps cth) (* sth sfi cps)))
			 (- (* cth sfi sps))
			 (* cth cfi cps)
			 (- ro))
	    
	    (float-vector 0
			 0
			 0
			 (* cfi sps)
			 (* sfi cps)
			 (- ha))))
	  ;;
	  (mat-dd-ni-he
	   (make-matrix-from-cvector
	    (float-vector (- ni)
			 (* cth sfi)
			 0
			 (- ni)
			 0
			 0)
	    
	    (float-vector (- ho)
			 (* sth sfi)
			 0
			 (- ho)
			 0
			 0)
	    
	    (float-vector 0
			 0
			 0
			 (- he)
			 0
			 0)))
	  ;;
	  (mat-dd-to-ri
	   (make-matrix-from-cvector
	    (float-vector (- to)
			 (* cth cfi cps)
			 (- (+ (* sth cps) (* cth sfi sps)))
			 (- (* sth sfi cps))
			 (- (* sth cfi sps))
			 (- to))
	    
	    (float-vector (- ti)
			 (* sth cfi cps)
			 (- (* cth cps) (* sth sfi sps))
			 (* cth sfi cps)
			 (* cth cfi sps)
			 (- ti))
	    
	    (float-vector 0
			 0
			 0
			 (- (* cfi cps))
			 (* sfi sps)
			 (- ri))))
	  ;;;;
	  ccam-vector-matrix
	  (ccam-dvector (float-vector 0 0 0 0 0 0))
	  (ccam-ddmatrix (make-matrix 6 6))
	  dk
	  (sq-err 0.0)
	  )
     (dolist (x many-samples)
	     (setq ccam-vector-matrix
		   (send x :ccam-dvector-ddmatrix-primitive
			 mat-i-wo
			 mat-diroha mat-dnihohe mat-dtotiri
			 mat-dd-i-ha mat-dd-ni-he mat-dd-to-ri
			 uv0 rk))
	     (v+ ccam-dvector (car ccam-vector-matrix) ccam-dvector)
	     (nm+ ccam-ddmatrix (cadr ccam-vector-matrix) ccam-ddmatrix)
	     (setq sq-err (+ sq-err (caddr ccam-vector-matrix)))
	     )
     (setq dk (simultaneous-equation ccam-ddmatrix
				     ccam-dvector))
     ;;     (setq *m* ccam-ddmatrix)
     ;;     (setq *v* ccam-dvector)
     (setq previous-th-wo
	   (concatenate float-vector th-ps invertpos))
     (send self :set-th-wo
	   (v- previous-th-wo
	       dk))   ;;;;
     (setq previous-err sq-err)
     (setq last-orient dk)
     (format t "raphson ...... >orient ~s err ~s ~%" dk sq-err)
     (print (list th-ps invertpos))
     nil
     ))
  (:cal-camera-param
   () (send-super :cal-camera-param)
   (send self :th-wo-frp))
  (:nlz
   ()
   (let* ((th (elt th-ps 0))
	  (fi (elt th-ps 1))
	  (ps (elt th-ps 2))
	  (th-i (floor (/ (+ th pi) (* 2.0 pi))))
	  (fi-i (floor (/ (+ fi pi) (* 2.0 pi))))
	  (ps-i (floor (/ (+ pi ps) (* 2.0 pi))))
	  (nu (vector-x invertpos))
	  (ru (vector-y invertpos))
	  (wo (vector-z invertpos)))
     (setq th (- th (* th-i (* 2.0 pi))))
     (setq fi (- fi (* fi-i (* 2.0 pi))))
     (setq ps (- ps (* ps-i (* 2.0 pi))))
     (when (< (cos fi) 0.0)
	   (setq th-ps (send self :anothersol))
	   (send self :nlz))
     (send self :set-th-wo (float-vector th fi ps nu ru wo))))
  (:anothersol
   ()
   (let* ((th (elt th-ps 0))
	  (fi (elt th-ps 1))
	  (ps (elt th-ps 2)))
     (setq th (+ th pi))
     (setq fi (- pi fi))
     (setq ps (- ps pi))
     (float-vector th fi ps)))
  (:set-by-th-wo
   ()
   (send self :cons-pos)
   (send self :reconstruct-transform34)
   )
  (:cons-rot
   ()
   (let* ((sth (elt 3th-ps3 0))
	  (cth (elt 3th-ps3 1))
	  (sfi (elt 3th-ps3 2))
	  (cfi (elt 3th-ps3 3))
	  (sps (elt 3th-ps3 4))
	  (cps (elt 3th-ps3 5))
	  (i (- (* cps cth) (* sth sfi sps)))
	  (ro (+ (* cps sth) (* cth sfi sps)))
	  (ha (- (* cfi sps)))
	  (ni (- (* sth cfi)))
	  (ho (* cth cfi))
	  (he sfi)
	  (to (+ (* cth sps) (* sth sfi cps)))
	  (ti (- (* sth sps) (* cth sfi cps)))
	  (ri (* cfi cps))
	  (r (make-matrix-from-rvector
	      (float-vector i ro ha)
	      (float-vector ni ho he)
	      (float-vector to ti ri))))
     (setq rot (inverse-matrix r))))
  (:cons-pos
   ()
   (let* ((nu (vector-x invertpos))
	  (ru (vector-y invertpos))
	  (wo (vector-z invertpos))
	  (p (scale -1.0 (transform (send self :cons-rot)
				    (float-vector nu ru wo)))))
     (setq pos p)))
  
  (:th-wo-frp
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
  (:raphson-calibrate
   (u r)
   ;;   (send self :cal-camera-param)
   (let* ((du (scale 0.05 (v- u uv0)))
	  (dr (scale 0.05 (v- r rk))))
     (dotimes (i 20)
	      (dotimes (j 4)
		       (send self :raphson)
		       )
	      (setq uv0 (v+ du uv0))
	      (setq rk  (v+ dr rk))
	      (format t "uv0= ~s rk= ~s ~%" uv0 rk)
	      )
     (setq uv0 u)
     (setq rk r)
     (dotimes (j 4)
	      (send self :raphson))
     )
   )
  (:setup-by-other-camera
   (cam)
   (send-super :setup-by-other-camera cam)
   (send self :th-wo-frp)
   )
  )

;;;;;;;following programm is to use error information
(defmethod point2point-calib-sample
  (:ccam-err-primitive
   (mat-i-wo
    uv0 rk)
   (let* ((k1 (vector-x rk))
	  (k2 (vector-y rk))
	  ;;
	  (u0 (vector-x uv0))
	  (v0 (vector-y uv0))
	  ;;
	  (u1 (vector-x uv))
	  (v1 (vector-y uv))
	  (a (send self :a mat-i-wo))
	  (b (send self :b mat-i-wo))
	  (c (send self :c mat-i-wo))
	  ;;;;
	  (ainv (/ 1.0 a))
	  ;;
	  (kak1 (* ainv b))
	  (kak2 (* ainv c))
	  ;;
	  (delta-u (+ (* kak1 k1) u0 (- u1)))
	  (delta-v (+ (* kak2 k2) v0 (- v1)))
	  ;;
	  )
     (+ (sqr delta-u) (sqr delta-v))
     ))
  )
(defmethod segment2segment-calib-sample
  (:ccam-err-primitive
   (mat-i-wo
    uv0 rk)
   (let* ((k1 (vector-x rk))
	  (k2 (vector-y rk))
	  ;;
	  (u0 (vector-x uv0))
	  (v0 (vector-y uv0))
	  ;;
	  (u1 (vector-x uv))
	  (v1 (vector-y uv))
	  (u2 (vector-x otheruv))
	  (v2 (vector-y otheruv))
	  ;;
	  (a1 (send self :a mat-i-wo xyz))
	  (b1 (send self :b mat-i-wo xyz))
	  (c1 (send self :c mat-i-wo xyz))
	  ;;
	  (a2 (send self :a mat-i-wo otherxyz))
	  (b2 (send self :b mat-i-wo otherxyz))
	  (c2 (send self :c mat-i-wo otherxyz))
	  ;;;;
	  (a1inv (/ 1.0 a1))
	  (a1inv2 (sqr a1inv))
	  (a1inv3 (* a1inv a1inv2))
	  ;;
	  (a2inv (/ 1.0 a2))
	  (a2inv2 (sqr a2inv))
	  (a2inv3 (* a2inv a2inv2))	  
	  ;;
	  (kak1-1 (* a1inv b1))
	  (kak2-1 (* a1inv c1))
	  (kak1-2 (* a2inv b2))
	  (kak2-2 (* a2inv c2))
	  ;;
	  (du (- u2 u1))
	  (dv (- v2 v1))
	  (dudvs (/ 1.0 (+ (sqr du) (sqr dv))))
	  (lc (* dv k1))
	  (mc (- (* du k2)))
	  (nc (- (* du (- v1 v0)) (* dv (- u1 u0))))
	  (derrc-sp (+ (* lc kak1-1) (* mc kak2-1) nc))
	  (derrc-ep (+ (* lc kak1-2) (* mc kak2-2) nc))
	  ;;;;
	  (sq-dist-err-sp
	   (* dudvs (sqr derrc-sp)))
	  (sq-dist-err-ep
	   (* dudvs (sqr derrc-ep)))
	  ;;
	  )
     (+ sq-dist-err-sp sq-dist-err-ep)
     ))
  )
(defmethod camera-calib-coord-raphson
  (:now-err
   ()
   (let* ((sth (elt 3th-ps3 0))
	  (cth (elt 3th-ps3 1))
	  (sfi (elt 3th-ps3 2))
	  (cfi (elt 3th-ps3 3))
	  (sps (elt 3th-ps3 4))
	  (cps (elt 3th-ps3 5))
	  (i (- (* cps cth) (* sth sfi sps)))
	  (ro (+ (* cps sth) (* cth sfi sps)))
	  (ha (- (* cfi sps)))
	  (ni (- (* sth cfi)))
	  (ho (* cth cfi))
	  (he sfi)
	  (to (+ (* cth sps) (* sth sfi cps)))
	  (ti (- (* sth sps) (* cth sfi cps)))
	  (ri (* cfi cps))
	  (nu (vector-x invertpos))
	  (ru (vector-y invertpos))
	  (wo (vector-z invertpos))
	  ;;
	  (mat-i-wo
	   (make-matrix-from-rvector
	    (float-vector i ro ha nu)
	    (float-vector ni ho he ru)
	    (float-vector to ti ri wo)))
	  ;;;;
	  (sq-err 0.0)
	  )
     (dolist (x many-samples)
	     (setq sq-err (+ sq-err (send x :ccam-err-primitive
					  mat-i-wo uv0 rk)))
	     )
     (format t "square error  ~s ~%" sq-err)
     (setq now-err sq-err)
     ))
  )
(defun acos-mer (x)
  (cond ((<= 1.00 x) 0.0)
	((< -1.00 x) (acos x))
	(t pi)))
(defun asin-mer (x)
  (cond ((<= 1.00 x) 1.5708)
	((< -1.00 x) (asin x))
	(t -1.5708)))

(defun sqr (x) (* x x))

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
   (let
       ((error-allowance 0.0)
	(old-previous-th-wo (float-vector 0 0 0 0 0 0))
	old-previous-error
	)
     (dolist (sample many-samples)
	     (inc error-allowance (send sample :err-allowance)))
     (send self :raphson)
     (loop
      (replace old-previous-th-wo previous-th-wo)
      (setq old-previous-error previous-err)
      (send self :raphson)
      (when (>= previous-err old-previous-error) (return)))
     (send self :set-th-wo old-previous-th-wo)
     (send self :set-by-th-wo)
     (setq now-err old-previous-error)
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

ーーーーーーーーraphson.l ここまで kokomadeーーーー

ーーーーーーーーlinraphs.l ここから kokokara ーーーー
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

ーーーーーーーーlinraphs.l ここまで kokomadeーーーー

使い方は、raphson.l(真面目にsin,cosの計算をする)またはlinraphs.l(線形
化しているので高速)
のどちらかをロードして、
(setq *camera* (instance camera-calib-coord-raphson :init "cwcalibyrs.dats"))
などとやります。このときにGanapathyの方法により,カメラパラメタとして自
動的に初期値が入ります。このあと
(send *camera* :raphson) ;;;;;;raphson,linraphs に共通
とすればrot,posを1ステップだけ更新します。内部パラメタuv0,rkはそのまま
です。収束するまでのステップを一気にやりたい時は
(send *camera* :converge) です。

なにかお気づきの点がありましたら連絡していただけませんか。

東京大学工学系研究科 機械工学専攻
井上・稲葉研究室(jsk) 修士2年 藤井誠

