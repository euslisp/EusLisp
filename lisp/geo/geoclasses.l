;;;; Class Definitions for Geometric Modeling
;;	1988
;;	Copyright (c) 1988, 1991,
;;	Toshihiro Matsui, Electrotechnical Laboratory
;;
;;	Dec/1991	symbol names exported to make use of packages
;;			All these classes are defined in GEOMETRY package.

(in-package "GEOMETRY")
;; export class names
(export 
      '(coordinates cascaded-coords bounding-box surrounding-box
	line edge winged-edge plane polygon face hole
	faceset
	body sphere
 	edge-image face-image
	viewing projection viewing2d parallel-viewing
	perspective-viewing stereo-viewing viewport viewer viewsurface))

;; Hirukawa's
(export '(constrained-point constraint-relation))

;; export slot names
(export '(pvert nvert vertices edges faces holes box worldcoords
	  pface nface angle
	  normal distance
	  model-normal model-distance model-vertices 
	  convexp evetedp csg
	  mbody primitive-face id flags))

;; export slot access macros
(export '(bounding-box-minpoint bounding-box-maxpoint
	  line-plist line-pvert line-nvert
	  edge-plist edge-pvert edge-nvert edge-pface edge-nface edge-angle
	  plane-normal plane-distance plane-plist
	  polygon-normal polygon-distance polygon-plist
	  polygon-vertices polygon-edges
	  face-plist face-normal face-distance face-edges face-vertices
	  face-convexp
	  faceset-plist faceset-box faceset-edges faceset-vertices faceset-faces 
	  body-plist body-box body-edges body-vertices body-faces body-csg
	  body-model-vertices body-convexp
	  viewing-viewcoords
	  viewer-eye viewer-port viewer-surface))


;;; Coordinates

(defclass coordinates
  :super propertied-object
  :slots (rot pos))

(defclass cascaded-coords
  :super coordinates
  :slots (parent descendants worldcoords manager changed))

;;; Geopack
(defclass bounding-box
  :super object
  :slots (minpoint maxpoint))

(defclass line :super propertied-object :slots (pvert nvert))

(defclass edge  :super line
  :slots (pface nface
	  (angle :type float)	;angle between adjacent faces
	  (flags :type integer)
	 ))

(defclass winged-edge :super edge
  :slots (pwing pcwing nwing ncwing))

(defclass plane :super propertied-object
  :slots
  ((normal   :type float-vector)	;surface normal #f(a b c)
   (distance :type float)	;distance to self
   ))
(defclass polygon
  :super  plane
  :slots
  (convexp	;if convex, t, concave, nil;
   edges		;profile edge list
   vertices	;profile vertex list
   (model-normal :type float-vector) ;surface-normal before transformation
   (model-distance :type float)
   ))

(defclass face :super polygon
		:slots (holes mbody primitive-face id))

(defclass hole :super polygon :slots (myface))

(defclass faceset :super cascaded-coords
	:slots	(box		;bounding box
		 faces
		 edges
		 vertices
		 model-vertices))

(defclass body  :super faceset
	  :slots (
		 convexp	;
		 evertedp
		 csg
		 ))

;; Hirukawa's constraint motion planning

(defclass constrained-point
  :super object
  :slots (position hisposition hisface myneighborhood condition))


(defclass constraint-relation
  :super object
  :slots (constraining-body constrained-body constraints))



(defclass sphere :super cascaded-coords
		 :slots (radius))

;;; hidden-line
(defclass edge-image
  :super object
  :slots
  ((edge3 :type edge)
   (homo-pvert :type float-vector)
   (homo-nvert :type float-vector) ;projected vertices
   (pvert2 :type float-vector)
   (nvert2 :type float-vector)	;normal coords representation
   segments
   (contourp)
   ))

(defclass face-image :super object
	:slots ((box :type bounding-box)
		edge-images
		(face3d :type face)
		distance))

;;; Viewing, Viewport, Viewsurface, Viewer

(defclass viewing :super cascaded-coords  :slots (viewcoords)) 
(defclass projection :super viewing
	  :slots ((screenx :type float)
		  (screeny :type float)
		  (hither :type float)
		  (yon :type float)
		  projection-matrix))
(defclass viewing2d :super projection)
(defclass parallel-viewing :super projection)
(defclass perspective-viewing :super projection
	  :slots ((viewdistance :type float)))
(defclass stereo-viewing 
  :slots (viewpoint offset target rightview leftview))

(defclass viewport :super coordinates)

(defclass viewer :super propertied-object
	:slots (eye port surface alt-surface))

(defclass viewsurface :super propertied-object)


(provide :geoclasses "@(#)$Id: geoclasses.l,v 1.1.1.1 2003/11/20 07:46:28 eus Exp $")

