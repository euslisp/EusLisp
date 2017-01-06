;;;;
;;;;	Foreign language interface
;;;;	1987-SEP-25
;;;;	Copyright Toshihiro MATSUI
;;;;	2004-Dec-17 i386 interface is added by T. Matsui

(in-package "LISP")
(eval-when (load eval)
#-(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)
(export '(read-symbol-table foreign-module))

(export '(load-foreign defforeign make-foreign-code defvoidforeigns
	defun-c-callable pod-address byte-size cstructclass cstruct
	defcstruct carray defcarray foreign-string make-foreign-string)) )

(defmethod load-module
 (:find (symname)
       (system::find-entry symname self)))


#-(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)   
(defun read-symbol-table (objfile &optional (offset 0))
  (let* ((nm)
	 (line nil)
	 (strm nil)
	 (address nil)
	 (mark nil)
	 (sym nil)
	 (eof (gensym))
	 (htab (make-hash-table :size 10 :test #'equal))
	 (*read-base* 16))
    ; run "nm -gp objfile >tmpfile". 
    (setq nm (piped-fork "nm" "-gp" objfile))
    ; read the symbol tables from the pipe
    (while (not (eq (setq line (read-line nm nil eof)) eof))
	(when (not (eq (elt line 0) #\ ))
	    (setq strm (make-string-input-stream  line))
	    (setq address (+ (read strm) offset)
		  mark (read strm))
	    (read-char strm)
	    (setq sym (read-line strm))
	    (setf (gethash sym htab) (list mark address))))
    (close nm)
    htab))

#-(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)
(defclass foreign-module :super compiled-code
			 :slots (symbol-table object-file))

#-(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)
(defmethod foreign-module
 (:code-alignment (symfile)
    (if (not (equal object-file symfile))
        (if (intersection '(:sun4 :news :vax :mips) *features*)
	    (- (sys:address codevector))
	    (- (+ (sys:address codevector) 2)))
        (cond
	    ((member :sun4 *features*)
	     (if (member :sunos4 *features*)
		 8
		 (- 1024 (mod (sys:address codevector) 1024))) )
	    ((member :vax *features*) 8)
	    ((member :mips *features*) 8)
	    (t  6))))	;sun3 --> 6
 (:load (file &key (symbol-input (namestring *symbol-input*))
		   (symbol-output "") (ld-option "")
		   (symbol-file file))
    (let ((om ; (sys:binload file "" "" symbol-input symbol-output ld-option)
		(load file :entry ""	;foreign module cannot have entry
			   :symbol-input symbol-input 
			   :symbol-output symbol-output
			   :ld-option ld-option)
		) )
	(setq codevector (compiled-code-codevector om)
	      quotevector (compiled-code-quotevector om)
	      object-file file
	      symbol-table
	         (read-symbol-table symbol-file
				    (send self :code-alignment symbol-file)))
	self  ))
 (:find (entry)   (gethash entry symbol-table))
 (:address (entry) (+ (sys:address codevector) (cadr (send self :find entry))))
 (:defforeign (name entry params result)
    (let ((fc (instance foreign-code))
          (e (gethash entry symbol-table)))
       (if (null e)
           (setq e (gethash (subseq entry 1) symbol-table)))
       (cond 
	  (e
	   (setq (fc . type) 0	;function
		 (fc . codevector) (self . codevector)
		 (fc . quotevector) (self . quotevector)
	         (fc . entry) (cadr e)
		 (fc . paramtypes) params
		 (fc . resulttype) result)
	   (setf (symbol-function name) fc)
	   name)
	  (t (warn "no such entry ~s~%" entry)))
      ))
   )

#+(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)
(defmethod foreign-code
 (:init (ent &optional param (result :integer))
    (setq codevector 0
	  quotevector nil
	  entry (if (consp ent) (car ent) ent)
	  entry2 (if (consp ent) (cadr ent))
	  paramtypes param
	  resulttype result
	  type 0)	; function
    self))

#+(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)
(defun make-foreign-code (fentry &optional param (result :integer)
					(fmod (sys::sysmod)))
	 (cond ((numberp fentry))
	       ((system::find-entry fentry fmod)
		(setq fentry (system::find-entry2 fentry fmod)))
	       (t (error "no such foreign entry ~s" fentry)))
   (instance foreign-code :init fentry param result))

;;;

#-(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)
(defun load-foreign (file &key  (symbol-input (namestring *symbol-input*))
				(symbol-output "")
			        (ld-option "")    (symbol-file file))
   (instance foreign-module :load file  :symbol-input symbol-input
					:symbol-output symbol-output
					:ld-option ld-option
					:symbol-file symbol-file))

#+(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)
(defun load-foreign (file)   (load file :entry ""))

#-(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)
(defmacro defforeign (name fmod label param result)
   `(send ,fmod :defforeign ',name ,label ',param ',result))

#+(or :solaris2 :linux :irix :irix6 :sunos4.1 :alpha :cygwin)
(defmacro defforeign  (name fmod label param result)
   `(setf (symbol-function ',name)
	  (make-foreign-code ,label ',param ',result ,fmod)))

(defmacro defvoidforeigns (mod &rest names)
   `(dolist (fname ',names)
	(setf (symbol-function (intern (string-upcase fname)))
	      (make-foreign-code fname nil :integer ,mod))))

;(eval-when (compile)
;  (defclass foreign-pod :super symbol :slots (podcode paramtypes resulttype)))

(defun byte-string (&rest bytes)
   (make-array (length bytes) :element-type :char :initial-contents bytes))

(defmethod foreign-pod
 (:pod-address () 
#-(or :x86_64 :aarch64)
	(+ 8 (sys:address podcode))
#+(or :x86_64 :aarch64)
	(+ 16 (sys:address podcode))
	)
 (:init (param result func)
    (let ((self-address (sys:address self)))
#+:sun3
      (progn
	 (inc self-address 2)
	 (setq podcode (byte-string
	        #x4E #x56 #x00 #x00			;linkw #0,a6
		#x48 #x6E #x00 #x08			;pea a6@(8)
		#x2F #x3C (ldb self-address 24 8)
		      (ldb self-address 16 8)
		      (ldb self-address 8 8)
		      (ldb self-address 0 8)	;movl #self,sp@-
		#x4E #xB9 (ldb *calleus* 24 8)
		      (ldb *calleus* 16 8)
		      (ldb *calleus* 8 8)
		      (ldb *calleus* 0 8)	;jsr _calleus
		#x50 #x8F				;addql 8,sp
		#x2d #x40 #x00 #x08			;movl d0,a6@(8)
		#xf2 #x2e #x44 #x00 #x00 #x08	;fmoves a6@(8),fp0
		#x4E #x5E				;unlk a6
		#x4E #x75				;rts
		)))
#+:sun4
	 (let ( (self-address-high (ldb self-address 10 22))
		(self-address-low (ldb self-address 0 10))
		(calleus (ash (- *calleus* (+ (sys:address podcode) 8 44))
			      -2)))
	   (setq podcode (byte-string	;18 long words
		 #x03 #x3F #xFF #xFF	;sethi
		 #x82 #x00 #x63 #xA0	;add
		 #x9D #xE3 #x80 #x01	;save
		 #xF0 #x27 #xA0 #x44	; %i0
		 #xF2 #x27 #xA0 #x48	; %i1
		 #xF4 #x27 #xA0 #x4C	; %i2
		 #xF6 #x27 #xA0 #x50	; %i3
		 #xF8 #x27 #xA0 #x54	; %i4
		 #xFA #x27 #xA0 #x58	; %i5
		 #x11 (ldb self-address-high 16 8)
		      (ldb self-address-high 8 8)
		      (ldb self-address-high 0 8)   ;sethi symboladdress,%o0
		 #x90 #x12 (+ #x20 (ldb self-address-low 8 2))
			  (ldb self-address-low 0 8)	;add ...
		 (+ #x40 (ldb calleus 24 6))	;call _calleus
		    (ldb calleus 16 8) (ldb calleus 8 8) (ldb calleus 0 8)
		 #x92 #x07 #xA0 #x44	;add
		 #xB0 #x10 #x00 #x08	;mov
		 #xD0 #x27 #xa0 #x44	;st
		 #xc1 #x07 #xa0 #x44	;ldf
		 #x81 #xC7 #xE0 #x08	;ret
		 #x81 #xE8 #x00 #x00	;restore
		)))
#+:i386
	(let ((calleus-offset 0))
	   (setq podcode (byte-string
		;; #x83 #xec #x08
		#x8d #x54 #x24 #x04
		#x52
		#x68  (ldb self-address 0 8)
		(ldb self-address 8 8) 
		(ldb self-address 16 8)
		(ldb self-address 24 8) 
		#xe8 0 0 0 0
		;;	#x89 #x44 #x24 #x04
		;;	#xd9 #x44 #x24 #x04
		#x5a #x5a #xc3
		#x90 #x90 #x90 #x90 ;;NOP
		#x90 #x90 #x90 #x90))
	   (if (eq :float result)
	       (replace podcode
			(list #x89 #x44 #x24 #x04 
			      #xd9 #x44 #x24 #x04
			      #x5a #x5a #xc3)
			:start1 15))
	;;  10 0000 8D542404              leal    4(%esp), %edx
	;;  11 0004 52                    pushl   %edx
	;;  12 0005 68785634              pushl   self
	;;  12      12
	;;  13 000a E8745634              call    calleus (relative)
	;;  13      12
	;;  14 000f 89442404              movl    %eax,4(%esp)
	;;  15 0013 D9442404              flds    4(%esp)
	;;  16 0017 83C408                addl    $8,%esp
	;;  17 001a C3                    ret
	   (setq calleus-offset (- *calleus* (+ (sys:address podcode) 8 15)))
	   (replace podcode
		    (list
			(ldb calleus-offset 0 8) (ldb calleus-offset 8 8)
			(ldb calleus-offset 16 8)  (ldb calleus-offset 24 8))
		    :start1 11)
	   podcode)
#|
#+:x86_64
	(let ((calleus-offset 0))
	   (setq podcode (byte-string
		#x55
		#x48 #x89 #xe5
		#x48 #x83 #xec #x08
		#x48 #x89 #x7d #xf8
		#x48 #x8d #x75 #xf8
		#x48 #xbf ;;#x00 #x00 #x00 #x00
		     (ldb self-address 0 8)
		     (ldb self-address 8 8)
		     (ldb self-address 16 8)
		     (ldb self-address 24 8)
		     (ldb self-address 32 8)
		     (ldb self-address 40 8)
		     (ldb self-address 48 8)
		     (ldb self-address 56 8)
		#xe8 #x00 #x00 #x00 #x00
		#xc9
		#xc3
		))
	;;  10 0000 8D542404              leal    4(%esp), %edx
	;;  11 0004 52                    pushl   %edx
	;;  12 0005 68785634              pushl   self
	;;  12      12
	;;  13 000a E8745634              call    calleus (relative)
	;;  13      12
	;;  14 000f 89442404              movl    %eax,4(%esp)
	;;  15 0013 D9442404              flds    4(%esp)
	;;  16 0017 83C408                addl    $8,%esp
	;;  17 001a C3                    ret
	   (setq calleus-offset (- *calleus* (+ (sys:address podcode) 16 27 4)))
	   (replace podcode
		    (list
			(ldb calleus-offset 0 8) (ldb calleus-offset 8 8)
			(ldb calleus-offset 16 8)  (ldb calleus-offset 24 8))
		    :start1 27)
		(format t "PODCODE ADDR: ~x~%" (+ 16 (sys:address podcode)))
	   podcode)
|#
#+:x86_64
	(let ((calleus-offset 0))
	   (setq podcode (byte-string
                #x48 #x83 #xec #x78
                #x48 #x89 #x3c #x24
                #x48 #x89 #x74 #x24 #x08
                #x48 #x89 #x54 #x24 #x10
                #x48 #x89 #x4c #x24 #x18
                #x4c #x89 #x44 #x24 #x20
                #x4c #x89 #x4c #x24 #x28
                #xf2 #x0f #x11 #x44 #x24 #x30
                #xf2 #x0f #x11 #x4c #x24 #x38
                #xf2 #x0f #x11 #x54 #x24 #x40
                #xf2 #x0f #x11 #x5c #x24 #x48
                #xf2 #x0f #x11 #x64 #x24 #x50
                #xf2 #x0f #x11 #x6c #x24 #x58
                #xf2 #x0f #x11 #x74 #x24 #x60
                #xf2 #x0f #x11 #x7c #x24 #x68
		#x48 #xbf ;;#x00 #x00 #x00 #x00 ;; mov $addr, %rdi
		     (ldb self-address 0 8)
		     (ldb self-address 8 8)
		     (ldb self-address 16 8)
		     (ldb self-address 24 8)
		     (ldb self-address 32 8)
		     (ldb self-address 40 8)
		     (ldb self-address 48 8)
		     (ldb self-address 56 8)
                #x48 #x89 #xe6
                #xb8 #x00 #x00 #x00 #x00
                #xe8 #x00 #x00 #x00 #x00
                #x48 #x83 #xc4 #x78
		#xc3                     ;; retq
                #x90 #x90 #x90 #x90
                #x90 #x90 #x90 #x90 #x90
		))
           (if (or (eq :float result) (eq :float32 result))
	       (replace podcode
			(list #x48 #x89 #x04 #x24
                              #xf2 #x0f #x10 #x04 #x24
                              #x48 #x83 #xc4 #x78
                              #xc3) :start1 104))
;; /* development version of pod-code for x86_64 written by Y.Kakiuchi */
;; 000:  48 83 ec 78             sub    $0x78,%rsp
;; 004:  48 89 3c 24             mov    %rdi,(%rsp)
;; 008:  48 89 74 24 08          mov    %rsi,0x8(%rsp)
;; 00d:  48 89 54 24 10          mov    %rdx,0x10(%rsp)
;  012:  48 89 4c 24 18          mov    %rcx,0x18(%rsp)
;; 017:  4c 89 44 24 20          mov    %r8,0x20(%rsp)
;; 01c:  4c 89 4c 24 28          mov    %r9,0x28(%rsp)
;; 021:  f2 0f 11 44 24 30       movsd  %xmm0,0x30(%rsp)
;; 027:  f2 0f 11 4c 24 38       movsd  %xmm1,0x38(%rsp)
;; 02d:  f2 0f 11 54 24 40       movsd  %xmm2,0x40(%rsp)
;; 033:  f2 0f 11 5c 24 48       movsd  %xmm3,0x48(%rsp)
;; 039:  f2 0f 11 64 24 50       movsd  %xmm4,0x50(%rsp)
;; 03f:  f2 0f 11 6c 24 58       movsd  %xmm5,0x58(%rsp)
;; 045:  f2 0f 11 74 24 60       movsd  %xmm6,0x60(%rsp)
;; 04b:  f2 0f 11 7c 24 68       movsd  %xmm7,0x68(%rsp)
;; 051:  48 bf 77 ef cd ab 77    mov    $0xabcdef77abcdef77,%rdi
;; 058:  ef cd ab
;; 05b:  48 89 e6                mov    %rsp,%rsi
;; 05e:  b8 00 00 00 00          mov    $0x0,%eax
;; 063:  e8 a0 01 00 00          callq  4007b8 <calleus>
;;; return integer
;; 068:  48 83 c4 78             add    $0x78,%rsp
;; 06c:  c3                      retq
;;; return float
;; 068:  48 89 04 24             mov    %rax,(%rsp)
;; 06c:  f2 0f 10 04 24          movsd  (%rsp),%xmm0
;; 071:  48 83 c4 78             add    $0x78,%rsp
;; 075:  c3                      retq
	   (setq calleus-offset (- *calleus* (+ (sys:address podcode) 16 100 4)))
	   (replace podcode
		    (list
			(ldb calleus-offset 0 8) (ldb calleus-offset 8 8)
			(ldb calleus-offset 16 8)  (ldb calleus-offset 24 8))
		    :start1 100)
           (if *debug* (format t "PODCODE ADDR: ~x~%" (+ 16 (sys:address podcode))))
	   podcode)
#+:sh4 
(progn
	(setq podcode (byte-string
		       #xe6 #x2f;;	e6 2f       	mov.l	r14,@-r15
		       #x22 #x4f;;	22 4f       	sts.l	pr,@-r15
		       #x05 #xd1;;	05 d1       	mov.l	40043c <bb+0x1c>,r1	! 0x4003e0
		       #xfc #x7f;;	fc 7f       	add	#-4,r15
		       #xf3 #x6e;;	f3 6e       	mov	r15,r14
		       #x42 #x2e;;	42 2e       	mov.l	r4,@r14
		       #x04 #xd4;;	04 d4       	mov.l	400440 <bb+0x20>,r4	! 0x12345678
		       #x0b #x41;;	0b 41       	jsr	@r1
		       #xe3 #x65;;	e3 65       	mov	r14,r5
		       #x04 #x7e;;	04 7e       	add	#4,r14
		       #xe3 #x6f;;	e3 6f       	mov	r14,r15
		       #x26 #x4f;;	26 4f       	lds.l	@r15+,pr
		       #x0b #x00;;	0b 00       	rts	
		       #xf6 #x6e;;	f6 6e       	mov.l	@r15+,r14
		       ;;#xe0 #x03;;	e0 03       	.word 0x03e0
		       ;;#x40 #x00;;	40 00       	.word 0x0040
		       (ldb *calleus* 0 8)
		       (ldb *calleus* 8 8)
		       (ldb *calleus* 16 8)
		       (ldb *calleus* 24 8)
		       ;;#x78 #x56;;	78 56       	mov.l	@(32,r7),r6
		       ;;#x34 #x12;;	34 12       	mov.l	r3,@(16,r2)
		       (ldb self-address 0 8)
		       (ldb self-address 8 8) 
		       (ldb self-address 16 8)
		       (ldb self-address 24 8) 
		       #x09 #x00;;	09 00       	nop	
		       #x09 #x00;;	09 00       	nop	
		       #x09 #x00;;	09 00       	nop
		       )
	      ))
#-(or :sun3 :sun4 :i386 :x86_64)
	 (error "not yet implemented for this processor")
      (cond 
	 ((listp func)
	   (if (eq (car func) 'lisp:lambda-closure)
	       (setq func (append '(lisp:lambda) (nthcdr 4 func)))))
	 ((derivedp func closure)
	       (setq func
		 (let* ((cfunc (instantiate compiled-code)))
		   (setq (cfunc . type) 0
			 (cfunc . codevector) (func . codevector)
			 (cfunc . quotevector) (func . quotevector)
			 (cfunc . entry) (func . entry))
		   cfunc))))
      (setq function func)
      (setq paramtypes param
	    resulttype result)
      self))
)



(defmacro defun-c-callable (name param &rest forms)
  (let ((paramspecs
	    (mapcar #'(lambda (x) (if (atom x) :integer (cadr x))) param))
        (paramsyms
	    (mapcar #'(lambda (x) (if (atom x) x (car x))) param))
	(result (if (keywordp (car forms))
		    (car forms)
		    :integer))
	(bod (if (keywordp (car forms))
		 (cdr forms)
	       forms))
	)
    `(progn
       (unintern ',name *package*)
       (send (let ((symbol foreign-pod))
		(intern ',(string name) *package*))
	     :init ',paramspecs ',result
	     #'(lambda ,paramsyms . ,bod)))))


(defun pod-address (x) (send x :pod-address))


;(eval-when (load)
;  (defvar *eus-module*
;    (let ((m (instance foreign-module)))
;      (setq (m . symbol-table) 
;	     (read-symbol-table "/usr/local/bin/eus"))
;      (setq (m . codevector) 0)
;      m)) )


;;;;	cstruct
;;;;	Enables handling C's struct in euslisp
;;;	
;;;	1987-Nov
;;;	Copyright Toshihiro MATSUI
;;;
;;;	(defcstruct structname
;;;		    (slotid :primitive-type)
;;;		    (slotid structname)
;;;		    (slotid (:primitive-type [*] [dimension])))

(defvar sizeof-types
  `((:pointer ,lisp::sizeof-*) (:long ,lisp::sizeof-long)
    (:int ,lisp::sizeof-int) (:integer ,lisp::sizeof-int)
    (:short ,lisp::sizeof-short) (:char ,lisp::sizeof-char)
    (:character ,lisp::sizeof-char) (:float ,lisp::sizeof-float)
    (:double ,lisp::sizeof-double) (:word 2) (:byte 1)))

(defun byte-size (typekey)
  (cadr (assq typekey sizeof-types)))

(defclass cstructclass :super vectorclass :slots (slotlist))

(defmethod cstructclass
 (:slotlist (&optional slots)
    (if (null slots) (return-from :slotlist slotlist))
    (setq slotlist nil)
    (let ((offset 0) (slotsize 0) (typespec) (element_size) (element_count 1)
	  (s) (typename) slist)
	(dolist (sl slots)	;expand reference to other cstructs
	   (setq typespec (cadr sl))
	   (cond ((and (symbolp typespec) (not (keywordp typespec)))
		  (dolist (x (send (symbol-value (cadr sl)) :slotlist))
		     (push (cons (intern (concatenate string	
				      (string (car sl)) "." (string (car x))))
				 (cdr x))
			   slist)))
		 (t (push sl slist))))
	(setq slist (nreverse slist))
	(dolist (sl slist)
	    (setq typename (car sl)
	    	  typespec (cadr sl)
		  s (cddr sl)
		  element_size (byte-size typespec))
	    (unless (keywordp typespec)
		(error "keyword expected for cstruct type"))
	    (when (eq (car s) '*)
		(setq typespec :pointer
		      element_size lisp::sizeof-*)	;pointer
		(pop s))
	    (setq element_count (if (car s) (car s) 1))
	    (setq slotsize (* element_size element_count))
	    (setq offset
		  (* (/ (+ offset element_size -1) element_size) element_size))
	    (push (list typename	;0
			typespec	;1
			element_count	;2
			element_size	;3
			offset		;4
			slotsize)	;5
		  slotlist)
	    (inc offset slotsize))
      (setq slotlist (nreverse slotlist))
      (setq size offset)
      slotlist))
 (:size () size)
 (:slot (id)
   (if id
     (assq id slotlist)
     (car slotlist)))
 (:offset (id &optional index)
    (let ((slot (send self :slot id)))
	(unless slot  (error "no such cstruct slot ~s" id))
	(cond (index
		(if (>= index (elt slot 2)) (error "index out of range"))
		(+ (elt slot 4) (* index  (elt slot 3))) )
	      (t  (elt slot 4)))))
 (:access (id &optional index)
    (let ((slot (send self :slot id)) (offset))
	(unless slot  (error "no such cstruct slot"))
	(cond (index
		(if (>= index (elt slot 2)) (error "index out of range"))
		(setq offset (+ (elt slot 4) (* index  (elt slot 3))) ))
	      (t (setq offset  (elt slot 4))))
	(list (elt slot 1) offset)))
  )

(defclass cstruct :super string :element-type :byte)

(defmethod cstruct
 (:get (id &optional index)
    (let ((slot (send (class self) :access id index)))
	(sys:peek self (cadr slot) (car slot))) )
 (:set (val id &optional index)
    (let ((slot (send (class self) :access id index)))
	(sys:poke val self (cadr slot) (car slot))))
 )


(defmacro defcstruct (struct-name &rest slotlist)
   (let (accessors slotname getter setter setter-fn type (offset 0)
	 slot slotsize substruct expanded-slotlist
	 element_type element_size accessor accessor-fn accessor-name
	 (struct-name-string (string struct-name)) (super 'cstruct))
     (when (eq (car slotlist) :super)
       (setq super (cadr slotlist))
       (setq slotlist (cddr slotlist)))
     (dolist (s slotlist)
	(setq type (cadr s))
	(if (and (symbolp type) (not (keywordp type))) ;struct of struct
	    (dolist (x (send (symbol-value (cadr s)) :slotlist))
		(push (list (intern (concatenate  string
				(string (car s)) "." (string (car x))))
			    (cadr x))
		      expanded-slotlist) )
	    (push s expanded-slotlist)))
     (dolist (s (nreverse expanded-slotlist))
	(setq slotname (string (car s))
	      type (cadr s)
	      accessor-name (concatenate string 
					 struct-name-string "-" slotname)
	      accessor (intern accessor-name)
	      accessor-fn (intern (concatenate string "SET-" accessor-name))
	      s (cddr s))
	(cond ((null s)
		(setq slotsize (byte-size type)
		      offset (* (/ (+ offset slotsize -1) slotsize) slotsize)
		      getter `(defun ,accessor (s)
				(sys:peek s ,offset ,type))
		      setter `(defsetf ,accessor ,accessor-fn)
		      setter-fn `(defun ,accessor-fn (s val)
				   (sys:poke val s ,offset ,type))))
	      (t
		(setq element_type type)	;array of pointer or primitive
		(when (eq (car s) '*)		;pointer 
		   (setq element_type :long)
		   (pop s))
		(setq element_size (byte-size element_type)
		      slotsize (* element_size (if (car s) (car s) 1))
		      offset (* (/ (+ offset element_size -1)
				   element_size) element_size))
		(cond
		   ((memq element_type '(:char :byte))
		    (setq getter `(defun ,accessor (s &optional i)
				    (if i
				      (sys:peek s (+ ,offset i) :byte)
				      (subseq s ,offset (+ ,offset ,slotsize)))))
		    (setq setter `(defsetf ,accessor ,accessor-fn)
			  setter-fn `(defun ,accessor-fn (s i &rest val)
				       (if val
					 (sys:poke (car val)
						   (+ ,offset i) :byte)
					 (replace s i :start1 ,offset
						      :end2 (length i))))))
		   (t
		    (setq getter `(defun ,accessor (s i)
				    (declare (fixnum i))
				    (sys:peek s (+ ,offset
						   (* i ,element_size))
					      ,element_type)))
		    (setq setter `(defsetf ,accessor ,accessor-fn)
			  setter-fn `(defun ,accessor-fn (s i val)
				       (declare (fixnum i))
				       (sys:poke val s
						 (+ ,offset
						    (* i ,element_size))
						 ,element_type))))))
	      (t (error "illegal type specifier")))
	(push getter accessors)
	(push setter accessors)
	(push setter-fn accessors)
	(inc offset slotsize))
     `(progn
	  (defclass ,struct-name :super ,super
				 :element-type :byte
				 :metaclass cstructclass)
	  (send ,struct-name :slotlist ',slotlist)
	  ,@(nreverse accessors)
	  ',struct-name)))

(defclass carray :super cstruct)

(defmethod carray
  (:get (&optional (index 0))
    (send-super :get nil index))
  (:set (val &optional (index 0))
    (send-super :set val nil index)))

(defmacro defcarray (array-name type &optional (size 1))
  (let* ((field (gensym (symbol-name type)))
	 (array-name-string (symbol-name array-name))
	 (accessor-string (concatenate string array-name-string "-"
				       (symbol-name field)))
	 (set (intern (concatenate string "SET-" array-name-string)))
	 (get-field (intern accessor-string))
	 (set-field (intern (concatenate string "SET-" accessor-string))))
    `(progn
       (defcstruct ,array-name :super carray (,field ,type ,size))
       (defun ,array-name (s &optional (i 0))
	 (,get-field s i))
       (defun ,set (s i &optional val)
	 (if val
	   (,set-field s i val)
	   (,set-field s 0 i)))
       (defsetf ,array-name ,set)
       ',array-name)))

(defclass foreign-string :super vector :element-type :foreign)
(defun make-foreign-string (addr size)
   (let* ((fstr (instantiate foreign-string size)) )
      (sys:poke addr (+ (* 2 lisp::sizeof-*) (sys:address fstr)) :long)
      fstr))

(provide :eusforeign "@(#)$Id$")
