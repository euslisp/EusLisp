;;;; gifcat.l
;;;	concatenates multiple gif figures horizontally and produces one 
;;;	gif file.  Unnecessary fields like comments are excluded.
;;;	Specially designed for display of visit count to a web site.
;;;;	February 6, 2003 (c) Toshihiro Matsui
;;;;
;;;	(concatenate-gif "outfile.gif" "infile1.gif" "infile2.gif" ...)
;;;	(number-gif  (n &optional (digits 6) (dir "gif1") (basedir "/home/www/cgi-bin/dream/")))
;;;	timing: (number-gif 123 6) gererates 900-1200 byte gif output
;;;	on EPIA-533MHz  (roughly equivalent to 266MHz Pentium)
;;;		interpreted--- 19-22ms
;;;		compiled------ 2.0-3.0ms 	

(export '(gif concatenate-gif  number-gif))

(defclass gif :super propertied-object
	:slots (LogicalScreenWidth
		LogicalScreenHeight
		FLAG
		GlobalColorTable
		BackGroundColorIndex
		PixelAspectRatio
		imageblocks
		index	gifbuf	
		blocks
		))

(defmethod gif
 (:next-byte (&optional i)
    (if i (setq index i))
    (prog1 (sys:peek gifbuf index :byte) (incf index)))
 (:next-short (&optional i)
    (if i (setq index i))	;better to compose from bytes
    (prog1 (sys:peek gifbuf index :short) (incf index 2)))
 (:next-n-bytes (n &optional i)
    (if i (setq index i))	;better to compose from bytes
    (subseq gifbuf index (incf index n)))
 (:next-var-block (&optional i)
    (if i (setq index i))	;better to compose from bytes
    (let ((blocklen (send self :next-byte)))
       (if (/= blocklen 0)
	   (send self :next-n-bytes blocklen)
	   nil)))
 (:read-file (gifname)	;string or pathname
   (let* ((fsize) (SizeofGlobalColorTable 0))
    (unless (probe-file gifname) (error "gif file does not exist" gifname))
    (setq fsize (file-size gifname))
    (setq gifbuf (make-string fsize))
    (with-open-file (f gifname)
	(unix:uread (send f :fd) gifbuf fsize ))
    ;; analyze the global header
    (setq index 6)
    (setq LogicalScreenWidth (send self :next-short))
    (setq LogicalScreenHeight (send self :next-short))
    (setq Flag (send self :next-byte))
    ;; (setq GlobalColorTableFlag (logtest Flag #x80))
    ;; (setq ColorResolution (1+ (ldb Flag 4 3)))	; num bits for a pixel color
    ;; (setq SortFlag (logtest Flag #x08))
    (setq BackGroundColorIndex (send self :next-byte))
    (setq PixelAspectRatio (send self :next-byte))
			;; (/ (+ 15 (send self :next-byte)) 64.0)
    (if (logtest flag #x80)
	(progn
	    (setq SizeofGlobalColorTable 		; num bytes 
		(* 3 (expt 2 (1+ (ldb Flag 0 3) ))))
	    (setq GlobalColorTable
		 (send self :next-n-bytes SizeofGlobalColorTable)))
	(setq globalcolortable (make-string 0)))
    ;; blocks
    (while t
	(case (send self :next-byte)
	  (#x3b (return))
	  (#x2c
	     (push (instance gif-imageblock :init self) blocks))
	  (#x21
	     (case (send self :next-byte)
		(#xf9 (push (instance gif-graphicControlExtension :init self)
			blocks))
		(#xfe (push (instance gif-CommentExtension :init self)
			blocks))
		(#x01  (error "gif PlainTextExtension is not yet implemented")
			;; (send self :plainTextExtension)
			)
		(#xff  (error "gif ApplicationExtension is not yet implemented")
			;;(send self :applicationExtension)
			)))
	  (t
		(error "unknown gif block or collapsed gif file" ))
	) )    )
   (setq Blocks (nreverse Blocks))
   self)
 (:width () LogicalScreenWidth )
 (:height () LogicalScreenHeight)
 (:flag () flag)
 (:colortable () globalcolortable)
 (:backgroundColorIndex () backgroundColorIndex)
 (:pixelAspectRatio () PixelAspectRatio)
 )

(defclass gif-imageBlock :super propertied-object
	:slots (giffile
		ImageLeftPosition ImageTopPosition
		ImageWidth ImageHeight
		Flag
		LocalColorTable
		LZW-MinimumCodeSize
		ImageData))

(defmethod gif-ImageBlock
 (:init (parent)
     (setq giffile parent)
     (setq ImageLeftPosition (send giffile :next-short))
     (setq ImageTopPosition (send giffile :next-short))
     (setq ImageWidth (send giffile :next-short))
     (setq ImageHeight (send giffile :next-short))
     (setq Flag (send giffile :next-byte))
     (setq LocalColorTable
	   (if (logtest Flag #x80)
		(send giffile :next-n-bytes
			(* 3 (expt 2 (1+ (ldb flag 0 3)))))
		""))
     (setq LZW-MinimumCodeSize (send giffile :next-byte))
     (let (x)
        (while (setq x (send giffile :next-var-block)) 
	   (push x imageData) )
	(setq imagedata (nreverse imagedata)))
     self)
 (:width () ImageWidth)
 (:height () ImageHeight)
 (:write-out (gout &optional (xpos 0) (ypos 0))
	(binout-byte gout #x2c)
	(binout-short gout xpos)
	(binout-short gout ypos)
	(binout-short gout ImageWidth)
	(binout-short gout imageheight)
	(cond ((equal (send giffile :colortable) global-color-table)
		(binout-byte gout flag)
		(binout-block gout LocalColorTable))
	      (t 
		(binout-byte gout 
			(logior flag #x80 (logand (gif-flag giffile) 7)))
		(binout-block gout (send giffile :ColorTable))))
	(binout-byte gout LZW-MinimumCodeSize)
	(dolist (b imagedata)   (binout-var-block gout b))
	(binout-byte gout 0))
  )

(defclass gif-graphicControlExtension :super propertied-object
	:slots (giffile flag delayTime TransparentColor Index extension))

(defmethod gif-GraphicControlExtension
 (:init (parent)
    (setq giffile parent)
    ;;(setq flag (send giffile :next-byte))
    ;;(setq delayTime (send giffile :next-short))
    ;;(setq transparentColorIndex (send giffile :next-byte))
    (setq extension (send giffile :next-var-block))
    (if (/= 0 (send giffile :next-byte))
	(error "gif graphicControlExtension does not terminate"))
    self)
 (:write-out (gout)
    (binout-byte gout #x21)
    (binout-byte gout #xF9)
    (binout-var-block gout extension)
    (binout-byte gout 0))
 )

(defclass gif-CommentExtension :super propertied-object
	:slots (giffile CommentData))

(defmethod gif-CommentExtension
 (:init (parent)
    (setq giffile parent)
    (let (x)
       (while (setq x (send giffile :next-var-block))
	  (push x commentData)))
    (setq commentData (nreverse commentData))
    self)
 )

(defun binout-short (strm word)
   (format strm  "~c~c" (ldb word 0 8) (ldb word 8 8)))

(defun binout-byte (strm byte) (write-byte byte strm))

(defun binout-block (strm blockstring)
   (format strm "~a" blockstring))

(defun binout-var-block (strm blockstring)
   (binout-byte strm (length blockstring))
   (binout-block strm blockstring))

(defun concatenate-gif (&rest gifnames)
   (let ((gifs) (height) (width) (total-width) (gifout) (pgif) (next-pos 0))
      (dolist (g gifnames)
	(push (instance gif :read-file g) gifs))
      (setq gifs (nreverse gifs))
      (setq pgif (first gifs))
      (setq height (send (car gifs) :height))	;take the max?
      (setq total-width (apply #'+ (send-all gifs :width)))
      (setq global-color-table (send pgif :colortable))
      ;; header
      ;; (setq gifout (open outfile :direction :output)) 
      (setq gifout (make-string-output-stream))
      (format gifout "GIF89a")
      (binout-short gifout total-width)
      (binout-short gifout height)
      (binout-byte gifout (gif-flag pgif))
      (binout-byte gifout (gif-backgroundColorIndex pgif))
      (binout-byte gifout (gif-pixelAspectRatio pgif))
      (binout-block gifout (gif-globalcolortable pgif))
      (dolist (g gifs)
	 (dolist (b (gif-blocks g))
		(cond ((derivedp b gif-imageblock)
			(send b :write-out gifout next-pos))
		      ((derivedp b gif-graphicControlExtension)	
		        (send b :write-out gifout))
		      (t
			;;(format *error-output* "~a is ignored~%" b)
			)))
	 (incf next-pos (send g :width))
	)
      (binout-byte gifout #x3b)
      ;; (close gifout)
      (get-output-stream-string gifout)
   ))

(defun number-gif (n &optional (num-digits 6) (dir "gif1") (basedir "/home/www/cgi-bin/dream/"))
   (let  ((digits (digits-string n num-digits))
	  (digit-gifs))
      (dotimes (i (length digits))
	 (push (format nil "~a~a/~c.gif" basedir dir (aref digits i))
		digit-gifs))
      (apply #'concatenate-gif (nreverse digit-gifs)))
   )

 
