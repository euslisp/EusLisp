;; character.l
;; Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>

(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(deftest test-char-compare
  (format *error-output* " char-compare test ~%")
  (assert (eq t (lisp::char= #\a #\a)) "(lisp::char= #\a #\a)")
  (assert (eq nil (lisp::char= #\A #\a)) "(lisp::char= #\A #\a)")
  (assert (eq nil (lisp::char= #\a #\b)) "(lisp::char= #\a #\b)")
  (assert (eq t (lisp::char= #\a #\a #\a)) "(lisp::char= #\a #\a #\a)")
  (assert (eq nil (lisp::char= #\a #\a #\b)) "(lisp::char= #\a #\a #\b)")

  (assert (eq nil (lisp::char/= #\a #\a)) "(lisp::char/= #\a #\a)")
  (assert (eq t (lisp::char/= #\A #\a)) "(lisp::char/= #\A #\a)")
  (assert (eq t (lisp::char/= #\a #\b)) "(lisp::char/= #\a #\b)")
  (assert (eq nil (lisp::char/= #\a #\a #\a)) "(lisp::char/= #\a #\a #\a)")
  (assert (eq nil (lisp::char/= #\a #\a #\b #\a)) "(lisp::char/= #\a #\a #\b #\a)")
  (assert (eq t (lisp::char/= #\a #\b #\c #\d)) "(lisp::char/= #\a #\b #\c #\d)")

  (assert (eq t (lisp::char< #\a #\b)) "(lisp::char< #\a #\b)")
  (assert (eq nil (lisp::char< #\b #\a)) "(lisp::char< #\b #\a)")
  (assert (eq nil (lisp::char< #\a #\a)) "(lisp::char< #\a #\a)")
  (assert (eq t (lisp::char< #\a #\e #\y #\z)) "(lisp::char< #\a #\e #\y #\z)")
  (assert (eq nil (lisp::char< #\a #\e #\e #\y)) "(lisp::char< #\a #\e #\e #\y)")

  (assert (eq nil (lisp::char> #\a #\b)) "(lisp::char> #\a #\b)")
  (assert (eq t (lisp::char> #\b #\a)) "(lisp::char> #\b #\a)")
  (assert (eq nil (lisp::char> #\a #\a)) "(lisp::char> #\a #\a)")
  (assert (eq t (lisp::char> #\d #\c #\b #\a)) "(lisp::char> #\d #\c #\b #\a)")
  (assert (eq nil (lisp::char> #\d #\d #\c #\a)) "(lisp::char> #\d #\d #\c #\a)")

  (assert (eq t (lisp::char<= #\a #\b)) "(lisp::char<= #\a #\b)")
  (assert (eq nil (lisp::char<= #\b #\a)) "(lisp::char<= #\b #\a)")
  (assert (eq t (lisp::char<= #\a #\a)) "(lisp::char<= #\a #\a)")
  (assert (eq t (lisp::char<= #\a #\e #\y #\z)) "(lisp::char<= #\a #\e #\y #\z)")
  (assert (eq t (lisp::char<= #\a #\e #\e #\y)) "(lisp::char<= #\a #\e #\e #\y)")

  (assert (eq nil (lisp::char>= #\a #\b)) "(lisp::char>= #\a #\b)")
  (assert (eq t (lisp::char>= #\b #\a)) "(lisp::char>= #\b #\a)")
  (assert (eq t (lisp::char>= #\a #\a)) "(lisp::char>= #\a #\a)")
  (assert (eq t (lisp::char>= #\d #\c #\b #\a)) "(lisp::char>= #\d #\c #\b #\a)")
  (assert (eq t (lisp::char>= #\d #\d #\c #\a)) "(lisp::char>= #\d #\d #\c #\a)")
)

(eval-when (load eval)
  (run-all-tests)
  (exit))
;; end of character.l
