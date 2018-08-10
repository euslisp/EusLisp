(require :unittest "lib/llib/unittest.l")

(init-unit-test)

(deftest test-directed-graph ()
  (let ((gr (instance directed-graph :init)) (a (instance node :init 'a))
	(b (instance node :init 'b)) (c (instance node :init 'c)) ar)
    (send gr :add-node a)
    (send gr :add-node b)
    (send gr :add-node c)
    (assert (eq a (send gr :node 'a))
	    "(send directed-graph :node name) success")
    (assert (eq 3 (length (send gr :nodes)))
	    "(send directed-graph :nodes) success")
    (setq ar (send gr :add-arc-from-to a b))
    (assert (and (eq (send ar :from) a)
		 (eq (send ar :to)   b))
	    "(send arc :from) and (send arc :to) success")
    (send gr :add-arc-from-to b c)
    (assert (find b (send gr :successors a) :key #'cdr)
	    "(send directed-graph :successors node) success")
    (send gr :remove-node b)
    (assert (equal (send gr :successors a) nil)
	    "(send directed-graph :remove node) success")
    (send gr :add-arc-from-to a c)
    (assert (find c (send gr :successors a) :key #'cdr)
	    "(send directed-graph :add-arc-from-to node node) success")
    (send gr :remove-arc (car (send a :arc-list)))
    (assert (equal (send gr :successors a) nil)
	    "(send directed-graph :remove-arc arc) success")
    (send gr :clear-nodes)
    (assert (equal (send gr :nodes) nil)
	    "(send directed-graph :clear-nodes) success")
    ))


(deftest test-graph ()
  (defmethod node
    (:cost () 0))
  (let ((gr (instance graph :init)) ar
	(a (instance node :init 'a)) (b (instance node :init 'b)))
    (send gr :add-node a)
    (send gr :add-node b)
    (setq ar (send gr :add-arc-from-to a b))
    (assert (= 1 (send gr :path-cost a ar b))
	    "(send graph :path-cost a a->b b) success")
    (send gr :start-state a)
    (send gr :goal-state b)
    (assert (send gr :goal-test b)
	    "(send graph :goal-test node) success")
    ))


;; test1 --> test2 --> test3
;;  |                   |
;;  +---------<---------+
(deftest test-a*-graph-search-1 ()
  (let ((gr (instance graph :init)) solver path)
    (defmethod a*-graph-search-solver
      (:hn (n p) 0.0))

    (setq solver (instance a*-graph-search-solver :init gr))

    (let ((test1 (instance node :init 'test1))
	  (test2 (instance node :init 'test2))
	  (test3 (instance node :init 'test3)))
      (send gr :add-node test1)
      (send gr :add-node test2)
      (send gr :add-node test3)
      (send gr :add-arc test1 test2)
      (send gr :add-arc test2 test3)
      (send gr :add-arc test3 test1))

    (send gr :start-state (send gr :node 'test1))
    (send gr :goal-state (send gr :node 'test3))
    (setq path (send solver :solve gr :verbose nil))
    (assert (equal (send-all (send-all path :state) :name)
		   '(test1 test2 test3))
	    "solve A* algorithm successfully")
    ))


;; a -- b -- c -- d -- e
;;      |         |
;;      f----g    h
;;      |         |
;;      +---------+
(defun test-a*-graph-search-2 ()
  (let ((gr (instance graph :init)) solver path)
    (defmethod a*-graph-search-solver
      (:hn (n p) 0.0))
    (setq solver (instance a*-graph-search-solver :init gr))
    (let ((a (instance node :init 'a)) (b (instance node :init 'b))
	  (c (instance node :init 'c)) (d (instance node :init 'd))
	  (e (instance node :init 'e)) (f (instance node :init 'f))
	  (g (instance node :init 'g)) (h (instance node :init 'h)))
      (send gr :add-node a)
      (send gr :add-node b)
      (send gr :add-node c)
      (send gr :add-node d)
      (send gr :add-node e)
      (send gr :add-node f)
      (send gr :add-node g)
      (send gr :add-node h)
      (send gr :add-arc a b :both t)
      (send gr :add-arc b c :both t)
      (send gr :add-arc c d :both t)
      (send gr :add-arc d e :both t)
      (send gr :add-arc b f :both t)
      (send gr :add-arc f g :both t)
      (send gr :add-arc f h :both t)
      (send gr :add-arc h d :both t))
    (send gr :start-state (send gr :node 'g))
    (send gr :goal-state (send gr :node 'e))
    (setq path (send solver :solve gr :verbose nil))
    (assert (equal (send-all (send-all path :state) :name)
		   '(g f h d e))
	    "solve A* problem successfully")
    ))


(run-all-tests)

(exit)
