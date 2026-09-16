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
#-(or :word-size=64)
	(+ 8 (sys:address podcode))
#+(or :word-size=64)
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
;; development version of pod-code for x86_64 written by Y.Kakiuchi;
;; self/*calleus* embedded as absolute 64bit immediates (movabs +
;; call *%reg) rather than a pc-relative call. A pc-relative call's
;; 32bit displacement can't reach a *calleus* (in eus's own .text/lib)
;; that lands more than +-2GB from this pod-code object (in the Lisp
;; heap) in the process's address space -- entirely possible with
;; ASLR on a modern 64bit Linux -- which silently truncates the
;; displacement and calls a bogus address. See the aarch64 stub above,
;; which never had a pc-relative option to begin with (AArch64's BL
;; only has a +-128MB range) and uses the same absolute-address
;; approach.
	(let* ((sa self-address)
	       (ca *calleus*))
	   (setq podcode
	     (apply #'byte-string
	       (append
		 (list
                    #x48 #x83 #xec #x78                 ;; sub  $0x78, %rsp
                    #x48 #x89 #x3c #x24                 ;; mov  %rdi, (%rsp)
                    #x48 #x89 #x74 #x24 #x08             ;; mov  %rsi, 0x8(%rsp)
                    #x48 #x89 #x54 #x24 #x10             ;; mov  %rdx, 0x10(%rsp)
                    #x48 #x89 #x4c #x24 #x18             ;; mov  %rcx, 0x18(%rsp)
                    #x4c #x89 #x44 #x24 #x20             ;; mov  %r8,  0x20(%rsp)
                    #x4c #x89 #x4c #x24 #x28             ;; mov  %r9,  0x28(%rsp)
                    #xf2 #x0f #x11 #x44 #x24 #x30         ;; movsd %xmm0, 0x30(%rsp)
                    #xf2 #x0f #x11 #x4c #x24 #x38         ;; movsd %xmm1, 0x38(%rsp)
                    #xf2 #x0f #x11 #x54 #x24 #x40         ;; movsd %xmm2, 0x40(%rsp)
                    #xf2 #x0f #x11 #x5c #x24 #x48         ;; movsd %xmm3, 0x48(%rsp)
                    #xf2 #x0f #x11 #x64 #x24 #x50         ;; movsd %xmm4, 0x50(%rsp)
                    #xf2 #x0f #x11 #x6c #x24 #x58         ;; movsd %xmm5, 0x58(%rsp)
                    #xf2 #x0f #x11 #x74 #x24 #x60         ;; movsd %xmm6, 0x60(%rsp)
                    #xf2 #x0f #x11 #x7c #x24 #x68         ;; movsd %xmm7, 0x68(%rsp)
                    #x48 #xbf                             ;; movabs $self-address, %rdi
                    (ldb sa 0 8) (ldb sa 8 8) (ldb sa 16 8) (ldb sa 24 8)
                    (ldb sa 32 8) (ldb sa 40 8) (ldb sa 48 8) (ldb sa 56 8)
                    #x48 #x89 #xe6                       ;; mov  %rsp, %rsi   (cargv pointer)
                    #xb8 #x00 #x00 #x00 #x00             ;; mov  $0x0, %eax
                    #x48 #xb8                             ;; movabs $calleus, %rax
                    (ldb ca 0 8) (ldb ca 8 8) (ldb ca 16 8) (ldb ca 24 8)
                    (ldb ca 32 8) (ldb ca 40 8) (ldb ca 48 8) (ldb ca 56 8)
                    #xff #xd0)                            ;; call *%rax
		 (if (or (eq :float result) (eq :float32 result))
		     (list
			#x48 #x89 #x04 #x24               ;; mov   %rax, (%rsp)
			#xf2 #x0f #x10 #x04 #x24          ;; movsd (%rsp), %xmm0
			#x48 #x83 #xc4 #x78               ;; add   $0x78, %rsp
			#xc3)                             ;; ret
		     (list
			#x48 #x83 #xc4 #x78               ;; add   $0x78, %rsp
			#xc3)))))                          ;; ret
           (if *debug* (format t "PODCODE ADDR: ~x~%" (+ 16 (sys:address podcode))))
	   ;; i386/x86_64 Linux historically grants heap pages execute
	   ;; permission via the kernel's READ_IMPLIES_EXEC personality
	   ;; quirk, triggered by this binary's non-NX (execstack) marking
	   ;; -- but that's a property of the *kernel* honoring it, not of
	   ;; this process, and isn't guaranteed on every host a container
	   ;; like this one might run under (e.g. CI running an old
	   ;; ubuntu:trusty *userland* on a current, possibly hardened,
	   ;; *host* kernel). Explicitly mprotect PROT_EXEC rather than
	   ;; relying on that, same as aarch64 (which never had the
	   ;; READ_IMPLIES_EXEC option to begin with) already has to.
	   (mprotect-exec (sys:address podcode) (+ 16 (length podcode)))
	   podcode)
#+:aarch64
;; AArch64 (ARM64, AAPCS64) pod-code trampoline.
;; Unlike the i386/x86_64 stubs, self-address and the *calleus* entry
;; point are embedded as absolute 64bit immediates (movz/movk, 16 bits
;; at a time) instead of a pc-relative call, so no relocation/offset
;; bookkeeping is needed once the byte-string is built.
;; AAPCS64 has 8 integer argument registers (x0-x7), unlike x86_64's 6
;; (SysV: rdi,rsi,rdx,rcx,r8,r9), so the cargv[] layout this trampoline
;; builds differs from the i386/x86_64 stubs; calleus.c's aarch64 branch
;; (EUS_MAX_IREGS) is written to match:
;;   cargv[0..7]  <- x0..x7   (8 integer/pointer args)
;;   cargv[8..15] <- d0..d7   (8 float/double args)
;;   cargv[16..]  == original incoming sp (any stack-passed args)
;; x30 (LR) is saved below cargv (at [sp,#0], cargv itself starts at
;; [sp,#16]) rather than inside it: blr has no free cargv slot to steal
;; the way the i386/x86_64 stubs do (6+8=14 leaves 2 spare slots before
;; their 16-slot vargv boundary; aarch64's 8+8=16 leaves none), and
;; cargv[16] must land exactly on the incoming sp so it lines up with
;; any genuine stack-passed arguments (aarch64 calls, unlike x86's
;; `call`, push nothing on the stack, so the incoming sp itself is
;; already the first stack argument's address).
	(let* ((sa self-address)
	       (ca *calleus*)
	       (w0 (logior #xd2800000 (ash (ldb sa 0 16) 5)))    ;; movz x0, sa[ 0:16]
	       (w1 (logior #xf2a00000 (ash (ldb sa 16 16) 5)))   ;; movk x0, sa[16:32], lsl #16
	       (w2 (logior #xf2c00000 (ash (ldb sa 32 16) 5)))   ;; movk x0, sa[32:48], lsl #32
	       (w3 (logior #xf2e00000 (ash (ldb sa 48 16) 5)))   ;; movk x0, sa[48:64], lsl #48
	       (w4 (logior #xd2800009 (ash (ldb ca 0 16) 5)))    ;; movz x9, ca[ 0:16]
	       (w5 (logior #xf2a00009 (ash (ldb ca 16 16) 5)))   ;; movk x9, ca[16:32], lsl #16
	       (w6 (logior #xf2c00009 (ash (ldb ca 32 16) 5)))   ;; movk x9, ca[32:48], lsl #32
	       (w7 (logior #xf2e00009 (ash (ldb ca 48 16) 5)))   ;; movk x9, ca[48:64], lsl #48
	       (w32 #'(lambda (w) (list (ldb w 0 8) (ldb w 8 8) (ldb w 16 8) (ldb w 24 8)))))
	  (setq podcode
	    (apply #'byte-string
	      (append
		(list
		   #xff #x43 #x02 #xd1     ;; sub  sp, sp, #0x90
		   #xfe #x03 #x00 #xf9     ;; str  x30, [sp, #0]     (LR save)
		   #xe0 #x0b #x00 #xf9     ;; str  x0,  [sp, #16]    (cargv[0])
		   #xe1 #x0f #x00 #xf9     ;; str  x1,  [sp, #24]
		   #xe2 #x13 #x00 #xf9     ;; str  x2,  [sp, #32]
		   #xe3 #x17 #x00 #xf9     ;; str  x3,  [sp, #40]
		   #xe4 #x1b #x00 #xf9     ;; str  x4,  [sp, #48]
		   #xe5 #x1f #x00 #xf9     ;; str  x5,  [sp, #56]
		   #xe6 #x23 #x00 #xf9     ;; str  x6,  [sp, #64]
		   #xe7 #x27 #x00 #xf9     ;; str  x7,  [sp, #72]    (cargv[7])
		   #xe0 #x2b #x00 #xfd     ;; str  d0,  [sp, #80]    (cargv[8])
		   #xe1 #x2f #x00 #xfd     ;; str  d1,  [sp, #88]
		   #xe2 #x33 #x00 #xfd     ;; str  d2,  [sp, #96]
		   #xe3 #x37 #x00 #xfd     ;; str  d3,  [sp, #104]
		   #xe4 #x3b #x00 #xfd     ;; str  d4,  [sp, #112]
		   #xe5 #x3f #x00 #xfd     ;; str  d5,  [sp, #120]
		   #xe6 #x43 #x00 #xfd     ;; str  d6,  [sp, #128]
		   #xe7 #x47 #x00 #xfd)    ;; str  d7,  [sp, #136]   (cargv[15])
		(funcall w32 w0) (funcall w32 w1) (funcall w32 w2) (funcall w32 w3)
		(list #xe1 #x43 #x00 #x91) ;; add  x1, sp, #16   (cargv pointer)
		(funcall w32 w4) (funcall w32 w5) (funcall w32 w6) (funcall w32 w7)
		(list
		   #x20 #x01 #x3f #xd6     ;; blr  x9       (call calleus)
		   #xfe #x03 #x40 #xf9)    ;; ldr  x30, [sp, #0]
		(if (or (eq :float result) (eq :float32 result))
		    (list #x00 #x00 #x67 #x9e) ;; fmov d0, x0  (reinterpret result as double)
		    nil)
		(list
		   #xff #x43 #x02 #x91     ;; add  sp, sp, #0x90
		   #xc0 #x03 #x5f #xd6)))) ;; ret
	  ;; the podcode byte-string lives in the ordinary (non-executable)
	  ;; Lisp heap; aarch64 Linux, unlike i386/x86_64, does not grant
	  ;; heap pages execute permission by default, so mark this
	  ;; object's page(s) PROT_EXEC before it can be jumped into.
	  (mprotect-exec (sys:address podcode) (+ 16 (length podcode)))
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
#-(or :sun3 :sun4 :i386 :x86_64 :aarch64)
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
