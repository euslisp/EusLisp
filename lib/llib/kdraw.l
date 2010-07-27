;;;
;;;	Kdraw primitives by M.Inaba 1991.9.3
;;;                (Add line type, arrow, MLine by N.Sawasaki 5 Sep. 1991)
;;;                (Add Poly, Elli, BSpl, CBSpl, Rect, pattern
;;;                                             by N.Sawasaki 6 Sep. 1991)
;;;                (Add Coordinate Transfomation by N.Sawasaki 7 Sep. 1991)
;;;
(defclass kdraw-viewsurface
  :super viewsurface
  :slots (color strm fname
	  linestyle	;0=solid, 1=dashed
	  linewidth	;1=thin  2,5= thick
	  )  )

(defmethod kdraw-viewsurface
  (:init (&rest args
		&key ((:color c) 0)
		((:fname f) "kdrawout.eps")
		&allow-other-keys)
	 (setq fname f)
	 (setq color c
	       linewidth 1
	       linestyle 0)
	 (send self :open fname)
	 self)
  (:open (&optional (f fname))
    (setq strm (open fname :direction :output))
    (setq *kdraw* strm)
    (setq *kdraw-coord* (list (unit-matrix 2) (float-vector 100 500))
	  *kdraw-coord-string* "[1 0 0 1 100 500 ]"
	  *kdraw-default-coord* *kdraw-coord*
	  *kdraw-default-coord-string* *kdraw-coord*)    ;; added by N.S
    (format strm
"%!PS-Adobe-2.0 EPSF-1.2
%%DocumentFonts:
%%Pages: 1
%%BoundingBox: 100 434 212 593
%%EndComments

50 dict begin

/arrowHeight 8 def
/arrowWidth 4 def
/none null def
/numGraphicParameters 17 def
/stringLimit 65535 def

/Begin {
save
numGraphicParameters dict begin
} def

/End {
end
restore
} def

/SetB {
dup type /nulltype eq {
pop
false /brushRightArrow idef
false /brushLeftArrow idef
true /brushNone idef
} {
/brushDashOffset idef
/brushDashArray idef
0 ne /brushRightArrow idef
0 ne /brushLeftArrow idef
/brushWidth idef
false /brushNone idef
} ifelse
} def

/SetCFg {
/fgblue idef
/fggreen idef
/fgred idef
} def

/SetCBg {
/bgblue idef
/bggreen idef
/bgred idef
} def

/SetF {
/printSize idef
/printFont idef
} def

/SetP {
dup type /nulltype eq {
pop true /patternNone idef
} {
/patternGrayLevel idef
patternGrayLevel -1 eq {
/patternString idef
} if
false /patternNone idef
} ifelse
} def

/BSpl {
0 begin
storexyn
newpath
n 1 gt {
0 0 0 0 0 0 1 1 true subspline
n 2 gt {
0 0 0 0 1 1 2 2 false subspline
1 1 n 3 sub {
/i exch def
i 1 sub dup i dup i 1 add dup i 2 add dup false subspline
} for
n 3 sub dup n 2 sub dup n 1 sub dup 2 copy false subspline
} if
n 2 sub dup n 1 sub dup 2 copy 2 copy false subspline
patternNone not brushLeftArrow not brushRightArrow not and and { ifill } if
brushNone not { istroke } if
0 0 1 1 leftarrow
n 2 sub dup n 1 sub dup rightarrow
} if
end
} dup 0 4 dict put def

/Circ {
newpath
0 360 arc
patternNone not { ifill } if
brushNone not { istroke } if
} def

/CBSpl {
0 begin
dup 2 gt {
storexyn
newpath
n 1 sub dup 0 0 1 1 2 2 true subspline
1 1 n 3 sub {
/i exch def
i 1 sub dup i dup i 1 add dup i 2 add dup false subspline
} for
n 3 sub dup n 2 sub dup n 1 sub dup 0 0 false subspline
n 2 sub dup n 1 sub dup 0 0 1 1 false subspline
patternNone not { ifill } if
brushNone not { istroke } if
} {
Poly
} ifelse
end
} dup 0 4 dict put def


/RRect { CBSpl } def

/Elli {
0 begin
newpath
4 2 roll
translate
scale
0 0 1 0 360 arc
patternNone not { ifill } if
brushNone not { istroke } if
end
} dup 0 1 dict put def

/Line {
0 begin
2 storexyn
newpath
x 0 get y 0 get moveto
x 1 get y 1 get lineto
brushNone not { istroke } if
0 0 1 1 leftarrow
0 0 1 1 rightarrow
end
} dup 0 4 dict put def

/MLine {
0 begin
storexyn
newpath
n 1 gt {
x 0 get y 0 get moveto
1 1 n 1 sub {
/i exch def
x i get y i get lineto
} for
patternNone not brushLeftArrow not brushRightArrow not and and { ifill } if
brushNone not { istroke } if
0 0 1 1 leftarrow
n 2 sub dup n 1 sub dup rightarrow
} if
end
} dup 0 4 dict put def

/Poly {
3 1 roll
newpath
moveto
-1 add
{ lineto } repeat
closepath
patternNone not { ifill } if
brushNone not { istroke } if
} def

/Rect {
0 begin
/t exch def
/r exch def
/b exch def
/l exch def
newpath
l b moveto
l t lineto
r t lineto
r b lineto
closepath
patternNone not { ifill } if
brushNone not { istroke } if
end
} dup 0 4 dict put def

/WhiteBg 1 def
/HollowBg 0 def
/Text { ishow } def

/idef {
dup where { pop pop pop } { exch def } ifelse
} def

/ifill {
0 begin
gsave
patternGrayLevel -1 ne {
fgred bgred fgred sub patternGrayLevel mul add
fggreen bggreen fggreen sub patternGrayLevel mul add
fgblue bgblue fgblue sub patternGrayLevel mul add setrgbcolor
eofill
} {
eoclip
originalCTM setmatrix
pathbbox /t exch def /r exch def /b exch def /l exch def
/w r l sub ceiling cvi def
/h t b sub ceiling cvi def
/imageByteWidth w 8 div ceiling cvi def
/imageHeight h def
bgred bggreen bgblue setrgbcolor
eofill
fgred fggreen fgblue setrgbcolor
w 0 gt h 0 gt and {
l b translate w h scale
w h true [w 0 0 h neg 0 h] { patternproc } imagemask
} if
} ifelse
grestore
end
} dup 0 8 dict put def

/istroke {
gsave
brushDashOffset -1 eq {
[] 0 setdash
1 setgray
} {
brushDashArray brushDashOffset setdash
fgred fggreen fgblue setrgbcolor
} ifelse
brushWidth setlinewidth
originalCTM setmatrix
stroke
grestore
} def
")
(format strm 
"/ishow {
0 begin
gsave
fgred fggreen fgblue setrgbcolor
WhiteBg eq /drawBg exch def
/fontDict printFont findfont printSize scalefont dup setfont def
/descender fontDict /FontBBox known {
fontDict begin 0 [FontBBox] 1 get FontMatrix end
transform exch pop } { 0 } ifelse def
/vertoffset 0 descender sub printSize sub printFont /Courier ne
printFont /Courier-Bold ne and { 1 add } if def {
drawBg {
gsave matrix setmatrix
newpath 0 vertoffset moveto
dup true charpath pathbbox
grestore exch pop 1 index sub exch 0 exch newpath moveto
/tH exch def pop
0 tH rlineto
dup stringwidth pop 0 rlineto
0 0 tH sub rlineto
closepath
currentgray
1 setgray fill
setgray } if
0 vertoffset moveto show
/vertoffset vertoffset printSize sub def
} forall
grestore
end
} dup 0 5 dict put def

/patternproc {
0 begin
/patternByteLength patternString length def
/patternHeight patternByteLength 8 mul sqrt cvi def
/patternWidth patternHeight def
/patternByteWidth patternWidth 8 idiv def
/imageByteMaxLength imageByteWidth imageHeight mul
stringLimit patternByteWidth sub min def
/imageMaxHeight imageByteMaxLength imageByteWidth idiv patternHeight idiv
patternHeight mul patternHeight max def
/imageHeight imageHeight imageMaxHeight sub store
/imageString imageByteWidth imageMaxHeight mul patternByteWidth add string def
0 1 imageMaxHeight 1 sub {
/y exch def
/patternRow y patternByteWidth mul patternByteLength mod def
/patternRowString patternString patternRow patternByteWidth getinterval def
/imageRow y imageByteWidth mul def
0 patternByteWidth imageByteWidth 1 sub {
/x exch def
imageString imageRow x add patternRowString putinterval
} for
} for
imageString
end
} dup 0 12 dict put def

/min {
dup 3 2 roll dup 4 3 roll lt { exch } if pop
} def

/max {
dup 3 2 roll dup 4 3 roll gt { exch } if pop
} def

/arrowhead {
0 begin
transform originalCTM itransform
/taily exch def
/tailx exch def
transform originalCTM itransform
/tipy exch def
/tipx exch def
/dy tipy taily sub def
/dx tipx tailx sub def
/angle dx 0 ne dy 0 ne or { dy dx atan } { 90 } ifelse def
gsave
originalCTM setmatrix
tipx tipy translate
angle rotate
newpath
0 0 moveto
arrowHeight neg arrowWidth 2 div lineto
arrowHeight neg arrowWidth 2 div neg lineto
closepath
patternNone not {
originalCTM setmatrix
/padtip arrowHeight 2 exp 0.25 arrowWidth 2 exp mul add sqrt brushWidth mul
arrowWidth div def
/padtail brushWidth 2 div def
tipx tipy translate
angle rotate
padtip 0 translate
arrowHeight padtip add padtail add arrowHeight div dup scale
arrowheadpath
ifill
} if
brushNone not {
originalCTM setmatrix
tipx tipy translate
angle rotate
arrowheadpath
istroke
} if
grestore
end
} dup 0 9 dict put def

/arrowheadpath {
newpath
0 0 moveto
arrowHeight neg arrowWidth 2 div lineto
arrowHeight neg arrowWidth 2 div neg lineto
closepath
} def

/leftarrow {
0 begin
y exch get /taily exch def
x exch get /tailx exch def
y exch get /tipy exch def
x exch get /tipx exch def
brushLeftArrow { tipx tipy tailx taily arrowhead } if
end
} dup 0 4 dict put def

/rightarrow {
0 begin
y exch get /tipy exch def
x exch get /tipx exch def
y exch get /taily exch def
x exch get /tailx exch def
brushRightArrow { tipx tipy tailx taily arrowhead } if
end
} dup 0 4 dict put def

/midpoint {
0 begin
/y1 exch def
/x1 exch def
/y0 exch def
/x0 exch def
x0 x1 add 2 div
y0 y1 add 2 div
end
} dup 0 4 dict put def

/thirdpoint {
0 begin
/y1 exch def
/x1 exch def
/y0 exch def
/x0 exch def
x0 2 mul x1 add 3 div
y0 2 mul y1 add 3 div
end
} dup 0 4 dict put def

/subspline {
0 begin
/movetoNeeded exch def
y exch get /y3 exch def
x exch get /x3 exch def
y exch get /y2 exch def
x exch get /x2 exch def
y exch get /y1 exch def
x exch get /x1 exch def
y exch get /y0 exch def
x exch get /x0 exch def
x1 y1 x2 y2 thirdpoint
/p1y exch def
/p1x exch def
x2 y2 x1 y1 thirdpoint
/p2y exch def
/p2x exch def
x1 y1 x0 y0 thirdpoint
p1x p1y midpoint
/p0y exch def
/p0x exch def
x2 y2 x3 y3 thirdpoint
p2x p2y midpoint
/p3y exch def
/p3x exch def
movetoNeeded { p0x p0y moveto } if
p1x p1y p2x p2y p3x p3y curveto
end
} dup 0 17 dict put def
")
(format strm
"/storexyn {
/n exch def
/y n array def
/x n array def
n 1 sub -1 0 {
/i exch def
y i 3 2 roll put
x i 3 2 roll put
} for
} def

%%EndProlog

%I Idraw 9 Grid 8 

%%Page: 1 1

Begin
%I b u
%I cfg u
%I cbg u
%I f u
%I k u
%I p u
%I t
[ 0.8 0 0 0.8 0 0 ] concat
/originalCTM matrix currentmatrix def
"))
  (:close ()
     (format strm "~%End %I eop~%showpage~%%%Trailer~%end~%~%")
     (close strm) )
  (:set-erase-mode ())
  (:set-show-mode ())
  (:clear ()
	  (send self :close)
	  (send self :open fname))
  (:flush () t)
  (:line-width (width) (setq linewidth width))
  (:line-style (dash) (setq linestyle  dash))
  (:color (c) (setq color c))
  (:drawline-primitive  (x0 y0 x1 y1 &optional color)
	  (format strm "Begin %I Line~%")
	  (format strm "%I b ~d~%"
		  (if (eql linestyle 1) 13107 65535))
	  (format strm "~d 0 0" linewidth)
	  (if (eql linestyle 0)
        	  (format strm "[] 0 SetB~%")
        	  (format strm "[2 2 2 2 2 2 2 2] 15 SetB~%"))
	  (format strm "%I cfg Black~%")
	  (format strm "0 0 0 SetCFg~%")
	  (format strm "%I cbg White~%")
	  (format strm "1 1 1 SetCBg~%")
	  (format strm "%I p~%")
;;;	  (format strm "3.36312e-44 SetP~%")
	(format strm "< ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff
 ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff
 ffffffff ffffffff ffffffff ffffffff > -1 SetP~%")
	  (format strm "%I t~%")
	  (format strm "[ 1 0 0 1 102 188 ] concat~%")
	  (format strm "%I~%")
	  (format strm "~a ~a ~a ~a Line~%"
		;;   x0 y0 x1 y1
		   (round x0) (round y0) (round x1) (round y1)
		)
	  (format strm "End~%") )
  (:begin-pict ()
     (format strm "
	Begin %I Pict
	%I b u
	%I cfg u
	%I cbg u
	%I f u
	%I k u
	%I p u
	%I t u~%") )
  (:end-pict () (format strm "End %I eop~%"))
  )

;;;

(defmacro kdraw (fname  &rest forms)
  (let (vr)
;;    (if (derivedp (car forms) viewer)   ;; Rewrite by I.Hara at 93/12/14
    (if (derivedp (eval (car forms)) viewer)
	(setq vr (car forms)
	      forms (cdr forms))
	(setq vr *viewer*))
    `(let ((*viewer*
	      (instance viewer :init 
		  :viewing (send ,vr :viewing)
		  :viewport 
			(instance viewport  :init 
			    :width 600 :height 600	;512*1/72" 
			    :xcenter 300 :ycenter 300)
		  :viewsurface
			(instance kdraw-viewsurface :init :fname ,fname))))
	(send *viewer* :viewsurface :begin-pict)
	(progn . ,forms)
	(send *viewer* :viewsurface :end-pict)
	(send *viewer* :viewsurface :close))
     ))


;;
;;
;;
(defun kdraw-check-linetype (type)
  (cond
   ((consp type)
    (cond
     ((eq (first type) 'norm)
      (cond
       ((eq (second type) 'bold1) '(65535 2 "[]" 0))
       ((eq (second type) 'bold2) (list 65535 5 "[]" 0))))
     ((eq (first type) 'dotted)
      (cond
       ((eq (second type) 'bold1) '(13107 2 "[2 2 2 2 2 2 2 2]" 15))
       ((eq (second type) 'bold1aux) '(13107 2 "[2 2 2 2 2 2 2 2]" 15))
       ((eq (second type) 'bold2) (list 13107 5 "[8 8]" 17))))))
   ((eq type 'dotted) '(13107 1 "[2 2 2 2 2 2 2 2]" 15))
   (t '(65535 1 "[]" 0)))
  )
;;
(defun kdraw-check-arrow (arrow)
  (cond
   ((eq arrow 'start) '(1 0))
   ((eq arrow 'end) '(0 1))
   ((eq arrow 'both) '(1 1))
   (t '(0 0)))
  )
;;
(defun kdraw-set-pattern  (pattern strm &optional arrow)
  (cond
   ((or (null arrow) (eq arrow 'none))
    (cond
     ((and (>= pattern 0) (<= pattern 1))
      (format strm "%I p~%")
      (format strm "~a SetP~%" pattern))
     (t (format strm "none SetP %I p n~%"))))
   (t (format strm "%I p~%")
      (format strm "0 SetP~%")))
  )
;;
(defun kdraw-make-coord (&key (xscale 1)
			      (yscale 1)
			      (rot 0.0)
			      (offset (float-vector 0 0))
			      (inv nil))
  (let* ((smat (make-matrix 2 2))
	 (rmat (make-matrix 2 2))
	 (theta (deg2rad rot))
	 (sin (sin theta))
	 (cos (cos theta)))
    (setf (aref smat 0 0) xscale)
    (setf (aref smat 1 1) yscale)
    (setf (aref rmat 0 0) cos)
    (setf (aref rmat 0 1) sin)
    (setf (aref rmat 1 0) (- sin))
    (setf (aref rmat 1 1) cos)
    (cond
     (inv (list (m* rmat smat) offset))
     (t (list (m* smat rmat) offset))))
  )
;;
(defun kdraw-make-trans-string (tcoord)
  (cond
   ((null tcoord) *kdraw-coord-string*)
   (t (make-coord-string (m* (first *kdraw-coord*) (first tcoord))
			 (v+ (second *kdraw-coord*) (second tcoord)))))
  )
;;
(defun kdraw-line (p0 p1 &key (type 'norm)
		      (arrow 'none)
		      (xscale 1)
		      (yscale 1)
		      (rot 0.0)
		      (offset (float-vector 0 0))
		      (inv nil)
		      (trans-coord nil)
		      ((:stream strm) *kdraw*))
  (let ((adata (kdraw-check-arrow arrow))
	(tdata (kdraw-check-linetype type)))
    (format strm "Begin %I Line~%")
    (format strm "%I b ~a~%" (first tdata))
    (format strm "~a ~a ~a ~a ~a SetB~%"
	    (second tdata) (first adata) (second adata) (third tdata) (fourth tdata))
    (format strm "%I cfg Black~%")
    (format strm "0 0 0 SetCFg~%")
    (format strm "%I cbg White~%")
    (format strm "1 1 1 SetCBg~%")
    (format strm "%I p~%")
    (format strm "3.36312e-44 SetP~%")
    (format strm "%I t~%")
    (if (null trans-coord)
	(setq trans-coord (kdraw-make-coord :xscale xscale
					    :yscale yscale
					    :rot rot
					    :offset offset
					    :inv inv)))
    (format strm "~a concat~%" (kdraw-make-trans-string trans-coord))
    (format strm "%I~%")
    (format strm "~a ~a ~a ~a Line~%"
	    (round (aref p0 0)) (round (aref p0 1))
	    (round (aref p1 0)) (round (aref p1 1)))
    (format strm "End~%"))
  strm)
;;
(defun kdraw-polyline (plist &key (type 'norm)
			     (arrow 'none)
			     (pattern -1)
			     (xscale 1)
			     (yscale 1)
			     (rot 0.0)
			     (offset (float-vector 0 0))
			     (inv nil)
			     (trans-coord nil)
			     ((:stream strm) *kdraw*))
  (let ((len (length plist))
	(adata (kdraw-check-arrow arrow))
	(tdata (kdraw-check-linetype type)))
    (format strm "Begin %I MLine~%")
    (format strm "%I b ~a~%" (first tdata))
    (format strm "~a ~a ~a ~a ~a SetB~%"
	    (second tdata) (first adata) (second adata) (third tdata) (fourth tdata))
    (format strm "%I cfg Black~%")
    (format strm "0 0 0 SetCFg~%")
    (format strm "%I cbg White~%")
    (format strm "1 1 1 SetCBg~%")
    (kdraw-set-pattern pattern strm arrow)
    (format strm "%I t~%")
    (if (null trans-coord)
	(setq trans-coord (kdraw-make-coord :xscale xscale
					    :yscale yscale
					    :rot rot
					    :offset offset
					    :inv inv)))
    (format strm "~a concat~%" (kdraw-make-trans-string trans-coord))
    (format strm "%I ~a~%" len)
    (dolist (pv plist)
	    (format strm "~a ~a ~%" (round (aref pv 0)) (round (aref pv 1))))
    (format strm "~a MLine~%" len)
    (format strm "End~%"))
  strm)
;;
(defun kdraw-polygon (plist &key (type 'norm)
			    (pattern -1)
			    (xscale 1)
			    (yscale 1)
			    (rot 0.0)
			    (offset (float-vector 0 0))
			    (inv nil)
			    (trans-coord nil)
			    ((:stream strm) *kdraw*))
  (let ((len (length plist))
	(tdata (kdraw-check-linetype type)))
    (format strm "Begin %I Poly~%")
    (format strm "%I b ~a~%" (first tdata))
    (format strm "~a 0 0 ~a ~a SetB~%"
	    (second tdata) (third tdata) (fourth tdata))
    (format strm "%I cfg Black~%")
    (format strm "0 0 0 SetCFg~%")
    (format strm "%I cbg White~%")
    (format strm "1 1 1 SetCBg~%")
    (kdraw-set-pattern pattern strm)
    (format strm "%I t~%")
    (if (null trans-coord)
	(setq trans-coord (kdraw-make-coord :xscale xscale
					    :yscale yscale
					    :rot rot
					    :offset offset
					    :inv inv)))
    (format strm "~a concat~%" (kdraw-make-trans-string trans-coord))
    (format strm "%I ~a~%" len)
    (dolist (pv plist)
	    (format strm "~a ~a ~%" (round (aref pv 0)) (round (aref pv 1))))
    (format strm "~a Poly~%" len)
    (format strm "End~%"))
  strm)
;;
(defun kdraw-elli (cv rx ry &key (type 'norm)
		      (pattern -1)
		      (xscale 1)
		      (yscale 1)
		      (rot 0.0)
		      (offset (float-vector 0 0))
		      (inv nil)
		      (trans-coord nil)
		      ((:stream strm) *kdraw*))
  (let ((tdata (kdraw-check-linetype type)))
    (format strm "Begin %I Elli~%")
    (format strm "%I b ~a~%" (first tdata))
    (format strm "~a 0 0 ~a ~a SetB~%"
	    (second tdata) (third tdata) (fourth tdata))
    (format strm "%I cfg Black~%")
    (format strm "0 0 0 SetCFg~%")
    (format strm "%I cbg White~%")
    (format strm "1 1 1 SetCBg~%")
    (kdraw-set-pattern pattern strm)
    (format strm "%I t~%")
    (if (null trans-coord)
	(setq trans-coord (kdraw-make-coord :xscale xscale
					    :yscale yscale
					    :rot rot
					    :offset offset
					    :inv inv)))
    (format strm "~a concat~%" (kdraw-make-trans-string trans-coord))
    (format strm "%I~%")
    (format strm "~a ~a ~a ~a Elli~%"
	    (round (aref cv 0)) (round (aref cv 1)) (round rx) (round ry))
    (format strm "End~%"))
  strm)
;;
(defun kdraw-bspl (plist &key (type 'norm)
			 (arrow 'none)
			 (pattern -1)
			 (xscale 1)
			 (yscale 1)
			 (rot 0.0)
			 (offset (float-vector 0 0))
			 (inv nil)
			 (trans-coord nil)
			 ((:stream strm) *kdraw*))
  (let ((len (length plist))
	(adata (kdraw-check-arrow arrow))
	(tdata (kdraw-check-linetype type)))
    (format strm "Begin %I BSpl~%")
    (format strm "%I b ~a~%" (first tdata))
    (format strm "~a ~a ~a ~a ~a SetB~%"
	    (second tdata) (first adata) (second adata) (third tdata) (fourth tdata))
    (format strm "%I cfg Black~%")
    (format strm "0 0 0 SetCFg~%")
    (format strm "%I cbg White~%")
    (format strm "1 1 1 SetCBg~%")
    (kdraw-set-pattern pattern strm arrow)
    (format strm "%I t~%")
    (if (null trans-coord)
	(setq trans-coord (kdraw-make-coord :xscale xscale
					    :yscale yscale
					    :rot rot
					    :offset offset
					    :inv inv)))
    (format strm "~a concat~%" (kdraw-make-trans-string trans-coord))
    (format strm "%I ~a~%" len)
    (dolist (pv plist)
	    (format strm "~a ~a ~%" (round (aref pv 0)) (round (aref pv 1))))
    (format strm "~a BSpl~%" len)
    (format strm "End~%"))
  strm)
;;
(defun kdraw-cbspl (plist &key (type 'norm)
			  (pattern -1)
			  (xscale 1)
			  (yscale 1)
			  (rot 0.0)
			  (offset (float-vector 0 0))
			  (inv nil)
			  (trans-coord nil)
			  ((:stream strm) *kdraw*))
  (let ((len (length plist))
	(tdata (kdraw-check-linetype type)))
    (format strm "Begin %I CBSpl~%")
    (format strm "%I b ~a~%" (first tdata))
    (format strm "~a 0 0 ~a ~a SetB~%"
	    (second tdata) (third tdata) (fourth tdata))
    (format strm "%I cfg Black~%")
    (format strm "0 0 0 SetCFg~%")
    (format strm "%I cbg White~%")
    (format strm "1 1 1 SetCBg~%")
    (kdraw-set-pattern pattern strm)
    (format strm "%I t~%")
    (if (null trans-coord)
	(setq trans-coord (kdraw-make-coord :xscale xscale
					    :yscale yscale
					    :rot rot
					    :offset offset
					    :inv inv)))
    (format strm "~a concat~%" (kdraw-make-trans-string trans-coord))
    (format strm "%I ~a~%" len)
    (dolist (pv plist)
	    (format strm "~a ~a ~%" (round (aref pv 0)) (round (aref pv 1))))
    (format strm "~a CBSpl~%" len)
    (format strm "End~%"))
  strm)
;;
(defun kdraw-rect (sv ev &key (type 'norm)
		      (pattern -1)
		      (xscale 1)
		      (yscale 1)
		      (rot 0.0)
		      (offset (float-vector 0 0))
		      (inv nil)
		      (trans-coord nil)
		      ((:stream strm) *kdraw*))
  (let ((tdata (kdraw-check-linetype type)))
    (format strm "Begin %I Rect~%")
    (format strm "%I b ~a~%" (first tdata))
    (format strm "~a 0 0 ~a ~a SetB~%"
	    (second tdata) (third tdata) (fourth tdata))
    (format strm "%I cfg Black~%")
    (format strm "0 0 0 SetCFg~%")
    (format strm "%I cbg White~%")
    (format strm "1 1 1 SetCBg~%")
    (kdraw-set-pattern pattern strm)
    (format strm "%I t~%")
    (if (null trans-coord)
	(setq trans-coord (kdraw-make-coord :xscale xscale
					    :yscale yscale
					    :rot rot
					    :offset offset
					    :inv inv)))
    (format strm "~a concat~%" (kdraw-make-trans-string trans-coord))
    (format strm "%I~%")
    (format strm "~a ~a ~a ~a Rect~%"
	    (round (aref sv 0)) (round (aref sv 1))
	    (round (aref ev 0)) (round (aref ev 1)))
    (format strm "End~%"))
  strm)
;;
;;
(defun make-coord-string (tmat offset)
  (format nil "[~a ~a ~a ~a ~a ~a ]"
	    (aref tmat 0 0) (aref tmat 0 1)
	    (aref tmat 1 0) (aref tmat 1 1)
	    (aref offset 0) (aref offset 1))
  )
;;
(defun kdraw-get-page-info () *kdraw-coord*)
;;
(defun kdraw-page-setup (&key
			 (xscale 1)
			 (yscale 1)
			 (rot 0.0)
			 (offset (float-vector 0 0))
			 (inv nil)			 
			 (trans-coord nil)
			 (default nil))
  (cond
   (default
     (setq *kdraw-coord* *kdraw-default-coord*
	   *kdraw-coord-string* *kdraw-default-coord-string*))
   (t
    (if (null trans-coord)
	(setq trans-coord (kdraw-make-coord :xscale xscale
					    :yscale yscale
					    :rot rot
					    :offset offset
					    :inv inv)))
    (setq *kdraw-coord* trans-coord
	  *kdraw-coord-string* (make-coord-string (first trans-coord)
						  (second trans-coord)))))
  *kdraw-coord*)
;;


