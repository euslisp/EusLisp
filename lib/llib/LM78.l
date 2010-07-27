;; LM78.l
;;   LM78 is an I/O chip on ATX mother board.
;;   It is located at 0x295 and 0x296 in the I/O address space, and
;;   reports power (+-12V and +-5V) voltage, temperature, and fan
;;   rotations.

;; Set up Linux low-level I/O functions.
;; This program has to be executed in the priviledged mode.
;;

;; (load "linux_lowio.so")
;; (ioperm #x400)
;;

(defparameter LM78-ADDR #x295)
(defparameter LM78-DATA #x296)

(defun LM78-volt ()
  (let ((vaddr #x20) (rvolts) (ivolt))
    (dotimes (i 7)
	(outb LM78-ADDR (+ vaddr i))
	(unix:usleep 10000)
	(setq ivolt (* (inb LM78-DATA) 0.016))
	(case i
	  ((3) (setq ivolt %(ivolt * (10.0 / 6.0))))
	  ((4) (setq ivolt %(ivolt * 4.0)))
	  ((5) (setq ivolt %(ivolt * -4.0)))
	  ((6) (setq ivolt %(ivolt * (-10.0 / 6.0))))
	  )
	(push ivolt rvolts)
	)
     (nreverse rvolts)))

(defun LM78-temp ()
   (let ((taddr #x27) (temper))
      (outb LM78-ADDR taddr)
      (unix:usleep 10000)
      (setq temper (inb LM78-DATA))
      temper))

(defun LM78 ()
   (let ((volts (LM78-volt)) (temp (LM78-temp)))
      (format t "core1=~s core2=~s I/O=~s~%5V=~s 12V=~s -12V=~s =5V=~s~%temperature= ~s degree Celcius~%"
	 (first volts) (second volts) (third volts) (fourth volts)
	 (fifth volts) (sixth volts) (seventh volts) temp)))

