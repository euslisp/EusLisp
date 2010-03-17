(require :http)
(require :kana "kana_euc")
(require :time)
(require :regexp "regexp")

(defparameter *exit-on-fatal-error* t)
 
(defparameter *zdnet-japan-url* (url-pathname "http://www.zdnet.co.jp/news/"))
(defparameter *ibaraki-bus-location-url* 
	(url-pathname "http://www.bus.nilim.go.jp/main_map.jsp?rosgrcd=001"))
(defparameter *asahi-news-url*  (url-pathname "http://www.asahi.com/"))

(defun zdnet-news-headlines ()
   (let ((headlines
	  (extract-html 'strong (second (read-http *zdnet-japan-url*)))) 
	 (end))
      ;; (setq *headlines* headlines)
      (setq headlines 
	 (collect-if #'(lambda (y) (> (length y) 18))
         (mapcar #'(lambda (x) (apply #'concatenate string
		  (collect-if #'stringp x)))
		headlines)))
      (if (setq end
		(position-if #'(lambda (x) (equal (subseq x 0 4) "ZDII"))
			     headlines))
	  (subseq headlines 0 end)
	  headlines)
     ))

(defun insert-zdnet-news (db)
  (let ((news (zdnet-news-headlines)) (now (send (now) :iso-string)))
      ;; (pprint news)
      (dolist (n news)
	 (send db :exec
		(format nil "insert into zdnet_news (category,time,content)
			 values ('~a','~a','~a')"
			'headline now n)))
  ))


(defun concatenate-strings (forms)
   (mapcar 
	#'(lambda (flist)
	    (apply #'concatenate string
		(mapcan #'(lambda (x)
		   (if (stringp x) (list (remove #\space x))  ))
		   flist)))
	forms) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; extract html document sandwitched by mark and mark-end.

(defun html-marked-items (html-list &optional (mark "■") (mark-end 'br)
				(end '/body) (include nil))
   (let ((finished) (item) (collect) (res) (result))
      (while (and html-list (not finished))
	 (setq item (pop html-list))
	 (cond ((or (and (stringp item)
			 (stringp mark) 
			 (equal mark (subseq item 0 (length mark))))
		    (and (symbolp mark)
			 (consp item) 
			 (eq mark (car item))) )
		  (if (and include (stringp mark))
			(push (subseq item (length mark)) res))
		  (setq collect t ))
	       ((and collect (consp item) (eql (car item) mark-end))
		(setq collect nil) (push (nreverse res) result)
		(setq res nil))
	       ((and (consp item) (eq (car item) end))
		(setq finished t))
	       (collect	 (push item  res) )
	       (t nil))  )
      (list (nreverse result) html-list)))

(defun asahi-news-line (html-list)
   (let ((line) (lpar))
      (setq line (apply #'concatenate string (remove-html-tags html-list)))
      (setq lpar (position #\lparen (reverse line)))
      (if lpar 
	  (subseq line 0 
		(- (length line) (position #\lparen (reverse line)) 1 ))
	  line) ))

(defun asahi-news ()
   (let ((news (second (read-http *asahi-news-url*)))
	 (item) (headlines) (society) (economy) (politics) (international)
	 (sports) (sorrow) (people))
      (setq *asahi-news* news)      
      (while news
	 (setq item (pop news))
	 (if (and (consp item) (eql (car item) 'hr) (eql (second item) 'noshade))
	     (return nil)))
      (setq *asahi-news1* news)
      (setq item (html-marked-items news "■" 'br '/table))
      (setq headlines (car item) news (cadr item))
      (setq headlines (mapcar #'asahi-news-line headlines))
      ;;
      (setq news (member-if #'(lambda (x) (and (consp x)
		;; (eql (car x) 'img) (equal (second (member 'alt x)) "社会" )
		(equal (subseq x 0 4) '(!-- start of national)) )
		)
		news))
      (setq *asahi-news2* news)
      (setq item (html-marked-items news "■" 'br '/tr))
      (setq society (car item) news (cadr item))
      (setq society (mapcar #'asahi-news-line society))
      ;;
      (setq news (member-if #'(lambda (x) (and (consp x)
		;; (eql (car x) 'img) (equal (second (member 'alt x)) "経済" )
		(equal (subseq x 0 4) '(!-- start of business)) )
		)
		news))
      (setq item (html-marked-items news "■" 'br '/tr))
      (setq economy (car item) news (cadr item))
      (setq economy (mapcar #'asahi-news-line economy))
      ;;
      (setq news (member-if #'(lambda (x) (and (consp x)
		;; (eql (car x) 'img) (equal (second (member 'alt x)) "政治" )
		(equal (subseq x 0 4) '(!-- start of politics)) )
		)
		news)) 
      (setq item (html-marked-items news "■" 'br  '/tr))
      (setq politics (car item) news (cadr item))
      (setq politics (mapcar #'asahi-news-line politics))
      ;;
      (setq news (member-if #'(lambda (x) (and (consp x)
		;; (eql (car x) 'img) (equal (second (member 'alt x)) "国際" )
		(equal (subseq x 0 4) '(!-- start of international)) )
		)
		news)) 
      (setq item (html-marked-items news "■" 'br '/tr))
      (setq international (car item) news (cadr item))
      (setq international (mapcar #'asahi-news-line international))
      ;;
      (setq news (member-if #'(lambda (x) (and (consp x)
		;; (eql (car x) 'img) (equal (second (member 'alt x)) "スポーツ" )
		(equal (subseq x 0 4) '(!-- start of sports)) )
		)
		news)) 
      (setq *asahi-news2* news)
      (setq item (html-marked-items news "■" 'br '/tr))
      (setq sports (car item) news (cadr item))
	(setq *sports* sports)
      (setq sports (mapcar #'asahi-news-line sports))
      ;;
      (setq news (member-if #'(lambda (x) (and (consp x)
		;; (eql (car x) 'img) (equal (second (member 'alt x)) "おくやみ" )
		(equal (subseq x 0 4) '(!-- start of feneral)) ) ;; spell mistake!
		)
		news))
      (setq item (html-marked-items news "■" 'br '/tr))
      (setq sorrow (car item) news (cadr item))
      (setq sorrow (mapcar #'asahi-news-line sorrow))
      ;;
      (setq news (member-if #'(lambda (x) (and (consp x)
		;; (eql (car x) 'img) (equal (second (member 'alt x)) "ひと" )
		(equal (subseq x 0 4) '(!-- start of personal)) )
		)
		news)) 
      (setq item (html-marked-items news "■" 'br '/tr))
      (setq people (car item) news (cadr item))
      (setq people (mapcar #'asahi-news-line people))
      ;;
      #|
      (setq news
	    (cddr
	    (mapcar #'(lambda (x) (apply #'concatenate string x))
		    (mapcar #'remove-html-tags (nreverse result)))))
      (setq news (remove-if #'null news))
      ;; time (09:23) at the end of each string should be removed
	|#
      
      (list headlines society economy politics international
		sports sorrow people)
   )
)

(defun insert-asahi-news (db)
  (let ((news (asahi-news)) (now (send (now) :iso-string))
	(categories '(headline society economy politics international sports
		sorrow people))
	(category))
      (dolist (lines news)
	 (setq category (pop categories))
	 (dolist (l lines)
	    (send db :exec
		(format nil "insert into asahi_news (category,time,content)
			 values ('~a','~a','~a')"
			category now l))) )
  ))



(provide :webnews "@(#)$Id$")

