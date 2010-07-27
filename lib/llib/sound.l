;;;;****************************************************************
;;;; sound.l  -- linux sound interface
;;;; Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;;; Dec 1997, First version
;;;; Feb 1998, sound scope (osciloscope)
;;;; Mar 2000, clear-sound-buffer and pipe to ninja
;;;; 

(eval-when (load)
  (defvar *audio-dsp* (open "/dev/dsp" :direction :io)))

(defconstant AFMT_QUERY           #x00000000) ;;  /* Return current fmt *
(defconstant AFMT_MU_LAW          #x00000001) ;;
(defconstant AFMT_A_LAW           #x00000002)
(defconstant AFMT_IMA_ADPCM       #x00000004)
(defconstant AFMT_U8              #x00000008)
(defconstant AFMT_S16_LE          #x00000010) ;;   /* Little endian signed
(defconstant AFMT_S16_BE          #x00000020) ;;   /* Big endian signed 16
(defconstant AFMT_S8              #x00000040) ;;
(defconstant AFMT_U16_LE          #x00000080) ;;   /* Little endian U16 */
(defconstant AFMT_U16_BE          #x00000100) ;;   /* Big endian U16 */
(defconstant AFMT_MPEG            #x00000200) ;;   /* MPEG (2) audio */


(defun SOUND-PCM-RATE (&optional (rate) (audio *audio-dsp*))
   ;; rate is either 5000,8000,16000 or higher?
   (let ((buf (make-string 4)))
      (sys:poke rate buf 0 :long)
      (unix:ioctl_wr audio #\P 2 buf 4)  ;; SNDCTL_DSP_SPEED
      (sys:peek buf 0 :long)))

(defun SOUND-PCM-CHANNELS( n &optional (audio *audio-dsp* ) )
    (let ((buf (make-string 4)))
	(sys:poke n buf 0 :long)
	(unix:ioctl_wr audio #\P 6 buf 4)  ;;SNDCTL_DSP_CHANNELS
	(sys:peek buf 0 :long))
   )

(defun SOUND-DSP-RESET (&optional (audio *audio-dsp*))
		    (unix:ioctl_ audio #\P 0))
(defun SOUND-DSP-SYNC (&optional (audio *audio-dsp*))
		    (unix:ioctl_ audio #\P 1))
(defun SOUND-DSP-NONBLOCK (&optional (audio *audio-dsp*))
		    (unix:ioctl_ audio #\P 14))

(defun SOUND-DSP-GETISPACE (&optional (audio *audio-dsp*))
   (let ((audio-buf-info (make-string 16)))
      (unix:ioctl_r audio #\P 13 audio-buf-info)
      ;; available-fragments, total#fragmants, fragment-size, available-space
      (list (sys:peek audio-buf-info 0 :long)
	    (sys:peek audio-buf-info 4 :long)
	    (sys:peek audio-buf-info 8 :long)
	    (sys:peek audio-buf-info 12 :long))
       ) )

(defun SOUND-DSP-GETOSPACE (&optional (audio *audio-dsp*))
   (let ((audio-buf-info (make-string 16)))
      (unix:ioctl_r audio #\P 12 audio-buf-info)
      ;; available-fragments, total#fragmants, fragment-size, available-space
      (list (sys:peek audio-buf-info 0 :long)
	    (sys:peek audio-buf-info 4 :long)
	    (sys:peek audio-buf-info 8 :long)
	    (sys:peek audio-buf-info 12 :long))
       ) )


(defun SOUND-PCM-FORMAT (&optional (aformat AFMT_S16_LE)
				   (audio *audio-dsp*))
    (let ((buf (make-string 4)) (stat))
	(unix:ioctl_wr audio #\P 11 buf 4) ;; SNDCTL_DSP_GETFMTS
	(sys:poke aformat buf 0 :long)
	(setq stat (unix:ioctl_wr audio #\P 5 buf 4))
	(sys:peek buf 0 :long)
	(unix:ioctl_r audio #\P 5 buf 4)	;;SOUND_PCM_READ_BITS
	(sys:peek buf 0 :long))
   )

(defun setup-sound (&key (rate 16000) (format AFMT_S16_LE) (audio *audio-dsp*) (channel 1))
   (sound-dsp-reset)
   (sound-pcm-rate rate)
   (sound-pcm-channels channel)
   (sound-pcm-format format)
   )


(defun clear-sound-buffer (&optional (audio *audio-dsp*))
    (let ((buf (make-string 4096)) (count))
       (while (> (car (print (sound-dsp-getispace))) 1)
	  (setq count (unix:uread (send audio :infd) buf 4096))) ) )


(defun pipe-sound (&optional (out *audio-dsp*)  (audio *audio-dsp*) (size 2048))
   (let ((buf (send (send audio :instream) :buffer)) (count))
      ;; extend sound buffer if it is too small to accomodate 'size' words.
      (if (< (length buf) (* 2 size))
	  (send (send audio :instream) :buffer (* 2 size)))
      (setq count (unix:uread audio (* 2 size)))
      ;; count is byte-count actually read.
      (unix:write out buf count)
      count))

(defun pipes (&optional (out *audio-dsp*))
    (clear-sound-buffer)
    (dotimes (i 100) (pipe-sound :out out) ))

(defun read-16bit-audio (&optional (size 100) (audio *audio-dsp*)
			 (res (make-array size :element-type :integer))
			 (offset 0))
   ;; multiply by 2, because of 16-bit sampling
   (let ((buf (send (send audio :instream) :buffer))
	 (count (- size offset)))
      (if (< (length buf) (* 2 size))
	  (send (send audio :instream) :buffer (* 2 size)))
      (unix:uread audio (* 2 count))
      (if (eql (send res :element-type) :integer)
	  (dotimes (s count)
		 (setf (aref res (+ offset s))  (sys:peek buf (* s 2) :short)) ))
      res))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun make-sound-scope (&optional (w 400) (h 300))
   (sound-pcm-rate 16000)
   (sound-pcm-channels 1)
   (sound-pcm-format AFMT_S16_LE)
   (setq *sound-scope* (instance x::graph-canvas :create :width w :height h)))

(defun sound-scope (&optional (times 100) (trigger 5))
   (clear-sound-buffer)
   (let* ((width (send *sound-scope* :width))
	  (size (* 3 width))
	  (data (make-array size :element-type :integer))
	  (triggerred nil)
	  (offset 0))
      (dotimes (i times)
	 (setq triggerred nil)
	 (while (not triggerred)
	    (setq offset 0)
            (setq data (read-16bit-audio size *audio-dsp* data offset))
	    (block :trigger
	        (while  (< offset (1- size))
		   (setq triggerred 
			 (and (> (aref data offset) trigger)
			      (< (aref data offset) (aref data (1+ offset)))) )
		   (if triggerred (return-from :trigger t))
		   (incf offset))        ) )
	 (replace data data :start2 offset)
	 (read-16bit-audio size *audio-dsp* data offset)
	 (send *sound-scope* :clear)
         (send *sound-scope* :graph data :max 30000 :min -30000)
	 (send *sound-scope* :flush))
      ))

;----------------------------------------------------------------

(provide :sound "@(#)$Id: sound.l,v 1.1.1.1 2003/11/20 07:53:27 eus Exp $")
