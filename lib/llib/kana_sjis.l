;;; kana_euc.l
;;; roman-ji and  kana conversion
;;;  (c) 1999, Toshihiro Matsui, Electrotechnical Laboratory
;;;
;;; 1. (romkan  romanji-string)  roman-ji --> kana
;;; 2. (romanji kana-string)  hiragana/katakana --> roman-ji
;;; 3. shift-jis to EUC conversion, JIS to EUC conversion
;;; 4. number(1, 2, ...) and date to romanji
;;; 5. conversion between katakana and hiragana
;;;
;;; !!!! Important !!!!
;;; *** Reading Japanese 16-bit character code as a string in EusLisp ***
;;; Reading Shift-JIS code definitely produces unexpected result.
;;; JIS (7 bit code prefixed by ESC+$+{@AB}) is OK, but the most
;;; preferrable Japanese code is EUC.  Therefore, Japanese handling
;;; program should use only EUC, and EUC-to-SJIS conversion for output.
;;; If you somehow have to read Shift-JIS code, use the read-line
;;; function for input.
;;;
;;; Reason:
;;; EusLisp reader does not know anything about kanji-code, and it just
;;; reads a byte stream assuming it produces English text. 8-bit codes
;;; are read unchanged. But there are two special characters, " (double quote)
;;; and \ (back-slash or currency sign).  The first is OK, because 
;;; shift-JIS code does not include the double quote character as a Japanse
;;; character constituent.  However, some characters' Shift-JIS representation
;;; uses #x5c as a lower byte of the 16-bit code, which is a back-slash character.
;;; For example, shift-JIS representation of "ソ" is #x835c.  The #x5c code
;;; fools the EusLisp reader, since it is taken as an escape character
;;; to read the next character as is.  This happens when the function "READ"
;;; is used to read strings.  Since "LOAD" also uses "READ", EusLisp source
;;; programs written in SJIS code cannot be read as expected.  READ-LINE
;;; is free from this problem.



(export '(romkan kana-date kana-time))


(defvar kana2 (make-array '(26 5) :initial-contents
  '(( )
    ("ば" "び" "ぶ" "べ" "ぼ")
    ("さ" "し" "す" "せ" "そ")
    ("だ" "ぢ" "づ" "で" "ど")
    ()
    ("ふぁ" "ふぃ" "ふ" "ふぇ" "ふぉ")
    ("が" "ぎ" "ぐ" "げ" "ご")
    ("は" "ひ" "ふ" "へ" "ほ")
    ()
    ("じゃ" "じ" "じゅ" "じぇ" "じょ")
    ("か" "き" "く" "け" "こ")
    ("ら" "り" "る" "れ" "ろ")
    ("ま" "み" "む" "め" "も")
    ("な" "に" "ぬ" "ね" "の")
    ()
    ("ぱ" "ぴ" "ぷ" "ぺ" "ぽ")
    ("くぁ" "くぃ" "きゅ" "きぇ" "きょ")
    ("ら" "り" "る" "れ" "ろ")
    ("さ" "し" "す" "せ" "そ")
    ("た" "ち" "つ" "て" "と")
    ()
    ("ぶぁ" "ぶぃ" "ぶ" "ぶぇ" "ぼ")
    ("わ" "ゐ" "う" "ゑ" "を")
    ("ぁ" "ぃ" "ぅ" "ぇ" "ぉ")
    ("や" "い" "ゆ" "いぇ" "よ")
    ("ざ" "じ" "ず" "ぜ" "ぞ")
    ) ) )

(defvar kana-y (make-array '(26 3) :initial-contents
  '(( )
    ("びゃ" "びゅ" "びょ")
    ("きゃ" "きゅ" "きょ")
    ("ぢゃ" "ぢゅ" "ぢょ")
    ()
    ()
    ("ぎゃ" "ぎゅ" "ぎょ")
    ("ひゃ" "ひゅ" "ひょ")
    ()
    ("じゃ" "じゅ" "じょ")
    ("きゃ" "きゅ" "きょ")
    ("りゃ" "りゅ" "りょ")
    ("みゃ" "みゅ" "みょ")
    ("にゃ" "にゅ" "にょ")
    ()
    ("ぴゃ" "ぴゅ" "ぴょ")
    ()
    ("りゃ" "りゅ" "りょ")
    ("しゃ" "しゅ" "しょ")
    ("ちゃ" "ちゅ" "ちょ")
    ()
    ("ぶぁ" "ぶゅ" "びょ")
    ("わ" "う"  "を")
    ("ぁ" "ぅ" "ぉ")
    ()
    ("じゃ" "じゅ" "じょ")
    ) ) )

