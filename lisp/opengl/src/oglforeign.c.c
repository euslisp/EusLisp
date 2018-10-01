/* $Header$ */

/* OpenGL function entries -- based on xwindow/xforeign.c */

#include <dlfcn.h>

#include <GL/gl.h>
#include "util.h"

#pragma init (init_object_module)

pointer glpkg;

extern pointer sysmod;

#if BUG_dl
static void *xlib_handle;
#endif

pointer defoglforeign(ctx,xentry)
register context *ctx;
char *xentry;
{ pointer fc, xsym;
  eusinteger_t entry; int i, len;
  char lname[100];
  len=strlen(xentry);
  for (i=0; i<len; i++) lname[i]=toupper(xentry[i]);
  lname[i]=0;
#if Cygwin /* dlopen libGL.dll and libGLU.dll */
  eusinteger_t dlhandle;
  dlhandle=(eusinteger_t)dlopen("cygGL-1.dll", RTLD_LAZY);
  entry=(eusinteger_t)dlsym((eusinteger_t)dlhandle, xentry);
  if ( !entry ) {
    dlhandle=(eusinteger_t)dlopen("cygGLU-1.dll", RTLD_LAZY);
    entry=(eusinteger_t)dlsym(dlhandle, xentry);}
  if ( !entry ) {
    dlhandle=(eusinteger_t)dlopen(0, RTLD_LAZY);
    entry=(eusinteger_t)dlsym(dlhandle, xentry);}
#elif Darwin
  eusinteger_t dlhandle;
  dlhandle=(eusinteger_t)dlopen(0, RTLD_LAZY);
  entry=(eusinteger_t)dlsym(dlhandle, xentry);
#else
#if (WORD_SIZE == 64)
  entry=(eusinteger_t)dlsym((void *)((eusinteger_t)(sysmod->c.ldmod.handle) & ~3L), xentry);
#else
  entry=(eusinteger_t)dlsym((void *)((eusinteger_t)(sysmod->c.ldmod.handle) & ~3), xentry);
#endif
#endif
  if (!entry) {
    fprintf(stderr, "defoglforeign: dlsym() failed for %s\n", xentry);
  }
  xsym=intern(ctx,lname, len, glpkg);
  fc=makeobject(C_FCODE);
  xsym->c.sym.spefunc=fc;
  fc->c.fcode.codevec=makeint(0);
  fc->c.fcode.quotevec=makeint(0);
  fc->c.fcode.subrtype=SUBR_FUNCTION;
  fc->c.fcode.paramtypes=NIL;
  fc->c.fcode.resulttype=K_INTEGER;
  fc->c.fcode.entry=makeint(entry>>2);
  fc->c.fcode.entry2=makeint(entry);    /* kanehiro's patch 2000.12.13 */
  /*printf("x: %s at %x, %x\n", xsym->c.sym.pname->c.str.chars, entry, fc->c.fcode.entry);*/
  export(xsym,glpkg); 
  return(xsym);}
  
