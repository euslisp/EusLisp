;;; -*- lisp -*-
;;; $Header: /home/cvs/euslisp/opengl/src/tkconst.l,v 1.1.1.1 2003/11/20 07:46:33 eus Exp $
;;; tkconst.l

(provide :tkconst)

(eval-when (compile eval)
   (unless (find-package "GL")
        (make-package "GL") ) )

(in-package "GL")

;;;
;;; Nano Window Toolkit.
;;;

(export '(TK_RGB
	  TK_INDEX
	  TK_SINGLE
	  TK_DOUBLE
	  TK_DIRECT
	  TK_INDIRECT
	  TK_ACCUM
	  TK_ALPHA
	  TK_DEPTH
	  TK_OVERLAY
	  TK_UNDERLAY
	  TK_STENCIL
	  TK_USE_ID
	  TK_EXACT_MATCH
	  TK_MINIMUM_CRITERIA
	  TK_X_DISPLAY
	  TK_X_WINDOW
	  TK_X_SCREEN
	  TK_LEFTBUTTON
	  TK_RIGHTBUTTON
	  TK_MIDDLEBUTTON
	  TK_SHIFT
	  TK_CONTROL
	  TK_RETURN
	  TK_ESCAPE
	  TK_SPACE
	  TK_LEFT
	  TK_UP
	  TK_RIGHT
	  TK_DOWN
	  TK_A
	  TK_B
	  TK_C
	  TK_D
	  TK_E
	  TK_F
	  TK_G
	  TK_H
	  TK_I
	  TK_J
	  TK_K
	  TK_L
	  TK_M
	  TK_N
	  TK_O
	  TK_P
	  TK_Q
	  TK_R
	  TK_S
	  TK_T
	  TK_U
	  TK_V
	  TK_W
	  TK_X
	  TK_Y
	  TK_Z
	  TK_la
	  TK_lb
	  TK_lc
	  TK_ld
	  TK_le
	  TK_lf
	  TK_lg
	  TK_lh
	  TK_li
	  TK_lj
	  TK_lk
	  TK_ll
	  TK_lm
	  TK_ln
	  TK_lo
	  TK_lp
	  TK_lq
	  TK_lr
	  TK_ls
	  TK_lt
	  TK_lu
	  TK_lv
	  TK_lw
	  TK_lx
	  TK_ly
	  TK_lz
	  TK_0
	  TK_1
	  TK_2
	  TK_3
	  TK_4
	  TK_5
	  TK_6
	  TK_7
	  TK_8
	  TK_9
	  TK_BLACK
	  TK_RED
	  TK_GREEN
	  TK_YELLOW
	  TK_BLUE
	  TK_MAGENTA
	  TK_CYAN
	  TK_WHITE
	  ))

;;;
;;; Window Types
;;;

(defconstant TK_RGB 		0)
(defconstant TK_INDEX 		1)
(defconstant TK_SINGLE 		0)
(defconstant TK_DOUBLE 		2)
(defconstant TK_DIRECT 		0)
(defconstant TK_INDIRECT 	4)
(defconstant TK_ACCUM 		8)
(defconstant TK_ALPHA 		16)
(defconstant TK_DEPTH 		32)
(defconstant TK_OVERLAY 	64)
(defconstant TK_UNDERLAY 	128)
(defconstant TK_STENCIL 	512)

;;;
;;; Display Mode Selection Criteria
;;;

(defconstant TK_USE_ID 			1)
(defconstant TK_EXACT_MATCH 		2)
(defconstant TK_MINIMUM_CRITERIA 	3)

;;; 
;;; Window Masks
;;;

(defmacro TK_IS_RGB(x)		`(zerop (logand ,x TK_INDEX)))
(defmacro TK_IS_INDEX(x)	`(not (zerop (logand ,x TK_INDEX))))
(defmacro TK_IS_SINGLE(x)	`(zerop (logand ,x TK_DOUBLE)))
(defmacro TK_IS_DOUBLE(x)	`(not (zerop (logand ,x TK_DOUBLE))))
(defmacro TK_IS_DIRECT(x)	`(zerop (logand ,x TK_INDIRECT)))
(defmacro TK_IS_INDIRECT(x)	`(not (zerop (logand ,x TK_INDIRECT))))
(defmacro TK_HAS_ACCUM(x)	`(not (zerop (logand ,x TK_ACCUM))))
(defmacro TK_HAS_ALPHA(x)	`(not (zerop (logand ,x TK_ALPHA))))
(defmacro TK_HAS_DEPTH(x)	`(not (zerop (logand ,x TK_DEPTH))))
(defmacro TK_HAS_OVERLAY(x)	`(not (zerop (logand ,x TK_OVERLAY))))
(defmacro TK_HAS_UNDERLAY(x)	`(not (zerop (logand ,x TK_UNDERLAY))))
(defmacro TK_HAS_STENCIL(x)	`(not (zerop (logand ,x TK_STENCIL))))

