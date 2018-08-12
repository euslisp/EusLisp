;; string.l
;; Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>

(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(deftest test-url-encode
  ;; privet
  (assert (string=
           (escaped-url-string-from-namestring "Привет")
           "%d0%9f%d1%80%d0%b8%d0%b2%d0%b5%d1%82"))

  ;; namasute
  (assert (string=
           (escaped-url-string-from-namestring "नमस्ते")
           "%e0%a4%a8%e0%a4%ae%e0%a4%b8%e0%a5%8d%e0%a4%a4%e0%a5%87"))

  ;; alphabet
  (assert (string=
           (escaped-url-string-from-namestring "abc123ABC :/.-_?=")
           "abc123ABC+:/.-_?="))

  (assert (string=
           "http://google.com/"
           (send (send (url-pathname "http://google.com/") :percent-escape) :string2)))

  (assert (string=
           (send (send (url-pathname "https://www.google.co.jp/?q=東大 ロボット") :percent-escape) :string2)
           "https://www.google.co.jp/?q=%e6%9d%b1%e5%a4%a7+%e3%83%ad%e3%83%9c%e3%83%83%e3%83%88"))
  (assert (string=
           (send (send (url-pathname "https://www.google.co.jp/?q=東大 ロボット") :percent-escape :queryp nil) :string2)
           "https://www.google.co.jp/?q=%e6%9d%b1%e5%a4%a7%20%e3%83%ad%e3%83%9c%e3%83%83%e3%83%88"))

  (assert (string=
           (send (send
                  (url-pathname
                   "https://www.google.co.jp/?q=%e6%9d%b1%e5%a4%a7%20%e3%83%ad%e3%83%9c%e3%83%83%e3%83%88")
                  :percent-escape :revert t :queryp nil) :string2)
           "https://www.google.co.jp/?q=東大 ロボット"))

  (assert (string=
           (send (send
                  (url-pathname
                   "https://www.google.co.jp/?q=%e6%9d%b1%e5%a4%a7+%e3%83%ad%e3%83%9c%e3%83%83%e3%83%88")
                  :percent-escape :revert t) :string2)
           "https://www.google.co.jp/?q=東大 ロボット"))

)

(eval-when (load eval)
  (run-all-tests)
  (exit))
; end of string.l