pointer oglforeign(ctx,n,argv)
register context *ctx;
int n;
pointer argv[];
{
  glpkg=     makepkg(ctx,makestring("GL",2),NIL,rawcons(ctx,lisppkg,NIL));

  defoglforeign(ctx,"glAccum");
  defoglforeign(ctx,"glAlphaFunc");
  defoglforeign(ctx,"glBegin");
  defoglforeign(ctx,"glBitmap");
  defoglforeign(ctx,"glBlendFunc");
  defoglforeign(ctx,"glCallList");
  defoglforeign(ctx,"glCallLists");
  defoglforeign(ctx,"glClear");
  defoglforeign(ctx,"glClearAccum");
  defoglforeign(ctx,"glClearColor");
  defoglforeign(ctx,"glClearDepth");
  defoglforeign(ctx,"glClearIndex");
  defoglforeign(ctx,"glClearStencil");
  defoglforeign(ctx,"glClipPlane");
  defoglforeign(ctx,"glColor3b");
  defoglforeign(ctx,"glColor3bv");
  defoglforeign(ctx,"glColor3d");
  defoglforeign(ctx,"glColor3dv");
  defoglforeign(ctx,"glColor3f");
  defoglforeign(ctx,"glColor3fv");
  defoglforeign(ctx,"glColor3i");
  defoglforeign(ctx,"glColor3iv");
  defoglforeign(ctx,"glColor3s");
  defoglforeign(ctx,"glColor3sv");
  defoglforeign(ctx,"glColor3ub");
  defoglforeign(ctx,"glColor3ubv");
  defoglforeign(ctx,"glColor3ui");
  defoglforeign(ctx,"glColor3uiv");
  defoglforeign(ctx,"glColor3us");
  defoglforeign(ctx,"glColor3usv");
  defoglforeign(ctx,"glColor4b");
  defoglforeign(ctx,"glColor4bv");
  defoglforeign(ctx,"glColor4d");
  defoglforeign(ctx,"glColor4dv");
  defoglforeign(ctx,"glColor4f");
  defoglforeign(ctx,"glColor4fv");
  defoglforeign(ctx,"glColor4i");
  defoglforeign(ctx,"glColor4iv");
  defoglforeign(ctx,"glColor4s");
  defoglforeign(ctx,"glColor4sv");
  defoglforeign(ctx,"glColor4ub");
  defoglforeign(ctx,"glColor4ubv");
  defoglforeign(ctx,"glColor4ui");
  defoglforeign(ctx,"glColor4uiv");
  defoglforeign(ctx,"glColor4us");
  defoglforeign(ctx,"glColor4usv");
  defoglforeign(ctx,"glColorMask");
  defoglforeign(ctx,"glColorMaterial");
  defoglforeign(ctx,"glCopyPixels");
  defoglforeign(ctx,"glCullFace");
  defoglforeign(ctx,"glDeleteLists");
  defoglforeign(ctx,"glDepthFunc");
  defoglforeign(ctx,"glDepthMask");
  defoglforeign(ctx,"glDepthRange");
  defoglforeign(ctx,"glDisable");
  defoglforeign(ctx,"glDrawBuffer");
  defoglforeign(ctx,"glDrawPixels");
  defoglforeign(ctx,"glEdgeFlag");
  defoglforeign(ctx,"glEdgeFlagv");
  defoglforeign(ctx,"glEnable");
  defoglforeign(ctx,"glEnd");
  defoglforeign(ctx,"glEndList");
  defoglforeign(ctx,"glEvalCoord1d");
  defoglforeign(ctx,"glEvalCoord1dv");
  defoglforeign(ctx,"glEvalCoord1f");
  defoglforeign(ctx,"glEvalCoord1fv");
  defoglforeign(ctx,"glEvalCoord2d");
  defoglforeign(ctx,"glEvalCoord2dv");
  defoglforeign(ctx,"glEvalCoord2f");
  defoglforeign(ctx,"glEvalCoord2fv");
  defoglforeign(ctx,"glEvalMesh1");
  defoglforeign(ctx,"glEvalMesh2");
  defoglforeign(ctx,"glEvalPoint1");
  defoglforeign(ctx,"glEvalPoint2");
  defoglforeign(ctx,"glFeedbackBuffer");
  defoglforeign(ctx,"glFinish");
  defoglforeign(ctx,"glFlush");
  defoglforeign(ctx,"glFogf");
  defoglforeign(ctx,"glFogfv");
  defoglforeign(ctx,"glFogi");
  defoglforeign(ctx,"glFogiv");
  defoglforeign(ctx,"glFrontFace");
  defoglforeign(ctx,"glFrustum");
  defoglforeign(ctx,"glGenLists");
  defoglforeign(ctx,"glGetBooleanv");
  defoglforeign(ctx,"glGetClipPlane");
  defoglforeign(ctx,"glGetDoublev");
  defoglforeign(ctx,"glGetError");
  defoglforeign(ctx,"glGetFloatv");
  defoglforeign(ctx,"glGetIntegerv");
  defoglforeign(ctx,"glGetLightfv");
  defoglforeign(ctx,"glGetLightiv");
  defoglforeign(ctx,"glGetMapdv");
  defoglforeign(ctx,"glGetMapfv");
  defoglforeign(ctx,"glGetMapiv");
  defoglforeign(ctx,"glGetMaterialfv");
  defoglforeign(ctx,"glGetMaterialiv");
  defoglforeign(ctx,"glGetPixelMapfv");
  defoglforeign(ctx,"glGetPixelMapuiv");
  defoglforeign(ctx,"glGetPixelMapusv");
  defoglforeign(ctx,"glGetPolygonStipple");
  defoglforeign(ctx,"glGetString");
  defoglforeign(ctx,"glGetTexEnvfv");
  defoglforeign(ctx,"glGetTexEnviv");
  defoglforeign(ctx,"glGetTexGendv");
  defoglforeign(ctx,"glGetTexGenfv");
  defoglforeign(ctx,"glGetTexGeniv");
  defoglforeign(ctx,"glGetTexImage");
  defoglforeign(ctx,"glGetTexLevelParameterfv");
  defoglforeign(ctx,"glGetTexLevelParameteriv");
  defoglforeign(ctx,"glGetTexParameterfv");
  defoglforeign(ctx,"glGetTexParameteriv");
  defoglforeign(ctx,"glHint");
  defoglforeign(ctx,"glIndexMask");
  defoglforeign(ctx,"glIndexd");
  defoglforeign(ctx,"glIndexdv");
  defoglforeign(ctx,"glIndexf");
  defoglforeign(ctx,"glIndexfv");
  defoglforeign(ctx,"glIndexi");
  defoglforeign(ctx,"glIndexiv");
  defoglforeign(ctx,"glIndexs");
  defoglforeign(ctx,"glIndexsv");
  defoglforeign(ctx,"glInitNames");
  defoglforeign(ctx,"glIsEnabled");
  defoglforeign(ctx,"glIsList");
  defoglforeign(ctx,"glLightModelf");
  defoglforeign(ctx,"glLightModelfv");
  defoglforeign(ctx,"glLightModeli");
  defoglforeign(ctx,"glLightModeliv");
  defoglforeign(ctx,"glLightf");
  defoglforeign(ctx,"glLightfv");
  defoglforeign(ctx,"glLighti");
  defoglforeign(ctx,"glLightiv");
  defoglforeign(ctx,"glLineStipple");
  defoglforeign(ctx,"glLineWidth");
  defoglforeign(ctx,"glListBase");
  defoglforeign(ctx,"glLoadIdentity");
  defoglforeign(ctx,"glLoadMatrixd");
  defoglforeign(ctx,"glLoadMatrixf");
  defoglforeign(ctx,"glLoadName");
  defoglforeign(ctx,"glLogicOp");
  defoglforeign(ctx,"glMap1d");
  defoglforeign(ctx,"glMap1f");
  defoglforeign(ctx,"glMap2d");
  defoglforeign(ctx,"glMap2f");
  defoglforeign(ctx,"glMapGrid1d");
  defoglforeign(ctx,"glMapGrid1f");
  defoglforeign(ctx,"glMapGrid2d");
  defoglforeign(ctx,"glMapGrid2f");
  defoglforeign(ctx,"glMaterialf");
  defoglforeign(ctx,"glMaterialfv");
  defoglforeign(ctx,"glMateriali");
  defoglforeign(ctx,"glMaterialiv");
  defoglforeign(ctx,"glMatrixMode");
  defoglforeign(ctx,"glMultMatrixd");
  defoglforeign(ctx,"glMultMatrixf");
  defoglforeign(ctx,"glNewList");
  defoglforeign(ctx,"glNormal3b");
  defoglforeign(ctx,"glNormal3bv");
  defoglforeign(ctx,"glNormal3d");
  defoglforeign(ctx,"glNormal3dv");
  defoglforeign(ctx,"glNormal3f");
  defoglforeign(ctx,"glNormal3fv");
  defoglforeign(ctx,"glNormal3i");
  defoglforeign(ctx,"glNormal3iv");
  defoglforeign(ctx,"glNormal3s");
  defoglforeign(ctx,"glNormal3sv");
  defoglforeign(ctx,"glOrtho");
  defoglforeign(ctx,"glPassThrough");
  defoglforeign(ctx,"glPixelMapfv");
  defoglforeign(ctx,"glPixelMapuiv");
  defoglforeign(ctx,"glPixelMapusv");
  defoglforeign(ctx,"glPixelStoref");
  defoglforeign(ctx,"glPixelStorei");
  defoglforeign(ctx,"glPixelTransferf");
  defoglforeign(ctx,"glPixelTransferi");
  defoglforeign(ctx,"glPixelZoom");
  defoglforeign(ctx,"glPointSize");
  defoglforeign(ctx,"glPolygonMode");
  defoglforeign(ctx,"glPolygonStipple");
  defoglforeign(ctx,"glPopAttrib");
  defoglforeign(ctx,"glPopMatrix");
  defoglforeign(ctx,"glPopName");
  defoglforeign(ctx,"glPushAttrib");
  defoglforeign(ctx,"glPushMatrix");
  defoglforeign(ctx,"glPushName");
  defoglforeign(ctx,"glRasterPos2d");
  defoglforeign(ctx,"glRasterPos2dv");
  defoglforeign(ctx,"glRasterPos2f");
  defoglforeign(ctx,"glRasterPos2fv");
  defoglforeign(ctx,"glRasterPos2i");
  defoglforeign(ctx,"glRasterPos2iv");
  defoglforeign(ctx,"glRasterPos2s");
  defoglforeign(ctx,"glRasterPos2sv");
  defoglforeign(ctx,"glRasterPos3d");
  defoglforeign(ctx,"glRasterPos3dv");
  defoglforeign(ctx,"glRasterPos3f");
  defoglforeign(ctx,"glRasterPos3fv");
  defoglforeign(ctx,"glRasterPos3i");
  defoglforeign(ctx,"glRasterPos3iv");
  defoglforeign(ctx,"glRasterPos3s");
  defoglforeign(ctx,"glRasterPos3sv");
  defoglforeign(ctx,"glRasterPos4d");
  defoglforeign(ctx,"glRasterPos4dv");
  defoglforeign(ctx,"glRasterPos4f");
  defoglforeign(ctx,"glRasterPos4fv");
  defoglforeign(ctx,"glRasterPos4i");
  defoglforeign(ctx,"glRasterPos4iv");
  defoglforeign(ctx,"glRasterPos4s");
  defoglforeign(ctx,"glRasterPos4sv");
  defoglforeign(ctx,"glReadBuffer");
  defoglforeign(ctx,"glReadPixels");
  defoglforeign(ctx,"glRectd");
  defoglforeign(ctx,"glRectdv");
  defoglforeign(ctx,"glRectf");
  defoglforeign(ctx,"glRectfv");
  defoglforeign(ctx,"glRecti");
  defoglforeign(ctx,"glRectiv");
  defoglforeign(ctx,"glRects");
  defoglforeign(ctx,"glRectsv");
  defoglforeign(ctx,"glRenderMode");
  defoglforeign(ctx,"glRotated");
  defoglforeign(ctx,"glRotatef");
  defoglforeign(ctx,"glScaled");
  defoglforeign(ctx,"glScalef");
  defoglforeign(ctx,"glScissor");
  defoglforeign(ctx,"glSelectBuffer");
  defoglforeign(ctx,"glShadeModel");
  defoglforeign(ctx,"glStencilFunc");
  defoglforeign(ctx,"glStencilMask");
  defoglforeign(ctx,"glStencilOp");
  defoglforeign(ctx,"glTexCoord1d");
  defoglforeign(ctx,"glTexCoord1dv");
  defoglforeign(ctx,"glTexCoord1f");
  defoglforeign(ctx,"glTexCoord1fv");
  defoglforeign(ctx,"glTexCoord1i");
  defoglforeign(ctx,"glTexCoord1iv");
  defoglforeign(ctx,"glTexCoord1s");
  defoglforeign(ctx,"glTexCoord1sv");
  defoglforeign(ctx,"glTexCoord2d");
  defoglforeign(ctx,"glTexCoord2dv");
  defoglforeign(ctx,"glTexCoord2f");
  defoglforeign(ctx,"glTexCoord2fv");
  defoglforeign(ctx,"glTexCoord2i");
  defoglforeign(ctx,"glTexCoord2iv");
  defoglforeign(ctx,"glTexCoord2s");
  defoglforeign(ctx,"glTexCoord2sv");
  defoglforeign(ctx,"glTexCoord3d");
  defoglforeign(ctx,"glTexCoord3dv");
  defoglforeign(ctx,"glTexCoord3f");
  defoglforeign(ctx,"glTexCoord3fv");
  defoglforeign(ctx,"glTexCoord3i");
  defoglforeign(ctx,"glTexCoord3iv");
  defoglforeign(ctx,"glTexCoord3s");
  defoglforeign(ctx,"glTexCoord3sv");
  defoglforeign(ctx,"glTexCoord4d");
  defoglforeign(ctx,"glTexCoord4dv");
  defoglforeign(ctx,"glTexCoord4f");
  defoglforeign(ctx,"glTexCoord4fv");
  defoglforeign(ctx,"glTexCoord4i");
  defoglforeign(ctx,"glTexCoord4iv");
  defoglforeign(ctx,"glTexCoord4s");
  defoglforeign(ctx,"glTexCoord4sv");
  defoglforeign(ctx,"glTexEnvf");
  defoglforeign(ctx,"glTexEnvfv");
  defoglforeign(ctx,"glTexEnvi");
  defoglforeign(ctx,"glTexEnviv");
  defoglforeign(ctx,"glTexGend");
  defoglforeign(ctx,"glTexGendv");
  defoglforeign(ctx,"glTexGenf");
  defoglforeign(ctx,"glTexGenfv");
  defoglforeign(ctx,"glTexGeni");
  defoglforeign(ctx,"glTexGeniv");
  defoglforeign(ctx,"glTexImage1D");
  defoglforeign(ctx,"glTexImage2D");
  defoglforeign(ctx,"glTexParameterf");
  defoglforeign(ctx,"glTexParameterfv");
  defoglforeign(ctx,"glTexParameteri");
  defoglforeign(ctx,"glTexParameteriv");
  defoglforeign(ctx,"glTranslated");
  defoglforeign(ctx,"glTranslatef");
  defoglforeign(ctx,"glVertex2d");
  defoglforeign(ctx,"glVertex2dv");
  defoglforeign(ctx,"glVertex2f");
  defoglforeign(ctx,"glVertex2fv");
  defoglforeign(ctx,"glVertex2i");
  defoglforeign(ctx,"glVertex2iv");
  defoglforeign(ctx,"glVertex2s");
  defoglforeign(ctx,"glVertex2sv");
  defoglforeign(ctx,"glVertex3d");
  defoglforeign(ctx,"glVertex3dv");
  defoglforeign(ctx,"glVertex3f");
  defoglforeign(ctx,"glVertex3fv");
  defoglforeign(ctx,"glVertex3i");
  defoglforeign(ctx,"glVertex3iv");
  defoglforeign(ctx,"glVertex3s");
  defoglforeign(ctx,"glVertex3sv");
  defoglforeign(ctx,"glVertex4d");
  defoglforeign(ctx,"glVertex4dv");
  defoglforeign(ctx,"glVertex4f");
  defoglforeign(ctx,"glVertex4fv");
  defoglforeign(ctx,"glVertex4i");
  defoglforeign(ctx,"glVertex4iv");
  defoglforeign(ctx,"glVertex4s");
  defoglforeign(ctx,"glVertex4sv");
  defoglforeign(ctx,"glViewport");
  defoglforeign(ctx,"gluErrorString");
  defoglforeign(ctx,"gluOrtho2D");
  defoglforeign(ctx,"gluPerspective");
  defoglforeign(ctx,"gluPickMatrix");
  defoglforeign(ctx,"gluLookAt");
  defoglforeign(ctx,"gluProject");
  defoglforeign(ctx,"gluUnProject");
  defoglforeign(ctx,"gluScaleImage");
  defoglforeign(ctx,"gluBuild1DMipmaps");
  defoglforeign(ctx,"gluBuild2DMipmaps");
  defoglforeign(ctx,"gluNewQuadric");
  defoglforeign(ctx,"gluDeleteQuadric");
  defoglforeign(ctx,"gluQuadricNormals");
  defoglforeign(ctx,"gluQuadricTexture");
  defoglforeign(ctx,"gluQuadricOrientation");
  defoglforeign(ctx,"gluQuadricDrawStyle");
  defoglforeign(ctx,"gluCylinder");
  defoglforeign(ctx,"gluDisk");
  defoglforeign(ctx,"gluPartialDisk");
  defoglforeign(ctx,"gluSphere");
  defoglforeign(ctx,"gluQuadricCallback");
  defoglforeign(ctx,"gluNewTess");
  defoglforeign(ctx,"gluTessCallback");
  defoglforeign(ctx,"gluDeleteTess");
  defoglforeign(ctx,"gluBeginPolygon");
  defoglforeign(ctx,"gluEndPolygon");
  defoglforeign(ctx,"gluNextContour");
  defoglforeign(ctx,"gluTessVertex");
  defoglforeign(ctx,"gluNewNurbsRenderer");
  defoglforeign(ctx,"gluDeleteNurbsRenderer");
  defoglforeign(ctx,"gluBeginSurface");
  defoglforeign(ctx,"gluBeginCurve");
  defoglforeign(ctx,"gluEndCurve");
  defoglforeign(ctx,"gluEndSurface");
  defoglforeign(ctx,"gluBeginTrim");
  defoglforeign(ctx,"gluEndTrim");
  defoglforeign(ctx,"gluPwlCurve");
  defoglforeign(ctx,"gluNurbsCurve");
  defoglforeign(ctx,"gluNurbsSurface");
  defoglforeign(ctx,"gluLoadSamplingMatrices");
  defoglforeign(ctx,"gluNurbsProperty");
  defoglforeign(ctx,"gluGetNurbsProperty");
  defoglforeign(ctx,"gluNurbsCallback");
  defoglforeign(ctx,"glXChooseVisual");
  defoglforeign(ctx,"glXCopyContext");
  defoglforeign(ctx,"glXCreateContext");
  defoglforeign(ctx,"glXCreateGLXPixmap");
  defoglforeign(ctx,"glXDestroyContext");
  defoglforeign(ctx,"glXDestroyGLXPixmap");
  defoglforeign(ctx,"glXGetConfig");
  defoglforeign(ctx,"glXGetCurrentContext");
  defoglforeign(ctx,"glXGetCurrentDrawable");
  defoglforeign(ctx,"glXIsDirect");
  defoglforeign(ctx,"glXMakeCurrent");
  defoglforeign(ctx,"glXQueryExtension");
  defoglforeign(ctx,"glXQueryVersion");
  defoglforeign(ctx,"glXSwapBuffers");
  defoglforeign(ctx,"glXUseXFont");
  defoglforeign(ctx,"glXWaitGL");
  defoglforeign(ctx,"glXWaitX");
#if !Cygwin && !Linux /* Cygwin does not have tkInitDisplayMode, etc... */
  /*defoglforeign(ctx,"tkInitDisplay");*/
  defoglforeign(ctx,"tkInitDisplayMode");
  /*defoglforeign(ctx,"tkInitDisplayModePolicy");*/
  /*defoglforeign(ctx,"tkInitDisplayModeID");*/
  defoglforeign(ctx,"tkInitPosition");
  defoglforeign(ctx,"tkInitWindow");
  defoglforeign(ctx,"tkCloseWindow");
  defoglforeign(ctx,"tkQuit");
  defoglforeign(ctx,"tkSetWindowLevel");
  defoglforeign(ctx,"tkSwapBuffers");
  defoglforeign(ctx,"tkExec");
  defoglforeign(ctx,"tkExposeFunc");
  defoglforeign(ctx,"tkReshapeFunc");
  defoglforeign(ctx,"tkDisplayFunc");
  defoglforeign(ctx,"tkKeyDownFunc");
  defoglforeign(ctx,"tkMouseDownFunc");
  defoglforeign(ctx,"tkMouseUpFunc");
  defoglforeign(ctx,"tkMouseMoveFunc");
  defoglforeign(ctx,"tkIdleFunc");
  defoglforeign(ctx,"tkGetColorMapSize");
  defoglforeign(ctx,"tkGetMouseLoc");
  defoglforeign(ctx,"tkGetSystem");
  /*defoglforeign(ctx,"tkGetDisplayModePolicy");*/
  /*defoglforeign(ctx,"tkGetDisplayModeID");*/
  /*defoglforeign(ctx,"tkGetDisplayMode");*/
  /*defoglforeign(ctx,"tkGetContext");*/
  defoglforeign(ctx,"tkSetOneColor");
  defoglforeign(ctx,"tkSetFogRamp");
  defoglforeign(ctx,"tkSetGreyRamp");
  defoglforeign(ctx,"tkSetRGBMap");
  defoglforeign(ctx,"tkSetOverlayMap");
  defoglforeign(ctx,"tkNewCursor");
  defoglforeign(ctx,"tkSetCursor");
  defoglforeign(ctx,"tkRGBImageLoad");
  defoglforeign(ctx,"tkCreateStrokeFont");
  defoglforeign(ctx,"tkCreateOutlineFont");
  defoglforeign(ctx,"tkCreateFilledFont");
  defoglforeign(ctx,"tkCreateBitmapFont");
  defoglforeign(ctx,"tkDrawStr");
  defoglforeign(ctx,"tkWireSphere");
  defoglforeign(ctx,"tkSolidSphere");
  defoglforeign(ctx,"tkWireCube");
  defoglforeign(ctx,"tkSolidCube");
  defoglforeign(ctx,"tkWireBox");
  defoglforeign(ctx,"tkSolidBox");
  defoglforeign(ctx,"tkWireTorus");
  defoglforeign(ctx,"tkSolidTorus");
  defoglforeign(ctx,"tkWireCylinder");
  defoglforeign(ctx,"tkSolidCylinder");
  defoglforeign(ctx,"tkWireCone");
  defoglforeign(ctx,"tkSolidCone");
#endif
/*  defoglforeign(ctx,"auxInitDisplayMode"); */
#ifdef IRIX
  /*defoglforeign(ctx,"auxInitDisplayModePolicy");*/
  /*defoglforeign(ctx,"auxInitDisplayModeID");*/
#endif
/*  defoglforeign(ctx,"auxInitPosition");
  defoglforeign(ctx,"auxInitWindow");
  defoglforeign(ctx,"auxCloseWindow");
  defoglforeign(ctx,"auxQuit");
  defoglforeign(ctx,"auxSwapBuffers");
  defoglforeign(ctx,"auxXDisplay");
  defoglforeign(ctx,"auxXWindow"); */
#ifdef IRIX
  /*defoglforeign(ctx,"auxXScreen");*/
#endif
/*  defoglforeign(ctx,"auxMainLoop");
  defoglforeign(ctx,"auxExposeFunc");
  defoglforeign(ctx,"auxReshapeFunc");
  defoglforeign(ctx,"auxIdleFunc");
  defoglforeign(ctx,"auxKeyFunc");
  defoglforeign(ctx,"auxMouseFunc");
  defoglforeign(ctx,"auxGetColorMapSize");
  defoglforeign(ctx,"auxGetMouseLoc"); */
#ifdef IRIX
  /*defoglforeign(ctx,"auxGetDisplayModePolicy");*/
  /*defoglforeign(ctx,"auxGetDisplayModeID");*/
  /*defoglforeign(ctx,"auxGetDisplayMode");*/
  /*defoglforeign(ctx,"auxGetContext");*/
#endif
/*  defoglforeign(ctx,"auxSetOneColor");
  defoglforeign(ctx,"auxSetFogRamp");
  defoglforeign(ctx,"auxSetGreyRamp");
  defoglforeign(ctx,"auxSetRGBMap");
  defoglforeign(ctx,"auxRGBImageLoad");
  defoglforeign(ctx,"auxCreateFont");
  defoglforeign(ctx,"auxDrawStr");
  defoglforeign(ctx,"auxWireSphere");
  defoglforeign(ctx,"auxSolidSphere");
  defoglforeign(ctx,"auxWireCube");
  defoglforeign(ctx,"auxSolidCube");
  defoglforeign(ctx,"auxWireBox");
  defoglforeign(ctx,"auxSolidBox");
  defoglforeign(ctx,"auxWireTorus");
  defoglforeign(ctx,"auxSolidTorus");
  defoglforeign(ctx,"auxWireCylinder");
  defoglforeign(ctx,"auxSolidCylinder");
  defoglforeign(ctx,"auxWireIcosahedron");
  defoglforeign(ctx,"auxSolidIcosahedron");
  defoglforeign(ctx,"auxWireOctahedron");
  defoglforeign(ctx,"auxSolidOctahedron");
  defoglforeign(ctx,"auxWireTetrahedron");
  defoglforeign(ctx,"auxSolidTetrahedron");
  defoglforeign(ctx,"auxWireDodecahedron");
  defoglforeign(ctx,"auxSolidDodecahedron");
  defoglforeign(ctx,"auxWireCone");
  defoglforeign(ctx,"auxSolidCone");
  defoglforeign(ctx,"auxWireTeapot");
  defoglforeign(ctx,"auxSolidTeapot"); */
  defoglforeign(ctx,"glClearColorfv");
  defoglforeign(ctx,"glOrtho6f");
  defoglforeign(ctx,"glOrthofv");
  defoglforeign(ctx,"glRotatefv");
  defoglforeign(ctx,"glTranslatefv");
/*  defoglforeign(ctx,"auxSolidTeapotfv"); */
  defoglforeign(ctx,"glClipPlanef");
/*  defoglforeign(ctx,"auxSolidSpherefv");
  defoglforeign(ctx,"auxWireSpherefv");
  defoglforeign(ctx,"auxSolidCylinderfv");
  defoglforeign(ctx,"auxSolidConefv");
  defoglforeign(ctx,"auxSolidBoxfv"); */
  defoglforeign(ctx,"gluPerspectivefv");
  defoglforeign(ctx,"gluLookAtfv");
  defoglforeign(ctx,"gluTessCallbackl");
/*  defoglforeign(ctx,"auxSolidTorusfv");
  defoglforeign(ctx,"auxSolidCubefv");
  defoglforeign(ctx,"auxSolidOctahedronfv"); */
  defoglforeign(ctx,"glClearAccumfv");
  defoglforeign(ctx,"glAccumfv");
  defoglforeign(ctx,"gluDiskfv");
  defoglforeign(ctx,"gluPartialDiskfv");
/*  defoglforeign(ctx,"auxWireIcosahedronfv"); */
  defoglforeign(ctx,"glScalefv");
  defoglforeign(ctx,"gluNurbsPropertyfv");
  defoglforeign(ctx,"glMapGrid2fv");
  defoglforeign(ctx,"glBitmapfv");
  defoglforeign(ctx,"glMap1fv");
  defoglforeign(ctx,"glMap2fv");
/*  defoglforeign(ctx,"auxSetOneColorfv"); */
  defoglforeign(ctx,"glFrustumfv");
  defoglforeign(ctx,"gluOrtho2Dfv");
  defoglforeign(ctx,"glPointSizefv");
  defoglforeign(ctx,"glClearIndexfv");
  defoglforeign(ctx,"alloctessinfo");
  defoglforeign(ctx,"tess_vertex_cb");
  defoglforeign(ctx,"glDepthRangefv");
#if (WORD_SIZE == 64)
  defoglforeign(ctx,"glPointSized");
  defoglforeign(ctx,"glLineWidthd");
  defoglforeign(ctx,"gluNurbsPropertyd");
#endif
  /* kanehiro's glu patch 2000.12.13 */
  defoglforeign(ctx,"gluTessBeginContour");
  defoglforeign(ctx,"gluTessEndContour");
  defoglforeign(ctx,"gluTessBeginPolygon");
  defoglforeign(ctx,"gluTessEndPolygon");

#if GL_EXT_texture_object && !Darwin
  defoglforeign(ctx,"glGenTexturesEXT");
  defoglforeign(ctx,"glBindTextureEXT");
#else
  defoglforeign(ctx,"glGenTextures");
  defoglforeign(ctx,"glBindTexture");
#endif
#if 0 /* GL_EXT_polygon_offset */
  defoglforeign(ctx,"glPolygonOffsetEXT");
  defoglforeign(ctx,"glPolygonOffsetEXTfv");
#endif

  return(argv[0]);}

static void init_object_module()
  { add_module_initializer("oglforeign", oglforeign);}
