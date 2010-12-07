#+:cygwin
(setq m (load-foreign "/usr/X11R6/bin/cygglut-3.dll"))
#-:cygwin
(setq m (load-foreign "/usr/lib/libglut.so"))

;; Display mode bit masks.
(defconstant GLUT_RGB			0)
(defconstant GLUT_RGBA			GLUT_RGB)
(defconstant GLUT_INDEX			1)
(defconstant GLUT_SINGLE		0)
(defconstant GLUT_DOUBLE		2)
(defconstant GLUT_ACCUM			4)
(defconstant GLUT_ALPHA			8)
(defconstant GLUT_DEPTH			16)
(defconstant GLUT_STENCIL		32)
(defconstant GLUT_MULTISAMPLE		128)
(defconstant GLUT_STEREO		256)
(defconstant GLUT_LUMINANCE		512)


;; Mouse buttons.
(defconstant GLUT_LEFT_BUTTON		0)
(defconstant GLUT_MIDDLE_BUTTON		1)
(defconstant GLUT_RIGHT_BUTTON		2)

;; Mouse button  state.
(defconstant GLUT_DOWN			0)
(defconstant GLUT_UP			1)

;; function keys
(defconstant GLUT_KEY_F1		1)
(defconstant GLUT_KEY_F2		2)
(defconstant GLUT_KEY_F3		3)
(defconstant GLUT_KEY_F4		4)
(defconstant GLUT_KEY_F5		5)
(defconstant GLUT_KEY_F6		6)
(defconstant GLUT_KEY_F7		7)
(defconstant GLUT_KEY_F8		8)
(defconstant GLUT_KEY_F9		9)
(defconstant GLUT_KEY_F10		10)
(defconstant GLUT_KEY_F11		11)
(defconstant GLUT_KEY_F12		12)
;; directional keys
(defconstant GLUT_KEY_LEFT		100)
(defconstant GLUT_KEY_UP		101)
(defconstant GLUT_KEY_RIGHT		102)
(defconstant GLUT_KEY_DOWN		103)
(defconstant GLUT_KEY_PAGE_UP		104)
(defconstant GLUT_KEY_PAGE_DOWN		105)
(defconstant GLUT_KEY_HOME		106)
(defconstant GLUT_KEY_END		107)
(defconstant GLUT_KEY_INSERT		108)

;; Entry/exit  state.
(defconstant GLUT_LEFT			0)
(defconstant GLUT_ENTERED		1)

;; Menu usage  state.
(defconstant GLUT_MENU_NOT_IN_USE	0)
(defconstant GLUT_MENU_IN_USE		1)

;; Visibility  state.
(defconstant GLUT_NOT_VISIBLE		0)
(defconstant GLUT_VISIBLE		1)

;;Window status  state.
(defconstant GLUT_HIDDEN		0)
(defconstant GLUT_FULLY_RETAINED	1)
(defconstant GLUT_PARTIALLY_RETAINED	2)
(defconstant GLUT_FULLY_COVERED		3)

;; Color index component selection values.
(defconstant GLUT_RED			0)
(defconstant GLUT_GREEN			1)
(defconstant GLUT_BLUE			2)

;; Stroke font constants (use these in GLUT program).
(defconstant GLUT_STROKE_ROMAN		0)
(defconstant GLUT_STROKE_MONO_ROMAN	1)

;;Bitmap font constants (use these in GLUT program).
(defconstant GLUT_BITMAP_9_BY_15	2)
(defconstant GLUT_BITMAP_8_BY_13	3)
(defconstant GLUT_BITMAP_TIMES_ROMAN_10	4)
(defconstant GLUT_BITMAP_TIMES_ROMAN_24	5)
(defconstant GLUT_BITMAP_HELVETICA_10	6)
(defconstant GLUT_BITMAP_HELVETICA_12	7)
(defconstant GLUT_BITMAP_HELVETICA_18	8)

