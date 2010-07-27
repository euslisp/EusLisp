;;;; crypt.l
;;;  Copyright 2000 (c)
;;;  Toshihiro Matsui, Agency of Industrial Science and Technologies
;;;
;;;  libcrypt.so is linked.
;;;  A plain password give is compared to an encrypted password,
;;;  and returns T if they match.

(let ((mm (load "/usr/lib/libcrypt.so")))
;; (crypt string salt)
(defforeign crypt mm "crypt" (:string :string) (:string 13))
)

(defparameter *salt-string*
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./")

(defparameter *safe-salt-string*
    "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghjkmnpqrstuvwxyz23456789./")


(defun random-string (len &optional (salt-string *salt-string*))
   (let ((salt (make-string len)))
      (dotimes (i len)
	(setf (char salt i) (char salt-string (random (length salt-string))) ))
      salt))

(defun rcrypt (str &optional (salt (random-string 2)))
      (crypt str salt))

      
;; compcrypt returns T if plain input-password matches with
;; the encrypted-password.
(defun compcrypt (input-password encrypted-password)
   (let ((salt
	   (coerce (list
   		(aref encrypted-password 0)
		(aref encrypted-password 1)) string)))
      (equal encrypted-password
	     (crypt input-password salt))))
      

(provide :crypt)


