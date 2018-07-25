;; LCS -Longest Common Substring
;; 2018-06-18 (c) Toshihiro Matsui


(defun r-lcs (x y m n)
   ;; recursive lcs
   (if (or (= m 0) (= n 0))
	0
	(if (= (elt x (1- m)) (elt y (1- n)))
	    (1+ (r-lcs x y (1- m) (1- n)))
	    (max (r-lcs x y (1- m) n) (r-lcs x y m (1- n))))))

(defun r-lcs-main (x y) (r-lcs x y (length x) (length y)))

(defun LCS (sa sb)	;; find the longest substring in sa and sb
   (let ((salen (length sa)) (sblen (length sb))
	 (mtab (make-array (list (length sa) (length sb)) :initial-element 0))
	 strs ch match (ii 0) (jj 0))
     (dotimes (i (1- salen))
	(setq ii (1+ i))
	(dotimes (j (1- sblen))
	   (setq jj (1+ j))
	   (if (eq (elt sa ii) (elt sb jj))
		(setf (aref mtab ii jj)  (1+ (aref mtab i j)))
		(setf (aref mtab ii jj)
		      (max (aref mtab i jj) (aref mtab ii j)) ) ) 
	   )
	)
     mtab ;; mtab has been built
     (labels ((build-lcs (i j)
	 (cond
	    ((= (aref mtab i j) 0) nil)
	    ((= (aref sa i) (aref sb j))
		(cons (aref sa i)  (build-lcs (1- i) (1- j))) )
	    ((> (aref mtab i (1- j)) (aref mtab (1- i) j))
		(build-lcs i (1- j)))
	    (t (build-lcs (1- i) j))) ) ) ; lcs defined
	(make-array (aref mtab (1- salen) (1- sblen))
		:element-type :char
		:initial-contents
			(reverse (build-lcs (1- salen) (1- sblen))))
	)
    )  )



;;	       (push (elt sa i) match)
       
(setq aa "TCAGAATTCCGGAA")
(setq bb "CGATGATGATCTACGAA")
      
