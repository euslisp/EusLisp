;;;; array.l
;;;;	array and vector operations:
;;;;	readmacro, make-array and vector/matrix arithmetics
;;;;	Copyright(c)1988, Toshihiro MATSUI, Electrotechnical Laboratory
;;;;

(in-package "LISP")


(export '(make-array array-total-size
	fill-pointer array-rank array-dimensions array-dimension
	array-vector row-major-aref list-dimensions read-array
	read-float-array read-integer-array float-vector-p
	integer-vector-p bit-vector-p matrixp make-matrix
	matrix-row matrix-column set-matrix-row set-matrix-column
	replace-matrix copy-matrix scale-matrix matrix
	acos asin unit-matrix m** simultaneous-equation
	inverse-matrix vector-x vector-y vector-z v=
	euler-matrix rpy-matrix))

;(defclass bit-vector :super vector
;		     :element-type :bit)

;(eval-when (compile)
;   (defclass array :super object
;		   :slots
;			 (entity rank fillpointer displaced-index-offset
;			   dim0 dim1 dim2 dim3 dim4 dim5 dim6)))

(eval-when (load eval)

#|
#define ELM_FIXED	0
#define ELM_BIT		1
#define ELM_CHAR	2
#define ELM_BYTE	3
#define ELM_INT		4
#define ELM_FLOAT	5
#define ELM_FOREIGN	6
#define ELM_POINTER	7
|#

(defmethod vectorclass
 (:elmtype () element-type)
 (:element-type ()
   (second (assoc element-type '(
      (0 :object)      (1 :bit)      (2 :character)      (3 :byte)
      (4 :integer)     (5 :float)    (6 :foreign)        (7 t) )))   )
 )

(defmethod vector
 (:elmtype () (send (class self) :elmtype))
 (:element-type () (send (class self) :element-type))
 )

(defmethod array
 (:element-type ()
    (cond ((float-vector-p entity) :float)
	  ((integer-vector-p entity) :integer)
	  ((stringp entity) :character)
	  ((bit-vector-p entity) :bit)
	  (t t))))

