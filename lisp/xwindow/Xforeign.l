#|
(export '(
	ActivateScreenSaver
	AddExtension
	AddHost
	AddHosts
	AddPixel
	AddToExtensionList
	AddToSaveSet
	AllPlanes
	AllocClassHint
	AllocColor
	AllocColorCells
	AllocColorPlanes
	AllocIconSize
	AllocNamedColor
	AllocSizeHints
	AllocStandardColormap
	AllocWMHints
	AllowEvents
	AutoRepeatOff
	AutoRepeatOn
	BaseFontNameListOfFontSet
	Bell
	BitmapBitOrder
	BitmapPad
	BitmapUnit
	BlackPixel
	BlackPixelOfScreen
	CellsOfScreen
	ChangeActivePointerGrab
	ChangeGC
	ChangeKeyboardControl
	ChangeKeyboardMapping
	ChangePointerControl
	ChangeProperty
	ChangeSaveSet
	ChangeWindowAttributes
	CheckIfEvent
	CheckMaskEvent
	CheckTypedEvent
	CheckTypedWindowEvent
	CheckWindowEvent
	CirculateSubwindows
	CirculateSubwindowsDown
	CirculateSubwindowsUp
	ClearArea
	ClearWindow
	ClipBox
	CloseDisplay
	CloseIM
	ConfigureWindow
	ConnectionNumber
	ContextDependentDrawing
	ConvertSelection
	CopyArea
	CopyColormapAndFree
	CopyGC
	CopyPlane
	CreateBitmapFromData
	CreateColormap
	CreateFontCursor
	CreateFontSet
	CreateGC
	CreateGlyphCursor
	CreateIC
	CreateImage
	CreatePixmap
	CreatePixmapCursor
	CreatePixmapFromBitmapData
	CreateRegion
	CreateSimpleWindow
	CreateWindow
	DefaultColormap
	DefaultColormapOfScreen
	DefaultDepth
	DefaultDepthOfScreen
	DefaultGC
	DefaultGCOfScreen
	DefaultRootWindow
	DefaultScreen
	DefaultScreenOfDisplay
	DefaultString
	DefaultVisual
	DefaultVisualOfScreen
	DefineCursor
	DeleteContext
	DeleteModifiermapEntry
	DeleteProperty
	DestroyIC
	DestroyImage
	DestroyRegion
	DestroySubwindows
	DestroyWindow
	DisableAccessControl
	DisplayCells
	DisplayHeight
	DisplayHeightMM
	DisplayKeycodes
	DisplayMotionBufferSize
	DisplayName
	DisplayOfIM
	DisplayOfScreen
	DisplayPlanes
	DisplayString
	DisplayWidth
	DisplayWidthMM
	DoesBackingStore
	DoesSaveUnders
	DrawArc
	DrawArcs
	DrawImageString
	DrawImageString16
	DrawLine
	DrawLines
	DrawPoint
	DrawPoints
	DrawRectangle
	DrawRectangles
	DrawSegments
	DrawString
	DrawString16
	DrawText
	DrawText16
	EHeadOfExtensionList
	ESetCloseDisplay
	ESetCopyGC
	ESetCreateFont
	ESetCreateGC
	ESetError
	ESetErrorString
	ESetEventToWire
	ESetFlushGC
	ESetFreeFont
	ESetFreeGC
	ESetPrintErrorValues
	ESetWireToError
	ESetWireToEvent
	EmptyRegion
	EnableAccessControl
	EqualRegion
	EventMaskOfScreen
	EventsQueued
	ExtentsOfFontSet
	FetchBuffer
	FetchBytes
	FetchName
	FillArc
	FillArcs
	FillPolygon
	FillRectangle
	FillRectangles
	FilterEvent
	FindContext
	FindOnExtensionList
	Flush
	FlushGC
	FontsOfFontSet
	ForceScreenSaver
	Free
	FreeColormap
	FreeColors
	FreeCursor
	FreeExtensionList
	FreeFont
	FreeFontInfo
	FreeFontNames
	FreeFontPath
	FreeFontSet
	FreeGC
	FreeModifiermap
	FreePixmap
	FreeStringList
	GContextFromGC
	Geometry
	GetAtomName
	GetClassHint
	GetCommand
	GetDefault
	GetErrorDatabaseText
	GetErrorText
	GetFontPath
	GetFontProperty
	GetGCValues
	GetGeometry
	GetICValues
	GetIMValues
	GetIconName
	GetIconSizes
	GetImage
	GetInputFocus
	GetKeyboardControl
	GetKeyboardMapping
	GetModifierMapping
	GetMotionEvents
	GetNormalHints
	GetPixel
	GetPointerControl
	GetPointerMapping
	GetRGBColormaps
	GetScreenSaver
	GetSelectionOwner
	GetSizeHints
	GetStandardColormap
	GetSubImage
	GetTextProperty
	GetTransientForHint
	GetVisualInfo
	GetWMClientMachine
	GetWMColormapWindows
	GetWMHints
	GetWMIconName
	GetWMName
	GetWMNormalHints
	GetWMProtocols
	GetWMSizeHints
	GetWindowAttributes
	GetWindowProperty
	GetZoomHints
	GrabButton
	GrabKey
	GrabKeyboard
	GrabPointer
	GrabServer
	HeightMMOfScreen
	HeightOfScreen
	IMOfIC
	IconifyWindow
	IfEvent
	ImageByteOrder
	InitExtension
	InsertModifiermapEntry
	InstallColormap
	InternAtom
	IntersectRegion
	KeycodeToKeysym
	KeysymToKeycode
	KeysymToString
	KillClient
	LastKnownRequestProcessed
	ListDepths
	ListExtensions
	ListFonts
	ListFontsWithInfo
	ListHosts
	ListInstalledColormaps
	ListPixmapFormats
	ListProperties
	LoadFont
	LoadQueryFont
	LocaleOfFontSet
	LocaleOfIM
	LookupColor
	LookupKeysym
	LookupString
	LowerWindow
	MapRaised
	MapSubwindows
	MapWindow
	MaskEvent
	MatchVisualInfo
	MaxCmapsOfScreen
	MaxRequestSize
	MinCmapsOfScreen
	MoveResizeWindow
	MoveWindow
	NewModifiermap
	NextEvent
	NextRequest
	NoOp
	OffsetRegion
	OpenDisplay
	OpenIM
	ParseColor
	ParseGeometry
	PeekEvent
	PeekIfEvent
	Pending
	PlanesOfScreen
	PointInRegion
	PolygonRegion
	ProtocolRevision
	ProtocolVersion
	PutBackEvent
	PutImage
	PutPixel
	QLength
	QueryBestCursor
	QueryBestSize
	QueryBestStipple
	QueryBestTile
	QueryColor
	QueryColors
	QueryExtension
	QueryFont
	QueryKeymap
	QueryPointer
	QueryTextExtents
	QueryTextExtents16
	QueryTree
	RaiseWindow
	ReadBitmapFile
	RebindKeysym
	RecolorCursor
	ReconfigureWMWindow
	RectInRegion
	RefreshKeyboardMapping
	RemoveFromSaveSet
	RemoveHost
	RemoveHosts
	ReparentWindow
	ResetScreenSaver
	ResizeWindow
	ResourceManagerString
	RestackWindows
	RootWindow
	RootWindowOfScreen
	RotateBuffers
	RotateWindowProperties
	SaveContext
	ScreenCount
	ScreenNumberOfScreen
	ScreenOfDisplay
	ScreenResourceString
	SelectInput
	SendEvent
	ServerVendor
	SetAccessControl
	SetAfterFunction
	SetArcMode
	SetAuthorization
	SetBackground
	SetClassHint
	SetClipMask
	SetClipOrigin
	SetClipRectangles
	SetCloseDownMode
	SetCommand
	SetDashes
	SetErrorHandler
	SetFillRule
	SetFillStyle
	SetFont
	SetFontPath
	SetForeground
	SetFunction
	SetGraphicsExposures
	SetICFocus
	SetICValues
	SetIOErrorHandler
	SetIconName
	SetIconSizes
	SetInputFocus
	SetLineAttributes
	SetLocaleModifiers
	SetModifierMapping
	SetNormalHints
	SetPlaneMask
	SetPointerMapping
	SetRGBColormaps
	SetRegion
	SetScreenSaver
	SetSelectionOwner
	SetSizeHints
	SetStandardColormap
	SetStandardProperties
	SetState
	SetStipple
	SetSubwindowMode
	SetTSOrigin
	SetTextProperty
	SetTile
	SetTransientForHint
	SetWMClientMachine
	SetWMColormapWindows
	SetWMHints
	SetWMIconName
	SetWMName
	SetWMNormalHints
	SetWMProperties
	SetWMProtocols
	SetWMSizeHints
	SetWindowBackground
	SetWindowBackgroundPixmap
	SetWindowBorder
	SetWindowBorderPixmap
	SetWindowBorderWidth
	SetWindowColormap
	SetZoomHints
	ShrinkRegion
	StoreBuffer
	StoreBytes
	StoreColor
	StoreColors
	StoreName
	StoreNamedColor
	StringListToTextProperty
	StringToKeysym
	SubImage
	SubtractRegion
	SupportsLocale
	Sync
	Synchronize
	TextExtents
	TextExtents16
	TextPropertyToStringList
	TextWidth
	TextWidth16
	TranslateCoordinates
	UndefineCursor
	UngrabButton
	UngrabKey
	UngrabKeyboard
	UngrabPointer
	UngrabServer
	UninstallColormap
	UnionRectWithRegion
	UnionRegion
	UnloadFont
	UnmapSubwindows
	UnmapWindow
	UnsetICFocus
	VaCreateNestedList
	VendorRelease
	VisualIDFromVisual
	WMGeometry
	WarpPointer
	WhitePixel
	WhitePixelOfScreen
	WidthMMOfScreen
	WidthOfScreen
	WindowEvent
	WithdrawWindow
	WriteBitmapFile
	XorRegion
	auDisposeAuth
	auFileName
	auGetBestAuthByAddr
	auReadAuth
	cmsAddColorSpace
	cmsAddFunctionSet
	cmsAllocColor
	cmsAllocNamedColor
	cmsCCCOfColormap
	cmsCIELabClipL
	cmsCIELabClipLab
	cmsCIELabClipab
	cmsCIELabColorSpace
	cmsCIELabQueryMaxC
	cmsCIELabQueryMaxL
	cmsCIELabQueryMaxLC
	cmsCIELabQueryMinL
	cmsCIELabToCIEXYZ
	cmsCIELabWhiteShiftColors
	cmsCIELab_ValidSpec
	cmsCIELab_prefix
	cmsCIELuvClipL
	cmsCIELuvClipLuv
	cmsCIELuvClipuv
	cmsCIELuvColorSpace
	cmsCIELuvQueryMaxC
	cmsCIELuvQueryMaxL
	cmsCIELuvQueryMaxLC
	cmsCIELuvQueryMinL
	cmsCIELuvToCIEuvY
	cmsCIELuvWhiteShiftColors
	cmsCIELuv_ValidSpec
	cmsCIELuv_prefix
	cmsCIEXYZColorSpace
	cmsCIEXYZToCIELab
	cmsCIEXYZToCIEuvY
	cmsCIEXYZToCIExyY
	cmsCIEXYZToRGBi
	cmsCIEXYZ_ValidSpec
	cmsCIEXYZ_prefix
	cmsCIEuvYColorSpace
	cmsCIEuvYToCIELuv
	cmsCIEuvYToCIEXYZ
	cmsCIEuvYToTekHVC
	cmsCIEuvY_ValidSpec
	cmsCIEuvY_prefix
	cmsCIExyYColorSpace
	cmsCIExyYToCIEXYZ
	cmsCIExyY_ValidSpec
	cmsCIExyY_prefix
	cmsClientWhitePointOfCCC
	cmsConvertColors
	cmsCreateCCC
	cmsDefaultCCC
	cmsDisplayOfCCC
	cmsFormatOfPrefix
	cmsFreeCCC
	cmsFreeColorDB
	cmsLRGB_RGB_ParseString
	cmsLRGB_RGBi_ParseString
	cmsLinearRGBFunctionSet
	cmsLookupColor
	cmsPrefixOfFormat
	cmsQueryBlack
	cmsQueryBlue
	cmsQueryColor
	cmsQueryColors
	cmsQueryGreen
	cmsQueryRed
	cmsQueryWhite
	cmsRGBColorSpace
	cmsRGBToRGBi
	cmsRGB_prefix
	cmsRGBiColorSpace
	cmsRGBiToCIEXYZ
	cmsRGBiToRGB
	cmsRGBi_prefix
	cmsScreenNumberOfCCC
	cmsScreenWhitePointOfCCC
	cmsSetCompressionProc
	cmsSetWhiteAdjustProc
	cmsSetWhitePoint
	cmsStoreColor
	cmsStoreColors
	cmsTekHVCClipC
	cmsTekHVCClipV
	cmsTekHVCClipVC
	cmsTekHVCColorSpace
	cmsTekHVCQueryMaxC
	cmsTekHVCQueryMaxV
	cmsTekHVCQueryMaxVC
	cmsTekHVCQueryMaxVSamples
	cmsTekHVCQueryMinV
	cmsTekHVCToCIEuvY
	cmsTekHVCWhiteShiftColors
	cmsTekHVC_ValidSpec
	cmsTekHVC_prefix
	cmsUNDEFINEDColorSpace
	cmsVisualOfCCC
	mbDrawImageString
	mbDrawString
	mbDrawText
	mbLookupString
	mbResetIC
	mbSetWMProperties
	mbTextEscapement
	mbTextExtents
	mbTextListToTextProperty
	mbTextPerCharExtents
	mbTextPropertyToTextList
	permalloc
	rmCombineDatabase
	rmCombineFileDatabase
	rmDestroyDatabase
	rmEnumerateDatabase
	rmGetDatabase
	rmGetFileDatabase
	rmGetResource
	rmGetStringDatabase
	rmInitialize
	rmLocaleOfDatabase
	rmMergeDatabases
	rmParseCommand
	rmPermStringToQuark
	rmPutFileDatabase
	rmPutLineResource
	rmPutResource
	rmPutStringResource
	rmQGetResource
	rmQGetSearchList
	rmQGetSearchResource
	rmQPutResource
	rmQPutStringResource
	rmQuarkToString
	rmSetDatabase
	rmStringToBindingQuarkList
	rmStringToQuark
	rmStringToQuarkList
	rmUniqueQuark
	wcDrawImageString
	wcDrawString
	wcDrawText
	wcFreeStringList
	wcLookupString
	wcResetIC
	wcTextEscapement
	wcTextExtents
	wcTextListToTextProperty
	wcTextPerCharExtents
	wcTextPropertyToTextList
	ctCreate
	ctFree
	ctNextItem
	ctReset
	muAddCloseDisplayHook
	muAddInitializer
	muAllStandardColormaps
	muCallInitializers
	muClientWindow
	muCompareISOLatin1
	muConvertStandardSelection
	muCopyISOLatin1Lowered
	muCopyISOLatin1Uppered
	muCreateColormap
	muCreatePixmapFromBitmap
	muCreateStippledPixmap
	muCursorNameToIndex
	muCvtFunctionToCallback
	muCvtStringToBackingStore
	muCvtStringToBitmap
	muCvtStringToColorCursor
	muCvtStringToCursor
	muCvtStringToGravity
	muCvtStringToJustify
	muCvtStringToLong
	muCvtStringToOrientation
	muCvtStringToShapeStyle
	muCvtStringToWidget
	muDQAddDisplay
	muDQCreate
	muDQDestroy
	muDQLookupDisplay
	muDQRemoveDisplay
	muDeleteStandardColormap
	muDistinguishableColors
	muDistinguishablePixels
	muDrawLogo
	muDrawRoundedRectangle
	muFillRoundedRectangle
	muGetAtomName
	muGetColormapAllocation
	muGetHostname
	muInternAtom
	muInternStrings
	muLocateBitmapFile
	muLocatePixmapFile
	muLookupAPL
	muLookupArabic
	muLookupCloseDisplayHook
	muLookupCyrillic
	muLookupGreek
	muLookupHebrew
	muLookupJISX0201
	muLookupKana
	muLookupLatin1
	muLookupLatin2
	muLookupLatin3
	muLookupLatin4
	muLookupStandardColormap
	muLookupString
	muMakeAtom
	muNameOfAtom
	muNewCvtStringToWidget
	muPrintDefaultErrorMessage
	muReadBitmapData
	muReadBitmapDataFromFile
	muReleaseStippledPixmap
	muRemoveCloseDisplayHook
	muReshapeWidget
	muScreenOfWindow
	muSimpleErrorHandler
	muStandardColormap
	muUpdateMapHints
	muVisualStandardColormaps
	muWnCountOwnedResources
	muWnFetchResources
	muWnInitializeNodes
	muWnNameToNode
	tAppAddActionHook
	tRemoveActionHook
	tCalloc
	tFree
	tMalloc
	tRealloc
	tMergeArgLists
	tAddCallback
	tAddCallbacks
	tCallCallbackList
	tCallCallbacks
	tHasCallbacks
	tRemoveAllCallbacks
	tRemoveCallback
	tRemoveCallbacks
	tGetMultiClickTime
	tSetMultiClickTime
	tAddConverter
	tAppAddConverter
	tAppReleaseCacheRefs
	tAppSetTypeConverter
	tCallConverter
	tCallbackReleaseCacheRef
	tCallbackReleaseCacheRefList
	tConvert
	tConvertAndStore
	tDirectConvert
	tSetTypeConverter
	tCvtColorToPixel
	tCvtIntToBool
	tCvtIntToBoolean
	tCvtIntToColor
	tCvtIntToFloat
	tCvtIntToFont
	tCvtIntToPixel
	tCvtIntToPixmap
	tCvtIntToShort
	tCvtIntToUnsignedChar
	tCvtStringToAtom
	tCvtStringToBool
	tCvtStringToBoolean
	tCvtStringToCursor
	tCvtStringToDimension
	tCvtStringToDisplay
	tCvtStringToFile
	tCvtStringToFloat
	tCvtStringToFont
	tCvtStringToFontSet
	tCvtStringToFontStruct
	tCvtStringToInitialState
	tCvtStringToInt
	tCvtStringToPixel
	tCvtStringToShort
	tCvtStringToUnsignedChar
	tCvtStringToVisual
	tDisplayStringConversionWarning
	tStringConversionWarning
	tAppCreateShell
	tCreateApplicationShell
	tCreateManagedWidget
	tCreatePopupShell
	tCreateWidget
	tInitializeWidgetClass
	tDestroyWidget
	tCloseDisplay
	tCreateApplicationContext
	tDatabase
	tDestroyApplicationContext
	tDisplayInitialize
	tDisplayToApplicationContext
	tGetApplicationNameAndClass
	tOpenDisplay
	tWidgetToApplicationContext
	tAppError
	tAppErrorMsg
	tAppGetErrorDatabase
	tAppGetErrorDatabaseText
	tAppSetErrorHandler
	tAppSetErrorMsgHandler
	tAppSetWarningHandler
	tAppSetWarningMsgHandler
	tAppWarning
	tAppWarningMsg
	tError
	tErrorMsg
	tGetErrorDatabase
	tGetErrorDatabaseText
	tSetErrorHandler
	tSetErrorMsgHandler
	tSetWarningHandler
	tSetWarningMsgHandler
	tWarning
	tWarningMsg
	tAddEventHandler
	tAddExposureToRegion
	tAddGrab
	tAddRawEventHandler
	tAppMainLoop
	tBuildEventMask
	tDispatchEvent
	tInsertEventHandler
	tInsertRawEventHandler
	tLastTimestampProcessed
	tMainLoop
	tRemoveEventHandler
	tRemoveGrab
	tRemoveRawEventHandler
	tWindowToWidget
	tIsApplicationShell
	tIsComposite
	tIsConstraint
	tIsOverrideShell
	tIsRectObj
	tIsShell
	tIsTopLevelShell
	tIsTransientShell
	tIsVendorShell
	tIsWMShell
	tIsWidget
	tMapWidget
	tNewString
	tUnmapWidget
	tAllocateGC
	tDestroyGC
	tGetGC
	tReleaseGC
	tConfigureWidget
	tMakeGeometryRequest
	tMakeResizeRequest
	tMoveWidget
	tQueryGeometry
	tResizeWidget
	tResizeWindow
	tTranslateCoords
	tGetActionKeysym
	tGetConstraintResourceList
	tGetResourceList
	tGetSubvalues
	tGetValues
	tAppInitialize
	tAppSetFallbackResources
	tInitialize
	tScreenDatabase
	tSetLanguageProc
	tToolkitInitialize
	tCXtToolkitError
	tCallAcceptFocus
	tClass
	tCreateWindow
	tDisplay
	tDisplayOfObject
	tFindFile
	tIsManaged
	tIsObject
	tIsRealized
	tIsSensitive
	tIsSubclass
	tName
	tNameToWidget
	tParent
	tRealizeWidget
	tResolvePathname
	tScreen
	tScreenOfObject
	tSuperclass
	tUnrealizeWidget
	tWindow
	tWindowOfObject
	tSetKeyboardFocus
	tManageChild
	tManageChildren
	tSetMappedWhenManaged
	tUnmanageChild
	tUnmanageChildren
	tAddInput
	tAddTimeOut
	tAddWorkProc
	tAppAddInput
	tAppAddTimeOut
	tAppAddWorkProc
	tAppNextEvent
	tAppPeekEvent
	tAppPending
	tAppProcessEvent
	tNextEvent
	tPeekEvent
	tPending
	tProcessEvent
	tRemoveInput
	tRemoveTimeOut
	tRemoveWorkProc
	tGrabButton
	tGrabKey
	tGrabKeyboard
	tGrabPointer
	tUngrabButton
	tUngrabKey
	tUngrabKeyboard
	tUngrabPointer
	tCallbackPopdown
	tPopdown
	tPopup
	tPopupSpringLoaded
	tCallbackExclusive
	tCallbackNone
	tCallbackNonexclusive
	tGetApplicationResources
	tGetSubresources
	tAppGetSelectionTimeout
	tAppSetSelectionTimeout
	tDisownSelection
	tGetSelectionRequest
	tGetSelectionTimeout
	tGetSelectionValue
	tGetSelectionValueIncremental
	tGetSelectionValues
	tGetSelectionValuesIncremental
	tOwnSelection
	tOwnSelectionIncremental
	tSetSelectionTimeout
	tSetSensitive
	tSetSubvalues
	tSetValues
	tSetWMColormapWindows
	tShellStrings
	tStrings
	tAddActions
	tAppAddActions
	tCallActionProc
	tGetActionList
	tMenuPopupAction
	tRegisterGrabAction
	tConvertCase
	tGetKeysymTable
	tKeysymToKeycodeList
	tRegisterCaseConverter
	tSetKeyTranslator
	tTranslateKey
	tTranslateKeycode
	tCvtStringToAcceleratorTable
	tCvtStringToTranslationTable
	tParseAcceleratorTable
	tParseTranslationTable
	tAugmentTranslations
	tInstallAccelerators
	tInstallAllAccelerators
	tOverrideTranslations
	tUninstallTranslations
	tVaAppCreateShell
	tVaAppInitialize
	tVaCreateManagedWidget
	tVaCreatePopupShell
	tVaCreateWidget
	tVaSetSubvalues
	tVaSetValues
	tVaGetApplicationResources
	tVaGetSubresources
	tVaGetSubvalues
	tVaGetValues
	tVaCreateArgsList
))
|#

