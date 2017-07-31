;*******************************************************************
;* class TRANSLATOR
;  LAP code to 68020 assembly code translator for eulisp compiler
;	1986-Sep
;	T.Matsui
; register usage:
;	a0-a1	work
;	a3	argv
;	a4	frame pointer for locals
;	a5	vsp (bind stack pointer)
;	a6	fp (C)
;	a7	sp (C)
;	
; 1987-Dec 	great modification to produce vax code
; 1988-Feb-18	Optimization using register stack pointer
;*******************************************************************

(in-package "COMPILER")

(defvar trans nil)

(defun c-stringize (x)
  (let ((s (prin1-to-string x)) r)
     (cond ((position #\newline s)
	    (dotimes (i (length s))
		(if (eql (char s i) #\newline)
		    (progn (push #\\ r) (push #\n r))
		    (push (char s i) r)))
	    (coerce (nreverse r) string))
	   (t s))))

(defclass translator :super object
		     :slots (cfile hfile push pushcount quotev))

(eval-when (load eval)

(defparameter ftab-next 0)
(defparameter external-functions nil)

(defun ftab-index (sym)
   (let ((index (get sym :ftab-index)))
      (if (null index)
	  (prog1 (setf (get sym :ftab-index) ftab-next)
		 (push sym external-functions)
		 (incf ftab-next))
	  index)))

(defmethod translator
 (:label (l)
   (send self :clearpush)
   (format cfile "~A:~%" l))
 (:comment (&rest c)
   (princ "/*" cfile)
   (while c (princ (pop c) cfile))
   (princ "*/" cfile)
   (terpri cfile))
#+:rgc
 (:nonpop ()
   (if push push
     (format nil "local[~d]" (1- pushcount))))
 (:pop ()
   (if push (prog1 push (setq push nil))
	    (progn (dec pushcount) (format nil "local[~d]" pushcount))))
 (:store (dest)
   (if (or (null push) (not (equal push dest)))
       (format cfile "	~A = ~A;~%" dest (send self :pop))
       (setq push nil)))
 (:push (src)
    (send self :clearpush)
    (setq push src))
 (:clearpush ()		;flush out reserved push
    (when push
	  (format cfile "	local[~d]= ~A;~%" pushcount push)
	  (inc pushcount))
    (setq push nil)) )

(defmethod translator
 (:quote-entry (q) 
    (let (p)
;      (format t ":quote-entry arg=~A" q)
      (cond ((and (symbolp q) (setq p (memq q quotev)))
	     (setq p (- (length quotev) (length p))))
	    (t (setq p (1- (length (setq quotev (nconc quotev (list q))))))))
;      (format t " entry=~A~%" p	)
      p)))

(defmethod translator
 (:dupe ()		;duplicate stack top
    (cond ((equal push "w") (send self :push "w"))
	  (t (send self :clearpush)
	     (send self :push (format nil "local[~d]" (1- pushcount))) )))
 (:discard (n)
    (when push (setq push nil) (dec n))
    (when (> n 0) (dec pushcount n)))
 (:adjust (n) (dec pushcount n))
 (:setpushcount (n) (setq pushcount n))
 (:offset-from-fp ()
    (send self :clearpush)
    pushcount)
 (:reset-vsp () (format cfile "	ctx->vsp=local+~d;~%" pushcount))
 (:bind-special (id)
    (send self :store "w")
    (send self :reset-vsp)
    (format cfile "	bindspecial(ctx,fqv[~d],w);~%" 
		  (send self :quote-entry id))
;    (send self :reset-fsp)
    (inc pushcount 3)			;3 longs for special bind frame
    )
 (:unbind-special (count)
    (send self :clearpush)
    (send self :reset-vsp)
    (format cfile "	unbindx(ctx,~d);~%" count)
;    (send self :reset-fsp)
    )
 (:pushenv () 
    (send self :clearpush)
    (send self :push "env")
    (send self :clearpush))
 (:enter (cname lname)
    (terpri cfile)
    (send self :comment lname)
    (setq pushcount 0)		;reset pushcount
				;because a4(vfp) changes here 
    (format cfile "static pointer ~A(ctx,n,argv,env)~%" cname)
    (format cfile "register context *ctx;~%")
    (format cfile "register int n; register pointer argv[]; pointer env;~%")
    (format cfile "{ register pointer *local=ctx->vsp, w, *fqv=qv;~%")
    (format cfile "  numunion nu;~%")
    )
 (:check-req-arg (req opt)	;check number of required arguments
   (if (> *safety* 1) (format cfile "	breakck;~%"))
   (if (> *safety* 0) 
       (if (>= req 0)
           (format cfile "	if (n~A~d) maerror();~%"
			   (if (= opt 0) "!=" "<") req))) )
 (:check-opt-arg (m lab)
   (format cfile "	if (n>=~d) { local[~d]=(argv[~d]); goto ~A;}~%"
		 (1+ m) pushcount m lab)) 
 (:check-rest-arg (m)
   (if (> *safety* 0)
       (format cfile "	if (n>~d) maerror();~%" m)) )
 (:rest (pcnt)
   (send self :clearpush)
   (send self :reset-vsp)
   (send self :push (format nil "minilist(ctx,&argv[n],n-~d)"  pcnt)))
 (:parse-key-params (keyvec req+opt keyn allowotherkeys)
   (send self :clearpush)
   (send self :reset-vsp)
   (format cfile
	   "	n=parsekeyparams(fqv[~d], &argv[~d], n-~d, local+~d, ~A);~%"
	   (send self :quote-entry keyvec) req+opt req+opt
	   pushcount
	   (if allowotherkeys 1 0))
   (inc pushcount keyn))
 (:check-key-arg (n lab)
   (format cfile "	if (n & (1<<~A)) goto ~A;~%" n lab))
 (:getbase (n argp) 
   (cond ((= n 0) (if argp "argv" "local"))
	 (t
	   (let* ((f "env->"))
	     (while (> n 1)
		(setq f (concatenate string f
			 "c.clo.env0->"))
		(dec n))
	     (setq f (concatenate string f
			(if argp "c.clo.env1"
				 "c.clo.env2")))
	     f))))
 (:load-t () (send self :push "T"))
 (:load-nil () (send self :push "NIL"))
#-:x86_64
 (:load-int (x) (send self :push (format nil "makeint(~d)" x)))
#+:x86_64
 (:load-int (x) (send self :push (format nil "makeint((eusinteger_t)~dL)" x)))
#-:x86_64
 (:load-float (x) (send self :push (format nil "makeflt(~8,8e)" x)))
#+:x86_64
 (:load-float (x) (send self :push (format nil "makeflt(~22,22e)" x)))
)

(defmethod translator
 (:load-quote (ent)
     (send self :push (format nil "fqv[~d]" (send self :quote-entry ent))))
)

(defmethod translator
 (:load-arg (n level)
    (send self :push 
	       (format nil "~A[~d]" (send self :getbase level 'arg) n)))
 (:load-local (n level)
    (send self :push
	       (format nil "~A[~d]" (send self :getbase level nil) n)))
 (:load-obj (n level)
    (send self :push
		(format nil "~A[0]->c.obj.iv[~d]"
			    (send self :getbase level 'arg) n)))
 (:load-global (ent)
    (send self :push (format nil "loadglobal(fqv[~d])"
				 (send self :quote-entry ent))))
 (:store-arg (n level)
    (send self :store (format nil "~A[~d]" (send self :getbase level 'arg) n)))
 (:store-local (offset level)
    (send self :store (format nil "~A[~d]" (send self :getbase level nil) offset)))
 (:store-obj (var level)
#+:rgc	     
	     (let ((p1 (send self :getbase level 'arg))
		   (p2 var))
	       (send self :store (format nil "noticeCollector1(~A[0]->c.obj.iv[~d]);~%	~A[0]->c.obj.iv[~d]"
					 p1 p2 p1 p2)))
#-:rgc	     
    (send self :store (format nil "~A[0]->c.obj.iv[~d]"
				(send self :getbase level 'arg) var)))
 (:store-global (var)
    (format cfile "	storeglobal(fqv[~d],~A);~%"
		  (send self :quote-entry var) (send self :pop)))
 (:load-ovaf (var)
    (send self :push
		(format nil
			"*(ovafptr(~A,fqv[~d]))"
			(send self :pop)
			(send self :quote-entry var))))
 (:load-indexed-ov (index)
    (send self :push 
	       (format nil "~A->c.obj.iv[~d]" 
			   (send self :pop) index)))
 (:store-ovaf (var)
    (send self :store
	#+:rgc		    
	(let ((p1 (send self :pop))
	      (p2 (send self :quote-entry var)))
	  (format nil "noticeCollector1(*(ovafptr(~A,fqv[~A])));~%	*(ovafptr(~A,fqv[~A]))"
		  p1 p2 p1 p2))
	#-:rgc
	       (format nil "*(ovafptr(~A,fqv[~A]))"
			(send self :pop) (send self :quote-entry var))))
 (:store-indexed-ov (index)
    (send self :store "w")
    #+:rgc
    (send self :store
	  (format nil "noticeCollector1(w->c.obj.iv[~d]);~%	w->c.obj.iv[~d]"
		  index index))
    #-:rgc
    (send self :store (format nil "w->c.obj.iv[~d]"  index)))
 (:call (sym n)
    (let ((entry))
       (setq entry (get sym 'user-function-entry))
       (if (null entry) (setq entry (get sym 'builtin-function-entry)))
       (send self :clearpush)
       (send self :reset-vsp)
       (unless (functionp sym)
         (format *error-output* "; ~C[34;7m~S~C[0;34m is assumed to be undefined function~C[0m~%"
                 #x1b sym #x1b #x1b))
       (if entry
	   (format cfile "	w=(pointer)~A(ctx,~d,local+~d); /*~A*/~%"
		     entry n (- pushcount n) sym)
	   (format cfile "	w=(*ftab[~d])(ctx,~d,local+~d,&ftab[~d],fqv[~d]); /*~A*/~%"
			(ftab-index sym)
			n (- pushcount n)
			(ftab-index sym)
			(send self :quote-entry sym)
			sym))
       (send self :discard n)
       (send self :push "w")  ))
 (:call-closure (entry argc)
    ;closure object on the top of stack
    (send self :store "w")	;closure
    (send self :reset-vsp)
    (format cfile "	w=~a(ctx,~d,local+~d,w);~%" entry argc (- pushcount argc))
    (send self :discard argc)
    (send self :push "w"))
 (:getfunc (sym)
    (send self :push (format nil "(pointer)get_sym_func(fqv[~d])"
				(send self :quote-entry sym))))
)

(defmethod translator
 (:1- () 
    (send self :push
	       (format nil "(pointer)((eusinteger_t)(~A)-4)" (send self :pop))))
 (:1+ () 
    (send self :push
	       (format nil "(pointer)((eusinteger_t)(~A)+4)" (send self :pop))))
 (:check-cons-nil ()  ; check if stack-top is cons or nil.
    (if (equal push "w")
	(send self :pop)
	(format cfile "	w=~a;~%" (send self :pop)))
    (format cfile "	if (!iscons(w) && w!=NIL) error(E_NOLIST);~%")
    (send self :push "w"))
 (:car ()
    (if  (< *optimize* 2)
	 (send self :push (format nil "xcar(~A)" (send self :pop)))
	 (progn  ; *optimize*>=2 
	    (when (>= *safety* 1)  (send self :check-cons-nil))
	    (send self :push (format nil "(~A)->c.cons.car" (send self :pop)))
	  )) )
 (:cdr ()
    (if  (< *optimize* 2)
	 (send self :push (format nil "xcdr(~A)" (send self :pop)))
	 (progn  ; *optimize*>=2 
	    (when (>= *safety* 1) (send self :check-cons-nil))
	    (send self :push (format nil "(~A)->c.cons.cdr" (send self :pop)))
	  )) )
 (:caar () 
    (cond ((< *optimize* 2)
	  (send self :push (format nil "xcar(xcar(~A))" (send self :pop))))
	  ((>= *safety* 1)
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.car" (send self :pop)))
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.car" (send self :pop)) ))
	  (t ; safety<1 and optimize>=2 
	    (send self :push (format nil "(~A)->c.cons.car->c.cons.car"
			 (send self :pop))) )) )
 (:cddr ()
    (cond ((< *optimize* 2)
	  (send self :push (format nil "xcdr(xcdr(~A))" (send self :pop))))
	  ((>= *safety* 1)
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.cdr" (send self :pop)))
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.cdr" (send self :pop))))
	  (t ; safety<1 and optimize>=2 
	    (send self :push (format nil "(~A)->c.cons.cdr->c.cons.cdr"
			 (send self :pop))) )) )
 (:cdar ()
    (cond ((< *optimize* 2)
	  (send self :push (format nil "xcdr(xcar(~A))" (send self :pop))))
	  ((>= *safety* 1)
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.car" (send self :pop)))
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.cdr" (send self :pop))) )
	  (t  ; safety<1 and optimize>=2 
	    (send self :push (format nil "(~A)->c.cons.car->c.cons.cdr"
			 (send self :pop))) )) )
 (:cadr ()
    (cond ((< *optimize* 2)
	  (send self :push (format nil "xcadr(~A)" (send self :pop))))
	  ((>= *safety* 1)
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.cdr" (send self :pop)))
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.car" (send self :pop))) )
	  (t ; safety<1 and optimize>=2 
	    (send self :push (format nil "(~A)->c.cons.cdr->c.cons.car"
			 (send self :pop))) )) )
 (:caddr ()
    (cond ((< *optimize* 2)
	  (send self :push (format nil "xcadr(xcdr(~A))" (send self :pop))))
	  ((>= *safety* 1)
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.cdr" (send self :pop)))
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.cdr" (send self :pop)))
	    (send self :check-cons-nil)
	    (send self :push  (format nil "(~A)->c.cons.car" (send self :pop))) )
	  (t ; safety<1 and optimize>=2 
	    (send self :push (format nil "(~A)->c.cons.cdr->c.cons.cdr->c.cons.car"
			 (send self :pop))) )) )
 (:cons ()
    (send self :store "w")
    (send self :reset-vsp)
    (send self :push (format nil "cons(ctx,~A,w)" (send self :pop))))
 (:svref ()		; reference to a simple general vector element
    (format cfile "	{ register eusinteger_t i=intval(~A);~%" (send self :pop))
    (let ((vec (send self :pop)))
	(format cfile "	  w=(~A->c.vec.v[i]);}~%" vec))
    (send self :push "w"))
 (:svset ()		; store to a simple general vector
    (send self :store "w")	;value
    (format cfile "	{ register eusinteger_t i; register pointer v;~%")
    (format cfile "	  i=intval(~A); v=~A;~%" (send self :pop)
						 (send self :pop))
#+:rgc
    (format cfile "	  noticeCollector(v->c.vec.v[i], w);~%")
    (format cfile "	  v->c.vec.v[i]=w;}~%")
    (send self :push "w"))
 (:char ()
    (format cfile "	{ register eusinteger_t i=intval(~A);~%" (send self :pop))
    (let ((vec (send self :pop)))
	(format cfile "	  w=makeint(~A->c.str.chars[i]);}~%" vec))
    (send self :push "w"))
 (:setchar ()
    (send self :store "w")	;value
    (format cfile "	{ register eusinteger_t i; register pointer v;~%")
    (format cfile "	  i=intval(~A); v=~A;~%" (send self :pop)
						 (send self :pop))
    (format cfile "	  v->c.str.chars[i]=intval(w);}~%")
    (send self :push "w"))
 (:bit ()
    (format cfile "	{ register eusinteger_t i=intval(~A);~%" (send self :pop))
    (let ((vec (send self :pop)))
	(format cfile "	  w=makeint(~A->c.str.chars[i/8]&(1<<(i&7))?1:0);}~%" vec))
    (send self :push "w"))
 (:setbit ()
    (send self :store "w")	;value
    (format cfile "	{ register eusinteger_t i; register byte *v;~%")
    (format cfile "	  i=intval(~A); v=~A->c.str.chars;~%" (send self :pop)
						 (send self :pop))
    (format cfile "	  if (((eusinteger_t)w)&4) v[i/8]|=(1<<(intval(i)&7));~%")
    (format cfile "	  else v[i/8]&= ~~(1<<(intval(i)&7));}~%")
    (send self :push "w"))
 (:vref (type)		; reference to a simple vector element
    (format cfile "	{ register eusinteger_t i=intval(~A);~%" (send self :pop))
    (let ((vec (send self :pop)))
      (case type
	  (character (format cfile "	  w=makeint(~A->c.str.chars[i]);}~%" vec))
	  (integer   (format cfile "	  w=makeint(~A->c.ivec.iv[i]);}~%" vec))
	  (float     (format cfile "	  w=makeflt(~A->c.fvec.fv[i]);}~%" vec))
	  (pointer   (format cfile "	  w=(~A->c.vec.v[i]);}~%" vec))
	  (T  (send self :error "unknown vector element type")))
      (send self :push "w")))
 (:vset (type)		; store to a vector element whose type is apparent
    (send self :store "w")	;value
    (format cfile "	{ register eusinteger_t i; register pointer v;~%")
    (format cfile "	  i=intval(~A); v=~A;~%" (send self :pop)
						 (send self :pop))
    (case type
	(character (format cfile "	  v->c.str.chars[i]=intval(w);}~%"))
	(integer   (format cfile "	  v->c.ivec.iv[i]=intval(w);}~%"))
	(float     (format cfile "	  v->c.fvec.fv[i]=fltval(w);}~%"))
	(pointer   
	 #+:rgc
		   (format cfile "	  noticeCollector(v->c.vec.v[i], w);~%")
		   (format cfile "	  v->c.vec.v[i]=w;}~%"))
	(T  (send self :error "unknown vector element type")))
    (send self :push "w"))
 (:nullx ()
    (send self :push (format nil "((~A)==NIL?T:NIL)" (send self :pop))))
 (:eqx ()
    (send self :push
	(format nil "((~A)==(~A)?T:NIL)" (send self :pop) (send self :pop))))
 (:memqx ()
    (send self :store "w")
    (send self :push (format nil "memq(~A,w)" (send self :pop))))
 (:type-check-predicate (pred)
    (send self :store "w")
    (send self :push
	  (format nil "(~A(w)?T:NIL)"
	       (cdr (assoc pred '((symbolp . "issymbol") (consp . "iscons")
				  (numberp . "isnum") (integerp . "isint")
				  (floatp . "isflt") (stringp . "isstring")
				 ))))))
 (:if-nil (lab)
    (format cfile "	if (~A==NIL) goto ~A;~%" (send self :pop) lab))
 (:if-t (lab)
    (format cfile "	if (~A!=NIL) goto ~A;~%" (send self :pop) lab))
 (:if-eq (lab)
    (format cfile "	if (~A==~A) goto ~A;~%" (send self :pop)
						(send self :pop) lab))
 (:if-neq (lab)
    (format cfile "	if (~A!=~A) goto ~A;~%" (send self :pop)
						(send self :pop) lab))
;;; integer arithmetics, machine architecture dependent
 (:int-op2 (op)		;+,-,*,logand,logior
    (cond ((memq op '(+ - logand logior))
	   (send self :store "w")
	   (when (memq op '(+ -))
	      (format cfile
		 "#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM~%	w=(pointer)((eusinteger_t)w-2);~%#endif~%"))
	   (send self :push
		 (format nil "(pointer)((eusinteger_t)~A ~A (eusinteger_t)w)"
			 (send self :pop) 
			 (cdr (assq op '((+ . "+") (- . "-") (logand . "&")
						(logior . "|")))))))
	  (t
	    (format cfile "	{ eusinteger_t i,j;~%")
	    (format cfile 
		"		j=intval(~A); i=intval(~A);~%"
		(send self :pop) (send self :pop))
	    (format cfile
		"		local[~d]=(makeint(i ~A j));}~%"
		pushcount
		(cdr (assq op '((+ . "+") (- . "-") (logand . "&")
				(logior . "|") (* . "*")))))
	    (inc pushcount))))
 (:int-neg ()
    (send self :push (format nil "makeint(-(intval(~A)))" (send self :pop))))
 (:int-abs ()
    (send self :push (format nil "makeint(abs(intval(~A)))" (send self :pop))))
 (:flt-abs ()
    (send self :push (format nil "makeflt((double)fabs(fltval(~A)))" (send self :pop))))
;;; comparison
 (:compare (type comparator lab)
    (cond ((eq comparator '<>) (send self :if-neq lab))
	  ((eq comparator '=) (send self :if-eq lab))
	  ((eq type 'int)
	    (send self :store "w")
	    (format cfile "	if ((eusinteger_t)~A ~A (eusinteger_t)w) goto ~A;~%"
			   (send self :pop) comparator lab))
	  ((eq type 'float)
	    (format cfile "	{ double left,right;~%")
	    (format cfile 
		"		right=fltval(~A); left=fltval(~A);~%"
		(send self :pop) (send self :pop))
	    (format cfile "	if (left ~A right) goto ~A;}~%" comparator lab))
	 (t (send self :error "illegal compare"))))
;;; floating arithemtics
 (:flt-op2 (op)
    (format cfile "	{ double x,y;~%")
    (format cfile 
	"		y=fltval(~A); x=fltval(~A);~%"
	(send self :pop) (send self :pop))
    (format cfile
	"		local[~d]=(makeflt(x ~A y));}~%"
	pushcount
	(cdr (assq op '((+ . +) (- . -) (* . *) (/ . /)))))
    (inc pushcount))
 (:flt-neg ()
    (send self :push (format nil "makeflt(-(fltval(~A)))" (send self :pop))))
;;; type check
 (:type-checker (tn)
    (cdr (assq tn '((symbolp . "issymbol") (integerp . "isint")
		    (numberp . "isnum")
		    (floatp . "isflt") (atom . "!iscons")
		    (consp . "iscons") (stringp . "isstring")))))
 (:if-type (type lab)
    (send self :store "w")
    (format cfile "	if (~A(w)) goto ~A;~%"
		  (send self :type-checker type) lab))
 (:if-not-type (type lab)
    (send self :store "w")
    (format cfile "	if (!~A(w)) goto ~A;~%"
		  (send self :type-checker type) lab))
;;;
 (:jump (lab)
    (send self :clearpush)
    (format cfile "	goto ~A;~%" lab))
 (:return ()
    (send self :clearpush)
    (format cfile "	ctx->vsp=local; return(local[0]);}~%")
    (if (not (= (dec pushcount) 0)) (warn ":return pushcount is ~d " pushcount)))
 (:del-frame (spe loc)	;number of special bindings and local variables
    (send self :store "w")
    (send self :discard (+ (* 3 spe) loc))
    (send self :push "w"))
  (:entercatch (exit)
    (format cfile "	{jmp_buf jb;~%")
    (send self :store "w")
    (send self :reset-vsp)
    (format cfile
	    "	mkcatchframe(ctx,w,(jmp_buf *)jb);~%")
    (format cfile
    "	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto ~A;}~%"
         exit)
;    (send self :reset-fsp)
    (inc pushcount 6))	;five long for a catch frame
 (:exitcatch (exlab)
    (send self :store "w")
    (send self :label exlab)
    (format cfile "	if (w==(pointer)(1)) w=makeint(0);~%")
    (format cfile "	restorecatch(ctx);};~%")
;    (send self :reset-fsp)
    (dec pushcount 6)
    (send self :push "w"))	;result of catch
 (:throw ()
    (send self :store "w")	;result
    (send self :reset-vsp)
    (format cfile "	throw(ctx,vpop(),w);~%")
    (format cfile "	error(E_NOCATCHER,NULL);~%"))
 (:bind-cleaner ()
    (send self :store "w")	;must be a closure
    (format cfile
	    "	local[~d]=(pointer)(ctx->protfp); local[~d]=w;
	ctx->protfp=(struct protectframe *)(local+~d);~%"
	    pushcount (1+ pushcount) pushcount)
    (inc pushcount 2))
 (:call-cleaner (cleaner)
    (send self :store "w")
    (send self :reset-vsp)
    (format cfile "	~A(ctx,0,local+~d,ctx->protfp->cleaner);~%" cleaner pushcount)
    (format cfile "	ctx->protfp=ctx->protfp->protlink;~%")
    (dec pushcount 2)
    (send self :push "w"))
 (:return-from (k need-unwind)	
    (send self :store "w")		;save result
    (send self :reset-vsp)
    (if need-unwind
	(format cfile  "	unwind(ctx,local+~d);~%" k))
    (format cfile "	local[~d]=w;~%" k)
    (inc pushcount))
 (:go-tag (k need-unwind)
    (send self :reset-vsp)
    (if need-unwind
	(format cfile  "	unwind(ctx,local+~d);~%" k))
    (inc pushcount))
  (:closure (lab)
    (send self :clearpush)
    (send self :reset-vsp)
    (send self :push
	  (format nil "makeclosure(codevec,quotevec,~A,env,argv,local)" lab)))
 (:defun (sym cname doc)
    (send self :clearpush)
    (send self :reset-vsp)
    (format cfile
	    "	compfun(ctx,fqv[~d],module,~A,fqv[~d]);~%" 
	    (send self :quote-entry sym)
	    cname
	    (send self :quote-entry doc)) )
 (:defmacro (sym label doc)
    (send self :clearpush)
    (send self :reset-vsp)
    (format cfile
	    "	compmacro(ctx,fqv[~d],module,~A,fqv[~d]);~%" 
	    (send self :quote-entry sym)
	    label
	    (send self :quote-entry doc)))
 (:quote-fqv-entry (q)
    (if (null q) "NIL" (format nil "fqv[~d]" (send self :quote-entry q))))
 (:defmethod (klass sel label doc)	;define func/macro/method/class
;   addcmethod(module,cfunc,sel,klass)
    (send self :clearpush)
    (send self :reset-vsp)
    (format cfile
	    "	addcmethod(ctx,module,~A,fqv[~d],fqv[~d],~A);~%"
	    label
	    (send self :quote-entry sel)
	    (send self :quote-entry klass)
	    (send self :quote-fqv-entry doc)	))
 (:declare-forward-function (name)
    (format hfile "static pointer ~A();~%" name))
 (:quote ()  quotev)
 (:init () 
    (setq push nil
	  pushcount 0  ))
 (:init-file (source-name cname hname entry)
    (setq cfile (open cname :direction :output) 
	  hfile (open hname :direction :output)
	  quotev nil
	  external-functions nil
	  ftab-next 0)
    (format cfile "/* ~a :  entry=~a */~%" (namestring cname) entry)
    (format cfile "/* compiled by ~a */~%" (lisp:lisp-implementation-version))
    (format cfile "#include \"eus.h\"~%")	;should specify -I opt.
    #+:rgc
    (format cfile "#include \"collector.h\"~%")
    (format cfile "#include \"~A.~A\"~%" (pathname-name hname) (pathname-type hname))
#-:alpha
    (format cfile "#pragma init (register_~a)~%" entry)
    (format cfile "extern double fabs();~%")
    (format cfile "extern pointer fcallx();~%")
    (format cfile "static void init_ftab();~%")
    (cond
       ((> *optimize* 2)
	(format cfile "#define loadglobal(s) s->c.sym.speval~%")
	#+:rgc
	(format cfile "#define storeglobal(s,val) {noticeCollector(s->c.sym.speval,(val)); s->c.sym.speval=(val)~%")
	#-:rgc
	(format cfile "#define storeglobal(s,val) s->c.sym.speval=(val)~%"))
       (t (format cfile "extern pointer loadglobal(),storeglobal();~%")))
    (format cfile "static pointer module,*qv,codevec,quotevec;~%")
    (if (memq 'lisp::solaris2 *features*)
	(format cfile "static pointer ___~a();~%" entry)
	(format cfile "extern pointer ___~a();~%" entry))
    (format cfile "extern pointer build_quote_vector();~%")
    (format cfile "static int register_~a()~%" entry)
    (format cfile "  { add_module_initializer(~s, ___~a);}~%~%"
		(concatenate string "___" (pathname-name source-name))
		 entry)
    (dolist (f *defun-list*)
      (format cfile "static pointer ~a();~%" (get f 'user-function-entry)))
    )
 (:eusmain (entry)
      (format cfile "~%/* initializer*/~%pointer ___~A(ctx,n,argv,env)
register context *ctx; int n; pointer *argv; pointer env;~%" entry)
    (format cfile "{ register pointer *local=ctx->vsp, w, *fqv;~%  register int i;~%")
    (format cfile "  numunion nu;~%")
    (format cfile "  module=argv[0];~%")
    (format cfile "  quotevec=build_quote_vector(ctx,QUOTE_STRINGS_SIZE, quote_strings);~%")
    (format cfile "  module->c.code.quotevec=quotevec;~%")
    (format cfile "  codevec=module->c.code.codevec;~%")
    (format cfile "  fqv=qv=quotevec->c.vec.v;~%")
    (format cfile "  init_ftab();~%")
    )
 (:write-quote-vector ()
    (format hfile "#define QUOTE_STRINGS_SIZE ~d~%" (length quotev))
    (format hfile "~astatic char *quote_strings[QUOTE_STRINGS_SIZE]={~%"
	(if (memq :solaris2 *features*) "const " ""))
    (dolist (q quotev)
       (let* ((s (prin1-to-string q)) (len (length s)) (ch))
	  (format hfile "    \"")
	  (dotimes (i len)
	     (cond ((eql (char s i) #\\)	;escaped
		    (write-byte #\\ hfile) (write-byte #\\ hfile))
	           ((eql (char s i) #\")	;double quote
		    (format hfile "\\\""))
		   ((eql (char s i) #\newline)
		    (format hfile "\\n"))
		   (t (write-byte (char s i) hfile))))
	  (format hfile "\",~%")))
     (format hfile "  };~%")
    )
 (:declare-ftab ()
    (if (> ftab-next 0)
        (format hfile "static pointer (*ftab[~d])();~%~%" ftab-next)))
 (:ftab-initializer ()
    (format cfile "static void init_ftab()~%{")
    (when (> ftab-next 0)
        (format cfile "  register int i;~%")
	(format cfile "  for (i=0; i<~d; i++) ftab[i]=fcallx;~%" ftab-next))
    (format cfile "}~%") 
    (dolist (ef external-functions)
	(remprop ef :ftab-index)) )
 (:close ()
    (close cfile)
    (close hfile))
 )

(setq trans (instance translator))

) ;eval-when


(provide :trans "$Id$")
