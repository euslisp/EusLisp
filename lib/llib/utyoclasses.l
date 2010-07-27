;;;
;;;
;;; 2 dimensional data type
(defclass 2dline
  :super object :slots (nor c))
(defclass 2dlnseg
  :super 2dline :slots (spos epos))
(defclass 2dlnsegs
  :super object :slots (segs count))
(defclass 2dpalnsegs
  :super 2dlnsegs
  :slots (step
	  perimenter
	  area))
(defclass 2dpoints
  :super object
  :slots (poss center count               
	       min-x max-x min-y max-y
	       gxx gxy gyy
	       ))
(defclass 2dpolyline
  :super 2dpoints
  :slots (length lnseg))
(defclass 2dpolygon :super 2dpolyline
  :slots (perimenter
	  area
	  convex-hal))
(defclass 2dbox :super 2dpolygon :slots (minpoint maxpoint))

;;; 3 dimensional data type
(defclass 3dline
  :super object
  :slots (ori pos))

(defclass 3dlnseg :super 3dline :slots (spos epos))
(defclass 3dpoints :super object
  :slots (poss center count               
	       min-x max-x
	       min-y max-y
	       min-z max-z
	       gxx gxy gyy gzz
	       ))
;;;
;;; Calibration
;;;
(defclass camera-calib-sample :super object :slots (uv xyz))
(defclass camera-calib-coord :super coordinates
  :slots (samplist
	  transform34
	  uv0 rk
	  ))
;;
;; pick-port
;;

(defclass model-pickport
	  :super viewer
	  :slots (objects edge-images)
	  )
(defclass image-pickport
	  :super viewer
	  :slots (polylines  )  )