(defun fill-initial-contents (vec offset dimensions seq)
   (let ((major-dimension (pop dimensions))
	 (increments 0))
      (cond
         (dimensions
	  (setq increments (apply #'* dimensions))
	  (dotimes (i major-dimension)
             (fill-initial-contents vec offset dimensions (elt seq i))
	     (inc offset increments)))
	 (t
	     (dotimes (i (length seq))
		(setf (aref vec offset) (elt seq i))
		(inc offset)
		(inc increments)
		(if (> increments major-dimension)
		    (error "array dimension mismatch")))))
      vec))

(defun make-array (dim &key (element-type vector)
			    (fill-pointer nil)
			    (displaced-to nil)
			    (displaced-index-offset 0)
			    (adjustable nil)
			    (initial-contents nil)
			    (initial-element nil)
		     &aux entity a)
   (unless (classp element-type)
	(setq element-type
	      (case element-type
		((:character character :char char :byte byte) string)
		((:bit bit) bit-vector)
		((:float float) float-vector)
		((:integer integer :int int fixnum :fixnum)  integer-vector)
	        (t vector))))
   (cond ((integerp dim)	;make a simple vector
	  (setq entity (instantiate element-type dim))
	  (setq a entity)
	  (setq dim (list dim)))
	 (t
	   (setq a (instantiate array))
	   (let* ((i 0)
		  (rank (length dim))
		  (total-size (apply #'* dim)))
	      (if (> rank 7) (error "array rank limit over"))
	      (unless (every #'integerp dim)
		  (error "integer expected for array dimensions"))
	      (setq entity
		    (cond ((vectorp displaced-to) displaced-to)
		          ((arrayp displaced-to)  (array-entity displaced-to))
	        	  (t  (instantiate element-type (max 1 total-size)))))
	      (setq (a . rank) rank)
	      (setf (array-entity a) entity)
	      (setf (array-fill-pointer a)
			 (if (numberp fill-pointer)
			     fill-pointer
			     (if fill-pointer total-size nil)))
	      (setf (array-displaced-index-offset a) displaced-index-offset)
	      (do ((i 0 (1+ i)))
		  ((>= i rank))
		(setslot a array (+ i 5)  (elt dim i))))))
      (when initial-element  (fill entity initial-element))
      (when initial-contents
	 (fill-initial-contents entity 0 dim initial-contents))
      a) 


(defun array-total-size (a)
   (let ((rank (a . rank)) (tsize 1))
      (dotimes  (n rank)
         (setq tsize (* tsize (slot a array (+ 5 n)))))
      tsize))

(defun fill-pointer (a)
    (if (arrayp a) (a . fill-pointer) (error "not an array"))	)
(defun array-rank (a) (a . rank))
    
(defun array-dimensions (a)
   (let ((rank (a . rank)) dims)
      (while (> rank 0) (setq dims (cons (slot a array (+ 5 (dec rank))) dims)))
      dims))

(defun array-dimension (a axis)
    (if (arrayp a) (slot a array (+ 5 axis))))

(defun array-vector (a)
   (cond ((vectorp a)  a)
         ((arrayp a) (array-entity a))
	 (t (error "not array"))))

(defun row-major-aref (a index)
   (aref (array-entity a) index))

;;;
;;; make intvector
;;;
;(defun make-intvector (len)
;  (instantiate integer-vector len))
;(defun integer-vector (&rest l)
;  (let* ((llen (length l))
;	 (iv (make-intvector llen))
;	 )
;    (dotimes (i llen iv)
;	     (setf (aref iv i) (pop l)))))
;)

;;;
;;; make a bit-vector of length 32 from an integer
;;;
#|
(defun make-bits (n)
   (let
      ((bv (instantiate bit-vector 32)))
      (dotimes (i 32) (setbit bv i (if (evenp n) 0 1)) (setq n (ash n -1)))
      bv))
|#
;;; array reader for #nA, #nF and #nI sharp macros
(defun list-dimensions (list)
   (cond ((consp (car list))
	  (cons (length list) (list-dimensions (car list))))
         (t (list (length list)))))

(defun read-array (strm char num)
   (let ((list (read strm t t t)))
       (make-array (list-dimensions list) :initial-contents list)))

(defun read-float-array (strm char num)
   (let ((list (read strm t t t)))
       (if (= num 0)
	   (apply 'float-vector list)
	   (make-array (list-dimensions list)
			:element-type :float
			:initial-contents list))))

(defun read-integer-array (strm char num)
   (let ((list (read strm t t t)))
      (if (= num 0)
          (apply 'integer-vector list)
          (make-array (list-dimensions list)
			:element-type :integer
			:initial-contents list))))

(eval-when (load eval)
(set-dispatch-macro-character #\# #\A 'read-array)
(set-dispatch-macro-character #\# #\F 'read-float-array)
(set-dispatch-macro-character #\# #\I 'read-integer-array)
)

;;;;	floatvector and matrix
;
(eval-when (load eval)
(defun float-vector-p (obj) (derivedp obj float-vector))
(defun integer-vector-p (obj) (derivedp obj integer-vector))
(defun bit-vector-p (obj) (derivedp obj bit-vector))

(defun matrixp (obj)
   (and (derivedp obj array) (float-vector-p (obj . entity))))
;(defun vector (&rest vlist)
;   (let* ((size (length vlist)) (vec (instantiate vector size)) (i 0))
;      (while (< i size) (setf (aref vec i) (pop vlist))  (inc i))
;      vec))
(defun make-matrix (row column &optional init)
   (make-array (list row column) :element-type :float :initial-contents init))
(defun matrix-row (mat row)
   ; extract a row vector from a matrix
   (when (eq (array-rank mat) 2)
      (subseq (mat . entity) (* (mat . dim1) row) (* (mat . dim1) (1+ row)))))
(defun matrix-column (mat col)
   ; extract a colume vector out of a matrix
   (when (eq (array-rank mat) 2)
      (let* ((matrow (array-dim0 mat))
	     (matcol (array-dim1 mat))
	     (ent (array-entity mat))
	     (v (instantiate (class (array-entity mat)) matrow)))
         (dotimes (i matrow)
	   (setf (aref v i) (aref ent (+ col (* i matcol)))))
         v)))

(defun set-matrix-row (mat row values)
   (when (eq (array-rank mat) 2)
      (replace (mat . entity) values
		:start1 (* (mat . dim1) row)
		:end1 (* (mat . dim1) (1+ row))) )
  mat)
(defun set-matrix-column (mat col values)
   (when (eq (array-rank mat) 2)
      (let* ((matrow (array-dim0 mat))
	     (matcol (array-dim1 mat))
	     (ent (array-entity mat)) )
         (dotimes (i matrow)
	   (setf (aref ent (+ col (* i matcol))) (elt values i)))
         ))
  mat)

(defun replace-matrix (dest src)
   (replace (array-entity dest) (array-entity src))
   dest)
(defun copy-matrix (mat)
   (let* ((r (make-matrix (array-dim0 mat) (array-dim1 mat))))
      (replace (array-entity r) (array-entity mat))
      r))
(defun scale-matrix (s m &optional (result (copy-matrix m)))
   (scale s (array-entity m) (array-entity result))
   result)
(defun matrix (&rest seq)
   (make-matrix (length seq) (apply #'max (mapcar #'length seq)) seq))
(defun acos (x)  (atan (sqrt (- 1.0 (* x x))) x))
(defun asin (x)  (atan x (sqrt (- 1.0 (* x x)))))
(defun unit-matrix (&optional (n 3))
   (let ((mat (make-matrix n n)))
      (dotimes (i n) (aset mat i i 1.0))
      mat))
(defun m** (m1 m2 &rest more-matrices &aux mat)
   (setq mat (m* m1 m2))
   (dolist (m more-matrices) (m* mat m mat))
   mat)

(defun simultaneous-equation (mat vec)
  (let* ((work (unit-matrix (array-dimension mat 0)))
	 (perm (lu-decompose mat work)))
     (lu-solve work perm vec)))

(defun inverse-matrix (mat)
  (let* ((dim (array-dimension mat 0))
	 (work (unit-matrix dim))
	 (perm (lu-decompose mat work))
	 (rvec)
         (result (make-matrix dim dim))
	 (vec (instantiate float-vector dim))
	 (i 0))
     (if (null perm) (return-from inverse-matrix 'degenerated))
     (dotimes (i dim)
	(setf (aref vec i) 1.0)
	(setq rvec (lu-solve work perm vec))
        (dotimes (j dim) (aset result j i (aref rvec j) ))
	(setf (aref vec i) 0.0))
     result))

#|
(defun pseudo-inverse (a b)
;;; a and b are n*m (m>n) matrix
 (let ((at (transpose a)))
    (m* (m* b at) (inverse-matrix (m* a at)))) )
)
|#

;;;
(defun vector-x (p) (aref (the float-vector p) 0))
(defun vector-y (p) (aref (the float-vector p) 1))
(defun vector-z (p) (aref (the float-vector p) 2))
(defun v= (a b)
  (zerop (distance a b)))

(defun euler-matrix (az ay az2)
"EULER-MATRIX (az ay az2) creates a rotation matrix which has been
rotated az, ay, and az2 radian around local z, y, and again z axes.
EULER-ANGLE extracts these angles out of a matrix."
  (let ((r (rotation-matrix az :z)))
     (rotate-matrix r ay :y nil r)
     (rotate-matrix r az2 :z nil r)
     r) )

(defun rpy-matrix (az ay ax)
"RPY-MATRIX (az ay ax) creates a new rotation matrix which has been 
rotated ax radian around x-axis in WORLD, ay radian around y-axis in
WORLD, and az radian around z axis in WORLD, in this order.
These angles can be extracted by the RPY-ANGLE function."
  (let ((r (rotation-matrix ax :x)))
     (rotate-matrix r ay :y t r)
     (rotate-matrix r az :z t r)
     r) )

(provide :array "@(#)$Id$")
