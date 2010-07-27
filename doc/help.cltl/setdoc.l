;; (c) Copyright Taiichi Yuasa and Masami Hagiya, 1984.  All rights reserved.
;; Copying of this file is authorized to users who have executed the true and
;; proper "License Agreement for Kyoto Common LISP" with SIGLISP.

;;;;   setdoc.lsp
;;;;
;;;;                    Sets doc-strings for built-in symbols.
;;;;			This file is intended to be loaded into KCL
;;;;			after initialization and before save.
;;;;			This file need not be compiled.
;;;;
;;;;		Completely rewritten after the publishment of "Common Lisp
;;;;		Handbook" in July 1987.


(in-package 'system)

(defmacro docfun (sym kind str)
  (print sym)
  `(with-open-file (f (format nil "HELP~d" ,(sxhash sym 50))
		      :direction :output
		      :if-exists :append
		      :if-does-not-exist :create )
     (format f "(~S function-documentation ~S)~%" ',sym ,str)) )

(defmacro docvar (sym kind str)
  (print sym)
  `(with-open-file (f (format nil "HELP~d" ,(sxhash sym 50))
		      :direction :output
		      :if-exists :append
		      :if-does-not-exist :create )
     (format f "(~S variable-documentation ~S)~%" ',sym ,str)) )


(defmacro doctype (sym str)
  (print sym)
  `(with-open-file (f (format nil "HELP~d" ,(sxhash sym 50))
		      :direction :output
		      :if-exists :append
		      :if-does-not-exist :create )
     (format f "(~s type-documentation ~s)~%" ',sym ,str)) )



