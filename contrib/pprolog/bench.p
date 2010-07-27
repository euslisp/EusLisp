; portable prolog benchmarks
;

+(NREVERSE (*X . *L0) *L)-(NREVERSE *L0 *L1)-(CONCAT *L1 (*X) *L).
+(NREVERSE () ()).

+(CONCAT (*A . *X) *Y (*A . *Z))-(CONCAT *X *Y *Z).
+(CONCAT () *Y *Y).

; [10-1:] Reverse 30 element.

+(REV15 *X)-(NREVERSE ( 1  2  3  4  5  6  7  8  9 10
                       11 12 13 14 15 ) *X).

; Problem 2. Quicksort.

+(QSORT (*X . *L) *R *R0)
      -(PARTITION *L *X *L1 *L2)
      -(QSORT *L2 *R1 *R0)
      -(QSORT *L1 *R (*X . *R1)).
+(QSORT () *R *R).

+(qsort2 (*h . *t) *s)-(partition *t *h *a *b)
		      -(qsort2 *a *s1)-(qsort2 *b *s2)
		      -(concat *s1 (*h . *s2) *s).
+(qsort2 () ()).

+(PARTITION (*X . *L) *Y (*X . *L1) *L2)
      -(EVAL (< *X *Y) T)
      -(PARTITION *L *Y *L1 *L2).
+(PARTITION (*X . *L) *Y *L1 (*X . *L2))
      -(PARTITION *L *Y *L1 *L2).
+(PARTITION () *A () ()).

+(bakasort *x *y)-(perm *x *y)-(ordered *y).

+(ordered ()).
+(ordered (*x)).
+(ordered (*x *y . *z)) - (eval (< *x *y) t)-(ordered (*y . *z)).

+(perm () ()).
+(perm *x (*y . *z)) -(delete *y *x *w) - (perm *w *z).


+(delete *x (*x . *y) *y).
+(delete *x (*y . *z) (*y . *w)) -(delete *x *z *w).


; [10-2:] Sort 20 element.

+(SORT20 *X)-(QSORT (27. 74. 17. 33. 94. 18. 46. 83. 65.  2.
                    32. 53. 28. 85. 99. 47. 28. 82.  6. 11. ) *X ()).


;+(aho *x)-(human *x).
;+(human ogasa).
;+(human suehiro).
;+(human hirai).
;+(human socrates).
;+(aho matsui).
+(qsort-bench (50 20 30 40 10 80 60 70 100 90
		51 21 31 41 11 81 61 71 101 91
		52 22 32 42 12 82 62 72 102 92
		53 23 33 43 13 83 63 73 103 93
		54 24 34 44 14 84 64 74 104 94)
	      *x ()).


ok