;; glutGet parameters.
(defconstant GLUT_WINDOW_X		100)
(defconstant GLUT_WINDOW_Y		101)
(defconstant GLUT_WINDOW_WIDTH		102)
(defconstant GLUT_WINDOW_HEIGHT		103)
(defconstant GLUT_WINDOW_BUFFER_SIZE	104)
(defconstant GLUT_WINDOW_STENCIL_SIZE	105)
(defconstant GLUT_WINDOW_DEPTH_SIZE	106)
(defconstant GLUT_WINDOW_RED_SIZE	107)
(defconstant GLUT_WINDOW_GREEN_SIZE	108)
(defconstant GLUT_WINDOW_BLUE_SIZE	109)
(defconstant GLUT_WINDOW_ALPHA_SIZE	110)
(defconstant GLUT_WINDOW_ACCUM_RED_SIZE	111)
(defconstant GLUT_WINDOW_ACCUM_GREEN_SIZE	112)
(defconstant GLUT_WINDOW_ACCUM_BLUE_SIZE	113)
(defconstant GLUT_WINDOW_ACCUM_ALPHA_SIZE	114)
(defconstant GLUT_WINDOW_DOUBLEBUFFER	115)
(defconstant GLUT_WINDOW_RGBA		116)
(defconstant GLUT_WINDOW_PARENT		117)
(defconstant GLUT_WINDOW_NUM_CHILDREN	118)
(defconstant GLUT_WINDOW_COLORMAP_SIZE	119)
(defconstant GLUT_WINDOW_NUM_SAMPLES	120)
(defconstant GLUT_WINDOW_STEREO		121)
(defconstant GLUT_WINDOW_CURSOR		122)
(defconstant GLUT_SCREEN_WIDTH		200)
(defconstant GLUT_SCREEN_HEIGHT		201)
(defconstant GLUT_SCREEN_WIDTH_MM	202)
(defconstant GLUT_SCREEN_HEIGHT_MM	203)
(defconstant GLUT_MENU_NUM_ITEMS	300)
(defconstant GLUT_DISPLAY_MODE_POSSIBLE	400)
(defconstant GLUT_INIT_WINDOW_X		500)
(defconstant GLUT_INIT_WINDOW_Y		501)
(defconstant GLUT_INIT_WINDOW_WIDTH	502)
(defconstant GLUT_INIT_WINDOW_HEIGHT	503)
(defconstant GLUT_INIT_DISPLAY_MODE	504)
(defconstant GLUT_ELAPSED_TIME		700)
(defconstant GLUT_WINDOW_FORMAT_ID	123)

;; glutDeviceGet parameters.
(defconstant GLUT_HAS_KEYBOARD		600)
(defconstant GLUT_HAS_MOUSE		601)
(defconstant GLUT_HAS_SPACEBALL		602)
(defconstant GLUT_HAS_DIAL_AND_BUTTON_BOX	603)
(defconstant GLUT_HAS_TABLET		604)
(defconstant GLUT_NUM_MOUSE_BUTTONS	605)
(defconstant GLUT_NUM_SPACEBALL_BUTTONS	606)
(defconstant GLUT_NUM_BUTTON_BOX_BUTTONS	607)
(defconstant GLUT_NUM_DIALS		608)
(defconstant GLUT_NUM_TABLET_BUTTONS	609)
(defconstant GLUT_DEVICE_IGNORE_KEY_REPEAT   610)
(defconstant GLUT_DEVICE_KEY_REPEAT         611)
(defconstant GLUT_HAS_JOYSTICK		612)
(defconstant GLUT_OWNS_JOYSTICK		613)
(defconstant GLUT_JOYSTICK_BUTTONS	614)
(defconstant GLUT_JOYSTICK_AXES		615)
(defconstant GLUT_JOYSTICK_POLL_RATE	616)

;; glutLayerGet parameters.
(defconstant GLUT_OVERLAY_POSSIBLE      800)
(defconstant GLUT_LAYER_IN_USE		801)
(defconstant GLUT_HAS_OVERLAY		802)
(defconstant GLUT_TRANSPARENT_INDEX	803)
(defconstant GLUT_NORMAL_DAMAGED	804)
(defconstant GLUT_OVERLAY_DAMAGED	805)

;; glutVideoResizeGet parameters.
(defconstant GLUT_VIDEO_RESIZE_POSSIBLE	900)
(defconstant GLUT_VIDEO_RESIZE_IN_USE	901)
(defconstant GLUT_VIDEO_RESIZE_X_DELTA	902)
(defconstant GLUT_VIDEO_RESIZE_Y_DELTA	903)
(defconstant GLUT_VIDEO_RESIZE_WIDTH_DELTA	904)
(defconstant GLUT_VIDEO_RESIZE_HEIGHT_DELTA	905)
(defconstant GLUT_VIDEO_RESIZE_X	906)
(defconstant GLUT_VIDEO_RESIZE_Y	907)
(defconstant GLUT_VIDEO_RESIZE_WIDTH	908)
(defconstant GLUT_VIDEO_RESIZE_HEIGHT	909)

