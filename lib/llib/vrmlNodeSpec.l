;;; VRMLnodeSpec.l

(unless (find-package "VRML") (make-package "VRML"))
(in-package "VRML")

(export '(vrml-object *nodetypes* *fieldtypes*))

(defparameter *nodeTypes* nil)
(defparameter *fieldTypes* nil)
(defparameter *pointScale* 1000.0)

(defclass vrml-object :super propertied-object)
(defmethod vrml-object 
 (:init () 
    (let ((defaults (apply #'append (mapcar #'cdr (get (send (class self) :name) :vrml-node-spec))))
	  )
	(dolist (d defaults)
	   (send self :set-field (car d) 
		(cond ((symbolp (third d)) (third d))
		      ((numberp (third d)) (third d))
		      (t (copy-seq (third d)))))))
    self)
 (:set-field (id val)
    (setslot self (class self) id val))
 (:get-field (id)
    (slot self (class self) id))
 )

(defun defvrmlclass (name)
   (make-class name :super vrml-object
		:slots (mapcar #'car (apply #'append (mapcar #'cdr (get name :vrml-node-spec))))))


(defun collect-and-merge (fields type)
   (list* type
         (mapcan #'(lambda (x)
                     (when (eql (first x) type)
			(pushnew (second x) *fieldtypes*)  
                        (list (list (third x) (second x) (fourth x))))
                     )
                  fields)
    ))

(defmacro define-vrml-node-spec (nodeId func &rest decls)
   `(progn
       (setq *nodetypes* (nconc *nodetypes* (list ',nodeId )))
       (setf (get ',nodeId :vrml-node-func)
	     ',func
	     (get ',nodeId :vrml-node-spec)
	     (list (collect-and-merge ',decls 'eventIn)
		   (collect-and-merge ',decls 'eventOut)
		   (append (collect-and-merge ',decls 'field)
			   (cdr (collect-and-merge ',decls 'exposedField))) ) )
	(send ',nodeId :global (defvrmlclass ',nodeId) ',nodeId))
)

(defun make-vrml-node (nodeType)
   (instance (symbol-value nodeType) :init))

;;;
;;;
;;;

(define-vrml-node-spec  Anchor
  nil
  (eventIn      MFNode   addChildren)
  (eventIn      MFNode   removeChildren)
  (exposedfield MFNode   children        ())
  (exposedfield SFString description     "")
  (exposedfield MFString parameter       ())
  (exposedfield MFString url             ())
  (field        SFVec3f  bboxCenter      (0 0 0))
  (field        SFVec3f  bboxSize        (-1 -1 -1))
)

(define-vrml-node-spec   Appearance
  nil
  (exposedfield SFNode material          NULL)
  (exposedfield SFNode texture           NULL)
  (exposedfield SFNode textureTransform  NULL)
)

(define-vrml-node-spec  AudioClip
  nil
  (exposedfield   SFString description      "")
  (exposedfield   SFBool   loop             FALSE)
  (exposedfield   SFFloat  pitch            1.0)
  (exposedfield   SFTime   startTime        0)
  (exposedfield   SFTime   stopTime         0)
  (exposedfield   MFString url              ())
  (eventOut       SFTime   duration_changed)
  (eventOut       SFBool   isActive)
)

(define-vrml-node-spec  Background
  nil
  (eventIn      SFBool   set_bind)
  (exposedfield MFFloat  groundAngle  ())
  (exposedfield MFColor  groundColor  ())
  (exposedfield MFString backUrl      ())
  (exposedfield MFString bottomUrl    ())
  (exposedfield MFString frontUrl     ())
  (exposedfield MFString leftUrl      ())
  (exposedfield MFString rightUrl     ())
  (exposedfield MFString topUrl       ())
  (exposedfield MFFloat  skyAngle     ())
  (exposedfield MFColor  skyColor     ( 0 0 0 ))
  (eventOut     SFBool   isBound)
)

(define-vrml-node-spec Billboard
  nil
  (eventIn      MFNode   addChildren)
  (eventIn      MFNode   removeChildren)
  (exposedfield SFVec3f  axisOfRotation  (0 1 0))
  (exposedfield MFNode   children        ())
  (field        SFVec3f  bboxCenter      (0 0 0))
  (field        SFVec3f  bboxSize        (-1 -1 -1))
)

(defun vrml-box-to-eus (vobj)
   (let* ((size (send vobj :get-field 'size))
	  (eus-cube))
     (if size
         (setq eus-cube 
	       (geo:make-cube (aref size 0) (aref size 1) (aref size 2))))
      eus-cube))

(define-vrml-node-spec  Box
  vrml-box-to-eus
  (field    SFVec3f size  #f(2 2 2))
)

(define-vrml-node-spec  Collision
  nil
  (eventIn      MFNode   addChildren)
  (eventIn      MFNode   removeChildren)
  (exposedfield MFNode   children        ())
  (exposedfield SFBool   collide         TRUE)
  (field        SFVec3f  bboxCenter      (0 0 0))
  (field        SFVec3f  bboxSize        (-1 -1 -1))
  (field        SFNode   proxy           NULL)
  (eventOut     SFTime   collideTime)
)

(define-vrml-node-spec  Color
  nil
  (exposedfield MFColor color  ())
)

(define-vrml-node-spec  ColorInterpolato
  nil
  (eventIn      SFFloat set_fraction)
  (exposedfield MFFloat key           ())
  (exposedfield MFColor keyValue      ())
  (eventOut     SFColor value_changed)
)

(define-vrml-node-spec  Cone
  nil
  (field     SFFloat   bottomRadius 1)
  (field     SFFloat   height       2)
  (field     SFBool    side         TRUE)
  (field     SFBool    bottom       TRUE)
)

(define-vrml-node-spec  Coordinate
  nil
  (exposedfield MFVec3f point  ())
)

(define-vrml-node-spec  CoordinateInterpolator
  nil
  (eventIn      SFFloat set_fraction)
  (exposedfield MFFloat key           ())
  (exposedfield MFVec3f keyValue      ())
  (eventOut     MFVec3f value_changed)
)

(define-vrml-node-spec  Cylinder
  nil
  (field    SFBool    bottom  TRUE)
  (field    SFFloat   height  2)
  (field    SFFloat   radius  1)
  (field    SFBool    side    TRUE)
  (field    SFBool    top     TRUE)
)

(define-vrml-node-spec  CylinderSensor
  nil
  (exposedfield SFBool     autoOffset TRUE)
  (exposedfield SFFloat    diskAngle  0.262)
  (exposedfield SFBool     enabled    TRUE)
  (exposedfield SFFloat    maxAngle   -1)
  (exposedfield SFFloat    minAngle   0)
  (exposedfield SFFloat    offset     0)
  (eventOut     SFBool     isActive)
  (eventOut     SFRotation rotation_changed)
  (eventOut     SFVec3f    trackPoint_changed)
)

(define-vrml-node-spec  DirectionalLight
  nil
  (exposedfield SFFloat ambientIntensity  0)
  (exposedfield SFColor color             (1 1 1))
  (exposedfield SFVec3f direction         (0 0 -1))
  (exposedfield SFFloat intensity         1)
  (exposedfield SFBool  on                TRUE)
)

(define-vrml-node-spec  ElevationGrid
  nil
  (eventIn      MFFloat  set_height)
  (exposedfield SFNode   color             NULL)
  (exposedfield SFNode   normal            NULL)
  (exposedfield SFNode   texCoord          NULL)
  (field        MFFloat  height            ())
  (field        SFBool   ccw               TRUE)
  (field        SFBool   colorPerVertex    TRUE)
  (field        SFFloat  creaseAngle       0)
  (field        SFBool   normalPerVertex   TRUE)
  (field        SFBool   solid             TRUE)
  (field        SFInt32  xDimension        0)
  (field        SFFloat  xSpacing          0.0)
  (field        SFInt32  zDimension        0)
  (field        SFFloat  zSpacing          0.0)
)

(define-vrml-node-spec  Extrusion
  nil
  (eventIn MFVec2f    set_crossSection)
  (eventIn MFRotation set_orientation)
  (eventIn MFVec2f    set_scale)
  (eventIn MFVec3f    set_spine)
  (field   SFBool     beginCap         TRUE)
  (field   SFBool     ccw              TRUE)
  (field   SFBool     convex           TRUE)
  (field   SFFloat    creaseAngle      0)
  (field   MFVec2f    crossSection     ( (1 1) (1 -1) (-1 -1) (-1 1) (1 1) ))
  (field   SFBool     endCap           TRUE)
  (field   MFRotation orientation      (0 0 1 0))
  (field   MFVec2f    scale            1 1)
  (field   SFBool     solid            TRUE)
  (field   MFVec3f    spine            (( 0 0 0) ( 0 1 0 )))
)

(define-vrml-node-spec  Fog
  nil
  (exposedfield SFColor  color            (1 1 1))
  (exposedfield SFString fogType          "LINEAR")
  (exposedfield SFFloat  visibilityRange  0)
  (eventIn      SFBool   set_bind)
  (eventOut     SFBool   isBound)
)

(define-vrml-node-spec  FontStyle
  nil
  (field SFString family       "SERIF")
  (field SFBool   horizontal   TRUE)
  (field MFString justify      "BEGIN")
  (field SFString language     "")
  (field SFBool   leftToRight  TRUE)
  (field SFFloat  size         1.0)
  (field SFFloat  spacing      1.0)
  (field SFString style        "PLAIN")
  (field SFBool   topToBottom  TRUE)
)

(defun vrml-group-to-list (node)
   (let ((children  (send node :get-field 'children)))
      (format t "group: ~s~%" children)
      (if (every #'(lambda (x) (derivedp x geo:cascaded-coords)) children)
	  (let ((cc (geo:cascoords)))
	     (dolist (c children) (send cc :assoc c))
	     (format t "group is combined in a cascoords:~s~%" cc)
	     cc)
	  children)))

(define-vrml-node-spec  Group
  vrml-group-to-list
  (eventIn      MFNode  addChildren)
  (eventIn      MFNode  removeChildren)
  (exposedfield MFNode  children       ())
  (field        SFVec3f bboxCenter     (0 0 0))
  (field        SFVec3f bboxSize       (-1 -1 -1))
)

(define-vrml-node-spec  ImageTexture
  nil
  (exposedfield MFString url     ())
  (field        SFBool   repeatS TRUE)
  (field        SFBool   repeatT TRUE)
)

(defun matching-edge (edges p1 p2)
   (dolist (e edges)
      (let ((pv (geo::edge-pvert e)) (nv (geo::edge-nvert e)))
	(if (or (and (eql p1 pv) (eql p2 nv))
		(and (eql p2 pv) (eql p1 nv)))
	    (return-from matching-edge e)))))

(defun find-or-create-edge (s1 s2 points edges)
   (let ((p1 (aref points s1)) (p2 (aref points s2))
	 (theEdge))
      (setq theEdge (matching-edge (aref edges s1) p1 p2))
      (unless theEdge
	(setq theEdge (instance geo:edge :init :pvertex p1 :nvertex p2))
	(push theEdge (aref edges s1))
	(push theEdge (aref edges s2)))
      theEdge))

(defun vrml-indexedfaceset-to-body (vobj)	;vrml-to-eus body
   (let* ((points
	     (coerce (mapcar #'(lambda (p) (scale *pointScale* p p)) (send (send vobj :get-field 'coord) :get-field 'point)) vector))
	  (coordindices (send vobj :get-field 'coordindex))
	  (normals
	   (if (not (eq 'NULL (send vobj :get-field 'normal)))
	     (coerce (send (send vobj :get-field 'normal) :get-field 'vector) vector)))
	  (normalindices (send vobj :get-field 'normalindex))
	  (edges (make-array (length points)))
	  (created-edges) (created-faces) (eusbody)
	  )
     (while coordindices
	;; constitute one face
	(let* ((s0 (pop coordindices)) (s1 s0) (s2 (pop coordindices))
	       (theEdge) (edge-list) (point-list (list (aref points s1))))
	  (while (not (eql s2 -1))
	     (push (aref points s2) point-list)
	     (setq theEdge (find-or-create-edge s1 s2 points edges))
	     (pushnew theEdge created-edges)
	     (push theEdge edge-list)
	     (setq s1 s2
		   s2 (pop coordindices)) )
	  (setq theEdge (find-or-create-edge s1 s0 points edges))
	  (pushnew theEdge created-edges)
	  (push theEdge edge-list)
	  ;; all constituent edges for a face is accumulated in edge-list
	  ;; set pface and nface here.
	  (push (aref points s0) point-list)
	  (nreverse edge-list)
	  (nreverse point-list)
	  (push (instantiate geo:face) created-faces)
	  (dolist (e edge-list)
	     (let* ((pv (pop point-list)) (nv (car point-list)))
	       ;; (setq xe e xpv pv xnv nv xface (car created-faces))
	       (send e :set-face pv nv (car created-faces))) )
	  (send (car created-faces) :init :edges edge-list)
	  )
	)
	;; all constituent edges for a body is listed in created-edges.
	;; all constituent faces for a body is listed in created-faces.
    (if (every #'(lambda (x) (and (first x) (second x)))
		(send-all created-edges :faces))
	(print 
	  (instance geo:body :init :faces created-faces :edges created-edges))
	(print
	  (instance geo:faceset :init :faces created-faces :edges created-edges))
	)
   ))

(define-vrml-node-spec  IndexedFaceSet
  vrml-indexedFaceSet-to-body
  (eventIn       MFInt32 set_colorIndex)
  (eventIn       MFInt32 set_coordIndex)
  (eventIn       MFInt32 set_normalIndex)
  (eventIn       MFInt32 set_texCoordIndex)
  (exposedfield  SFNode  color             NULL)
  (exposedfield  SFNode  coord             NULL)
  (exposedfield  SFNode  normal            NULL)
  (exposedfield  SFNode  texCoord          NULL)
  (field         SFBool  ccw               TRUE)
  (field         MFInt32 colorIndex        ())
  (field         SFBool  colorPerVertex    TRUE)
  (field         SFBool  convex            TRUE)
  (field         MFInt32 coordIndex        ())
  (field         SFFloat creaseAngle       0)
  (field         MFInt32 normalIndex       ())
  (field         SFBool  normalPerVertex   TRUE)
  (field         SFBool  solid             TRUE)
  (field         MFInt32 texCoordIndex     ())
)

(define-vrml-node-spec  IndexedLineSet
  nil
  (eventIn       MFInt32 set_colorIndex)
  (eventIn       MFInt32 set_coordIndex)
  (exposedfield  SFNode  color             NULL)
  (exposedfield  SFNode  coord             NULL)
  (field         MFInt32 colorIndex        ())
  (field         SFBool  colorPerVertex    TRUE)
  (field         MFInt32 coordIndex        ())
)

(define-vrml-node-spec  Inline
  nil
  (exposedfield MFString url        ())
  (field        SFVec3f  bboxCenter (0 0 0))
  (field        SFVec3f  bboxSize   (-1 -1 -1))
)

(define-vrml-node-spec  LOD
  nil
  (exposedfield MFNode  level    ())
  (field        SFVec3f center   (0 0 0))
  (field        MFFloat range    ())
)

(define-vrml-node-spec  Material
  nil
  (exposedfield SFFloat ambientIntensity  0.2)
  (exposedfield SFColor diffuseColor      (0.8 0.8 0.8))
  (exposedfield SFColor emissiveColor     (0 0 0))
  (exposedfield SFFloat shininess         (0.2))
  (exposedfield SFColor specularColor     (0 0 0))
  (exposedfield SFFloat transparency      0)
)

(define-vrml-node-spec  MovieTexture
  nil
  (exposedfield SFBool   loop             FALSE)
  (exposedfield SFFloat  speed            1)
  (exposedfield SFTime   startTime        0)
  (exposedfield SFTime   stopTime         0)
  (exposedfield MFString url              ())
  (field        SFBool   repeatS          TRUE)
  (field        SFBool   repeatT          TRUE)
  (eventOut     SFFloat  duration_changed)
  (eventOut     SFBool   isActive)
)

(define-vrml-node-spec  NavigationInfo
  nil
  (eventIn      SFBool   set_bind)
  (exposedfield MFFloat  avatarSize       ( 0.25  1.6  0.75 ))
  (exposedfield SFBool   headlight        TRUE)
  (exposedfield SFFloat  speed            1.0)
  (exposedfield MFString type             "WALK")
  (exposedfield SFFloat  visibilityLimit  0.0)
  (eventOut     SFBool   isBound)
)

(define-vrml-node-spec  Normal
  nil
  (exposedfield MFVec3f vector  ())
)

(define-vrml-node-spec  NormalInterpolator
  nil
  (eventIn      SFFloat set_fraction)
  (exposedfield MFFloat key           ())
  (exposedfield MFVec3f keyValue      ())
  (eventOut     MFVec3f value_changed)
)

(define-vrml-node-spec  OrientationInterpolator
  nil
  (eventIn      SFFloat    set_fraction)
  (exposedfield MFFloat    key           ())
  (exposedfield MFRotation keyValue         ())
  (eventOut     SFRotation value_changed)
)

(define-vrml-node-spec  PixelTexture
  nil
  (exposedfield SFImage  image      (0 0 0))
  (field        SFBool   repeatS    TRUE)
  (field        SFBool   repeatT    TRUE)
)

(define-vrml-node-spec  PlaneSensor
  nil
  (exposedfield SFBool  autoOffset          TRUE)
  (exposedfield SFBool  enabled             TRUE)
  (exposedfield SFVec2f maxPosition         (-1 -1))
  (exposedfield SFVec2f minPosition         (0 0))
  (exposedfield SFVec3f offset              (0 0 0))
  (eventOut     SFBool  isActive)
  (eventOut     SFVec3f trackPoint_changed)
  (eventOut     SFVec3f translation_changed)
)

(define-vrml-node-spec  PointLight
  nil
  (exposedfield SFFloat ambientIntensity  0)
  (exposedfield SFVec3f attenuation       (1 0 0))
  (exposedfield SFColor color             (1 1 1))
  (exposedfield SFFloat intensity         1)
  (exposedfield SFVec3f location          (0 0 0))
  (exposedfield SFBool  on                TRUE)
  (exposedfield SFFloat radius            100)
)

(define-vrml-node-spec  PointSet
  nil
  (exposedfield  SFNode  color      NULL)
  (exposedfield  SFNode  coord      NULL)
)

(define-vrml-node-spec  PositionInterpolator
  nil
  (eventIn      SFFloat set_fraction)
  (exposedfield MFFloat key           ())
  (exposedfield MFVec3f keyValue      ())
  (eventOut     SFVec3f value_changed)
)

(define-vrml-node-spec  ProximitySensor
  nil
  (exposedfield SFVec3f    center      (0 0 0))
  (exposedfield SFVec3f    size        (0 0 0))
  (exposedfield SFBool     enabled     TRUE)
  (eventOut     SFBool     isActive)
  (eventOut     SFVec3f    position_changed)
  (eventOut     SFRotation orientation_changed)
  (eventOut     SFTime     enterTime)
  (eventOut     SFTime     exitTime)
)

(define-vrml-node-spec  ScalarInterpolator
  nil
  (eventIn      SFFloat set_fraction)
  (exposedfield MFFloat key           ())
  (exposedfield MFFloat keyValue      ())
  (eventOut     SFFloat value_changed)
)

(define-vrml-node-spec  Script 
  nil
  (exposedfield MFString url           ())
  (field        SFBool   directOutput  FALSE)
  (field        SFBool   mustEvaluate  FALSE)
  ; And any number of
  (eventIn      eventTypeName eventInName)
  (field        fieldTypeName fieldName initialValue)
  (eventOut     eventTypeName eventOutName)
)

(defun vrml-shape-to-body (node)
  (let ((geom (send node :get-field 'geometry))
	(appe (send node :get-field 'appearance)) )
    (if (derivedp geom geo:coordinates)
	(progn (setf (get geom :appearnce) appe)
	       geom)
        node)
    ))

(define-vrml-node-spec  Shape
  vrml-shape-to-body
  (exposedfield SFNode appearance NULL)
  (exposedfield SFNode geometry   NULL)
)

(define-vrml-node-spec  Sound
  nil
  (exposedfield SFVec3f  direction     (0 0 1))
  (exposedfield SFFloat  intensity     1)
  (exposedfield SFVec3f  location      (0 0 0))
  (exposedfield SFFloat  maxBack       10)
  (exposedfield SFFloat  maxFront      10)
  (exposedfield SFFloat  minBack       1)
  (exposedfield SFFloat  minFront      1)
  (exposedfield SFFloat  priority      0)
  (exposedfield SFNode   source        NULL)
  (field        SFBool   spatialize    TRUE)
)

(define-vrml-node-spec  Sphere
  nil
  (field SFFloat radius  1)
)

(define-vrml-node-spec  SphereSensor
  nil
  (exposedfield SFBool     autoOffset        TRUE)
  (exposedfield SFBool     enabled           TRUE)
  (exposedfield SFRotation offset            (0 1 0 0))
  (eventOut     SFBool     isActive)
  (eventOut     SFRotation rotation_changed)
  (eventOut     SFVec3f    trackPoint_changed)
)

(define-vrml-node-spec  SpotLight
  nil
  (exposedfield SFFloat ambientIntensity  0)
  (exposedfield SFVec3f attenuation       (1 0 0))
  (exposedfield SFFloat beamWidth         1.570796)
  (exposedfield SFColor color             (1 1 1))
  (exposedfield SFFloat cutOffAngle       0.785398)
  (exposedfield SFVec3f direction         (0 0 -1))
  (exposedfield SFFloat intensity         1)
  (exposedfield SFVec3f location          (0 0 0))
  (exposedfield SFBool  on                TRUE)
  (exposedfield SFFloat radius            100)
)

(define-vrml-node-spec  Switch
  nil
  (exposedfield    MFNode  choice      ())
  (exposedfield    SFInt32 whichChoice -1)
)

(define-vrml-node-spec  Text
  nil
  (exposedfield  MFString string    ())
  (exposedfield  SFNode   fontStyle NULL)
  (exposedfield  MFFloat  length    ())
  (exposedfield  SFFloat  maxExtent 0.0)
)

(define-vrml-node-spec  TextureCoordinate
  nil
  (exposedfield MFVec2f point  ())
)

(define-vrml-node-spec  TextureTransform
  nil
  (exposedfield SFVec2f center      (0 0))
  (exposedfield SFFloat rotation    0)
  (exposedfield SFVec2f scale       (1 1))
  (exposedfield SFVec2f translation (0 0))
)

(define-vrml-node-spec  TimeSensor
  nil
  (exposedfield SFTime   cycleInterval 1)
  (exposedfield SFBool   enabled       TRUE)
  (exposedfield SFBool   loop          FALSE)
  (exposedfield SFTime   startTime     0)
  (exposedfield SFTime   stopTime      0)
  (eventOut     SFTime   cycleTime)
  (eventOut     SFFloat  fraction_changed)
  (eventOut     SFBool   isActive)
  (eventOut     SFTime   time)
)

(define-vrml-node-spec  TouchSensor
  nil
  (exposedfield SFBool  enabled TRUE)
  (eventOut     SFVec3f hitNormal_changed)
  (eventOut     SFVec3f hitPoint_changed)
  (eventOut     SFVec2f hitTexCoord_changed)
  (eventOut     SFBool  isActive)
  (eventOut     SFBool  isOver)
  (eventOut     SFTime  touchTime)
)

(defun select-objects (objs klass)
   (mapcan  #'(lambda (b) (if (derivedp b klass) (list b)))
	    objs) )   

(defun vrml-transform-to-eus (node)
  (let ((bodies (send node :get-field 'children))
	(translation (send node :get-field 'translation))
	(rotation (send node :get-field 'rotation))
	(scale (send node :get-field 'scale))
	(b) (c) (cc))
     (setq bodies (select-objects bodies geo:cascaded-coords))
     (setq cc (instance geo:cascaded-coords :init
		:axis (car rotation)
		:angle (second rotation)
		:pos (coerce translation float-vector)) )
     (cond ((> (length bodies) 1)
	    (dolist (b bodies)
		(push b *vrml-bodies*)
		(send cc :assoc b))
	    (warning-message 2 "bundled cascoords created: ~s~%" cc)
	    cc)
	   (t (send (car bodies) :transform (send cc :worldcoords) :world)
	      (car bodies)))
      ;; node
     ))

(define-vrml-node-spec  Transform
  vrml-transform-to-eus
  (eventIn      MFNode      addChildren)
  (eventIn      MFNode      removeChildren)
  (exposedfield SFVec3f     center           (0 0 0))
  (exposedfield MFNode      children         ())
  (exposedfield SFRotation  rotation         (0 0 1 0))
  (exposedfield SFVec3f     scale            (1 1 1))
  (exposedfield SFRotation  scaleOrientation (0 0 1  0))
  (exposedfield SFVec3f     translation      (0 0 0))
  (field        SFVec3f     bboxCenter       (0 0 0))
  (field        SFVec3f     bboxSize         (-1 -1 -1))
)

(define-vrml-node-spec Viewpoint
  nil
  (eventIn      SFBool     set_bind)
  (exposedfield SFFloat    fieldOfView    0.785398)
  (exposedfield SFBool     jump           TRUE)
  (exposedfield SFRotation orientation    (0 0 1  0))
  (exposedfield SFVec3f    position       (0 0 10))
  (field        SFString   description    "")
  (eventOut     SFTime     bindTime)
  (eventOut     SFBool     isBound)
)

(define-vrml-node-spec  VisibilitySensor
  nil
  (exposedfield SFVec3f center   (0 0 0))
  (exposedfield SFBool  enabled  TRUE)
  (exposedfield SFVec3f size     (0 0 0))
  (eventOut     SFTime  enterTime)
  (eventOut     SFTime  exitTime)
  (eventOut     SFBool  isActive)
)

(define-vrml-node-spec  WorldInfo
  nil
  (field MFString info  ())
  (field SFString title "")
)

;****************************************************************
; euslisp extension node

(define-vrml-node-spec LoadWRL
  nil
  (field SFString url "")
  )

(define-vrml-node-spec PointerMotion
  nil
  (field MFNode	     children ())
  (field SFRotation  rotation         (0 0 1 0))
  (field SFVec3f     translation      (0 0 0))
  )

(provide :vrml-node-spec)
