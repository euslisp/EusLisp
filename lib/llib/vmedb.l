;;;; VMEbus debugger
;;;;	for the installation of MMD on sun4
;;;;	1988-Jun-15
;;;;	Copyright(c) Toshihiro MATSUI
;;;;

(defvar *memory-stream*)
(defvar *memory*)
(defvar *devname*) 
(defvar *prompt*)
(defvar *stred-base* 16)

(defun map-memory (devstream &key (length 65536)
				  (offset 0)
				  (protection 7))
   (let ((vaddr (unix:valloc length)))
	(if (< vaddr 0) (error "valloc failed"))
	(if (< (unix:mmap vaddr length protection 1 devstream offset)
	       0)
	    nil
	    (make-foreign-string vaddr length))))


(defun read-hex (stream default)
  (let ((*read-base* *stred-base*)) (read stream nil default)))

(defun read-string (stream default)
  (let (ch (s (make-array '(1) :fill-pointer 0 :element-type :character)))
    (while (eq (setq ch (read-char stream)) #\ ))
    (while (> ch #\ )  (vector-push-extend ch s)
		       (setq ch (read-char stream nil #\ )))
    (s . entity)))

(defun dumpstring (str addr count size &optional (file t))
   (let ((i 0)
	 (words/line (cdr (assq size '((byte . 16) (short . 8) (long . 4))))))
      (dotimes (i count)
         (if (= (mod i words/line) 0) (format file "~8,8x " addr))
	 (case size
	   (byte  (format file "~2,2x " (logand #xff (sys:peek str addr :byte)))
		  (inc addr 1))
	   (short (format file "~4,4x " (logand #xffff (sys:peek str addr :short)))
		  (inc addr 2))
	   (long  (format file "~8,8x " (sys:peek str addr :long))
		  (inc addr 4)))
         (if (= (mod i words/line) (1- words/line)) (terpri file)))))

(defun examinestring (str addr mode &optional (file t))
   (let ((comstr) (newdata))
     (while t
	(format file "~8,8x " addr)
	(case mode
	   (byte  (format file "~2,2x " (logand #xff (sys:peek str addr :byte))))
	   (short (format file "~4,4x " (logand #xffff (sys:peek str addr :short))))
	   (long  (format file "~8,8x " (sys:peek str addr :long))))
        (finish-output file)
	(setq comstr (make-string-input-stream (read-line)))
	(setq newdata (read-hex comstr nil))
	(cond
	  ((numberp newdata)
		(case mode
		   (byte  (sys:poke newdata str addr :byte)  (inc addr 1))
		   (short (sys:poke newdata str addr :short) (inc addr 2))
		   (long  (sys:poke newdata str addr :long)  (inc addr 4))))
	  ((memq newdata '(- b))
		(dec addr (cdr (assq mode '((byte . 1) (short . 2) (long . 4))))))
	  ((memq newdata '(q quit)) (return-from examinestring nil))
	  ((null newdata)
		(inc addr (cdr (assq mode '((byte . 1) (short . 2) (long . 4))))))
	  (t (format file "?~%")))
	)) )

(defun fillstring (data memory address count mode)
   (dotimes (i count)
	(case mode
	   (byte  (sys:poke data memory address :byte)  (inc address 1))
	   (short (sys:poke data memory address :short) (inc address 2))
	   (long  (sys:poke data memory address :long)  (inc address 4)))))

(defun vmedb ()
   (let ((comstr) (command) (access-mode 'short	)
	 (address 0) (count 64) (data 0))
     (if (null *memory*) (setq *prompt* ": "))
     (while t
       (catch 'vmedb
	(princ *prompt*) (finish-output t)
	(setq comstr (make-string-input-stream (read-line)))
	(setq command (read comstr nil nil))
	(case command
	  ((quit q) (return-from vmedb t))
	  ((short byte long) (setq access-mode command))
	  ((address addr a) (setq address (read-hex comstr address)))
	  ((+) (inc address (read-hex comstr 1)))
	  ((-) (dec address (read-hex comstr 1)))
	  ((count) (setq count (read-hex comstr count)))
	  ((v vme)
	     (let* ((address-width (read comstr nil 32))
		    (data-width (read comstr nil 32))
		    (offset (intvector (read-hex comstr 0) 0))
		    (size (read-hex comstr 65536)))
	        (setq *devname* (format nil "/dev/vme~sd~s"
					  address-width data-width))
	        (when *memory* (close *memory-stream*))
	        (setq *memory-stream* (open *devname* :direction :io
					    :if-does-not-exist nil))
		(cond
		   ((null *memory-stream*)
		    (warning-message 1 "cannot open ~s~%" *devname*))
		   (t
		    (setq *memory* (map-memory *memory-stream*
						:length size
						:offset offset))
		    (setq *prompt* (format nil "vme~dd~d: "
					      address-width data-width))
		    (setq address 0))) ))
	  ((device)
	     (setq *devname* (read-string comstr nil))
	     (let* ((offset (intvector (read-hex comstr 0) 0))
		    (size (read-hex comstr 65536)))
	        (when *memory* (close *memory-stream*))
	        (setq *memory-stream* (open *devname* :direction :io
					    :if-does-not-exist nil))
		(cond
		   ((null *memory-stream*)
		    (warning-message 1 "cannot open ~s~%" *devname*))
		   (t
		    (setq *memory* (map-memory *memory-stream*
						:length size
						:offset offset))
		    (setq *prompt* (format nil "~s: " *devname*)
			  address 0))) ))
	  ((dump d)
	     (when *memory*
	        (setq address (read-hex comstr address))
	        (setq count (read-hex comstr count))
	        (dumpstring *memory* address count access-mode)))
	  ((next n)
	     (when *memory*
	 	 (inc address (* count (cdr (assq access-mode 
				'((byte . 1) (short . 2) (long . 4))))))
	         (dumpstring *memory* address count access-mode)))
	  ((previous p)
	     (when *memory*
	         (dec address (* count (cdr (assq access-mode
				 '((byte .1) (short . 2) (long . 4))))))
	     	 (dumpstring *memory* address count access-mode)))
	  ((examine ex e x)
	     (when *memory*
		 (setq address (read-hex comstr address))
	         (examinestring *memory* address access-mode)))
	  ((f fill)
	      (setq data (read-hex comstr 0))
	      (setq address (read-hex comstr address))
	      (setq count (read-hex comstr count))
	      (fillstring data *memory* address count access-mode))
	  ((lisp l)
	     (catch 'eusexit (reploop "lisp> ")))
	  ((? h help)
	     (format t "
	A[ddress] num		set address
	C[ount] num		set word count for dump
	D[ump] [addr] [count]	display memory contents
	E[xamine] [addr]	examine and deposite memory
	F[ill] [data] [addr] [count] fill data from addr count times
	Q[uit]			terminate debugging
	byte			set access mode to byte(8bit)
	short			set access mode to short(16bit)
	long			set access mode to long(32bit)
	V[me] [addr-width] [data-width] [offset] [windowsize]
				open vme bus
				addr-width is one of 16,24 or 32
				data-width is one of 16 or 32
				offset is multiple of 64KB
				default windowsize is 64KB
	device devname [offset] [window-size]
				open memory device such as /dev/fb
	+,- [num]		increment or decrement address
	N[ext]			dump next memory contents
	P[revious]		dump previous memory contents
	L[isp]			escape to eusLisp~%"))
	  (t (format t "?~%")))))))
	     
(defun vmedb-sighandler (c s)
   (warning-message 1 " interrupted~%")
   (throw 'vmedb nil))

(defun vme-debug (argv)
  ;; vmedebug address-width data-width offset(64KB-unit)
     (format t "VMEbus (memory device) debugger~%")
     (unix:signal unix:sigint 'vmedb-sighandler)