;; glutUseLayer parameters.
(defconstant GLUT_NORMAL		0)
(defconstant GLUT_OVERLAY		1)

;; glutGetModifiers return mask.
(defconstant GLUT_ACTIVE_SHIFT		1)
(defconstant GLUT_ACTIVE_CTRL		2)
(defconstant GLUT_ACTIVE_ALT		4)

;; glutSetCursor parameters.
;; Basic arrows.
(defconstant GLUT_CURSOR_RIGHT_ARROW	0)
(defconstant GLUT_CURSOR_LEFT_ARROW	1)
;; Symbolic cursor shapes.
(defconstant GLUT_CURSOR_INFO		2)
(defconstant GLUT_CURSOR_DESTROY	3)
(defconstant GLUT_CURSOR_HELP		4)
(defconstant GLUT_CURSOR_CYCLE		5)
(defconstant GLUT_CURSOR_SPRAY		6)
(defconstant GLUT_CURSOR_WAIT		7)
(defconstant GLUT_CURSOR_TEXT		8)
(defconstant GLUT_CURSOR_CROSSHAIR	9)
;; Directional cursors.
(defconstant GLUT_CURSOR_UP_DOWN	10)
(defconstant GLUT_CURSOR_LEFT_RIGHT	11)
;; Sizing cursors.
(defconstant GLUT_CURSOR_TOP_SIDE	12)
(defconstant GLUT_CURSOR_BOTTOM_SIDE	13)
(defconstant GLUT_CURSOR_LEFT_SIDE	14)
(defconstant GLUT_CURSOR_RIGHT_SIDE	15)
(defconstant GLUT_CURSOR_TOP_LEFT_CORNER	16)
(defconstant GLUT_CURSOR_TOP_RIGHT_CORNER	17)
(defconstant GLUT_CURSOR_BOTTOM_RIGHT_CORNER	18)
(defconstant GLUT_CURSOR_BOTTOM_LEFT_CORNER	19)
;; Inherit from parent window.
(defconstant GLUT_CURSOR_INHERIT	100)
;; Blank cursor.
(defconstant GLUT_CURSOR_NONE		101)
;; Fullscreen crosshair (if available).
(defconstant GLUT_CURSOR_FULL_CROSSHAIR	102)

;; GLUT initialization subAPI.
(defforeign glutInit m "glutInit" () :integer)
(defforeign glutInitDisplayMode m "glutInitDisplayMode" () :integer)
(defforeign glutInitWindowPosition m "glutInitWindowPosition" () :integer)
(defforeign glutInitWindowSize m "glutInitWindowSize" () :integer)
(defforeign glutMainLoop m "glutMainLoop" () :integer)

;; GLUT window sub-API.
(defforeign glutCreateWindow m "glutCreateWindow" () :integer)
(defforeign glutCreateSubWindow m "glutCreateSubWindow" () :integer)
(defforeign glutDestroyWindow m "glutDestroyWindow" () :integer)
(defforeign glutPostRedisplay m "glutPostRedisplay" () :integer)
(defforeign glutPostWindowRedisplay m "glutPostWindowRedisplay" () :integer)
(defforeign glutSwapBuffers m "glutSwapBuffers" () :integer)
(defforeign glutGetWindow m "glutGetWindow" () :integer)
(defforeign glutSetWindow m "glutSetWindow" () :integer)
(defforeign glutSetWindowTitle m "glutSetWindowTitle" () :integer)
(defforeign glutSetIconTitle m "glutSetIconTitle" () :integer)
(defforeign glutPositionWindow m "glutPositionWindow" () :integer)
(defforeign glutReshapeWindow m "glutReshapeWindow" () :integer)
(defforeign glutPopWindow m "glutReshapeWindow" () :integer)
(defforeign glutPushWindow m "glutPushWindow" () :integer)
(defforeign glutIconifyWindow m "glutIconifyWindow" () :integer)
(defforeign glutShowWindow m "glutShowWindow" () :integer)
(defforeign glutHideWindow m "glutHideWindow" () :integer)
(defforeign glutFullScreen m "glutFullScreen" () :integer)
(defforeign glutSetCursor m "glutSetCursor" () :integer)
(defforeign glutWarpPointer m "glutWarpPointer" () :integer)