;;;
;;; Windowing System Specific Gets
;;;

(defconstant TK_X_DISPLAY 1)
(defconstant TK_X_WINDOW  2)
(defconstant TK_X_SCREEN  3)

;;;
;;; Event Status
;;;

(defconstant	TK_LEFTBUTTON		1)
(defconstant	TK_RIGHTBUTTON		2)
(defconstant	TK_MIDDLEBUTTON		4)
(defconstant	TK_SHIFT		1)
(defconstant	TK_CONTROL		2)

;;; 
;;; Key Codes
;;;

(defconstant TK_RETURN 		        #x0D)
(defconstant TK_ESCAPE 		        #x1B)
(defconstant TK_SPACE 		        #x20)
(defconstant TK_LEFT 			#x25)
(defconstant TK_UP 			#x26)
(defconstant TK_RIGHT     		#x27)
(defconstant TK_DOWN 			#x28)
(defconstant TK_A 			#\A)
(defconstant TK_B 			#\B)
(defconstant TK_C 			#\C)
(defconstant TK_D 			#\D)
(defconstant TK_E 			#\E)
(defconstant TK_F 			#\F)
(defconstant TK_G 			#\G)
(defconstant TK_H 			#\H)
(defconstant TK_I 			#\I)
(defconstant TK_J 			#\J)
(defconstant TK_K 			#\K)
(defconstant TK_L 			#\L)
(defconstant TK_M 			#\M)
(defconstant TK_N 			#\N)
(defconstant TK_O 			#\O)
(defconstant TK_P 			#\P)
(defconstant TK_Q 			#\Q)
(defconstant TK_R 			#\R)
(defconstant TK_S 			#\S)
(defconstant TK_T 			#\T)
(defconstant TK_U 			#\U)
(defconstant TK_V 			#\V)
(defconstant TK_W 			#\W)
(defconstant TK_X 			#\X)
(defconstant TK_Y 			#\Y)
(defconstant TK_Z 			#\Z)
(defconstant TK_la 			#\a)
(defconstant TK_lb 			#\b)
(defconstant TK_lc 			#\c)
(defconstant TK_ld 			#\d)
(defconstant TK_le 			#\e)
(defconstant TK_lf 			#\f)
(defconstant TK_lg 			#\g)
(defconstant TK_lh 			#\h)
(defconstant TK_li 			#\i)
(defconstant TK_lj 			#\j)
(defconstant TK_lk 			#\k)
(defconstant TK_ll 			#\l)
(defconstant TK_lm 			#\m)
(defconstant TK_ln 			#\n)
(defconstant TK_lo 			#\o)
(defconstant TK_lp 			#\p)
(defconstant TK_lq 			#\q)
(defconstant TK_lr 			#\r)
(defconstant TK_ls 			#\s)
(defconstant TK_lt 			#\t)
(defconstant TK_lu 			#\u)
(defconstant TK_lv 			#\v)
(defconstant TK_lw 			#\w)
(defconstant TK_lx 			#\x)
(defconstant TK_ly 			#\y)
(defconstant TK_lz 			#\z)
(defconstant TK_0 			#\0)
(defconstant TK_1 			#\1)
(defconstant TK_2 			#\2)
(defconstant TK_3 			#\3)
(defconstant TK_4 			#\4)
(defconstant TK_5 			#\5)
(defconstant TK_6 			#\6)
(defconstant TK_7 			#\7)
(defconstant TK_8 			#\8)
(defconstant TK_9 			#\9)

;;;
;;; Color Macros
;;;

(defconstant TK_BLACK    0)
(defconstant TK_RED      1)
(defconstant TK_GREEN    2)
(defconstant TK_YELLOW   3)
(defconstant TK_BLUE     4)
(defconstant TK_MAGENTA  5)
(defconstant TK_CYAN     6)
(defconstant TK_WHITE    7)

;; extern float tkRGBMap[8][3];
;;
;;; #define TK_SETCOLOR(x, y) (TK_IS_RGB((x)) ? glColor3fv(tkRGBMap[(y)]) : glIndexf((y)))
;(defmacro TK_SETCOLOR (x y) `(if (TK_IS_RGB ,x) (glColor3fv tkRGBMap[(,y)]) (glIndexf ,y)))

;;;
;;; RGB Image Structure
;;;

(defcstruct TK_RGBImageRec 
  (sizeX :integer)
  (sizeY :integer)
  (data :char *))
