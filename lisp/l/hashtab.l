;;;
;;;	hashtable
;;;
;;;	Copyright(C) Toshihiro MATSUI, all rights reserved
;;;	1986-Jun

(in-package "LISP")
(export '(hash-table make-hash-table gethash sethash remhash hash-table-p
	maphash clrhash queue))

(defclass hash-table :slots
			((key :type vector)
			 (value :type vector)
			 (size :type :integer)
			 (count :type :integer)
			 (hash-function)
			 (test-function)
			 (rehash-size)
			 (empty :type symbol)
			 (deleted :type symbol)
			 (not-found)))

(export '(hash-table-key hash-table-value hash-table-size
	hash-table-count hash-table-hash-function hash-table-test-function
	hash-table-rehash-size))

(eval-when (load eval)
(defmethod hash-table
 (:size () size)
 (:find (s)
    (let* ((hash (abs (mod (funcall hash-function s) size))) (entry) (empty-pos))
      (while t
	(setq entry (svref key hash))
	(if (funcall test-function entry s) (return-from :find hash))
	(when (eq entry empty)
	      (if (null empty-pos) (setq empty-pos hash))
	      (return-from :find (+ empty-pos size)))
	(when (eq entry deleted)
	      (if (null empty-pos) (setq empty-pos hash)))
	(if (>= (inc hash) size) (setq hash 0)))
      nil))
 (:get (s)
    (let ((entry (send self :find s)))
      (if (>= entry size) not-found (svref value entry))))
 (:enter (sym val)
    (let ((entry (send self :find sym)))
      (when (>= entry size)	;new entry?
	 (when (> count (/ size rehash-size))
	     (send self :extend)
	     (setq entry (send self :find sym))  )
	 (inc count)
	 (setq entry (- entry size)))
      (svset key entry sym)
      (svset value entry val)
      val))
 (:delete (sym)
    (let ((pos (send self :find sym)) (i 0))
      (when (< pos size) 
	(dec count)
	(svset key pos deleted)
	(svset value pos nil)))    )
 (:extend ()
    (let* ((altsize (* 2 size))
	   (altkey (make-array altsize))
	   (altvalue (make-array altsize))
	   x)
      (dotimes (i altsize) (svset altkey i empty))	;clear all entries
      (setq x key		;exchange key and value 
	    key altkey
	    altkey x
	    x value
	    value altvalue
	    altvalue x
	    x size
	    size altsize
	    altsize x
	    count 0)
      (dotimes (i altsize)
	 (setq x (svref altkey i))
	 (if (and (not (eq x empty)) (not (eq x deleted)))
	     (send self :enter x (svref altvalue i))))
      self ))
 (:hash (s)
    (setq s (string s))
    (mod (funcall hash-function  (string s)) size))
 (:map (func)
    "map func to the key and its value"
    (let (k v)
      (dotimes (i size)
	 (setq k (svref key i))
         (unless (or (eql k empty) (eql k deleted))
	    (funcall func k (svref value i))))) )
 (:list-values ()
    (let (k v)
      (dotimes (i size)
	 (setq k (svref key i))
         (unless (or (eql k empty) (eql k deleted))
	    (push (svref value i) v)) )
      v))
 (:list-keys ()
    (let (k v)
      (dotimes (i size)
	 (setq k (svref key i))
         (unless (or (eql k empty) (eql k deleted))
	    (push k v)) )
      v))
 (:list ()
    (let (k v)
      (dotimes (i size)
	 (setq k (svref key i))
         (unless (or (eql k empty) (eql k deleted))
	    (push (cons k (svref value i)) v)) )
      v))
 (:hash-function (&optional hf)
    (if hf (setq hash-function hf))
    hash-function)
 (:clear ()
    (dotimes (i size)
	(setf (aref key i) empty
	      (aref value i) nil))
    self)
 (:prin1 (&optional (strm t) &rest mesgs)
    (send-super* :prin1 strm
	(format nil "~d/~d" count size) mesgs))
 (:init (&key  ((:not-found nofound) nil)
	       ((:size s) 10) (test #'eq) ((:rehash-size rehash) 2.0)
		(hash #'sxhash))
    (setq size s
	  key (instantiate vector size)
	  value (instantiate vector size)
	  hash-function hash
	  test-function test
	  empty (gensym "EMPTY")
	  deleted (gensym "DEL")
	  not-found nofound
	  count 0
	  rehash-size rehash)
    (dotimes (i s) (svset key i empty))
    self)
  )
)

(eval-when (load eval)
(defun make-hash-table (&key (size 10) (test #'eq) (rehash-size 1.7)
				(hash #'sxhash) (not-found nil))
  (instance hash-table :init :size size
			     :test test
			     :rehash-size rehash-size
			     :hash hash	
			     :not-found not-found))
(defun gethash (key htab) (send htab :get key))
(defun sethash (key htab val) (send htab :enter key val))
(defun remhash (key htab) (send htab :delete key))
(defun hash-table-p (x) (derivedp x hash-table))
(defun maphash (func hashtab) (send hashtab :map func))
(defun clrhash (hashtab) (send hashtab :clear))
)

#|;; queue
;;	1989-Oct
;;	(c)1989 T.Matsui, ETL
;;

(defclass queue :super cons
		:slots (backward))

(defmethod queue
 (:backward () backward)
 (:forward () cdr)
 (:set-backward (back) (setq backward back))
 (:set-forward (for) (setq cdr for))
 (:link (back for)
    (send (send self :first) :set-backward back)
    (send (send self :last) :set-forward for)
    self)
 (:remove ()
    (if cdr  (send cdr :set-backward backward))
    (if backward  (send backward :set-forward cdr))
    (setq cdr nil backward nil)	;isolate self
    self)
 (:insert-before (target)
    (let ((back (send target :backward))
	  (head (send self :first)) (tail (send self :last)))
       (if back (send back :set-forward head))
       (send head :set-backward back)
       (send target :set-backward tail)
       (send tail :set-forward target))
    self)
 (:insert-after (target)
    (let ((for (send target :forward))
	  (head (send self :first)) (tail (send self :last)))
       (if for (send for :set-backward tail))
       (send tail :set-forward for)
       (send target :set-forward head)
       (send head :set-backward target))
    self)
 (:first ()
    (if backward (send backward :first) self))
 (:last ()
    (if cdr (send cdr :last) self))
 (:nconc (tail)
    (send tail :insert-after (send self :last)))
 (:length (&optional (len 0))
    (if cdr (send cdr :length (1+ len)) (1+ len)))
 (:init ()
    (setq cdr nil backward nil)
    self)
)

|#

;;
;; new version of queue 
;; 1995 June, Toshihiro Matsui
;;

(defclass queue :super cons)

(defmethod queue
 (:init () (setq car nil cdr nil) self)
 (:length () (length car))
 (:empty? () (null car))
 (:trim (s) ;; discard old entries to keep the size of this queue to 's'
     (dotimes (i (- (length car) s)) (send self :dequeue)))
 (:dequeue (&optional (error-p nil))
     (cond ((null car)
		(if error-p
		    (error "nothing queued ~s" self)
		    nil))
	   ((eq car cdr)	;last element
	    (prog1 (car car) (setq car nil cdr nil)))
	   (t  (prog1 (car car) (setq car (cdr car))))))
 (:enqueue (x)
     (cond (cdr
	    (setf (cdr cdr) (cons x nil))
	    (setf cdr (cdr cdr)))
	   (t
	     (setq cdr (cons x nil))
	     (setq car cdr)))
     x)
 (:search (item &optional (test #'equal))
     (find item car :test test))
 (:delete (item &optional (test #'equal) (count 1))
     (setq car (delete item car :test test :count count))
     (setq cdr (last car))
     self) 
 (:first () (car car))
 (:last () (car cdr))
 )
  
(provide :hashtab "@(#)$Id: hashtab.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $")

