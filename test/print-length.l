(require :unittest "lib/llib/unittest.l")

(init-unit-test)

;; extended from `ansi-test' example
;; https://gitlab.common-lisp.net/ansi-test/ansi-test

(defmacro print-test (form result &rest bindings)
  `(let ,bindings
     (assert
      (string=
       (prin1-to-string ,form)
       ,result))))


;; LISTS

(deftest print-length-list.1 ()
  (let ((x '(|A| |B| |C| |D| |E| |F|))
        (res (list
              "(...)"
              "(A ...)"
              "(A B ...)"
              "(A B C ...)"
              "(A B C D ...)"
              "(A B C D E ...)"
              "(A B C D E F)"
              "(A B C D E F)"
              "(A B C D E F)")))
     (let ((*print-case* :upcase)
           (*print-length* nil))
       (dotimes (i 9)
         (print-test x (pop res) (*print-length* i))))))

(deftest print-length-list.2 ()
  (let ((seq (make-list 100000 :initial-element 0))
        (*print-length* nil))
    (assert
     (equal seq (read-from-string (prin1-to-string seq))))))

(deftest print-length-list.3 ()
  (print-test '(1) "(1)" (*print-length* nil)))

(deftest print-length-list.4 ()
  (print-test '(1 . 2) "(1 . 2)" (*print-length* 1)))

(deftest print-length-list.5 ()
  (print-test '(1) "(1)" (*print-length* (1+ most-positive-fixnum))))


;; VECTORS

(deftest print-length-vector.1 ()
  (let ((x #(|A| |B| |C| |D| |E| |F|))
        (res (list
              "#(...)"
              "#(A ...)"
              "#(A B ...)"
              "#(A B C ...)"
              "#(A B C D ...)"
              "#(A B C D E ...)"
              "#(A B C D E F)"
              "#(A B C D E F)"
              "#(A B C D E F)")))
     (let ((*print-case* :upcase)
           (*print-length* nil))
       (dotimes (i 9)
         (print-test x (pop res) (*print-length* i))))))

(deftest print-length-vector.2 ()
  (let ((seq (make-array 100000 :initial-element 0))
        (*print-length* nil))
    (assert
     (equal seq (read-from-string (prin1-to-string seq))))))


;; FLOAT VECTORS

(deftest print-length-float-vector.1 ()
  (let ((x #f(1 2 3 4 5 6))
        (res (list
              "#f(...)"
              "#f(1.0 ...)"
              "#f(1.0 2.0 ...)"
              "#f(1.0 2.0 3.0 ...)"
              "#f(1.0 2.0 3.0 4.0 ...)"
              "#f(1.0 2.0 3.0 4.0 5.0 ...)"
              "#f(1.0 2.0 3.0 4.0 5.0 6.0)"
              "#f(1.0 2.0 3.0 4.0 5.0 6.0)"
              "#f(1.0 2.0 3.0 4.0 5.0 6.0)")))
    (let (*print-length*)
       (dotimes (i 9)
         (print-test x (pop res) (*print-length* i))))))

(deftest print-length-float-vector.2 ()
  (let ((seq (make-array 100000 :element-type float-vector))
        (*print-length* nil))
    (assert
     (equal seq (read-from-string (prin1-to-string seq))))))


;; INTEGER VECTORS

(deftest print-length-integer-vector.1 ()
  (let ((x #i(1 2 3 4 5 6))
        (res (list
              "#i(...)"
              "#i(1 ...)"
              "#i(1 2 ...)"
              "#i(1 2 3 ...)"
              "#i(1 2 3 4 ...)"
              "#i(1 2 3 4 5 ...)"
              "#i(1 2 3 4 5 6)"
              "#i(1 2 3 4 5 6)"
              "#i(1 2 3 4 5 6)")))
     (let (*print-length*)
       (dotimes (i 9)
         (print-test x (pop res) (*print-length* i))))))

(deftest print-length-integer-vector.2 ()
  (let ((seq (make-array 100000 :element-type integer-vector))
        (*print-length* nil))
    (assert
     (equal seq (read-from-string (prin1-to-string seq))))))


;; BIT VECTORS
(deftest print-length-bitvector.1 ()
  (print-test #*00110101100011 "#*00110101100011" (*print-length* 0)))


;; STRUCTURES

(defstruct print-length-struct foo)

(deftest print-length-structure.1
    (let ((*print-case* :upcase)
          (*print-structure* t)
          (s (instantiate print-length-struct))
          acc)
      (send s :set-val 'foo 17)
      (dotimes (i 5)
        (let ((*print-length* i))
          (push (prin1-to-string s) acc)))
      (assert
       (member (nreverse acc)
               '(("#s(...)"
                  "#s(PRINT-LENGTH-STRUCT ...)"
                  "#s(PRINT-LENGTH-STRUCT FOO ...)"
                  "#s(PRINT-LENGTH-STRUCT FOO 17)"
                  "#s(PRINT-LENGTH-STRUCT FOO 17)")
                 ("#s(PRINT-LENGTH-STRUCT ...)"
                  "#s(PRINT-LENGTH-STRUCT FOO 17)"
                  "#s(PRINT-LENGTH-STRUCT FOO 17)"
                  "#s(PRINT-LENGTH-STRUCT FOO 17)"
                  "#s(PRINT-LENGTH-STRUCT FOO 17)"))
               :test 'equal))))


;; RUN TESTS

(eval-when (load eval)
  (run-all-tests)
  (exit))