;; GLUT overlay sub-API.
(defforeign glutEstablishOverlay m "glutEstablishOverlay" () :integer)
(defforeign glutRemoveOverlay m "glutRemoveOverlay" () :integer)
(defforeign glutUseLayer m "glutUseLayer" () :integer)
(defforeign glutPostOverlayRedisplay m "glutPostOverlayRedisplay" () :integer)
(defforeign glutPostWindowOverlayRedisplay m "glutPostWindowOverlayRedisplay" () :integer)
(defforeign glutShowOverlay m "glutShowOverlay" () :integer)
(defforeign glutHideOverlay m "glutHideOverlay" () :integer)

;; GLUT menu sub-API.
(defforeign glutCreateMenu m "glutCreateMenu" () :integer)
(defforeign glutDestroyMenu m "glutDestroyMenu" () :integer)
(defforeign glutGetMenu m "glutGetMenu" () :integer)
(defforeign glutSetMenu m "glutSetMenu" () :integer)
(defforeign glutAddMenuEntry m "glutAddMenuEntry" () :integer)
(defforeign glutAddSubMenu m "glutAddSubMenu" () :integer)
(defforeign glutChangeToMenuEntry m "glutChangeToMenuEntry" () :integer)
(defforeign glutChangeToSubMenu m "glutChangeToSubMenu" () :integer)
(defforeign glutRemoveMenuItem m "glutRemoveMenuItem" () :integer)
(defforeign glutAttachMenu m "glutAttachMenu" () :integer)
(defforeign glutDetachMenu m "glutDetachMenu" () :integer)

;; GLUT window callback sub-API.
(defforeign glutDisplayFunc m "glutDisplayFunc" () :integer)
(defforeign glutReshapeFunc m "glutReshapeFunc" () :integer)
(defforeign glutKeyboardFunc m "glutKeyboardFunc" () :integer)
(defforeign glutMouseFunc m "glutMouseFunc" () :integer)
(defforeign glutMotionFunc m "glutMotionFunc" () :integer)
(defforeign glutPassiveMotionFunc m "glutPassiveMotionFunc" () :integer)
(defforeign glutEntryFunc m "glutEntryFunc" () :integer)
(defforeign glutVisibilityFunc m "glutVisibilityFunc" () :integer)
(defforeign glutIdleFunc m "glutIdleFunc" () :integer)
(defforeign glutTimerFunc m "glutTimerFunc" () :integer)
(defforeign glutMenuStateFunc m "glutMenuStateFunc" () :integer)
(defforeign glutSpecialFunc m "glutSpecialFunc" () :integer)
(defforeign glutSpaceballMotionFunc m "glutSpaceballMotionFunc" () :integer)
(defforeign glutSpaceballRotateFunc m "glutSpaceballRotateFunc" () :integer)
(defforeign glutSpaceballButtonFunc m "glutSpaceballButtonFunc" () :integer)
(defforeign glutButtonBoxFunc m "glutButtonBoxFunc" () :integer)
(defforeign glutDialsFunc m "glutDialsFunc" () :integer)
(defforeign glutTabletMotionFunc m "glutTabletMotionFunc" () :integer)
(defforeign glutTabletButtonFunc m "glutTabletButtonFunc" () :integer)
(defforeign glutMenuStatusFunc m "glutMenuStatusFunc" () :integer)
(defforeign glutOverlayDisplayFunc m "glutOverlayDisplayFunc" () :integer)
(defforeign glutWindowStatusFunc m "glutWindowStatusFunc" () :integer)
(defforeign glutKeyboardUpFunc m "glutKeyboardUpFunc" () :integer)
(defforeign glutSpecialUpFunc m "glutSpecialUpFunc" () :integer)
(defforeign glutJoystickFunc m "glutJoystickFunc" () :integer)

;; GLUT color index sub-API.
(defforeign glutSetColor m "glutSetColor" () :integer)
(defforeign glutGetColor m "glutGetColor" () :integer)
(defforeign glutCopyColormap m "glutCopyColormap" () :integer)

