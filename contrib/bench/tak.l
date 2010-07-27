
; [1] function call/return

; **** Tarai ****
;      where number-manipulations may be replaced
;      by those restricted to integer if available

; To speed up, generic arithmetic operations are replaced 
; by integer arithmetic operations:
;

(DEFUN TARAI (X Y Z)
   (COND ((> X Y)
          (TARAI (TARAI (1- X) Y Z)
                 (TARAI (1- Y) Z X)
                 (TARAI (1- Z) X Y) ))
         (T Y) ))

(DEFUN TAK (X Y Z)
   (COND ((NOT (< Y X)) Z)
        (T (TAK (TAK (1- X) Y Z)
                (TAK (1- Y) Z X)
                (TAK (1- Z) X Y) ))))

(DEFUN fTAK (X Y Z)
   (declare (integer x y z))
   (COND ((NOT (< Y X)) Z)
        (T (fTAK (fTAK (1- X) Y Z)
                 (fTAK (1- Y) Z X)
                 (fTAK (1- Z) X Y) ))))

(DEFUN dTAK (X Y Z)
   (declare (integer x y z))
   (COND ((NOT (< Y X)) Z)
        (T (dTAK (dTAK (1- X) Y Z)
                 (dTAK (1- Y) Z X)	
                 (dTAK (1- Z) X Y) ))))

; Measure the following forms:
; [1-1:]
; (TARAI 8 4 0)       ; tarai is called 12605 times.
                      ;    with 9453 sub1's and 9454 else parts.

; [1-2:]
; (TARAI 10 5 0)      ; tarai is called 343073 times.
                      ;    with 257304 sub1's.

; [1-3:]     **** Try only the compiled code! ****
; (TARAI 12 6 0)      ; tarai is called 12604861 times.
                      ;    with 9453645 sub1's.

; [1-4:]
; (TAK 18 12 6)       ; tak is called 63609 times.
                      ;    in honor of USA Lisp comunity
;(DEFUN BENCH11 (ITER) (timing ITER (TARAI 8 4 0)))
;(DEFUN BENCH12 (ITER) (timing ITER (TARAI 10 5 0)))
;(DEFUN BENCH13 (ITER) (timing ITER (TARAI 12 6 0)))
;(DEFUN BENCH14 (ITER) (timing ITER (TAK 18 12 6)))

(defvar tx)
(defvar ty)
(defvar tz)

(defun stak (tx ty tz)
  (stak-aux))
(defun stak-aux ()
  (if (	not (< ty tx))
      tz
      (let ((tx (let ((tx (1- tx)) (ty ty) (tz tz))  (stak-aux)))
	    (ty (let ((tx (1- ty)) (ty tz) (tz tx))  (stak-aux)))
	    (tz (let ((tx (1- tz)) (ty tx) (tz ty))  (stak-aux))))
;	(print (list tx ty tz))
	 (stak-aux))))

