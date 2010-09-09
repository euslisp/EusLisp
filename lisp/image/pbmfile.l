;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; raw, PBM, PGM and PPM file I/O
;;; (c) 1992, Toshihiro Matsui, Electrotechnical Laboratory
;;; Oct/1992
;;; Dec/1992	accept streams in addition to files
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(unless (find-package "IMAGE")
	(make-package "IMAGE" :nicknames '("IMG" "IP")))
(in-package "IMAGE")

(export '(read-pnm-file read-pnm write-pgm write-ppm write-pnm write-pnm-file))

(defun read-raw-image (file &optional (x 256) (y x))
   "read a file of raw pixel data"
   (let ((image-vector (make-array (* x y) :element-type :byte)))
      (with-open-file (f file)
         (unix:uread (send f :infd) image-vector))
      image-vector))

(defun write-raw-image (file img)
   "write pixel data out to a file"
   (with-open-file (f file)
       (unix:write (send f :outfd) img))
   img)

;; PBM

(defun read-pbm-token (f eof)
   (prog (ch)
      read-again
      (while (member (setq ch (read-char f nil eof))
		'(#\space #\tab #\newline)))
      (unread-char ch f)
      (cond ((eql ch eof) (return eof))
	    ((eql ch #\#) (read-line f) (go read-again))
	    (t (return  (read f))))))

(defun read-ascii-pbm (f img width height)
   (error "undefined read-ascii-pbm"))
(defun read-binary-pbm (f img width height)
   (error "undefined read-binary-pbm"))

;;
;; pgm
(defun write-pgm (f image  &optional (depth 255)
			(width (send image :width))
			(height (send image :height)))
   "write-pgm always uses binary format"
   (format f "P5 ~d ~d ~d~%" width height depth)
   (unix:write (send f :outfd) (array-entity image)))

;;
;;
(defun read-ascii-pgm (f img width height)
     (let* ((eof (cons nil nil))    (token)
	    (maxval (read-pbm-token f eof))
	    (size (* width height))   )
	(if (/= maxval 255)
	    (error "unknown pgm file format maxval=~A" maxval))
	(dotimes (i size)
	   (setq token  (read-pbm-token f eof))
	   (if (eql token eof) (error "unexpected EOF"))
	   (setf (char img i) token))
	(setq img (instance grayscale-image :init width height img))
	(send img :name (send f :fname))
	img   ) )

(defun read-binary-pgm (f img width height)
   (let* ((img1) (offset)
	  (size (* width height)) (read-length)
	  (eof (cons nil nil))
	  (maxval (read-pbm-token f eof))   )
	(if (/= maxval 255)
	    (error "unknown pgm file format maxval=~A" maxval))
	(setq img (make-string size))
	(read-char f)
	(replace img (setq img1 (send (send f :instream) :tail-string)))
	(send (send f :instream) :discard)
	(setq offset (length img1))
	(while (< offset size)
	   (setq read-length
		(unix:uread (send f :infd) img 
			(- size offset)
			offset))
	   (if (<= read-length 0) (error "EOF hit while reading pgm file"))
	   (incf offset read-length)
	   ; (print offset)
	   )
	(setq img (instance grayscale-image :init width height img))
	(send img :name (send f :fname))
	img   
	))

;; ppm 

(defun read-binary-ppm (f rgb width height)
   (let* ((size (* width height))
	  (eof (cons nil nil))
	  (maxval (read-pbm-token f eof))
	  img sbuf
	  offset (buflen (* size 3))  rdlen)
	(if (/= maxval 255)
	    (error "unknown ppm file format maxval=~A" maxval))
	(read-char f)
	(replace rgb (setq sbuf (send (send f :instream) :tail-string)))
	(setq offset (length sbuf))
	(when (> (mod (length sbuf) 3) 0)
	    ;; align to 3byte boundary
	    (setq rdlen (- 3 (mod (length sbuf) 3)))
	    (unix:uread (send f :infd) rgb rdlen offset)
	    (incf offset rdlen)   )
	(while (> (setq rdlen (unix:uread (send f :infd) rgb (- buflen offset) offset)) 0)
	   (incf offset rdlen)  )
	(setq img (instance color-image24 :init	width height rgb))
	(send img :name (send f :fname))
	img   
	))

(defun read-ascii-ppm (f rgb width height)
     (let* (rgbimg (eof (cons nil nil))  (token)
	    (maxval (read-pbm-token f eof))
	    (size (* width height))  (ii) )
	(if (/= maxval 255)
	    (error "unknown ppm file format maxval=~A" maxval))
	(dotimes (i size)
	   (setq ii (* i 3))
	   ;; red
	   (setq token  (read-pbm-token f eof))
	   (if (eql token eof) (error "unexpected EOF"))
	   (setf (char rgb ii) token)
	   ;; green
           (setq token  (read-pbm-token f eof))
	   (if (eql token eof) (error "unexpected EOF"))
	   (setf (char rgb (1+ ii)) token)
	   ;; blue
	   (setq token  (read-pbm-token f eof))
	   (if (eql token eof) (error "unexpected EOF"))
	   (setf (char rgb (+ ii 2)) token))
	(setq rgbimg (instance color-image24 :init
			width height rgb))
	(send rgbimg :name (send f :fname))
	rgbimg   ) )

(defun write-ppm (f rgb-image)
   "write-ppm always uses binary (P6) format"
   (setq rgb-image (send rgb-image :to24))
   (format f "P6 ~d ~d ~d~%" (send rgb-image :width)
			(send rgb-image :height) 255)
   (unix:write (send f :outfd) (send rgb-image :entity))
   )

;; PNM

(defun read-pnm (f &optional buf0)
     (let ((ch (read-char f))
	   (width) (height)
	   (eof (cons nil nil))
	   (size)   )
	(unless (eql (char-upcase ch) #\P)
	   (error "not a p[bgp]m file") )
	(setq ch (read-char f))
	(setq width (read-pbm-token f eof)
	      height  (read-pbm-token f eof))
        (setq size (* width height))
	(if (or (> size (* 4096 4096)) (< size 0))
	    (error "image too big or negative"))
        (unless buf0
	  (case ch
	   ((#\1 #\4) (setq buf0 (make-string (/ (+ size 7) 8))))
	   ((#\2 #\5) (setq buf0 (make-string size)))
	   ((#\3 #\6) (setq buf0 (make-string (* size 3))))) )
	(case ch
	   (#\1 (read-ascii-pbm f buf0 width height))
	   (#\2 (read-ascii-pgm f buf0 width height))
	   (#\3 (read-ascii-ppm f buf0 width height))
	   (#\4 (read-binary-pbm f buf0 width height))
	   (#\5 (read-binary-pgm f buf0 width height))
	   (#\6 (read-binary-ppm f buf0 width height))
	   (t (error "unknown pbm magic number")))))

(defun read-pnm-file (file &optional buf)
   (with-open-file (f file)
       (read-pnm f buf)))


(defun write-pnm (f img)
   (cond((derivedp img color-image) (write-ppm f img)) 
	((derivedp img color-image) (write-ppm f img)) 
	((derivedp img multi-channel-image)  (write-ppm f img))
   	((derivedp img grayscale-image)  (write-pgm f img))
	)
  )

(defun write-pnm-file (file img)
   (with-open-file (f file :direction :output)   (write-pnm f img)))

;;; misc functions

#|
(defun raster32-to-ppm (rasfile ppmfile)
   (let ((header (make-string 32))
	 (width) (height) (length) rgb r g b size (j 0))
      (declare (integer j))
      (with-open-file (ras rasfile)
         (unix:uread (send ras :infd) header)
	 (setq width (sys:peek header 4 :integer)
	       height (sys:peek header 8 :integer)
	       length (sys:peek header 16 :integer)
	       size (* width height))
	 (setq rgb (make-string length))
	 (unix:uread (send ras :infd) rgb)
	 (setq r (make-string size)
	       g (make-string size)
	       b (make-string size))
	 (print size)
	 (dotimes (i size)
	    (setf (char r i) (aref rgb (incf j))
		  (char g i) (aref rgb (incf j))
		  (char b i) (aref rgb (incf j)))
	    (incf j))
	 (print "writing ppm")
         (write-ppm
		ppmfile
		(instance color-pixel-image :init width height
			r g b)))))

(defun swap-red-blue (cimg)
   (instance color-pixel-image :init
	(send cimg :width) (send cimg :height)
	(send cimg :blue) (send cimg :green) (send cimg :red)))

(defun swap-rb (file)
   (let ((img (read-pnm file)))
      (setq img (swap-red-blue img))
      (write-ppm file img)))

(defun read-halve-hls (file)
   (let ((img (read-pnm file)))
      (setq img (send img :halve))
      (send img :hls)
      (send img :display-hls)
      img))
|#

(provide :pbmfile "#(@)$Id$")