;; GLUT state retrieval sub-API.
(defforeign glutGet m "glutGet" () :integer)
(defforeign glutDeviceGet m "glutDeviceGet" () :integer)
(defforeign glutExtensionSupported m "glutExtensionSupported" () :integer)
(defforeign glutGetModifiers m "glutGetModifiers" () :integer)
(defforeign glutLayerGet m "glutLayerGet" () :integer)

;; GLUT font sub-API
(defforeign glutBitmapCharacter m "glutBitmapCharacter" () :integer)
(defforeign glutBitmapWidth m "glutBitmapWidth" () :integer)
(defforeign glutStrokeCharacter m "glutStrokeCharacter" () :integer)
(defforeign glutStrokeWidth m "glutStrokeWidth" () :integer)
(defforeign glutBitmapLength m "glutBitmapLength" () :integer)
(defforeign glutStrokeLength m "glutStrokeLength" () :integer)

;; GLUT pre-built models sub-API
(defforeign glutWireSphere m "glutWireSphere" () :integer)
(defforeign glutSolidSphere m "glutSolidSphere" () :integer)
(defforeign glutWireCone m "glutWireCone" () :integer)
(defforeign glutSolidCone m "glutSolidCone" () :integer)
(defforeign glutWireCube m "glutWireCube" () :integer)
(defforeign glutSolidCube m "glutSolidCube" () :integer)
(defforeign glutWireTorus m "glutWireTorus" () :integer)
(defforeign glutSolidTorus m "glutSolidTorus" () :integer)
(defforeign glutWireDodecahedron m "glutWireDodecahedron" () :integer)
(defforeign glutSolidDodecahedron m "glutSolidDodecahedron" () :integer)
(defforeign glutWireTeapot m "glutWireTeapot" () :integer)
(defforeign glutSolidTeapot m "glutSolidTeapot" () :integer)
(defforeign glutWireOctahedron m "glutWireOctahedron" () :integer)
(defforeign glutSolidOctahedron m "glutSolidOctahedron" () :integer)
(defforeign glutWireTetrahedron m "glutWireTetrahedron" () :integer)
(defforeign glutSolidTetrahedron m "glutSolidTetrahedron" () :integer)
(defforeign glutWireIcosahedron m "glutWireIcosahedron" () :integer)
(defforeign glutSolidIcosahedron m "glutSolidIcosahedron" () :integer)

;; GLUT video resize sub-API.
(defforeign glutVideoResizeGet m "glutVideoResizeGet" () :integer)
(defforeign glutSetupVideoResizing m "glutSetupVideoResizing" () :integer)
(defforeign glutStopVideoResizing m "glutStopVideoResizing" () :integer)
(defforeign glutVideoResize m "glutVideoResize" () :integer)
(defforeign glutVideoPan m "glutVideoPan" () :integer)

;; GLUT debugging sub-API.
(defforeign glutReportErrors m "glutReportErrors" () :integer)

;; GLUT device control sub-API.
;; glutSetKeyRepeat modes.
(defconstant GLUT_KEY_REPEAT_OFF	0)
(defconstant GLUT_KEY_REPEAT_ON		1)
(defconstant GLUT_KEY_REPEAT_DEFAULT	2)

;; Joystick button masks.
(defconstant GLUT_JOYSTICK_BUTTON_A		1)
(defconstant GLUT_JOYSTICK_BUTTON_B		2)
(defconstant GLUT_JOYSTICK_BUTTON_C		4)
(defconstant GLUT_JOYSTICK_BUTTON_D		8)

(defforeign glutIgnoreKeyRepeat m "glutIgnoreKeyRepeat" () :integer)
(defforeign glutSetKeyRepeat m "glutSetKeyRepeat" () :integer)
(defforeign glutForceJoystickFunc m "glutForceJoystickFunc" () :integer)

;; GLUT game mode sub-API.
;; glutGameModeGet.
(defconstant GLUT_GAME_MODE_ACTIVE           0)
(defconstant GLUT_GAME_MODE_POSSIBLE         1)
(defconstant GLUT_GAME_MODE_WIDTH            2)
(defconstant GLUT_GAME_MODE_HEIGHT           3)
(defconstant GLUT_GAME_MODE_PIXEL_DEPTH      4)
(defconstant GLUT_GAME_MODE_REFRESH_RATE     5)
(defconstant GLUT_GAME_MODE_DISPLAY_CHANGED  6)

