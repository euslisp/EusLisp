;;;; eucfname.l
;;;; convert shift-jis coded filenames into euc.
;;;; This is found necessary when samba became to support file name coding conversion
;;;  between shift-jis and euc.  Before, file names sent from Windows client to a 
;;;  linux server were directly written as linux filenames.  Since there was no
;;;  conversion, only Windows client could see the correct representation of the
;;;  Nihon-go file names.  On linux, these filenames were displayed with '???' as
;;;  if they were broken files.  Since samba 2.2, file name conversion has been
;;;  provided.  Now we can see correct filenames both on Windows and Linux.
;;;  However, for that, shift-jis file names already stored on a linux server
;;;  needs to be converted to euc.  This program does it.

(require :romkan "kana_euc")

(defun eucfname (&optional (wd ".") (descend t))
   (let (dirs (file-count 0) (nihongo-count 0) newname fname)
      (dolist (e (directory wd))
	 (unless (member e '("." "..") :test #'equal)
	    (incf file-count)
	    (setq fname (format nil "~a/~a" wd e))
	    (setq newname
		  (if (some #'(lambda (x) (logtest x #x80)) fname)
		      (prog1 (setq newname (sjis2euc fname))
			     (unix::rename fname newname)
			     (incf nihongo-count))
		      fname))
	    (if (eql (probe-file newname) :directory) (push newname dirs))
	    )
	)
	;; descend to subdirectories
      (print dirs)
      (when descend
        (dolist (d (nreverse dirs))
          (format t ";; decsend to ~a pwd=~a~%" d (pwd))
	  (eucfname d descend)))
   (format nil "~d files are scanned, ~d nihongo-filenames are converted.~%" 
	file-count nihongo-count))

   )

