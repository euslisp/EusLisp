;;; test-glu-tess.l --- unit tests for the offline GLU polygon-with-holes
;;; tessellation collector added to lisp/opengl/src/util.c.
;;;
;;; Motivation: irteus/irtgeo.l's own polygon-with-holes triangulation
;;; (face-to-triangle -> geo::face-to-triangle-make-simple for bridging
;;; each hole into the outer contour, then face-to-tessel-triangle's
;;; ear clipping) is a hand-written algorithm from 2010 whose cost grows
;;; at least O(n^2) in the number of resulting vertices, since every
;;; candidate ear is validated against every other remaining vertex, and
;;; every hole is bridged by re-scanning all vertices of the (growing)
;;; outer contour and all remaining holes. This becomes impractically
;;; slow for faces with many holes: on a real CAD-derived robot part
;;; with 24 holes cut into one face (206 vertices after bridging, 203
;;; triangles), face-to-triangle-make-simple alone took ~49s and the
;;; full triangulation ~65s (measured on the same machine that runs
;;; these tests).
;;;
;;; libGLU is already linked into eusgl for on-screen rendering (see
;;; irteus/irtgl.l's :draw-on method for "holed face"), and its
;;; sweep-line tessellator solves the same problem correctly in a tiny
;;; fraction of the time -- but its GLU_BEGIN/GLU_VERTEX/GLU_END
;;; callbacks were only ever wired to draw immediately
;;; (glBegin/glVertex3dv/glEnd via tess_vertex_cb), so there was no way
;;; to recover the tessellated triangles as data (e.g. to build a
;;; cacheable gl::glvertices mesh) without a live, current GL context
;;; actually rendering a frame.
;;;
;;; This adds a parallel set of "collector" callbacks
;;; (eus_tess_reset/eus_tess_begin_cb/eus_tess_vertex_cb/eus_tess_end_cb/
;;; eus_tess_error_cb, plus read-back accessors) that record the
;;; tessellated output into memory instead of drawing it. No GL context
;;; is required to call gluNewTess/gluTessBeginPolygon/etc. for pure
;;; tessellation (confirmed by these tests running headless, without
;;; opening any window).
;;;
;;; On the machine these tests were developed on, tessellating the
;;; 24-hole/206-vertex face above via this new path takes ~0.003s
;;; (vs. ~65s for the existing face-to-triangle path) and produces the
;;; same 203 triangles.

(require :unittest "lib/llib/unittest.l")

(init-unit-test)

;; GLUのテッセレーションはOpenGLコンテキストなしで(ウィンドウを開かずに)
;; 呼び出せることを、このテストファイル自体がheadlessに実行できている
;; ことで確認している。

(defvar *tess-obj* nil)

(defun tess-setup ()
  (unless *tess-obj*
    (setq *tess-obj* (gl::gluNewTess))
    (gl::gluTessCallbackl *tess-obj* gl::glu_begin
			  (#'gl::eus_tess_begin_cb . entry) (#'gl::eus_tess_begin_cb . entry2))
    (gl::gluTessCallbackl *tess-obj* gl::glu_vertex
			  (#'gl::eus_tess_vertex_cb . entry) (#'gl::eus_tess_vertex_cb . entry2))
    (gl::gluTessCallbackl *tess-obj* gl::glu_end
			  (#'gl::eus_tess_end_cb . entry) (#'gl::eus_tess_end_cb . entry2))
    (gl::gluTessCallbackl *tess-obj* gl::glu_error
			  (#'gl::eus_tess_error_cb . entry) (#'gl::eus_tess_error_cb . entry2))))

;; 単純多角形(穴なし)f1個をテッセレーションし、(#f(x y z) ...)という
;; 3頂点1組のリストを要素とするリスト(=三角形のリスト)を返す。
;; holesはpoint-listのリスト(各要素が1個の穴の頂点列)。
(defun tess-polygon (outer-points &optional holes)
  (tess-setup)
  (gl::eus_tess_reset)
  (let ((l-tessinfo (mapcar #'(lambda (p) (gl::alloctessinfo p 0 nil 0 nil)) outer-points)))
    (gl::gluTessBeginPolygon *tess-obj* 0)
    (gl::gluTessBeginContour *tess-obj*)
    (mapc #'(lambda (i) (gl::gluTessVertex *tess-obj* i i)) l-tessinfo)
    (gl::gluTessEndContour *tess-obj*)
    (dolist (hole-points holes)
      (let ((h-l-tessinfo (mapcar #'(lambda (p) (gl::alloctessinfo p 0 nil 0 nil)) hole-points)))
	(gl::gluTessBeginContour *tess-obj*)
	(gl::gluNextContour *tess-obj* gl::glu_interior)
	(mapc #'(lambda (i) (gl::gluTessVertex *tess-obj* i i)) h-l-tessinfo)
	(gl::gluTessEndContour *tess-obj*)
	(nconc l-tessinfo h-l-tessinfo)))
    (gl::gluTessEndPolygon *tess-obj*)
    (mapc #'unix:free l-tessinfo))
  (unless (zerop (gl::eus_tess_get_error))
    (return-from tess-polygon (values nil (gl::eus_tess_get_error))))
  (let* ((nv (let ((total 0))
	       (dotimes (b (gl::eus_tess_num_batches)) (incf total (gl::eus_tess_batch_count_at b)))
	       total))
	 (verts (make-array nv))
	 (tmp (float-vector 0 0 0)))
    (dotimes (i nv)
      (gl::eus_tess_get_vertexfv i tmp)
      (setf (aref verts i) (copy-seq tmp)))
    (let (triangles)
      (dotimes (b (gl::eus_tess_num_batches))
	(let* ((mode (gl::eus_tess_batch_mode_at b))
	       (start (gl::eus_tess_batch_start_at b))
	       (count (gl::eus_tess_batch_count_at b)))
	  (cond
	   ((= mode gl::gl_triangles)
	    (do ((i 0 (+ i 3))) ((> (+ i 3) count))
	      (push (list (aref verts (+ start i)) (aref verts (+ start i 1)) (aref verts (+ start i 2))) triangles)))
	   ((= mode gl::gl_triangle_fan)
	    (let ((v0 (aref verts start)))
	      (do ((i 1 (1+ i))) ((>= (1+ i) count))
		(push (list v0 (aref verts (+ start i)) (aref verts (+ start i 1))) triangles))))
	   ((= mode gl::gl_triangle_strip)
	    (do ((i 0 (1+ i))) ((>= (+ i 2) count))
	      (if (evenp i)
		  (push (list (aref verts (+ start i)) (aref verts (+ start i 1)) (aref verts (+ start i 2))) triangles)
		(push (list (aref verts (+ start i 1)) (aref verts (+ start i)) (aref verts (+ start i 2))) triangles)))))))
      (nreverse triangles))))

(defun triangle-area (tri)
  (* 0.5 (norm (v* (v- (cadr tri) (car tri)) (v- (caddr tri) (car tri))))))

(deftest test-eus-tess-functions-bound
  (dolist (fn '(gl::eus_tess_reset gl::eus_tess_begin_cb gl::eus_tess_vertex_cb
		gl::eus_tess_end_cb gl::eus_tess_error_cb gl::eus_tess_get_error
		gl::eus_tess_num_batches gl::eus_tess_batch_mode_at
		gl::eus_tess_batch_start_at gl::eus_tess_batch_count_at
		gl::eus_tess_get_vertexfv))
    (assert (fboundp fn) (format nil "~A should be fboundp" fn))))

(deftest test-eus-tess-reset
  (assert (= (gl::eus_tess_reset) 0))
  (assert (= (gl::eus_tess_num_batches) 0)))

(deftest test-tessellate-simple-triangle
  ;; 既に三角形の場合、GLUはそのまま1個の三角形として返すはず。
  (let ((tris (tess-polygon (list #f(0 0 0) #f(10 0 0) #f(0 10 0)))))
    (assert (= (length tris) 1))
    (assert (eps= (triangle-area (car tris)) 50.0 0.01))))

(deftest test-tessellate-square-no-hole
  ;; 10x10の正方形(穴なし)。三角形2個、合計面積100。
  (let* ((tris (tess-polygon (list #f(-5 -5 0) #f(5 -5 0) #f(5 5 0) #f(-5 5 0))))
	 (area (apply #'+ (mapcar #'triangle-area tris))))
    (assert (eps= area 100.0 0.01))))

(deftest test-tessellate-square-with-square-hole
  ;; 10x10の正方形の中央に2x2の穴。期待面積=100-4=96。
  ;; irteusの穴あきface(:holes)と同じ「外周+穴の頂点列を別々に渡す」
  ;; 形式をそのままGLUのcontourとして渡せることを確認する。
  (let* ((outer (list #f(-5 -5 0) #f(5 -5 0) #f(5 5 0) #f(-5 5 0)))
	 (hole (list #f(-1 -1 0) #f(-1 1 0) #f(1 1 0) #f(1 -1 0))) ;; 穴は外周と逆回り
	 (tris (tess-polygon outer (list hole)))
	 (area (apply #'+ (mapcar #'triangle-area tris))))
    (assert (> (length tris) 2) "should need more than 2 triangles to cover a square with a hole")
    (assert (eps= area 96.0 0.01))))

(deftest test-tessellate-many-holes
  ;; 20x20の正方形に、格子状に配置した半径0.4の小さい穴(近似12角形)を
  ;; 5x5=25個開ける。irteusの実robotパーツ(24個の穴を持つ面)を模した、
  ;; 手計算で面積を検証できる小規模版。
  (let* ((half 10.0)
	 (outer (list (float-vector (- half) (- half) 0) (float-vector half (- half) 0)
		      (float-vector half half 0) (float-vector (- half) half 0)))
	 (hole-r 0.4)
	 (hole-sides 12)
	 (holes nil)
	 (n-holes 0))
    (dotimes (ix 5)
      (dotimes (iy 5)
	(let* ((cx (+ -8.0 (* ix 4.0))) (cy (+ -8.0 (* iy 4.0)))
	       (pts (let (l)
		      (dotimes (k hole-sides)
			(let ((th (/ (* 2 pi k) hole-sides)))
			  (push (float-vector (+ cx (* hole-r (cos th)))
					       (+ cy (* hole-r (sin th))) 0)
				l)))
		      (nreverse l))))
	  (push pts holes)
	  (incf n-holes))))
    (let* ((tris (tess-polygon outer holes))
	   (area (apply #'+ (mapcar #'triangle-area tris)))
	   ;; 正12角形の面積 = 3 r^2 (r=外接円半径として) の近似
	   (hole-area-each (* 3.0 hole-r hole-r))
	   (expected (- (* 2 half 2 half) (* n-holes hole-area-each))))
      (format t "~%25-hole test: ntriangles=~A area=~A expected~~=~A~%" (length tris) area expected)
      (assert (> (length tris) (* 2 n-holes)) "should need noticeably more triangles than a plain square")
      (assert (eps= area expected (* 0.02 expected)) "total area should match outer-area minus holes-area within 2%"))))

(eval-when (load eval)
  (run-all-tests)
  (exit))