(let ((Xlib (load-foreign "/usr/lib/X11/libX11.so.4.10")))
  (defforeign ActivateScreenSaver Xlib "_XActivateScreenSaver" () :integer)
  (defforeign AddExtension Xlib "_XAddExtension" () :integer)
  (defforeign AddHost Xlib "_XAddHost" () :integer)
  (defforeign AddHosts Xlib "_XAddHosts" () :integer)
  (defforeign AddPixel Xlib "_XAddPixel" () :integer)
  (defforeign AddToExtensionList Xlib "_XAddToExtensionList" () :integer)
  (defforeign AddToSaveSet Xlib "_XAddToSaveSet" () :integer)
  (defforeign AllPlanes Xlib "_XAllPlanes" () :integer)
  (defforeign AllocClassHint Xlib "_XAllocClassHint" () :integer)
  (defforeign AllocColor Xlib "_XAllocColor" () :integer)
  (defforeign AllocColorCells Xlib "_XAllocColorCells" () :integer)
  (defforeign AllocColorPlanes Xlib "_XAllocColorPlanes" () :integer)
  (defforeign AllocIconSize Xlib "_XAllocIconSize" () :integer)
  (defforeign AllocNamedColor Xlib "_XAllocNamedColor" () :integer)
  (defforeign AllocSizeHints Xlib "_XAllocSizeHints" () :integer)
  (defforeign AllocStandardColormap Xlib "_XAllocStandardColormap" () :integer)
  (defforeign AllocWMHints Xlib "_XAllocWMHints" () :integer)
  (defforeign AllowEvents Xlib "_XAllowEvents" () :integer)
  (defforeign AutoRepeatOff Xlib "_XAutoRepeatOff" () :integer)
  (defforeign AutoRepeatOn Xlib "_XAutoRepeatOn" () :integer)
  (defforeign BaseFontNameListOfFontSet Xlib "_XBaseFontNameListOfFontSet" () :integer)
  (defforeign Bell Xlib "_XBell" () :integer)
  (defforeign BitmapBitOrder Xlib "_XBitmapBitOrder" () :integer)
  (defforeign BitmapPad Xlib "_XBitmapPad" () :integer)
  (defforeign BitmapUnit Xlib "_XBitmapUnit" () :integer)
  (defforeign BlackPixel Xlib "_XBlackPixel" () :integer)
  (defforeign BlackPixelOfScreen Xlib "_XBlackPixelOfScreen" () :integer)
  (defforeign CellsOfScreen Xlib "_XCellsOfScreen" () :integer)
  (defforeign ChangeActivePointerGrab Xlib "_XChangeActivePointerGrab" () :integer)
  (defforeign ChangeGC Xlib "_XChangeGC" () :integer)
  (defforeign ChangeKeyboardControl Xlib "_XChangeKeyboardControl" () :integer)
  (defforeign ChangeKeyboardMapping Xlib "_XChangeKeyboardMapping" () :integer)
  (defforeign ChangePointerControl Xlib "_XChangePointerControl" () :integer)
  (defforeign ChangeProperty Xlib "_XChangeProperty" () :integer)
  (defforeign ChangeSaveSet Xlib "_XChangeSaveSet" () :integer)
  (defforeign ChangeWindowAttributes Xlib "_XChangeWindowAttributes" () :integer)
  (defforeign CheckIfEvent Xlib "_XCheckIfEvent" () :integer)
  (defforeign CheckMaskEvent Xlib "_XCheckMaskEvent" () :integer)
  (defforeign CheckTypedEvent Xlib "_XCheckTypedEvent" () :integer)
  (defforeign CheckTypedWindowEvent Xlib "_XCheckTypedWindowEvent" () :integer)
  (defforeign CheckWindowEvent Xlib "_XCheckWindowEvent" () :integer)
  (defforeign CirculateSubwindows Xlib "_XCirculateSubwindows" () :integer)
  (defforeign CirculateSubwindowsDown Xlib "_XCirculateSubwindowsDown" () :integer)
  (defforeign CirculateSubwindowsUp Xlib "_XCirculateSubwindowsUp" () :integer)
  (defforeign ClearArea Xlib "_XClearArea" () :integer)
  (defforeign ClearWindow Xlib "_XClearWindow" () :integer)
  (defforeign ClipBox Xlib "_XClipBox" () :integer)
  (defforeign CloseDisplay Xlib "_XCloseDisplay" () :integer)
  (defforeign CloseIM Xlib "_XCloseIM" () :integer)
  (defforeign ConfigureWindow Xlib "_XConfigureWindow" () :integer)
  (defforeign ConnectionNumber Xlib "_XConnectionNumber" () :integer)
  (defforeign ContextDependentDrawing Xlib "_XContextDependentDrawing" () :integer)
  (defforeign ConvertSelection Xlib "_XConvertSelection" () :integer)
  (defforeign CopyArea Xlib "_XCopyArea" () :integer)
  (defforeign CopyColormapAndFree Xlib "_XCopyColormapAndFree" () :integer)
  (defforeign CopyGC Xlib "_XCopyGC" () :integer)
  (defforeign CopyPlane Xlib "_XCopyPlane" () :integer)
  (defforeign CreateBitmapFromData Xlib "_XCreateBitmapFromData" () :integer)
  (defforeign CreateColormap Xlib "_XCreateColormap" () :integer)
  (defforeign CreateFontCursor Xlib "_XCreateFontCursor" () :integer)
  (defforeign CreateFontSet Xlib "_XCreateFontSet" () :integer)
  (defforeign CreateGC Xlib "_XCreateGC" () :long)
  (defforeign CreateGlyphCursor Xlib "_XCreateGlyphCursor" () :integer)
  (defforeign CreateIC Xlib "_XCreateIC" () :integer)
  (defforeign CreateImage Xlib "_XCreateImage" () :integer)
  (defforeign CreatePixmap Xlib "_XCreatePixmap" () :integer)
  (defforeign CreatePixmapCursor Xlib "_XCreatePixmapCursor" () :integer)
  (defforeign CreatePixmapFromBitmapData Xlib "_XCreatePixmapFromBitmapData" () :integer)
  (defforeign CreateRegion Xlib "_XCreateRegion" () :integer)
  (defforeign CreateSimpleWindow Xlib "_XCreateSimpleWindow" () :integer)
  (defforeign CreateWindow Xlib "_XCreateWindow" () :integer)
  (defforeign DefaultColormap Xlib "_XDefaultColormap" () :integer)
  (defforeign DefaultColormapOfScreen Xlib "_XDefaultColormapOfScreen" () :integer)
  (defforeign DefaultDepth Xlib "_XDefaultDepth" () :integer)
  (defforeign DefaultDepthOfScreen Xlib "_XDefaultDepthOfScreen" () :integer)
  (defforeign DefaultGC Xlib "_XDefaultGC" () :integer)
  (defforeign DefaultGCOfScreen Xlib "_XDefaultGCOfScreen" () :integer)
  (defforeign DefaultRootWindow Xlib "_XDefaultRootWindow" () :integer)
  (defforeign DefaultScreen Xlib "_XDefaultScreen" () :integer)
  (defforeign DefaultScreenOfDisplay Xlib "_XDefaultScreenOfDisplay" () :integer)
  (defforeign DefaultString Xlib "_XDefaultString" () :integer)
  (defforeign DefaultVisual Xlib "_XDefaultVisual" () :integer)
  (defforeign DefaultVisualOfScreen Xlib "_XDefaultVisualOfScreen" () :integer)
  (defforeign DefineCursor Xlib "_XDefineCursor" () :integer)
  (defforeign DeleteContext Xlib "_XDeleteContext" () :integer)
  (defforeign DeleteModifiermapEntry Xlib "_XDeleteModifiermapEntry" () :integer)
  (defforeign DeleteProperty Xlib "_XDeleteProperty" () :integer)
  (defforeign DestroyIC Xlib "_XDestroyIC" () :integer)
  (defforeign DestroyImage Xlib "_XDestroyImage" () :integer)
  (defforeign DestroyRegion Xlib "_XDestroyRegion" () :integer)
  (defforeign DestroySubwindows Xlib "_XDestroySubwindows" () :integer)
  (defforeign DestroyWindow Xlib "_XDestroyWindow" () :integer)
  (defforeign DisableAccessControl Xlib "_XDisableAccessControl" () :integer)
  (defforeign DisplayCells Xlib "_XDisplayCells" () :integer)
  (defforeign DisplayHeight Xlib "_XDisplayHeight" () :integer)
  (defforeign DisplayHeightMM Xlib "_XDisplayHeightMM" () :integer)
  (defforeign DisplayKeycodes Xlib "_XDisplayKeycodes" () :integer)
  (defforeign DisplayMotionBufferSize Xlib "_XDisplayMotionBufferSize" () :integer)
  (defforeign DisplayName Xlib "_XDisplayName" () :integer)
  (defforeign DisplayOfIM Xlib "_XDisplayOfIM" () :integer)
  (defforeign DisplayOfScreen Xlib "_XDisplayOfScreen" () :integer)
  (defforeign DisplayPlanes Xlib "_XDisplayPlanes" () :integer)
  (defforeign DisplayString Xlib "_XDisplayString" () :integer)
  (defforeign DisplayWidth Xlib "_XDisplayWidth" () :integer)
  (defforeign DisplayWidthMM Xlib "_XDisplayWidthMM" () :integer)
  (defforeign DoesBackingStore Xlib "_XDoesBackingStore" () :integer)
  (defforeign DoesSaveUnders Xlib "_XDoesSaveUnders" () :integer)
  (defforeign DrawArc Xlib "_XDrawArc" () :integer)
  (defforeign DrawArcs Xlib "_XDrawArcs" () :integer)
  (defforeign DrawImageString Xlib "_XDrawImageString" () :integer)
  (defforeign DrawImageString16 Xlib "_XDrawImageString16" () :integer)
  (defforeign DrawLine Xlib "_XDrawLine" () :integer)
  (defforeign DrawLines Xlib "_XDrawLines" () :integer)
  (defforeign DrawPoint Xlib "_XDrawPoint" () :integer)
  (defforeign DrawPoints Xlib "_XDrawPoints" () :integer)
  (defforeign DrawRectangle Xlib "_XDrawRectangle" () :integer)
  (defforeign DrawRectangles Xlib "_XDrawRectangles" () :integer)
  (defforeign DrawSegments Xlib "_XDrawSegments" () :integer)
  (defforeign DrawString Xlib "_XDrawString" () :integer)
  (defforeign DrawString16 Xlib "_XDrawString16" () :integer)
  (defforeign DrawText Xlib "_XDrawText" () :integer)
  (defforeign DrawText16 Xlib "_XDrawText16" () :integer)
  (defforeign EHeadOfExtensionList Xlib "_XEHeadOfExtensionList" () :integer)
  (defforeign ESetCloseDisplay Xlib "_XESetCloseDisplay" () :integer)
  (defforeign ESetCopyGC Xlib "_XESetCopyGC" () :integer)
  (defforeign ESetCreateFont Xlib "_XESetCreateFont" () :integer)
  (defforeign ESetCreateGC Xlib "_XESetCreateGC" () :integer)
  (defforeign ESetError Xlib "_XESetError" () :integer)
  (defforeign ESetErrorString Xlib "_XESetErrorString" () :integer)
  (defforeign ESetEventToWire Xlib "_XESetEventToWire" () :integer)
  (defforeign ESetFlushGC Xlib "_XESetFlushGC" () :integer)
  (defforeign ESetFreeFont Xlib "_XESetFreeFont" () :integer)
  (defforeign ESetFreeGC Xlib "_XESetFreeGC" () :integer)
  (defforeign ESetPrintErrorValues Xlib "_XESetPrintErrorValues" () :integer)
  (defforeign ESetWireToError Xlib "_XESetWireToError" () :integer)
  (defforeign ESetWireToEvent Xlib "_XESetWireToEvent" () :integer)
  (defforeign EmptyRegion Xlib "_XEmptyRegion" () :integer)
  (defforeign EnableAccessControl Xlib "_XEnableAccessControl" () :integer)
  (defforeign EqualRegion Xlib "_XEqualRegion" () :integer)
  (defforeign EventMaskOfScreen Xlib "_XEventMaskOfScreen" () :integer)
  (defforeign EventsQueued Xlib "_XEventsQueued" () :integer)
  (defforeign ExtentsOfFontSet Xlib "_XExtentsOfFontSet" () :integer)
  (defforeign FetchBuffer Xlib "_XFetchBuffer" () :integer)
  (defforeign FetchBytes Xlib "_XFetchBytes" () :integer)
  (defforeign FetchName Xlib "_XFetchName" () :integer)
  (defforeign FillArc Xlib "_XFillArc" () :integer)
  (defforeign FillArcs Xlib "_XFillArcs" () :integer)
  (defforeign FillPolygon Xlib "_XFillPolygon" () :integer)
  (defforeign FillRectangle Xlib "_XFillRectangle" () :integer)
  (defforeign FillRectangles Xlib "_XFillRectangles" () :integer)
  (defforeign FilterEvent Xlib "_XFilterEvent" () :integer)
  (defforeign FindContext Xlib "_XFindContext" () :integer)
  (defforeign FindOnExtensionList Xlib "_XFindOnExtensionList" () :integer)
  (defforeign Flush Xlib "_XFlush" () :integer)
  (defforeign FlushGC Xlib "_XFlushGC" () :integer)
  (defforeign FontsOfFontSet Xlib "_XFontsOfFontSet" () :integer)
  (defforeign ForceScreenSaver Xlib "_XForceScreenSaver" () :integer)
  (defforeign Free Xlib "_XFree" () :integer)
  (defforeign FreeColormap Xlib "_XFreeColormap" () :integer)
  (defforeign FreeColors Xlib "_XFreeColors" () :integer)
  (defforeign FreeCursor Xlib "_XFreeCursor" () :integer)
  (defforeign FreeExtensionList Xlib "_XFreeExtensionList" () :integer)
  (defforeign FreeFont Xlib "_XFreeFont" () :integer)
  (defforeign FreeFontInfo Xlib "_XFreeFontInfo" () :integer)
  (defforeign FreeFontNames Xlib "_XFreeFontNames" () :integer)
  (defforeign FreeFontPath Xlib "_XFreeFontPath" () :integer)
  (defforeign FreeFontSet Xlib "_XFreeFontSet" () :integer)
  (defforeign FreeGC Xlib "_XFreeGC" () :integer)
  (defforeign FreeModifiermap Xlib "_XFreeModifiermap" () :integer)
  (defforeign FreePixmap Xlib "_XFreePixmap" () :integer)
  (defforeign FreeStringList Xlib "_XFreeStringList" () :integer)
  (defforeign GContextFromGC Xlib "_XGContextFromGC" () :integer)
  (defforeign Geometry Xlib "_XGeometry" () :integer)
  (defforeign GetAtomName Xlib "_XGetAtomName" () :integer)
  (defforeign GetClassHint Xlib "_XGetClassHint" () :integer)
  (defforeign GetCommand Xlib "_XGetCommand" () :integer)
  (defforeign GetDefault Xlib "_XGetDefault" () :integer)
  (defforeign GetErrorDatabaseText Xlib "_XGetErrorDatabaseText" () :integer)
  (defforeign GetErrorText Xlib "_XGetErrorText" () :integer)
  (defforeign GetFontPath Xlib "_XGetFontPath" () :integer)
  (defforeign GetFontProperty Xlib "_XGetFontProperty" () :integer)
  (defforeign GetGCValues Xlib "_XGetGCValues" () :integer)
  (defforeign GetGeometry Xlib "_XGetGeometry" () :integer)
  (defforeign GetICValues Xlib "_XGetICValues" () :integer)
  (defforeign GetIMValues Xlib "_XGetIMValues" () :integer)
  (defforeign GetIconName Xlib "_XGetIconName" () :integer)
  (defforeign GetIconSizes Xlib "_XGetIconSizes" () :integer)
  (defforeign GetImage Xlib "_XGetImage" () :integer)
  (defforeign GetInputFocus Xlib "_XGetInputFocus" () :integer)
  (defforeign GetKeyboardControl Xlib "_XGetKeyboardControl" () :integer)
  (defforeign GetKeyboardMapping Xlib "_XGetKeyboardMapping" () :integer)
  (defforeign GetModifierMapping Xlib "_XGetModifierMapping" () :integer)
  (defforeign GetMotionEvents Xlib "_XGetMotionEvents" () :integer)
  (defforeign GetNormalHints Xlib "_XGetNormalHints" () :integer)
  (defforeign GetPixel Xlib "_XGetPixel" () :integer)
  (defforeign GetPointerControl Xlib "_XGetPointerControl" () :integer)
  (defforeign GetPointerMapping Xlib "_XGetPointerMapping" () :integer)
  (defforeign GetRGBColormaps Xlib "_XGetRGBColormaps" () :integer)
  (defforeign GetScreenSaver Xlib "_XGetScreenSaver" () :integer)
  (defforeign GetSelectionOwner Xlib "_XGetSelectionOwner" () :integer)
  (defforeign GetSizeHints Xlib "_XGetSizeHints" () :integer)
  (defforeign GetStandardColormap Xlib "_XGetStandardColormap" () :integer)
  (defforeign GetSubImage Xlib "_XGetSubImage" () :integer)
  (defforeign GetTextProperty Xlib "_XGetTextProperty" () :integer)
  (defforeign GetTransientForHint Xlib "_XGetTransientForHint" () :integer)
  (defforeign GetVisualInfo Xlib "_XGetVisualInfo" () :integer)
  (defforeign GetWMClientMachine Xlib "_XGetWMClientMachine" () :integer)
  (defforeign GetWMColormapWindows Xlib "_XGetWMColormapWindows" () :integer)
  (defforeign GetWMHints Xlib "_XGetWMHints" () :integer)
  (defforeign GetWMIconName Xlib "_XGetWMIconName" () :integer)
  (defforeign GetWMName Xlib "_XGetWMName" () :integer)
  (defforeign GetWMNormalHints Xlib "_XGetWMNormalHints" () :integer)
  (defforeign GetWMProtocols Xlib "_XGetWMProtocols" () :integer)
  (defforeign GetWMSizeHints Xlib "_XGetWMSizeHints" () :integer)
  (defforeign GetWindowAttributes Xlib "_XGetWindowAttributes" () :integer)
  (defforeign GetWindowProperty Xlib "_XGetWindowProperty" () :integer)
  (defforeign GetZoomHints Xlib "_XGetZoomHints" () :integer)
  (defforeign GrabButton Xlib "_XGrabButton" () :integer)
  (defforeign GrabKey Xlib "_XGrabKey" () :integer)
  (defforeign GrabKeyboard Xlib "_XGrabKeyboard" () :integer)
  (defforeign GrabPointer Xlib "_XGrabPointer" () :integer)
  (defforeign GrabServer Xlib "_XGrabServer" () :integer)
  (defforeign HeightMMOfScreen Xlib "_XHeightMMOfScreen" () :integer)
  (defforeign HeightOfScreen Xlib "_XHeightOfScreen" () :integer)
  (defforeign IMOfIC Xlib "_XIMOfIC" () :integer)
  (defforeign IconifyWindow Xlib "_XIconifyWindow" () :integer)
  (defforeign IfEvent Xlib "_XIfEvent" () :integer)
  (defforeign ImageByteOrder Xlib "_XImageByteOrder" () :integer)
  (defforeign InitExtension Xlib "_XInitExtension" () :integer)
  (defforeign InsertModifiermapEntry Xlib "_XInsertModifiermapEntry" () :integer)
  (defforeign InstallColormap Xlib "_XInstallColormap" () :integer)
  (defforeign InternAtom Xlib "_XInternAtom" () :integer)
  (defforeign IntersectRegion Xlib "_XIntersectRegion" () :integer)
  (defforeign KeycodeToKeysym Xlib "_XKeycodeToKeysym" () :integer)
  (defforeign KeysymToKeycode Xlib "_XKeysymToKeycode" () :integer)
  (defforeign KeysymToString Xlib "_XKeysymToString" () :integer)
  (defforeign KillClient Xlib "_XKillClient" () :integer)
  (defforeign LastKnownRequestProcessed Xlib "_XLastKnownRequestProcessed" () :integer)
  (defforeign ListDepths Xlib "_XListDepths" () :integer)
  (defforeign ListExtensions Xlib "_XListExtensions" () :integer)
  (defforeign ListFonts Xlib "_XListFonts" () :integer)
  (defforeign ListFontsWithInfo Xlib "_XListFontsWithInfo" () :integer)
  (defforeign ListHosts Xlib "_XListHosts" () :integer)
  (defforeign ListInstalledColormaps Xlib "_XListInstalledColormaps" () :integer)
  (defforeign ListPixmapFormats Xlib "_XListPixmapFormats" () :integer)
  (defforeign ListProperties Xlib "_XListProperties" () :integer)
  (defforeign LoadFont Xlib "_XLoadFont" () :integer)
  (defforeign LoadQueryFont Xlib "_XLoadQueryFont" () :integer)
  (defforeign LocaleOfFontSet Xlib "_XLocaleOfFontSet" () :integer)
  (defforeign LocaleOfIM Xlib "_XLocaleOfIM" () :integer)
  (defforeign LookupColor Xlib "_XLookupColor" () :integer)
  (defforeign LookupKeysym Xlib "_XLookupKeysym" () :integer)
  (defforeign LookupString Xlib "_XLookupString" () :integer)
  (defforeign LowerWindow Xlib "_XLowerWindow" () :integer)
  (defforeign MapRaised Xlib "_XMapRaised" () :integer)
  (defforeign MapSubwindows Xlib "_XMapSubwindows" () :integer)
  (defforeign MapWindow Xlib "_XMapWindow" () :integer)
  (defforeign MaskEvent Xlib "_XMaskEvent" () :integer)
  (defforeign MatchVisualInfo Xlib "_XMatchVisualInfo" () :integer)
  (defforeign MaxCmapsOfScreen Xlib "_XMaxCmapsOfScreen" () :integer)
  (defforeign MaxRequestSize Xlib "_XMaxRequestSize" () :integer)
  (defforeign MinCmapsOfScreen Xlib "_XMinCmapsOfScreen" () :integer)
  (defforeign MoveResizeWindow Xlib "_XMoveResizeWindow" () :integer)
  (defforeign MoveWindow Xlib "_XMoveWindow" () :integer)
  (defforeign NewModifiermap Xlib "_XNewModifiermap" () :integer)
  (defforeign NextEvent Xlib "_XNextEvent" () :integer)
  (defforeign NextRequest Xlib "_XNextRequest" () :integer)
  (defforeign NoOp Xlib "_XNoOp" () :integer)
  (defforeign OffsetRegion Xlib "_XOffsetRegion" () :integer)
  (defforeign OpenDisplay Xlib "_XOpenDisplay" () :integer)
  (defforeign OpenIM Xlib "_XOpenIM" () :integer)
  (defforeign ParseColor Xlib "_XParseColor" () :integer)
  (defforeign ParseGeometry Xlib "_XParseGeometry" () :integer)
  (defforeign PeekEvent Xlib "_XPeekEvent" () :integer)
  (defforeign PeekIfEvent Xlib "_XPeekIfEvent" () :integer)
  (defforeign Pending Xlib "_XPending" () :integer)
  (defforeign PlanesOfScreen Xlib "_XPlanesOfScreen" () :integer)
  (defforeign PointInRegion Xlib "_XPointInRegion" () :integer)
  (defforeign PolygonRegion Xlib "_XPolygonRegion" () :integer)
  (defforeign ProtocolRevision Xlib "_XProtocolRevision" () :integer)
  (defforeign ProtocolVersion Xlib "_XProtocolVersion" () :integer)
  (defforeign PutBackEvent Xlib "_XPutBackEvent" () :integer)
  (defforeign PutImage Xlib "_XPutImage" () :integer)
  (defforeign PutPixel Xlib "_XPutPixel" () :integer)
  (defforeign QLength Xlib "_XQLength" () :integer)
  (defforeign QueryBestCursor Xlib "_XQueryBestCursor" () :integer)
  (defforeign QueryBestSize Xlib "_XQueryBestSize" () :integer)
  (defforeign QueryBestStipple Xlib "_XQueryBestStipple" () :integer)
  (defforeign QueryBestTile Xlib "_XQueryBestTile" () :integer)
  (defforeign QueryColor Xlib "_XQueryColor" () :integer)
  (defforeign QueryColors Xlib "_XQueryColors" () :integer)
  (defforeign QueryExtension Xlib "_XQueryExtension" () :integer)
  (defforeign QueryFont Xlib "_XQueryFont" () :integer)
  (defforeign QueryKeymap Xlib "_XQueryKeymap" () :integer)
  (defforeign QueryPointer Xlib "_XQueryPointer" () :integer)
  (defforeign QueryTextExtents Xlib "_XQueryTextExtents" () :integer)
  (defforeign QueryTextExtents16 Xlib "_XQueryTextExtents16" () :integer)
  (defforeign QueryTree Xlib "_XQueryTree" () :integer)
  (defforeign RaiseWindow Xlib "_XRaiseWindow" () :integer)
  (defforeign ReadBitmapFile Xlib "_XReadBitmapFile" () :integer)
  (defforeign RebindKeysym Xlib "_XRebindKeysym" () :integer)
  (defforeign RecolorCursor Xlib "_XRecolorCursor" () :integer)
  (defforeign ReconfigureWMWindow Xlib "_XReconfigureWMWindow" () :integer)
  (defforeign RectInRegion Xlib "_XRectInRegion" () :integer)
  (defforeign RefreshKeyboardMapping Xlib "_XRefreshKeyboardMapping" () :integer)
  (defforeign RemoveFromSaveSet Xlib "_XRemoveFromSaveSet" () :integer)
  (defforeign RemoveHost Xlib "_XRemoveHost" () :integer)
  (defforeign RemoveHosts Xlib "_XRemoveHosts" () :integer)
  (defforeign ReparentWindow Xlib "_XReparentWindow" () :integer)
  (defforeign ResetScreenSaver Xlib "_XResetScreenSaver" () :integer)
  (defforeign ResizeWindow Xlib "_XResizeWindow" () :integer)
  (defforeign ResourceManagerString Xlib "_XResourceManagerString" () :integer)
  (defforeign RestackWindows Xlib "_XRestackWindows" () :integer)
  (defforeign RootWindow Xlib "_XRootWindow" () :integer)
  (defforeign RootWindowOfScreen Xlib "_XRootWindowOfScreen" () :integer)
  (defforeign RotateBuffers Xlib "_XRotateBuffers" () :integer)
  (defforeign RotateWindowProperties Xlib "_XRotateWindowProperties" () :integer)
  (defforeign SaveContext Xlib "_XSaveContext" () :integer)
  (defforeign ScreenCount Xlib "_XScreenCount" () :integer)
  (defforeign ScreenNumberOfScreen Xlib "_XScreenNumberOfScreen" () :integer)
  (defforeign ScreenOfDisplay Xlib "_XScreenOfDisplay" () :integer)
  (defforeign ScreenResourceString Xlib "_XScreenResourceString" () :integer)
  (defforeign SelectInput Xlib "_XSelectInput" () :integer)
  (defforeign SendEvent Xlib "_XSendEvent" () :integer)
  (defforeign ServerVendor Xlib "_XServerVendor" () :integer)
  (defforeign SetAccessControl Xlib "_XSetAccessControl" () :integer)
  (defforeign SetAfterFunction Xlib "_XSetAfterFunction" () :integer)
  (defforeign SetArcMode Xlib "_XSetArcMode" () :integer)
  (defforeign SetAuthorization Xlib "_XSetAuthorization" () :integer)
  (defforeign SetBackground Xlib "_XSetBackground" () :integer)
  (defforeign SetClassHint Xlib "_XSetClassHint" () :integer)
  (defforeign SetClipMask Xlib "_XSetClipMask" () :integer)
  (defforeign SetClipOrigin Xlib "_XSetClipOrigin" () :integer)
  (defforeign SetClipRectangles Xlib "_XSetClipRectangles" () :integer)
  (defforeign SetCloseDownMode Xlib "_XSetCloseDownMode" () :integer)
  (defforeign SetCommand Xlib "_XSetCommand" () :integer)
  (defforeign SetDashes Xlib "_XSetDashes" () :integer)
  (defforeign SetErrorHandler Xlib "_XSetErrorHandler" () :integer)
  (defforeign SetFillRule Xlib "_XSetFillRule" () :integer)
  (defforeign SetFillStyle Xlib "_XSetFillStyle" () :integer)
  (defforeign SetFont Xlib "_XSetFont" () :integer)
  (defforeign SetFontPath Xlib "_XSetFontPath" () :integer)
  (defforeign SetForeground Xlib "_XSetForeground" () :integer)
  (defforeign SetFunction Xlib "_XSetFunction" () :integer)
  (defforeign SetGraphicsExposures Xlib "_XSetGraphicsExposures" () :integer)
  (defforeign SetICFocus Xlib "_XSetICFocus" () :integer)
  (defforeign SetICValues Xlib "_XSetICValues" () :integer)
  (defforeign SetIOErrorHandler Xlib "_XSetIOErrorHandler" () :integer)
  (defforeign SetIconName Xlib "_XSetIconName" () :integer)
  (defforeign SetIconSizes Xlib "_XSetIconSizes" () :integer)
  (defforeign SetInputFocus Xlib "_XSetInputFocus" () :integer)
  (defforeign SetLineAttributes Xlib "_XSetLineAttributes" () :integer)
  (defforeign SetLocaleModifiers Xlib "_XSetLocaleModifiers" () :integer)
  (defforeign SetModifierMapping Xlib "_XSetModifierMapping" () :integer)
  (defforeign SetNormalHints Xlib "_XSetNormalHints" () :integer)
  (defforeign SetPlaneMask Xlib "_XSetPlaneMask" () :integer)
  (defforeign SetPointerMapping Xlib "_XSetPointerMapping" () :integer)
  (defforeign SetRGBColormaps Xlib "_XSetRGBColormaps" () :integer)
  (defforeign SetRegion Xlib "_XSetRegion" () :integer)
  (defforeign SetScreenSaver Xlib "_XSetScreenSaver" () :integer)
  (defforeign SetSelectionOwner Xlib "_XSetSelectionOwner" () :integer)
  (defforeign SetSizeHints Xlib "_XSetSizeHints" () :integer)
  (defforeign SetStandardColormap Xlib "_XSetStandardColormap" () :integer)
  (defforeign SetStandardProperties Xlib "_XSetStandardProperties" () :integer)
  (defforeign SetState Xlib "_XSetState" () :integer)
  (defforeign SetStipple Xlib "_XSetStipple" () :integer)
  (defforeign SetSubwindowMode Xlib "_XSetSubwindowMode" () :integer)
  (defforeign SetTSOrigin Xlib "_XSetTSOrigin" () :integer)
  (defforeign SetTextProperty Xlib "_XSetTextProperty" () :integer)
  (defforeign SetTile Xlib "_XSetTile" () :integer)
  (defforeign SetTransientForHint Xlib "_XSetTransientForHint" () :integer)
  (defforeign SetWMClientMachine Xlib "_XSetWMClientMachine" () :integer)
  (defforeign SetWMColormapWindows Xlib "_XSetWMColormapWindows" () :integer)
  (defforeign SetWMHints Xlib "_XSetWMHints" () :integer)
  (defforeign SetWMIconName Xlib "_XSetWMIconName" () :integer)
  (defforeign SetWMName Xlib "_XSetWMName" () :integer)
  (defforeign SetWMNormalHints Xlib "_XSetWMNormalHints" () :integer)
  (defforeign SetWMProperties Xlib "_XSetWMProperties" () :integer)
  (defforeign SetWMProtocols Xlib "_XSetWMProtocols" () :integer)
  (defforeign SetWMSizeHints Xlib "_XSetWMSizeHints" () :integer)
  (defforeign SetWindowBackground Xlib "_XSetWindowBackground" () :integer)
  (defforeign SetWindowBackgroundPixmap Xlib "_XSetWindowBackgroundPixmap" () :integer)
  (defforeign SetWindowBorder Xlib "_XSetWindowBorder" () :integer)
  (defforeign SetWindowBorderPixmap Xlib "_XSetWindowBorderPixmap" () :integer)
  (defforeign SetWindowBorderWidth Xlib "_XSetWindowBorderWidth" () :integer)
  (defforeign SetWindowColormap Xlib "_XSetWindowColormap" () :integer)
  (defforeign SetZoomHints Xlib "_XSetZoomHints" () :integer)
  (defforeign ShrinkRegion Xlib "_XShrinkRegion" () :integer)
  (defforeign StoreBuffer Xlib "_XStoreBuffer" () :integer)
  (defforeign StoreBytes Xlib "_XStoreBytes" () :integer)
  (defforeign StoreColor Xlib "_XStoreColor" () :integer)
  (defforeign StoreColors Xlib "_XStoreColors" () :integer)
  (defforeign StoreName Xlib "_XStoreName" () :integer)
  (defforeign StoreNamedColor Xlib "_XStoreNamedColor" () :integer)
  (defforeign StringListToTextProperty Xlib "_XStringListToTextProperty" () :integer)
  (defforeign StringToKeysym Xlib "_XStringToKeysym" () :integer)
  (defforeign SubImage Xlib "_XSubImage" () :integer)
  (defforeign SubtractRegion Xlib "_XSubtractRegion" () :integer)
  (defforeign SupportsLocale Xlib "_XSupportsLocale" () :integer)
  (defforeign Sync Xlib "_XSync" () :integer)
  (defforeign Synchronize Xlib "_XSynchronize" () :integer)
  (defforeign TextExtents Xlib "_XTextExtents" () :integer)
  (defforeign TextExtents16 Xlib "_XTextExtents16" () :integer)
  (defforeign TextPropertyToStringList Xlib "_XTextPropertyToStringList" () :integer)
  (defforeign TextWidth Xlib "_XTextWidth" () :integer)
  (defforeign TextWidth16 Xlib "_XTextWidth16" () :integer)
  (defforeign TranslateCoordinates Xlib "_XTranslateCoordinates" () :integer)
  (defforeign UndefineCursor Xlib "_XUndefineCursor" () :integer)
  (defforeign UngrabButton Xlib "_XUngrabButton" () :integer)
  (defforeign UngrabKey Xlib "_XUngrabKey" () :integer)
  (defforeign UngrabKeyboard Xlib "_XUngrabKeyboard" () :integer)
  (defforeign UngrabPointer Xlib "_XUngrabPointer" () :integer)
  (defforeign UngrabServer Xlib "_XUngrabServer" () :integer)
  (defforeign UninstallColormap Xlib "_XUninstallColormap" () :integer)
  (defforeign UnionRectWithRegion Xlib "_XUnionRectWithRegion" () :integer)
  (defforeign UnionRegion Xlib "_XUnionRegion" () :integer)
  (defforeign UnloadFont Xlib "_XUnloadFont" () :integer)
  (defforeign UnmapSubwindows Xlib "_XUnmapSubwindows" () :integer)
  (defforeign UnmapWindow Xlib "_XUnmapWindow" () :integer)
  (defforeign UnsetICFocus Xlib "_XUnsetICFocus" () :integer)
  (defforeign VaCreateNestedList Xlib "_XVaCreateNestedList" () :integer)
  (defforeign VendorRelease Xlib "_XVendorRelease" () :integer)
  (defforeign VisualIDFromVisual Xlib "_XVisualIDFromVisual" () :integer)
  (defforeign WMGeometry Xlib "_XWMGeometry" () :integer)
  (defforeign WarpPointer Xlib "_XWarpPointer" () :integer)
  (defforeign WhitePixel Xlib "_XWhitePixel" () :integer)
  (defforeign WhitePixelOfScreen Xlib "_XWhitePixelOfScreen" () :integer)
  (defforeign WidthMMOfScreen Xlib "_XWidthMMOfScreen" () :integer)
  (defforeign WidthOfScreen Xlib "_XWidthOfScreen" () :integer)
  (defforeign WindowEvent Xlib "_XWindowEvent" () :integer)
  (defforeign WithdrawWindow Xlib "_XWithdrawWindow" () :integer)
  (defforeign WriteBitmapFile Xlib "_XWriteBitmapFile" () :integer)
  (defforeign XorRegion Xlib "_XXorRegion" () :integer)
  (defforeign auDisposeAuth Xlib "_XauDisposeAuth" () :integer)
  (defforeign auFileName Xlib "_XauFileName" () :integer)
  (defforeign auGetBestAuthByAddr Xlib "_XauGetBestAuthByAddr" () :integer)
  (defforeign auReadAuth Xlib "_XauReadAuth" () :integer)
  (defforeign cmsAddColorSpace Xlib "_XcmsAddColorSpace" () :integer)
  (defforeign cmsAddFunctionSet Xlib "_XcmsAddFunctionSet" () :integer)
  (defforeign cmsAllocColor Xlib "_XcmsAllocColor" () :integer)
  (defforeign cmsAllocNamedColor Xlib "_XcmsAllocNamedColor" () :integer)
  (defforeign cmsCCCOfColormap Xlib "_XcmsCCCOfColormap" () :integer)
  (defforeign cmsCIELabClipL Xlib "_XcmsCIELabClipL" () :integer)
  (defforeign cmsCIELabClipLab Xlib "_XcmsCIELabClipLab" () :integer)
  (defforeign cmsCIELabClipab Xlib "_XcmsCIELabClipab" () :integer)
  (defforeign cmsCIELabColorSpace Xlib "_XcmsCIELabColorSpace" () :integer)
  (defforeign cmsCIELabQueryMaxC Xlib "_XcmsCIELabQueryMaxC" () :integer)
  (defforeign cmsCIELabQueryMaxL Xlib "_XcmsCIELabQueryMaxL" () :integer)
  (defforeign cmsCIELabQueryMaxLC Xlib "_XcmsCIELabQueryMaxLC" () :integer)
  (defforeign cmsCIELabQueryMinL Xlib "_XcmsCIELabQueryMinL" () :integer)
  (defforeign cmsCIELabToCIEXYZ Xlib "_XcmsCIELabToCIEXYZ" () :integer)
  (defforeign cmsCIELabWhiteShiftColors Xlib "_XcmsCIELabWhiteShiftColors" () :integer)
  (defforeign cmsCIELab_ValidSpec Xlib "_XcmsCIELab_ValidSpec" () :integer)
  (defforeign cmsCIELab_prefix Xlib "_XcmsCIELab_prefix" () :integer)
  (defforeign cmsCIELuvClipL Xlib "_XcmsCIELuvClipL" () :integer)
  (defforeign cmsCIELuvClipLuv Xlib "_XcmsCIELuvClipLuv" () :integer)
  (defforeign cmsCIELuvClipuv Xlib "_XcmsCIELuvClipuv" () :integer)
  (defforeign cmsCIELuvColorSpace Xlib "_XcmsCIELuvColorSpace" () :integer)
  (defforeign cmsCIELuvQueryMaxC Xlib "_XcmsCIELuvQueryMaxC" () :integer)
  (defforeign cmsCIELuvQueryMaxL Xlib "_XcmsCIELuvQueryMaxL" () :integer)
  (defforeign cmsCIELuvQueryMaxLC Xlib "_XcmsCIELuvQueryMaxLC" () :integer)
  (defforeign cmsCIELuvQueryMinL Xlib "_XcmsCIELuvQueryMinL" () :integer)
  (defforeign cmsCIELuvToCIEuvY Xlib "_XcmsCIELuvToCIEuvY" () :integer)
  (defforeign cmsCIELuvWhiteShiftColors Xlib "_XcmsCIELuvWhiteShiftColors" () :integer)
  (defforeign cmsCIELuv_ValidSpec Xlib "_XcmsCIELuv_ValidSpec" () :integer)
  (defforeign cmsCIELuv_prefix Xlib "_XcmsCIELuv_prefix" () :integer)
  (defforeign cmsCIEXYZColorSpace Xlib "_XcmsCIEXYZColorSpace" () :integer)
  (defforeign cmsCIEXYZToCIELab Xlib "_XcmsCIEXYZToCIELab" () :integer)
  (defforeign cmsCIEXYZToCIEuvY Xlib "_XcmsCIEXYZToCIEuvY" () :integer)
  (defforeign cmsCIEXYZToCIExyY Xlib "_XcmsCIEXYZToCIExyY" () :integer)
  (defforeign cmsCIEXYZToRGBi Xlib "_XcmsCIEXYZToRGBi" () :integer)
  (defforeign cmsCIEXYZ_ValidSpec Xlib "_XcmsCIEXYZ_ValidSpec" () :integer)
  (defforeign cmsCIEXYZ_prefix Xlib "_XcmsCIEXYZ_prefix" () :integer)
  (defforeign cmsCIEuvYColorSpace Xlib "_XcmsCIEuvYColorSpace" () :integer)
  (defforeign cmsCIEuvYToCIELuv Xlib "_XcmsCIEuvYToCIELuv" () :integer)
  (defforeign cmsCIEuvYToCIEXYZ Xlib "_XcmsCIEuvYToCIEXYZ" () :integer)
  (defforeign cmsCIEuvYToTekHVC Xlib "_XcmsCIEuvYToTekHVC" () :integer)
  (defforeign cmsCIEuvY_ValidSpec Xlib "_XcmsCIEuvY_ValidSpec" () :integer)
  (defforeign cmsCIEuvY_prefix Xlib "_XcmsCIEuvY_prefix" () :integer)
  (defforeign cmsCIExyYColorSpace Xlib "_XcmsCIExyYColorSpace" () :integer)
  (defforeign cmsCIExyYToCIEXYZ Xlib "_XcmsCIExyYToCIEXYZ" () :integer)
  (defforeign cmsCIExyY_ValidSpec Xlib "_XcmsCIExyY_ValidSpec" () :integer)
  (defforeign cmsCIExyY_prefix Xlib "_XcmsCIExyY_prefix" () :integer)
  (defforeign cmsClientWhitePointOfCCC Xlib "_XcmsClientWhitePointOfCCC" () :integer)
  (defforeign cmsConvertColors Xlib "_XcmsConvertColors" () :integer)
  (defforeign cmsCreateCCC Xlib "_XcmsCreateCCC" () :integer)
  (defforeign cmsDefaultCCC Xlib "_XcmsDefaultCCC" () :integer)
  (defforeign cmsDisplayOfCCC Xlib "_XcmsDisplayOfCCC" () :integer)
  (defforeign cmsFormatOfPrefix Xlib "_XcmsFormatOfPrefix" () :integer)
  (defforeign cmsFreeCCC Xlib "_XcmsFreeCCC" () :integer)
  (defforeign cmsFreeColorDB Xlib "_XcmsFreeColorDB" () :integer)
  (defforeign cmsLRGB_RGB_ParseString Xlib "_XcmsLRGB_RGB_ParseString" () :integer)
  (defforeign cmsLRGB_RGBi_ParseString Xlib "_XcmsLRGB_RGBi_ParseString" () :integer)
  (defforeign cmsLinearRGBFunctionSet Xlib "_XcmsLinearRGBFunctionSet" () :integer)
  (defforeign cmsLookupColor Xlib "_XcmsLookupColor" () :integer)
  (defforeign cmsPrefixOfFormat Xlib "_XcmsPrefixOfFormat" () :integer)
  (defforeign cmsQueryBlack Xlib "_XcmsQueryBlack" () :integer)
  (defforeign cmsQueryBlue Xlib "_XcmsQueryBlue" () :integer)
  (defforeign cmsQueryColor Xlib "_XcmsQueryColor" () :integer)
  (defforeign cmsQueryColors Xlib "_XcmsQueryColors" () :integer)
  (defforeign cmsQueryGreen Xlib "_XcmsQueryGreen" () :integer)
  (defforeign cmsQueryRed Xlib "_XcmsQueryRed" () :integer)
  (defforeign cmsQueryWhite Xlib "_XcmsQueryWhite" () :integer)
  (defforeign cmsRGBColorSpace Xlib "_XcmsRGBColorSpace" () :integer)
  (defforeign cmsRGBToRGBi Xlib "_XcmsRGBToRGBi" () :integer)
  (defforeign cmsRGB_prefix Xlib "_XcmsRGB_prefix" () :integer)
  (defforeign cmsRGBiColorSpace Xlib "_XcmsRGBiColorSpace" () :integer)
  (defforeign cmsRGBiToCIEXYZ Xlib "_XcmsRGBiToCIEXYZ" () :integer)
  (defforeign cmsRGBiToRGB Xlib "_XcmsRGBiToRGB" () :integer)
  (defforeign cmsRGBi_prefix Xlib "_XcmsRGBi_prefix" () :integer)
  (defforeign cmsScreenNumberOfCCC Xlib "_XcmsScreenNumberOfCCC" () :integer)
  (defforeign cmsScreenWhitePointOfCCC Xlib "_XcmsScreenWhitePointOfCCC" () :integer)
  (defforeign cmsSetCompressionProc Xlib "_XcmsSetCompressionProc" () :integer)
  (defforeign cmsSetWhiteAdjustProc Xlib "_XcmsSetWhiteAdjustProc" () :integer)
  (defforeign cmsSetWhitePoint Xlib "_XcmsSetWhitePoint" () :integer)
  (defforeign cmsStoreColor Xlib "_XcmsStoreColor" () :integer)
  (defforeign cmsStoreColors Xlib "_XcmsStoreColors" () :integer)
  (defforeign cmsTekHVCClipC Xlib "_XcmsTekHVCClipC" () :integer)
  (defforeign cmsTekHVCClipV Xlib "_XcmsTekHVCClipV" () :integer)
  (defforeign cmsTekHVCClipVC Xlib "_XcmsTekHVCClipVC" () :integer)
  (defforeign cmsTekHVCColorSpace Xlib "_XcmsTekHVCColorSpace" () :integer)
  (defforeign cmsTekHVCQueryMaxC Xlib "_XcmsTekHVCQueryMaxC" () :integer)
  (defforeign cmsTekHVCQueryMaxV Xlib "_XcmsTekHVCQueryMaxV" () :integer)
  (defforeign cmsTekHVCQueryMaxVC Xlib "_XcmsTekHVCQueryMaxVC" () :integer)
  (defforeign cmsTekHVCQueryMaxVSamples Xlib "_XcmsTekHVCQueryMaxVSamples" () :integer)
  (defforeign cmsTekHVCQueryMinV Xlib "_XcmsTekHVCQueryMinV" () :integer)
  (defforeign cmsTekHVCToCIEuvY Xlib "_XcmsTekHVCToCIEuvY" () :integer)
  (defforeign cmsTekHVCWhiteShiftColors Xlib "_XcmsTekHVCWhiteShiftColors" () :integer)
  (defforeign cmsTekHVC_ValidSpec Xlib "_XcmsTekHVC_ValidSpec" () :integer)
  (defforeign cmsTekHVC_prefix Xlib "_XcmsTekHVC_prefix" () :integer)
  (defforeign cmsUNDEFINEDColorSpace Xlib "_XcmsUNDEFINEDColorSpace" () :integer)
  (defforeign cmsVisualOfCCC Xlib "_XcmsVisualOfCCC" () :integer)
  (defforeign mbDrawImageString Xlib "_XmbDrawImageString" () :integer)
  (defforeign mbDrawString Xlib "_XmbDrawString" () :integer)
  (defforeign mbDrawText Xlib "_XmbDrawText" () :integer)
  (defforeign mbLookupString Xlib "_XmbLookupString" () :integer)
  (defforeign mbResetIC Xlib "_XmbResetIC" () :integer)
  (defforeign mbSetWMProperties Xlib "_XmbSetWMProperties" () :integer)
  (defforeign mbTextEscapement Xlib "_XmbTextEscapement" () :integer)
  (defforeign mbTextExtents Xlib "_XmbTextExtents" () :integer)
  (defforeign mbTextListToTextProperty Xlib "_XmbTextListToTextProperty" () :integer)
  (defforeign mbTextPerCharExtents Xlib "_XmbTextPerCharExtents" () :integer)
  (defforeign mbTextPropertyToTextList Xlib "_XmbTextPropertyToTextList" () :integer)
  (defforeign permalloc Xlib "_Xpermalloc" () :integer)
  (defforeign rmCombineDatabase Xlib "_XrmCombineDatabase" () :integer)
  (defforeign rmCombineFileDatabase Xlib "_XrmCombineFileDatabase" () :integer)
  (defforeign rmDestroyDatabase Xlib "_XrmDestroyDatabase" () :integer)
  (defforeign rmEnumerateDatabase Xlib "_XrmEnumerateDatabase" () :integer)
  (defforeign rmGetDatabase Xlib "_XrmGetDatabase" () :integer)
  (defforeign rmGetFileDatabase Xlib "_XrmGetFileDatabase" () :integer)
  (defforeign rmGetResource Xlib "_XrmGetResource" () :integer)
  (defforeign rmGetStringDatabase Xlib "_XrmGetStringDatabase" () :integer)
  (defforeign rmInitialize Xlib "_XrmInitialize" () :integer)
  (defforeign rmLocaleOfDatabase Xlib "_XrmLocaleOfDatabase" () :integer)
  (defforeign rmMergeDatabases Xlib "_XrmMergeDatabases" () :integer)
  (defforeign rmParseCommand Xlib "_XrmParseCommand" () :integer)
  (defforeign rmPermStringToQuark Xlib "_XrmPermStringToQuark" () :integer)
  (defforeign rmPutFileDatabase Xlib "_XrmPutFileDatabase" () :integer)
  (defforeign rmPutLineResource Xlib "_XrmPutLineResource" () :integer)
  (defforeign rmPutResource Xlib "_XrmPutResource" () :integer)
  (defforeign rmPutStringResource Xlib "_XrmPutStringResource" () :integer)
  (defforeign rmQGetResource Xlib "_XrmQGetResource" () :integer)
  (defforeign rmQGetSearchList Xlib "_XrmQGetSearchList" () :integer)
  (defforeign rmQGetSearchResource Xlib "_XrmQGetSearchResource" () :integer)
  (defforeign rmQPutResource Xlib "_XrmQPutResource" () :integer)
  (defforeign rmQPutStringResource Xlib "_XrmQPutStringResource" () :integer)
  (defforeign rmQuarkToString Xlib "_XrmQuarkToString" () :integer)
  (defforeign rmSetDatabase Xlib "_XrmSetDatabase" () :integer)
  (defforeign rmStringToBindingQuarkList Xlib "_XrmStringToBindingQuarkList" () :integer)
  (defforeign rmStringToQuark Xlib "_XrmStringToQuark" () :integer)
  (defforeign rmStringToQuarkList Xlib "_XrmStringToQuarkList" () :integer)
  (defforeign rmUniqueQuark Xlib "_XrmUniqueQuark" () :integer)
  (defforeign wcDrawImageString Xlib "_XwcDrawImageString" () :integer)
  (defforeign wcDrawString Xlib "_XwcDrawString" () :integer)
  (defforeign wcDrawText Xlib "_XwcDrawText" () :integer)
  (defforeign wcFreeStringList Xlib "_XwcFreeStringList" () :integer)
  (defforeign wcLookupString Xlib "_XwcLookupString" () :integer)
  (defforeign wcResetIC Xlib "_XwcResetIC" () :integer)
  (defforeign wcTextEscapement Xlib "_XwcTextEscapement" () :integer)
  (defforeign wcTextExtents Xlib "_XwcTextExtents" () :integer)
  (defforeign wcTextListToTextProperty Xlib "_XwcTextListToTextProperty" () :integer)
  (defforeign wcTextPerCharExtents Xlib "_XwcTextPerCharExtents" () :integer)
  (defforeign wcTextPropertyToTextList Xlib "_XwcTextPropertyToTextList" () :integer)
#|
  (defforeign ctCreate Xlib "_XctCreate" () :integer)
  (defforeign ctFree Xlib "_XctFree" () :integer)
  (defforeign ctNextItem Xlib "_XctNextItem" () :integer)
  (defforeign ctReset Xlib "_XctReset" () :integer)
  (defforeign muAddCloseDisplayHook Xlib "_XmuAddCloseDisplayHook" () :integer)
  (defforeign muAddInitializer Xlib "_XmuAddInitializer" () :integer)
  (defforeign muAllStandardColormaps Xlib "_XmuAllStandardColormaps" () :integer)
  (defforeign muCallInitializers Xlib "_XmuCallInitializers" () :integer)
  (defforeign muClientWindow Xlib "_XmuClientWindow" () :integer)
  (defforeign muCompareISOLatin1 Xlib "_XmuCompareISOLatin1" () :integer)
  (defforeign muConvertStandardSelection Xlib "_XmuConvertStandardSelection" () :integer)
  (defforeign muCopyISOLatin1Lowered Xlib "_XmuCopyISOLatin1Lowered" () :integer)
  (defforeign muCopyISOLatin1Uppered Xlib "_XmuCopyISOLatin1Uppered" () :integer)
  (defforeign muCreateColormap Xlib "_XmuCreateColormap" () :integer)
  (defforeign muCreatePixmapFromBitmap Xlib "_XmuCreatePixmapFromBitmap" () :integer)
  (defforeign muCreateStippledPixmap Xlib "_XmuCreateStippledPixmap" () :integer)
  (defforeign muCursorNameToIndex Xlib "_XmuCursorNameToIndex" () :integer)
  (defforeign muCvtFunctionToCallback Xlib "_XmuCvtFunctionToCallback" () :integer)
  (defforeign muCvtStringToBackingStore Xlib "_XmuCvtStringToBackingStore" () :integer)
  (defforeign muCvtStringToBitmap Xlib "_XmuCvtStringToBitmap" () :integer)
  (defforeign muCvtStringToColorCursor Xlib "_XmuCvtStringToColorCursor" () :integer)
  (defforeign muCvtStringToCursor Xlib "_XmuCvtStringToCursor" () :integer)
  (defforeign muCvtStringToGravity Xlib "_XmuCvtStringToGravity" () :integer)
  (defforeign muCvtStringToJustify Xlib "_XmuCvtStringToJustify" () :integer)
  (defforeign muCvtStringToLong Xlib "_XmuCvtStringToLong" () :integer)
  (defforeign muCvtStringToOrientation Xlib "_XmuCvtStringToOrientation" () :integer)
  (defforeign muCvtStringToShapeStyle Xlib "_XmuCvtStringToShapeStyle" () :integer)
  (defforeign muCvtStringToWidget Xlib "_XmuCvtStringToWidget" () :integer)
  (defforeign muDQAddDisplay Xlib "_XmuDQAddDisplay" () :integer)
  (defforeign muDQCreate Xlib "_XmuDQCreate" () :integer)
  (defforeign muDQDestroy Xlib "_XmuDQDestroy" () :integer)
  (defforeign muDQLookupDisplay Xlib "_XmuDQLookupDisplay" () :integer)
  (defforeign muDQRemoveDisplay Xlib "_XmuDQRemoveDisplay" () :integer)
  (defforeign muDeleteStandardColormap Xlib "_XmuDeleteStandardColormap" () :integer)
  (defforeign muDistinguishableColors Xlib "_XmuDistinguishableColors" () :integer)
  (defforeign muDistinguishablePixels Xlib "_XmuDistinguishablePixels" () :integer)
  (defforeign muDrawLogo Xlib "_XmuDrawLogo" () :integer)
  (defforeign muDrawRoundedRectangle Xlib "_XmuDrawRoundedRectangle" () :integer)
  (defforeign muFillRoundedRectangle Xlib "_XmuFillRoundedRectangle" () :integer)
  (defforeign muGetAtomName Xlib "_XmuGetAtomName" () :integer)
  (defforeign muGetColormapAllocation Xlib "_XmuGetColormapAllocation" () :integer)
  (defforeign muGetHostname Xlib "_XmuGetHostname" () :integer)
  (defforeign muInternAtom Xlib "_XmuInternAtom" () :integer)
  (defforeign muInternStrings Xlib "_XmuInternStrings" () :integer)
  (defforeign muLocateBitmapFile Xlib "_XmuLocateBitmapFile" () :integer)
  (defforeign muLocatePixmapFile Xlib "_XmuLocatePixmapFile" () :integer)
  (defforeign muLookupAPL Xlib "_XmuLookupAPL" () :integer)
  (defforeign muLookupArabic Xlib "_XmuLookupArabic" () :integer)
  (defforeign muLookupCloseDisplayHook Xlib "_XmuLookupCloseDisplayHook" () :integer)
  (defforeign muLookupCyrillic Xlib "_XmuLookupCyrillic" () :integer)
  (defforeign muLookupGreek Xlib "_XmuLookupGreek" () :integer)
  (defforeign muLookupHebrew Xlib "_XmuLookupHebrew" () :integer)
  (defforeign muLookupJISX0201 Xlib "_XmuLookupJISX0201" () :integer)
  (defforeign muLookupKana Xlib "_XmuLookupKana" () :integer)
  (defforeign muLookupLatin1 Xlib "_XmuLookupLatin1" () :integer)
  (defforeign muLookupLatin2 Xlib "_XmuLookupLatin2" () :integer)
  (defforeign muLookupLatin3 Xlib "_XmuLookupLatin3" () :integer)
  (defforeign muLookupLatin4 Xlib "_XmuLookupLatin4" () :integer)
  (defforeign muLookupStandardColormap Xlib "_XmuLookupStandardColormap" () :integer)
  (defforeign muLookupString Xlib "_XmuLookupString" () :integer)
  (defforeign muMakeAtom Xlib "_XmuMakeAtom" () :integer)
  (defforeign muNameOfAtom Xlib "_XmuNameOfAtom" () :integer)
  (defforeign muNewCvtStringToWidget Xlib "_XmuNewCvtStringToWidget" () :integer)
  (defforeign muPrintDefaultErrorMessage Xlib "_XmuPrintDefaultErrorMessage" () :integer)
  (defforeign muReadBitmapData Xlib "_XmuReadBitmapData" () :integer)
  (defforeign muReadBitmapDataFromFile Xlib "_XmuReadBitmapDataFromFile" () :integer)
  (defforeign muReleaseStippledPixmap Xlib "_XmuReleaseStippledPixmap" () :integer)
  (defforeign muRemoveCloseDisplayHook Xlib "_XmuRemoveCloseDisplayHook" () :integer)
  (defforeign muReshapeWidget Xlib "_XmuReshapeWidget" () :integer)
  (defforeign muScreenOfWindow Xlib "_XmuScreenOfWindow" () :integer)
  (defforeign muSimpleErrorHandler Xlib "_XmuSimpleErrorHandler" () :integer)
  (defforeign muStandardColormap Xlib "_XmuStandardColormap" () :integer)
  (defforeign muUpdateMapHints Xlib "_XmuUpdateMapHints" () :integer)
  (defforeign muVisualStandardColormaps Xlib "_XmuVisualStandardColormaps" () :integer)
  (defforeign muWnCountOwnedResources Xlib "_XmuWnCountOwnedResources" () :integer)
  (defforeign muWnFetchResources Xlib "_XmuWnFetchResources" () :integer)
  (defforeign muWnInitializeNodes Xlib "_XmuWnInitializeNodes" () :integer)
  (defforeign muWnNameToNode Xlib "_XmuWnNameToNode" () :integer)
  (defforeign tAppAddActionHook Xlib "_XtAppAddActionHook" () :integer)
  (defforeign tRemoveActionHook Xlib "_XtRemoveActionHook" () :integer)
  (defforeign tCalloc Xlib "_XtCalloc" () :integer)
  (defforeign tFree Xlib "_XtFree" () :integer)
  (defforeign tMalloc Xlib "_XtMalloc" () :integer)
  (defforeign tRealloc Xlib "_XtRealloc" () :integer)
  (defforeign tMergeArgLists Xlib "_XtMergeArgLists" () :integer)
  (defforeign tAddCallback Xlib "_XtAddCallback" () :integer)
  (defforeign tAddCallbacks Xlib "_XtAddCallbacks" () :integer)
  (defforeign tCallCallbackList Xlib "_XtCallCallbackList" () :integer)
  (defforeign tCallCallbacks Xlib "_XtCallCallbacks" () :integer)
  (defforeign tHasCallbacks Xlib "_XtHasCallbacks" () :integer)
  (defforeign tRemoveAllCallbacks Xlib "_XtRemoveAllCallbacks" () :integer)
  (defforeign tRemoveCallback Xlib "_XtRemoveCallback" () :integer)
  (defforeign tRemoveCallbacks Xlib "_XtRemoveCallbacks" () :integer)
  (defforeign tGetMultiClickTime Xlib "_XtGetMultiClickTime" () :integer)
  (defforeign tSetMultiClickTime Xlib "_XtSetMultiClickTime" () :integer)
  (defforeign tAddConverter Xlib "_XtAddConverter" () :integer)
  (defforeign tAppAddConverter Xlib "_XtAppAddConverter" () :integer)
  (defforeign tAppReleaseCacheRefs Xlib "_XtAppReleaseCacheRefs" () :integer)
  (defforeign tAppSetTypeConverter Xlib "_XtAppSetTypeConverter" () :integer)
  (defforeign tCallConverter Xlib "_XtCallConverter" () :integer)
  (defforeign tCallbackReleaseCacheRef Xlib "_XtCallbackReleaseCacheRef" () :integer)
  (defforeign tCallbackReleaseCacheRefList Xlib "_XtCallbackReleaseCacheRefList" () :integer)
  (defforeign tConvert Xlib "_XtConvert" () :integer)
  (defforeign tConvertAndStore Xlib "_XtConvertAndStore" () :integer)
  (defforeign tDirectConvert Xlib "_XtDirectConvert" () :integer)
  (defforeign tSetTypeConverter Xlib "_XtSetTypeConverter" () :integer)
  (defforeign tCvtColorToPixel Xlib "_XtCvtColorToPixel" () :integer)
  (defforeign tCvtIntToBool Xlib "_XtCvtIntToBool" () :integer)
  (defforeign tCvtIntToBoolean Xlib "_XtCvtIntToBoolean" () :integer)
  (defforeign tCvtIntToColor Xlib "_XtCvtIntToColor" () :integer)
  (defforeign tCvtIntToFloat Xlib "_XtCvtIntToFloat" () :integer)
  (defforeign tCvtIntToFont Xlib "_XtCvtIntToFont" () :integer)
  (defforeign tCvtIntToPixel Xlib "_XtCvtIntToPixel" () :integer)
  (defforeign tCvtIntToPixmap Xlib "_XtCvtIntToPixmap" () :integer)
  (defforeign tCvtIntToShort Xlib "_XtCvtIntToShort" () :integer)
  (defforeign tCvtIntToUnsignedChar Xlib "_XtCvtIntToUnsignedChar" () :integer)
  (defforeign tCvtStringToAtom Xlib "_XtCvtStringToAtom" () :integer)
  (defforeign tCvtStringToBool Xlib "_XtCvtStringToBool" () :integer)
  (defforeign tCvtStringToBoolean Xlib "_XtCvtStringToBoolean" () :integer)
  (defforeign tCvtStringToCursor Xlib "_XtCvtStringToCursor" () :integer)
  (defforeign tCvtStringToDimension Xlib "_XtCvtStringToDimension" () :integer)
  (defforeign tCvtStringToDisplay Xlib "_XtCvtStringToDisplay" () :integer)
  (defforeign tCvtStringToFile Xlib "_XtCvtStringToFile" () :integer)
  (defforeign tCvtStringToFloat Xlib "_XtCvtStringToFloat" () :integer)
  (defforeign tCvtStringToFont Xlib "_XtCvtStringToFont" () :integer)
  (defforeign tCvtStringToFontSet Xlib "_XtCvtStringToFontSet" () :integer)
  (defforeign tCvtStringToFontStruct Xlib "_XtCvtStringToFontStruct" () :integer)
  (defforeign tCvtStringToInitialState Xlib "_XtCvtStringToInitialState" () :integer)
  (defforeign tCvtStringToInt Xlib "_XtCvtStringToInt" () :integer)
  (defforeign tCvtStringToPixel Xlib "_XtCvtStringToPixel" () :integer)
  (defforeign tCvtStringToShort Xlib "_XtCvtStringToShort" () :integer)
  (defforeign tCvtStringToUnsignedChar Xlib "_XtCvtStringToUnsignedChar" () :integer)
  (defforeign tCvtStringToVisual Xlib "_XtCvtStringToVisual" () :integer)
  (defforeign tDisplayStringConversionWarning Xlib "_XtDisplayStringConversionWarning" () :integer)
  (defforeign tStringConversionWarning Xlib "_XtStringConversionWarning" () :integer)
  (defforeign tAppCreateShell Xlib "_XtAppCreateShell" () :integer)
  (defforeign tCreateApplicationShell Xlib "_XtCreateApplicationShell" () :integer)
  (defforeign tCreateManagedWidget Xlib "_XtCreateManagedWidget" () :integer)
  (defforeign tCreatePopupShell Xlib "_XtCreatePopupShell" () :integer)
  (defforeign tCreateWidget Xlib "_XtCreateWidget" () :integer)
  (defforeign tInitializeWidgetClass Xlib "_XtInitializeWidgetClass" () :integer)
  (defforeign tDestroyWidget Xlib "_XtDestroyWidget" () :integer)
  (defforeign tCloseDisplay Xlib "_XtCloseDisplay" () :integer)
  (defforeign tCreateApplicationContext Xlib "_XtCreateApplicationContext" () :integer)
  (defforeign tDatabase Xlib "_XtDatabase" () :integer)
  (defforeign tDestroyApplicationContext Xlib "_XtDestroyApplicationContext" () :integer)
  (defforeign tDisplayInitialize Xlib "_XtDisplayInitialize" () :integer)
  (defforeign tDisplayToApplicationContext Xlib "_XtDisplayToApplicationContext" () :integer)
  (defforeign tGetApplicationNameAndClass Xlib "_XtGetApplicationNameAndClass" () :integer)
  (defforeign tOpenDisplay Xlib "_XtOpenDisplay" () :integer)
  (defforeign tWidgetToApplicationContext Xlib "_XtWidgetToApplicationContext" () :integer)
  (defforeign tAppError Xlib "_XtAppError" () :integer)
  (defforeign tAppErrorMsg Xlib "_XtAppErrorMsg" () :integer)
  (defforeign tAppGetErrorDatabase Xlib "_XtAppGetErrorDatabase" () :integer)
  (defforeign tAppGetErrorDatabaseText Xlib "_XtAppGetErrorDatabaseText" () :integer)
  (defforeign tAppSetErrorHandler Xlib "_XtAppSetErrorHandler" () :integer)
  (defforeign tAppSetErrorMsgHandler Xlib "_XtAppSetErrorMsgHandler" () :integer)
  (defforeign tAppSetWarningHandler Xlib "_XtAppSetWarningHandler" () :integer)
  (defforeign tAppSetWarningMsgHandler Xlib "_XtAppSetWarningMsgHandler" () :integer)
  (defforeign tAppWarning Xlib "_XtAppWarning" () :integer)
  (defforeign tAppWarningMsg Xlib "_XtAppWarningMsg" () :integer)
  (defforeign tError Xlib "_XtError" () :integer)
  (defforeign tErrorMsg Xlib "_XtErrorMsg" () :integer)
  (defforeign tGetErrorDatabase Xlib "_XtGetErrorDatabase" () :integer)
  (defforeign tGetErrorDatabaseText Xlib "_XtGetErrorDatabaseText" () :integer)
  (defforeign tSetErrorHandler Xlib "_XtSetErrorHandler" () :integer)
  (defforeign tSetErrorMsgHandler Xlib "_XtSetErrorMsgHandler" () :integer)
  (defforeign tSetWarningHandler Xlib "_XtSetWarningHandler" () :integer)
  (defforeign tSetWarningMsgHandler Xlib "_XtSetWarningMsgHandler" () :integer)
  (defforeign tWarning Xlib "_XtWarning" () :integer)
  (defforeign tWarningMsg Xlib "_XtWarningMsg" () :integer)
  (defforeign tAddEventHandler Xlib "_XtAddEventHandler" () :integer)
  (defforeign tAddExposureToRegion Xlib "_XtAddExposureToRegion" () :integer)
  (defforeign tAddGrab Xlib "_XtAddGrab" () :integer)
  (defforeign tAddRawEventHandler Xlib "_XtAddRawEventHandler" () :integer)
  (defforeign tAppMainLoop Xlib "_XtAppMainLoop" () :integer)
  (defforeign tBuildEventMask Xlib "_XtBuildEventMask" () :integer)
  (defforeign tDispatchEvent Xlib "_XtDispatchEvent" () :integer)
  (defforeign tInsertEventHandler Xlib "_XtInsertEventHandler" () :integer)
  (defforeign tInsertRawEventHandler Xlib "_XtInsertRawEventHandler" () :integer)
  (defforeign tLastTimestampProcessed Xlib "_XtLastTimestampProcessed" () :integer)
  (defforeign tMainLoop Xlib "_XtMainLoop" () :integer)
  (defforeign tRemoveEventHandler Xlib "_XtRemoveEventHandler" () :integer)
  (defforeign tRemoveGrab Xlib "_XtRemoveGrab" () :integer)
  (defforeign tRemoveRawEventHandler Xlib "_XtRemoveRawEventHandler" () :integer)
  (defforeign tWindowToWidget Xlib "_XtWindowToWidget" () :integer)
  (defforeign tIsApplicationShell Xlib "_XtIsApplicationShell" () :integer)
  (defforeign tIsComposite Xlib "_XtIsComposite" () :integer)
  (defforeign tIsConstraint Xlib "_XtIsConstraint" () :integer)
  (defforeign tIsOverrideShell Xlib "_XtIsOverrideShell" () :integer)
  (defforeign tIsRectObj Xlib "_XtIsRectObj" () :integer)
  (defforeign tIsShell Xlib "_XtIsShell" () :integer)
  (defforeign tIsTopLevelShell Xlib "_XtIsTopLevelShell" () :integer)
  (defforeign tIsTransientShell Xlib "_XtIsTransientShell" () :integer)
  (defforeign tIsVendorShell Xlib "_XtIsVendorShell" () :integer)
  (defforeign tIsWMShell Xlib "_XtIsWMShell" () :integer)
  (defforeign tIsWidget Xlib "_XtIsWidget" () :integer)
  (defforeign tMapWidget Xlib "_XtMapWidget" () :integer)
  (defforeign tNewString Xlib "_XtNewString" () :integer)
  (defforeign tUnmapWidget Xlib "_XtUnmapWidget" () :integer)
  (defforeign tAllocateGC Xlib "_XtAllocateGC" () :integer)
  (defforeign tDestroyGC Xlib "_XtDestroyGC" () :integer)
  (defforeign tGetGC Xlib "_XtGetGC" () :integer)
  (defforeign tReleaseGC Xlib "_XtReleaseGC" () :integer)
  (defforeign tConfigureWidget Xlib "_XtConfigureWidget" () :integer)
  (defforeign tMakeGeometryRequest Xlib "_XtMakeGeometryRequest" () :integer)
  (defforeign tMakeResizeRequest Xlib "_XtMakeResizeRequest" () :integer)
  (defforeign tMoveWidget Xlib "_XtMoveWidget" () :integer)
  (defforeign tQueryGeometry Xlib "_XtQueryGeometry" () :integer)
  (defforeign tResizeWidget Xlib "_XtResizeWidget" () :integer)
  (defforeign tResizeWindow Xlib "_XtResizeWindow" () :integer)
  (defforeign tTranslateCoords Xlib "_XtTranslateCoords" () :integer)
  (defforeign tGetActionKeysym Xlib "_XtGetActionKeysym" () :integer)
  (defforeign tGetConstraintResourceList Xlib "_XtGetConstraintResourceList" () :integer)
  (defforeign tGetResourceList Xlib "_XtGetResourceList" () :integer)
  (defforeign tGetSubvalues Xlib "_XtGetSubvalues" () :integer)
  (defforeign tGetValues Xlib "_XtGetValues" () :integer)
  (defforeign tAppInitialize Xlib "_XtAppInitialize" () :integer)
  (defforeign tAppSetFallbackResources Xlib "_XtAppSetFallbackResources" () :integer)
  (defforeign tInitialize Xlib "_XtInitialize" () :integer)
  (defforeign tScreenDatabase Xlib "_XtScreenDatabase" () :integer)
  (defforeign tSetLanguageProc Xlib "_XtSetLanguageProc" () :integer)
  (defforeign tToolkitInitialize Xlib "_XtToolkitInitialize" () :integer)
  (defforeign tCXtToolkitError Xlib "_XtCXtToolkitError" () :integer)
  (defforeign tCallAcceptFocus Xlib "_XtCallAcceptFocus" () :integer)
  (defforeign tClass Xlib "_XtClass" () :integer)
  (defforeign tCreateWindow Xlib "_XtCreateWindow" () :integer)
  (defforeign tDisplay Xlib "_XtDisplay" () :integer)
  (defforeign tDisplayOfObject Xlib "_XtDisplayOfObject" () :integer)
  (defforeign tFindFile Xlib "_XtFindFile" () :integer)
  (defforeign tIsManaged Xlib "_XtIsManaged" () :integer)
  (defforeign tIsObject Xlib "_XtIsObject" () :integer)
  (defforeign tIsRealized Xlib "_XtIsRealized" () :integer)
  (defforeign tIsSensitive Xlib "_XtIsSensitive" () :integer)
  (defforeign tIsSubclass Xlib "_XtIsSubclass" () :integer)
  (defforeign tName Xlib "_XtName" () :integer)
  (defforeign tNameToWidget Xlib "_XtNameToWidget" () :integer)
  (defforeign tParent Xlib "_XtParent" () :integer)
  (defforeign tRealizeWidget Xlib "_XtRealizeWidget" () :integer)
  (defforeign tResolvePathname Xlib "_XtResolvePathname" () :integer)
  (defforeign tScreen Xlib "_XtScreen" () :integer)
  (defforeign tScreenOfObject Xlib "_XtScreenOfObject" () :integer)
  (defforeign tSuperclass Xlib "_XtSuperclass" () :integer)
  (defforeign tUnrealizeWidget Xlib "_XtUnrealizeWidget" () :integer)
  (defforeign tWindow Xlib "_XtWindow" () :integer)
  (defforeign tWindowOfObject Xlib "_XtWindowOfObject" () :integer)
  (defforeign tSetKeyboardFocus Xlib "_XtSetKeyboardFocus" () :integer)
  (defforeign tManageChild Xlib "_XtManageChild" () :integer)
  (defforeign tManageChildren Xlib "_XtManageChildren" () :integer)
  (defforeign tSetMappedWhenManaged Xlib "_XtSetMappedWhenManaged" () :integer)
  (defforeign tUnmanageChild Xlib "_XtUnmanageChild" () :integer)
  (defforeign tUnmanageChildren Xlib "_XtUnmanageChildren" () :integer)
  (defforeign tAddInput Xlib "_XtAddInput" () :integer)
  (defforeign tAddTimeOut Xlib "_XtAddTimeOut" () :integer)
  (defforeign tAddWorkProc Xlib "_XtAddWorkProc" () :integer)
  (defforeign tAppAddInput Xlib "_XtAppAddInput" () :integer)
  (defforeign tAppAddTimeOut Xlib "_XtAppAddTimeOut" () :integer)
  (defforeign tAppAddWorkProc Xlib "_XtAppAddWorkProc" () :integer)
  (defforeign tAppNextEvent Xlib "_XtAppNextEvent" () :integer)
  (defforeign tAppPeekEvent Xlib "_XtAppPeekEvent" () :integer)
  (defforeign tAppPending Xlib "_XtAppPending" () :integer)
  (defforeign tAppProcessEvent Xlib "_XtAppProcessEvent" () :integer)
  (defforeign tNextEvent Xlib "_XtNextEvent" () :integer)
  (defforeign tPeekEvent Xlib "_XtPeekEvent" () :integer)
  (defforeign tPending Xlib "_XtPending" () :integer)
  (defforeign tProcessEvent Xlib "_XtProcessEvent" () :integer)
  (defforeign tRemoveInput Xlib "_XtRemoveInput" () :integer)
  (defforeign tRemoveTimeOut Xlib "_XtRemoveTimeOut" () :integer)
  (defforeign tRemoveWorkProc Xlib "_XtRemoveWorkProc" () :integer)
  (defforeign tGrabButton Xlib "_XtGrabButton" () :integer)
  (defforeign tGrabKey Xlib "_XtGrabKey" () :integer)
  (defforeign tGrabKeyboard Xlib "_XtGrabKeyboard" () :integer)
  (defforeign tGrabPointer Xlib "_XtGrabPointer" () :integer)
  (defforeign tUngrabButton Xlib "_XtUngrabButton" () :integer)
  (defforeign tUngrabKey Xlib "_XtUngrabKey" () :integer)
  (defforeign tUngrabKeyboard Xlib "_XtUngrabKeyboard" () :integer)
  (defforeign tUngrabPointer Xlib "_XtUngrabPointer" () :integer)
  (defforeign tCallbackPopdown Xlib "_XtCallbackPopdown" () :integer)
  (defforeign tPopdown Xlib "_XtPopdown" () :integer)
  (defforeign tPopup Xlib "_XtPopup" () :integer)
  (defforeign tPopupSpringLoaded Xlib "_XtPopupSpringLoaded" () :integer)
  (defforeign tCallbackExclusive Xlib "_XtCallbackExclusive" () :integer)
  (defforeign tCallbackNone Xlib "_XtCallbackNone" () :integer)
  (defforeign tCallbackNonexclusive Xlib "_XtCallbackNonexclusive" () :integer)
  (defforeign tGetApplicationResources Xlib "_XtGetApplicationResources" () :integer)
  (defforeign tGetSubresources Xlib "_XtGetSubresources" () :integer)
  (defforeign tAppGetSelectionTimeout Xlib "_XtAppGetSelectionTimeout" () :integer)
  (defforeign tAppSetSelectionTimeout Xlib "_XtAppSetSelectionTimeout" () :integer)
  (defforeign tDisownSelection Xlib "_XtDisownSelection" () :integer)
  (defforeign tGetSelectionRequest Xlib "_XtGetSelectionRequest" () :integer)
  (defforeign tGetSelectionTimeout Xlib "_XtGetSelectionTimeout" () :integer)
  (defforeign tGetSelectionValue Xlib "_XtGetSelectionValue" () :integer)
  (defforeign tGetSelectionValueIncremental Xlib "_XtGetSelectionValueIncremental" () :integer)
  (defforeign tGetSelectionValues Xlib "_XtGetSelectionValues" () :integer)
  (defforeign tGetSelectionValuesIncremental Xlib "_XtGetSelectionValuesIncremental" () :integer)
  (defforeign tOwnSelection Xlib "_XtOwnSelection" () :integer)
  (defforeign tOwnSelectionIncremental Xlib "_XtOwnSelectionIncremental" () :integer)
  (defforeign tSetSelectionTimeout Xlib "_XtSetSelectionTimeout" () :integer)
  (defforeign tSetSensitive Xlib "_XtSetSensitive" () :integer)
  (defforeign tSetSubvalues Xlib "_XtSetSubvalues" () :integer)
  (defforeign tSetValues Xlib "_XtSetValues" () :integer)
  (defforeign tSetWMColormapWindows Xlib "_XtSetWMColormapWindows" () :integer)
  (defforeign tShellStrings Xlib "_XtShellStrings" () :integer)
  (defforeign tStrings Xlib "_XtStrings" () :integer)
  (defforeign tAddActions Xlib "_XtAddActions" () :integer)
  (defforeign tAppAddActions Xlib "_XtAppAddActions" () :integer)
  (defforeign tCallActionProc Xlib "_XtCallActionProc" () :integer)
  (defforeign tGetActionList Xlib "_XtGetActionList" () :integer)
  (defforeign tMenuPopupAction Xlib "_XtMenuPopupAction" () :integer)
  (defforeign tRegisterGrabAction Xlib "_XtRegisterGrabAction" () :integer)
  (defforeign tConvertCase Xlib "_XtConvertCase" () :integer)
  (defforeign tGetKeysymTable Xlib "_XtGetKeysymTable" () :integer)
  (defforeign tKeysymToKeycodeList Xlib "_XtKeysymToKeycodeList" () :integer)
  (defforeign tRegisterCaseConverter Xlib "_XtRegisterCaseConverter" () :integer)
  (defforeign tSetKeyTranslator Xlib "_XtSetKeyTranslator" () :integer)
  (defforeign tTranslateKey Xlib "_XtTranslateKey" () :integer)
  (defforeign tTranslateKeycode Xlib "_XtTranslateKeycode" () :integer)
  (defforeign tCvtStringToAcceleratorTable Xlib "_XtCvtStringToAcceleratorTable" () :integer)
  (defforeign tCvtStringToTranslationTable Xlib "_XtCvtStringToTranslationTable" () :integer)
  (defforeign tParseAcceleratorTable Xlib "_XtParseAcceleratorTable" () :integer)
  (defforeign tParseTranslationTable Xlib "_XtParseTranslationTable" () :integer)
  (defforeign tAugmentTranslations Xlib "_XtAugmentTranslations" () :integer)
  (defforeign tInstallAccelerators Xlib "_XtInstallAccelerators" () :integer)
  (defforeign tInstallAllAccelerators Xlib "_XtInstallAllAccelerators" () :integer)
  (defforeign tOverrideTranslations Xlib "_XtOverrideTranslations" () :integer)
  (defforeign tUninstallTranslations Xlib "_XtUninstallTranslations" () :integer)
  (defforeign tVaAppCreateShell Xlib "_XtVaAppCreateShell" () :integer)
  (defforeign tVaAppInitialize Xlib "_XtVaAppInitialize" () :integer)
  (defforeign tVaCreateManagedWidget Xlib "_XtVaCreateManagedWidget" () :integer)
  (defforeign tVaCreatePopupShell Xlib "_XtVaCreatePopupShell" () :integer)
  (defforeign tVaCreateWidget Xlib "_XtVaCreateWidget" () :integer)
  (defforeign tVaSetSubvalues Xlib "_XtVaSetSubvalues" () :integer)
  (defforeign tVaSetValues Xlib "_XtVaSetValues" () :integer)
  (defforeign tVaGetApplicationResources Xlib "_XtVaGetApplicationResources" () :integer)
  (defforeign tVaGetSubresources Xlib "_XtVaGetSubresources" () :integer)
  (defforeign tVaGetSubvalues Xlib "_XtVaGetSubvalues" () :integer)
  (defforeign tVaGetValues Xlib "_XtVaGetValues" () :integer)
  (defforeign tVaCreateArgsList Xlib "_XtVaCreateArgsList" () :integer)
)
|#