(defvar kana-ts (make-array '(5) :initial-contents
  '("つぁ" "つぃ" "つ" "つぇ" "つぉ" )))
(defvar kana-ch (make-array '(5) :initial-contents
  '("ちゃ" "ち" "ちゅ" "ちぇ" "ちょ")))
(defvar kana-sh (make-array '(5) :initial-contents
  '("しゃ" "し" "しゅ" "しぇ" "しょ")))

(defun vowelp (ch) (member ch '(#\A #\I #\U #\E #\O)))

(defun vowel-ord (ch)
     (let ((ord (cadr (assoc ch
		 '((#\A 0) (#\I 1) (#\U 2) (#\E 3) (#\O 4))))))
	(if ord ord 0)))

(defun vowel-ord3 (ch)
     (cond ((cadr (assoc ch  '((#\A 0) (#\U 1) (#\O 2)))))
	   (t 1))
	)

(defun char-string (ch)
   (make-array 1 :initial-contents (list ch) :element-type :char))

(defun kana-decimal (num &optional (one t))
   (cond ((< num 0) (concatenate string "mainasu" (kana-decimal (- num))))
	 ((< num 10)
	    (case num
		(0 "rei")
		(1 (if one "ichi" ""))
		(2 "ni")
		(3 "sann")
		(4 "yonn")
		(5 "go")
		(6 "roku")
		(7 "nana")
		(8 "hachi")
		(9 "kyuu")))
	 ((< num 100)
	    (concatenate string (kana-decimal (/ num 10) nil) "juu"
		(if (= (mod num 10) 0) "" (kana-decimal (mod num 10)))))
	 ((< num 1000)
	    (concatenate string (kana-decimal (/ num 100) nil) "hyaku"
		(if (= (mod num 100) 0) "" (kana-decimal (mod num 100)))))
	 ((< num 10000)
	    (concatenate string (kana-decimal (/ num 1000) t) "senn"
		(if (= (mod num 1000) 0) "" (kana-decimal (mod num 1000)))))
	 ((< num 100000)
	    (concatenate string (kana-decimal (/ num 10000) t) "mann"
		(if (= (mod num 10000) 0) "" (kana-decimal (mod num 10000)))))
	 (t  "totemotakusann")
	))

(defun romnum1 (s)
  (let (num (ch (read-char s nil nil)) )
    (if (null ch) (return-from romnum1 ""))
    (while (and ch (digit-char-p ch))
        (push ch num)
	(setq ch (read-char s nil nil)) )
    (if ch (unread-char ch s))
    (romkan (kana-decimal
	(read-from-string (coerce (nreverse num) string)))))  )

(defun romnum (s)	;s is a stream
  (let ((num1) (num2) (ch (read-char s nil nil)) sign r)
    (push (cond ((eql ch #\+) (romkan "purasu"))
	        ((eql ch #\-) (romkan "mainasu"))
	        (t (unread-char ch s) ""))
	  r)
    (push (romnum1 s) r)
    (setq ch (read-char s nil nil))
    (while (eql ch #\.)
	(push (romkan "tenn") r)
	(push (romnum1 s) r)
	(setq ch (read-char s nil nil))
        (print ch)
	)
    (if ch  (unread-char ch s))
    (apply #'concatenate string  (nreverse r))
  ))


(defun romkan (str)
   (catch :kana
   (with-input-from-string (s (string-upcase str))
      (let (ch1 ch2 ch3 k result last-vowel)
        (flet
	   ((nextch () (let ((ch (read-char s nil 'eof)))
		(if (eql ch 'eof)
		    (throw :kana (apply #'concatenate string (nreverse result)))
		    ch)) ) )
	 (while (not (eql (setq ch1 (read-char s nil 'eof)) 'eof))
	    (setq k (assoc ch1
		'((#\A "あ") (#\I "い") (#\E "え") (#\O "お") (#\U "う"))))
	    (cond
	       (k (setq last-vowel ch1) (push (cadr k) result))
	       ((and (eql ch1 #\-) (not (eql (car result) #\space)))
		(push (second (assoc last-vowel 
			'((#\A "あ") (#\I "い") (#\E "え")
			  (#\O "お") (#\U "う"))))
		      result))
	       ((or (eql ch1 #\+) (eql ch1 #\-) (digit-char-p ch1))
		(unread-char ch1 s)
		(push (romnum s) result))
	       ((or (eq ch1 #\') (eq ch1 #\\))
		(push (char-string (nextch)) result))
	       ((not (alpha-char-p ch1)) (push (char-string ch1) result))
	       (t (setq ch2 (nextch))
		  (setq last-vowel ch2)
		  (cond 
		     ((vowelp ch2)
		      (push  (aref kana2 (- ch1 #\A) (vowel-ord ch2)) result))
		     ((eq ch2 #\Y)
			(setq ch3 (nextch))
			(setq last-vowel ch3)
			(push (aref kana-y (- ch1 #\A) (vowel-ord3 ch3)) result))
                     ((and (eq ch1 #\T) (eq ch2 #\S))
			(setq ch3 (nextch))
			(setq last-vowel ch3)
			(push (aref kana-ts (vowel-ord ch3)) result))
		     ((and (eq ch1 #\C) (eq ch2 #\H))
			(setq ch3 (nextch))
			(setq last-vowel ch3)
			(push (aref kana-ch (vowel-ord ch3)) result))
		     ((and (eq ch1 #\S) (eq ch2 #\H))
			(setq ch3 (nextch))
			(setq last-vowel ch3)
			(push (aref kana-sh (vowel-ord ch3)) result))
		     ((and (eq ch1 #\N) (eq  ch2 #\N))
			(push "ん" result))
		     ((and (eq ch1 #\N) (not (vowelp ch2)))
			(unread-char ch2 s)
			(push "ん" result))
		     ((eq ch1 ch2)
			(push "っ" result)
			(unread-char ch2 s))
		     (t 
			(push (make-array 2 :element-type :character
				:initial-contents (list ch1 ch2)) result))
		      )  )
		)) ;; while
	(throw :kana (apply #'concatenate string (nreverse result)))
	) ) )
       ) )

#| #i(50 40 22 22 9 96 2 0 0) |#

(defun romanji-date (month-int day-int week-int &optional (conversion t))
    (format nil "~agatsu~a~ayoubi"
	(if conversion (kana-decimal (1+ month-int)) (1+ month-int))
	(case day-int
		(1 "tsuitachi")		(2 "futsuka")
		(3 "mikka")		(4 "yokka")
		(5 "itsuka")		(6 "muika")
		(7 "nanoka")		(8 "yo-ka")
		(9 "kokonoka")		(10 "to-ka")
		(20 "hatsuka")
		(t  (format nil "~anichi"
			(if conversion 
			    (kana-decimal day-int)
			     day-int))) )
	(elt #("nichi" "getsu" "ka" "sui" "moku" "kinn" "do")
	     week-int))
    )

(defun kana-date (&optional (xtime (unix::localtime)) (conversion t))
   (let ((year-int) (month-int) (day-int) (week-int))
      (if (eql xtime :now) (setq xtime (instance calendar-time :now)))
      (cond ((derivedp xtime calendar-time)
	     (setq year-int (send xtime :year)
		   month-int (send xtime :month)
		   day-int (send xtime :day)
		   week-int (send xtime :weekday)) )
	    ((derivedp xtime vector)
		(setq year-int (aref xtime 5)
		      month-int (aref xtime 4)
		      day-int (aref xtime 3)
		      week-int (aref xtime 6))) 
	    (t (error "time object or vector expected for kana-date"))
	    )
	  #|(year (format nil "19~dnenn " year-int))|#
	(romanji-date month-int day-int week-int)
	)
   )

(defun kana-time (&optional (xtime (unix::localtime)) (conversion nil))
   (if (eql xtime :now) (setq xtime (instance calendar-time :now)))
   (let ((hour-int) (minute-int) (hour12))
      (cond ((derivedp xtime calendar-time)
	     (setq hour-int (send xtime :hour)
		   minute-int (send xtime :minute)))
	    ((derivedp xtime vector)
		(setq hour-int (aref xtime 2)
		      minute-int (aref xtime 1)))
	    (t (error "time object or vector expected for kana-date"))
	    )
       (setq hour12 (if (> hour-int 12) (- hour-int 12) hour-int))
       (format nil  "~a ~aji~a~a"
	   (if (> hour-int 12) "gogo" "gozen")
	   (if conversion (kana-decimal hour12) hour12 )
	   (if conversion (kana-decimal minute-int)  minute-int)
	   (if (member (mod minute-int 10) '(1 3 4 6 8 0)) "punn" "funn"))
	))
        


;;****************************************************************
;; Conversion between Shift-JIS , JIS and EUC
;;****************************************************************

(defun sjis2euc-char (hi low s)
   (if (<= hi #x9f)
	(setq hi
	      (if (< low #x9f) (- (ash hi 1) #xE1) (- (ash hi 1) #xE0)))
	(if (< low #x9f)
	    (setq hi
	          (if (< low #x9f) (- (ash hi 1) #x161) (- (ash hi 1) #x160))))
	)
   (if (< low #x7f)
	(decf low #x1f)
	(if (< low #x9f)
	    (decf low #x20)
	    (decf low #x7e)))
   (write-byte (logior #x80 hi) s)
   (write-byte (logior #x80 low) s))

(defun sjis2euc (instr)
   (with-input-from-string (in instr)
     (with-output-to-string (out)
       (let ((ch1 0) (ch2 0) (eucp nil))
	 (declare (integer ch1 ch2))
	 (while (integerp (setq ch1 (read-char in nil nil)))
	    (cond
		 ((or eucp (< ch1 #x80)) (write-byte ch1 out))
		 ((or (< #x80 ch1 #xA0) (<= #xE0 ch1 #xEF))
		   (setq ch2 (read-char in nil -1))
		   (cond ((and (<= #x40 ch2 #xfc)
				(/= ch2 #x7f))
			  (sjis2euc-char ch1 ch2 out))
			 (t (write-byte ch1 out)
			    (if (/= ch2 -1) (write-byte ch2 out))))
		   )
		 (t (write-byte ch1 out) (setq eucp t)))))	;; this is EUC string!
      (get-output-stream-string out))))

(defun euc2sjis-char (c2 c1 s)
     (setq c2 (logand #x7f c2)
	   c1 (logand #x7f c1))
     ;; The MSB (eighth bit) of c2 and c1 must have been stripped off.
     (write-byte 
           (+ (ash (- c2 1) -1)
	      (if (<= c2 #x5e) #x71 #xb1))
	   s)
     (write-byte 
           (+ c1 
              (if (logtest c2 1)
                  (if (< c1 #x60) #x1f #x20)
                  #x7e))
	   s)
    )

(defun euc2sjis (instr)
   (with-input-from-string (in instr)
     (with-output-to-string (out)
       (let ((ch1 0) (ch2 0))
	 (declare (integer ch1 ch2))
	 (while (integerp (setq ch1 (read-char in nil nil)))
	    (cond ((<= #x81 ch1 #xf0)
		   (setq ch2 (read-char in nil -1))
		   (cond ((<= #x81 ch2 #xfe)
			  (euc2sjis-char ch1 ch2 out))
			 (t (write-byte ch1 out)
			    (if (/= ch2 -1) (write-byte ch2 out))))
		   )
		 (t (write-byte ch1 out)) ) ) )
      (get-output-stream-string out))))
	 
(defun jis2euc (jstr)
   (let ((estr (make-string (length jstr))) (e 0) jch kanji
	 (escape 0) (esc1 0) (esc2 0))
     (flet ((put-estr (ch) (setf (char estr e) ch) (incf e)))
       (dotimes (j (length jstr))
	 (setq jch (char jstr j))
	 (case escape
	  (0 (if (= jch #x1b)
		 (setq escape 1)
		 (put-estr (logior (if kanji #x80 0) jch))))
	  (1 (setq esc1 jch)
	     (if (= jch #\$)
		 (setq escape 2)
		 (if (= jch #\()	;)
		     (setq escape 4)
		     (progn
			   (put-estr #x1b) (put-estr jch)))))
	  (2 (setq esc2 jch)
	     (if (member jch '(#\B #\@))
		 (progn (setq escape 0) (setq kanji t))
		 (progn (put-estr #x1b) (put-estr esc1) (put-estr jch))))
	  (4 (setq esc2 jch)
	     (if (= jch #\J)
		 (progn (setq escape 0) (setq kanji nil))
		 (progn (put-estr #x1b) (put-estr esc1) (put-estr jch))))))
	(subseq estr 0 e))))



;;;; romanji.l
;;;  hiragana/katakana --> roman-ji conversion
;;;  (c) 1999, Toshihiro Matsui, Electrotechnical Laboratory
;;;  kana is always represented by EUC
;;; EUC encoding of hiragana:   #xa4a1 --#xa4f3
;;; EUC encoding of katagana:   #xa5a1 --#xa5f6
;;; Katakana set is larger than Hiragana, because the former includes
;;; "ヶ", "ヵ", and "ヴ".

(defparameter hiragana-aiueo
	 '("あ" "い" "う" "え" "お" "ア" "イ" "ウ" "エ" "オ"))

(defparameter hiragana-small-aiueo
	 '("ぁ" "ぃ" "ぅ" "ぇ" "ぉ" "ァ" "ィ" "ゥ" "ェ" "ォ"))

(defparameter hiragana-small-yayuyo 
	 '("ゃ" "ゅ" "ょ" "ャ" "ュ" "ョ"))

(defparameter hiragana-small-tsu '("っ" "ッ"))

(defparameter hiragana-1 '(
		("あ" "a") ("い" "i") ("う" "u") ("え" "e") ("お" "o")
		("か" "ka") ("き" "ki") ("く" "ku") ("け" "ke") ("こ" "ko")
		("さ" "sa") ("し" "shi") ("す" "su") ("せ" "se") ("そ" "so")
		("た" "ta") ("ち" "chi") ("つ" "tsu") ("て" "te") ("と" "to")
		("な" "na") ("に" "ni") ("ぬ" "nu") ("ね" "ne") ("の" "no")
		("は" "ha") ("ひ" "hi") ("ふ" "fu") ("へ" "he")  ("ほ" "ho")
		("ま" "ma") ("み" "mi") ("む" "mu") ("め" "me") ("も" "mo")
		("や" "ya") ("い" "yi") ("ゆ" "yu") ("え" "ye")  ("よ" "yo")
		("ら" "ra") ("り" "ri") ("る" "ru") ("れ" "re") ("ろ" "ro")
		("わ" "wa") ("ゐ"  "wi") ("う" "wu") ("ゑ" "we") ("を" "wo")
		("が" "ga") ("ぎ" "gi") ("ぐ" "gu")  ("げ" "ge") ("ご" "go")
		("ざ" "za") ("じ" "ji") ("ず" "zu") ("ぜ" "ze") ("ぞ" "zo")
		("だ" "da") ("ぢ" "di") ("づ" "du") ("で" "de") ("ど" "do")
		("ば" "ba") ("び" "bi") ("ぶ" "bu") ("べ" "be") ("ぼ" "bo")
		("ぱ" "pa") ("ぴ" "pi") ("ぷ" "pu") ("ぺ" "pe") ("ぽ" "po")
		("ん" "nn")
		("ぁ" "a") ("ぃ" "i") ("ぅ" "u") ( "ぇ" "e") ("ぉ" "o")
		("ゃ" "ya") ("ゅ" "yu")  ("ょ" "yo")
		("。" ".") ("、" ",") ("「" "\"") ("」" "\"") ("ー" "-")
		;;
		;;カタカナ
		;;
		("ア" "a") ("イ" "i") ("ウ" "u") ("エ" "e") ("オ" "o")
		("カ" "ka") ("キ" "ki") ("ク" "ku") ("ケ" "ke") ("コ" "ko")
		("サ" "sa") ("シ" "shi") ("ス" "su") ("セ" "se")
		;;
		;; sjis code of "so" is #x835c.
		;; Since #x5c represents a backslash used for a single-char escape,
		;; the lisp reader cannot read this string...
		;;  ("ソ" "so")
		;;
		("タ" "ta") ("チ" "chi") ("ツ" "tsu") ("テ" "te") ("ト" "to")
		("ナ" "na") ("ニ" "ni") ("ヌ" "nu") ("ネ" "ne") ("ノ" "no")
		("ハ" "ha") ("ヒ" "hi") ("フ" "fu") ("ヘ" "he")  ("ホ" "ho")
		("マ" "ma") ("ミ" "mi") ("ム" "mu") ("メ" "me") ("モ" "mo")
		("ヤ" "ya") ("ユ" "yu") ("ヨ" "yo")
		("ラ" "ra") ("リ" "ri") ("ル" "ru") ("レ" "re") ("ロ" "ro")
		("ワ" "wa") ("ヰ"  "wi") ("ヱ" "we") ("ヲ" "wo")
		("ガ" "ga") ("ギ" "gi") ("グ" "gu")  ("ゲ" "ge") ("ゴ" "go")
		("ザ" "za") ("ジ" "ji") ("ズ" "zu") ("ゼ" "ze") ("ゾ" "zo")
		("ダ" "da") ("ヂ" "di") ("ヅ" "du") ("デ" "de") ("ド" "do")
		("バ" "ba") ("ビ" "bi") ("ブ" "bu") ("ベ" "be") ("ボ" "bo")
		("パ" "pa") ("ピ" "pi") ("プ" "pu") ("ペ" "pe") ("ポ" "po")
		("ン" "nn")
		("ァ" "a") ("ィ" "i") ("ゥ" "u") ( "ェ" "e") ("ォ" "o")
		("ャ" "ya") ("ュ" "yu")  ("ョ" "yo")
		)
)

(defparameter hiragana-2 '(
	("きゃ" "kya") ("きゅ" "kyu") ("きょ" "kyo")
	("しゃ" "sha")  ("しゅ" "shu")  ("しょ" "sho") 
	("ちゃ""cha")  ("ちゅ" "chu")  ("ちょ" "cho") 
	("にゃ" "nya")  ("にゅ" "nyu")  ("にょ" "nyo") 
	("ひゃ" "hya")  ("ひゅ" "hyu")  ("ひょ" "hyo") 
	("みゃ" "mya")  ("みゅ" "myu")  ("みょ" "myo") 
	("りゃ" "rya")  ("りゅ" "ryu")  ("りょ" "ryo") 
	("ぎゃ" "gya")  ("ぎゅ" "gyu")  ("ぎょ" "gyo") 
	("じゃ" "ja")  ("じゅ" "ju")  ("じょ" "jo") 
	("ぢゃ" "dya")  ("ぢゅ" "dyu")  ("ぢょ" "dyo") 
	("ぴゃ" "pya")  ("ぴゅ" "pyu")  ("ぴょ" "pyo") 
	("でゅ" "dyu") ("てゅ" "tyu")
	;;
	("キャ" "kya") ("キュ" "kyu") ("キョ" "kyo")
	("シャ" "sha")  ("シュ" "shu")  ("ショ" "sho") 
	("チャ""cha")  ("チュ" "chu")  ("チョ" "cho") 
	("ニャ" "nya")  ("ニュ" "nyu")  ("ニョ" "nyo") 
	("ヒャ" "hya")  ("ヒュ" "hyu")  ("ヒョ" "hyo") 
	("ミャ" "mya")  ("ミュ" "myu")  ("ミョ" "myo") 
	("リャ" "rya")  ("リュ" "ryu")  ("リョ" "ryo") 
	("ギャ" "gya")  ("ギュ" "gyu")  ("ギョ" "gyo") 
	("ジャ" "ja")  ("ジュ" "ju")  ("ジョ" "jo") 
	("ヂャ" "dya")  ("ヂュ" "dyu")  ("ヂョ" "dyo") 
	("ピャ" "pya")  ("ピュ" "pyu")  ("ピョ" "pyo") 
	("デュ" "dyu") ("テュ" "tyu")
	))

(defparameter hiragana-3 '(
	("てぃ" "ti" ) ("でぃ" "di" )
	("とぅ" "tu" ) ("どぅ" "du" )
	("ふぁ" "fa" ) ("ふぃ" "fi" ) ("ふぇ" "fe" ) ("ふぉ" "fo" )
	("うぃ" "ui" ) ("うぇ" "ue" ) ("うぉ" "uo" )
	("ちぇ" "che" )
	("つぁ" "tsa" ) ("つぃ" "tsi" ) ("つぇ" "tse" ) ("つぉ" "tso" )
	("しぇ" "she" )
	("くぁ" "kua" ) ("くぃ" "kui" ) ("くぇ" "kue" ) ("くぉ" "kuo" )
	("じぇ" "je" )
	;;;
	("ティ" "ti" ) ("ディ" "di" )
	("トゥ" "tu" ) ("ドゥ" "du" )
	("ファ" "fa" ) ("フィ" "fi" ) ("フェ" "fe" ) ("フォ" "fo" )
	("ウィ" "ui" ) ("ウェ" "ue" ) ("ウォ" "uo" )
	("チェ" "che" )
	("ツァ" "tsa" ) ("ツィ" "tsi" ) ("ツェ" "tse" ) ("ツォ" "tso" )
	("シェ" "she" )
	("クァ" "kua" ) ("クィ" "kui" ) ("クェ" "kue" ) ("クォ" "kuo" )
	("ジェ" "je" )
	))
;;("-"  )


(defun romanji (kanastring)	;; kana --> Roman-ji
   (prog ((result) (kstream (make-string-input-stream kanastring))
	  (ch1) (ch2) (ch3) (ch4)
	  (kstr1 "  ") (kstr2 "    ") (roman)
	  (i 0) (len (length kanastring)))
      :begin
      (when (>= i len)
	 (return (apply #'concatenate string (nreverse result) )))
      (setq ch1 (aref kanastring i))
      (when (< ch1 #x80)	;; ascii?
	 (push (coerce (list ch1) string) result)
	 (incf i)
	 (go :begin))
      (setq ch2 (if (< (1+ i) len) (aref kanastring (1+ i)) #\space))
      (setq ch3 (if (< (+ i 2) len) (aref kanastring (+ i 2)) #\space))
      (setq ch4 (if (< (+ i 3) len) (aref kanastring (+ i 3)) #\space))
      (setf (aref kstr1 0) ch3 (aref kstr1 1) ch4)
	;;  きゃ、きゅ、きょ
      (setf (aref kstr2 0) ch1 (aref kstr2 1) ch2
	    (aref kstr2 2) ch3 (aref kstr2 3) ch4)
      (when (member kstr1 hiragana-small-yayuyo :test #'equal)
	  (setq roman (member kstr2 hiragana-2 :test #'equal :key #'car))
	  (push (second (first roman)) result)
	  (incf i 4)
	  (go :begin))
	;; てぃ、ちぇ
      (when (member kstr1 hiragana-small-aiueo :test #'equal)
	  (setq roman (member kstr2 hiragana-3 :test #'equal :key #'car))
	  (push (second (first roman)) result)
	  (incf i 4)
	  (go :begin))
      (setf (aref kstr1 0) ch1 (aref kstr1 1) ch2)
	;;(print kstr1)
	;; っおぃ
      (when (member kstr1 hiragana-small-tsu :test #'equal)
	 (setf (aref kstr1 0) ch3 (aref kstr1 1) ch4)
	 (setq roman (second (first
			 (member kstr1 hiragana-1 :key #'car :test #'equal))))
	 (push (coerce (list (aref roman 0)) string) result)
	 ;; (push roman result)
	 (incf i 2)
	 (go :begin))
      (if (setq roman (member kstr1 hiragana-1 :key #'car :test #'equal))
	  (push (second (first roman)) result))
      :next
      (incf i 2)
      (go :begin)))


(defun hira2kata (hirastr)
   (let* ((len (length hirastr))  (ch1) (ch2) (k 0)
	  (katastr (make-string len))) 
      (while (< k len)
	 (setq ch1 (aref hirastr k))
	 (cond ((logtest ch1 #x80)	;; 2-byte code
		(if (= ch1 #xA4) (setq ch1 #xA5))
		(setf (aref katastr k) ch1
		      (aref katastr (incf k)) (aref hirastr k)))
	       (t (setf (aref katastr k) ch1)) )
	 (incf k))
      katastr))

(defun kata2hira (katastr)
   (let* ((len (length katastr))  (ch1) (ch2) (k 0)
	  (hirastr (make-string len))) 
      (while (< k len)
	 (setq ch1 (aref katastr k))
	 (cond ((logtest ch1 #x80)	;; 2-byte code
		(if (= ch1 #xA5) (setq ch1 #xA4))
		(setf (aref hirastr k) ch1
		      (aref hirastr (incf k)) (aref katastr k)))
	       (t (setf (aref hirastr k) ch1)) )
	 (incf k))
      hirastr))
	        


;;(romanji "わたしは123まついです。abcひゅうるいちぇんぐふぁつぉでゅ")

(setq euc-space (make-string 2))
	(setf (char euc-space 0) #xa1)
	(setf (char euc-space 1) #xa1)

(defun string-match-at (pattern target pos)
   (let ((plen (length pattern)))
      (dotimes (i plen)
	 (if (not (eq (aref pattern i) (aref target (+ pos i))))
	     (return-from string-match-at nil)))
      t))

(defun string-match (pattern target &optional (start 0))
    (dotimes (i (- (length target) (length pattern) start -1))
	  (if (string-match-at pattern target (+ i start))
	      (return-from string-match (+ i start))))
       nil)

(defun euc-string-trim (euc-str target)
   (let ((first-byte (aref euc-str 0)) (second-byte (aref euc-str 1))
	 (x 0) (end (length target))
	 (out 0)
	 (trimmed (make-string (length target))))
      (while (< x end)
	 (if (> (aref target x) 128)
	     (if (or (/= first-byte (char target x))
		       (/= second-byte (char target (1+ x))))
		 (setf (char trimmed out) (char target x)
		       (char trimmed (1+ out)) (char target (1+ x))
			out (+ out 2) 
			x (+ x 2))
		 (setf x (+ 2 x)))	;;skip it!
	     (setf (char trimmed out) (char target x)
		   out (1+ out) x (1+ x))))
      (subseq trimmed 0 out)))

(defun euc-digit (estr pos)
   (let  ((first (char estr pos)))
      (cond ((<= #\0 first #\9) (- first #\0))
	    ((and (eq first #xa3)
		  (<= #xb0 (char estr (1+ pos)) #xb9))
	     (- (char estr (1+ pos)) #xb0)))))

(defun euc-number (estr)
   (let ((len (length estr)) (val 0) (x) (p 0) (sign 1))
      (while (< p len)
	;; skip blanks
	(cond ((eq (char estr p) #\space) (incf p))
	      ((and (eq (char estr p) #xa0) (eq (char estr (1+ p)) #xa0))
		(incf p 2))
	      ((euc-digit estr p)    (return))
	      (t (return))))
      (cond ((eq (char estr p) #\-) (setq sign -1) (incf p))
	    ((equal (subseq estr p (+ p 2)) "ー")
		(setq sign -1) (incf p 2))
	    ((equal (subseq estr p (+ p 8)) "マイナス")
		(setq sign -1) (incf p 8)) )
      (while (< p len)
	(if (setq x (euc-digit estr p))
	    (setq val (+ (* val 10) x))
	    (return-from euc-number (* sign val)))
	(incf p 2))
      (* sign val)))




(provide :romkan "#(@)$Id$")


