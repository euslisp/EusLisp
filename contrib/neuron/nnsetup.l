;;; -*- Mode: lisp -*-
(if (not (find-package 'nn))
    (make-package 'nn :nicknames '(neural-network)))
(in-package 'nn)
(load "nnsub" :package 'nn)
(load "nn" :package 'nn)


