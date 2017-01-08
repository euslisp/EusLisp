/*
 * $Header$
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include "util.h"

struct tessinfo {
  GLdouble vert[3];
  GLint tp;
  GLdouble tcoord[2];
  GLint np;
  GLdouble ncoord[3];
};

void glClearColorfv(v)
  eusfloat_t v[4];
{
  glClearColor((GLclampf)v[0], (GLclampf)v[1], (GLclampf)v[2], (GLclampf)v[3]);
}

void glOrtho6f(left, right, bottom, top, near, far)
  eusfloat_t left;
  eusfloat_t right;
  eusfloat_t bottom;
  eusfloat_t top;
  eusfloat_t near;
  eusfloat_t far;
{
  glOrtho((GLdouble)left, (GLdouble)right, (GLdouble)bottom, (GLdouble)top,
	  (GLdouble)near, (GLdouble)far);
}

void glOrthofv(v)
  eusfloat_t v[6];
{
  glOrtho((GLdouble)v[0], (GLdouble)v[1], (GLdouble)v[2], (GLdouble)v[3],
	  (GLdouble)v[4], (GLdouble)v[5]);
}

void glRotatefv(v)
  eusfloat_t v[4];
{
  glRotatef((GLfloat)v[0], (GLfloat)v[1], (GLfloat)v[2], (GLfloat)v[3]);
}

void glTranslatefv(v)
  eusfloat_t v[3];
{
  glTranslatef((GLfloat)v[0], (GLfloat)v[1], (GLfloat)v[2]);
}


void glClipPlanef(pl, eqn)
  eusinteger_t pl;
  eusfloat_t eqn[4];
{
  GLdouble d_eqn[4];

  d_eqn[0] = eqn[0];
  d_eqn[1] = eqn[1];
  d_eqn[2] = eqn[2];
  d_eqn[3] = eqn[3];

  glClipPlane((GLenum)pl, d_eqn);
}

void gluPerspectivefv(v)
  eusfloat_t v[4];
{
  gluPerspective((GLdouble)v[0], (GLdouble)v[1],
		 (GLdouble)v[2], (GLdouble)v[3]);
}

void gluLookAtfv(v)
  eusfloat_t v[9];
{
  gluLookAt((GLdouble)v[0], (GLdouble)v[1], (GLdouble)v[2],
	    (GLdouble)v[3], (GLdouble)v[4], (GLdouble)v[5],
	    (GLdouble)v[6], (GLdouble)v[7], (GLdouble)v[8]);
}

void gluTessCallbackl(tobj, which, fn, fn2)
  eusinteger_t *tobj;
  eusinteger_t which;
  eusinteger_t fn;
  eusinteger_t fn2;
{
  eusinteger_t addr = fn << 2;
  if ( fn2 != 0 ) addr = addr | (fn2 & 0x0000ffff);
  gluTessCallback((GLUtriangulatorObj *)tobj, (GLenum)which,
		  (void (*)()) ( addr ));
}

void glClearAccumfv(v)
  eusfloat_t v[4];
{
  glClearAccum((GLfloat)v[0], (GLfloat)v[1], (GLfloat)v[2], (GLfloat)v[3]);
}

void glAccumfv(op, v)
  eusinteger_t op;
  eusfloat_t   v[1];
{
  glAccum((GLenum)op, (GLfloat)v[0]);
}

void gluDiskfv(qobj, v)
  eusinteger_t qobj;
  eusfloat_t   v[4];
{
  gluDisk((GLUquadricObj *)qobj, (GLdouble)v[0], (GLdouble)v[1], 
	  (GLint)v[2], (GLint)v[3]);
}

void gluPartialDiskfv(qobj, v)
  eusinteger_t *qobj;
  eusfloat_t   v[6];
{ 
  gluPartialDisk((GLUquadricObj *)qobj, (GLdouble)v[0], (GLdouble)v[1],
		 (GLint)v[2], (GLint)v[3], (GLdouble)v[4], (GLdouble)v[5]);
}

void glScalefv(v)
  eusfloat_t v[3];
{
  glScalef((GLfloat)v[0], (GLfloat)v[1], (GLfloat)v[2]);
}

void gluNurbsPropertyfv(nobj, property, value)
  eusinteger_t nobj;
  eusinteger_t property;
  eusfloat_t   *value;
{
  gluNurbsProperty((GLUnurbsObj *)nobj, (GLenum)property, (GLfloat)*value);
}

void glMapGrid2fv(v)
  eusfloat_t v[6];
{
  glMapGrid2f((GLint)v[0], (GLfloat)v[1], (GLfloat)v[2],
	      (GLint)v[3], (GLfloat)v[4], (GLfloat)v[5]);
}

void glBitmapfv(w, h, v, b)
  eusinteger_t w;
  eusinteger_t h;
  eusfloat_t   v[4];
  eusinteger_t b;
{
  glBitmap((GLsizei)w, (GLsizei)h,
	   (GLfloat)v[0], (GLfloat)v[1], (GLfloat)v[2], (GLfloat)v[3],
	   (GLubyte *)b);
}

void glMap1fv(target, args, points)
  eusinteger_t target;
  eusfloat_t   args[4];
  eusinteger_t points;
{
  glMap1f((GLenum)target, (GLfloat)args[0], (GLfloat)args[1],
	  (GLint)args[2], (GLint)args[3], (GLfloat *)points);
}

void glMap2fv(target, args, points)
  eusinteger_t target;
  eusfloat_t   args[8];
  eusinteger_t points;
{
  glMap2f((GLenum)target, 
	  (GLfloat)args[0], (GLfloat)args[1], (GLint)args[2], (GLint)args[3], 
	  (GLfloat)args[4], (GLfloat)args[5], (GLint)args[6], (GLint)args[7],
	  (GLfloat *)points);
}

void glFrustumfv(v)
  eusfloat_t v[6];
{
  glFrustum((GLdouble)v[0], (GLdouble)v[1], (GLdouble)v[2],
	    (GLdouble)v[3], (GLdouble)v[4], (GLdouble)v[5]);
}

void gluOrtho2Dfv(v)
  eusfloat_t v[4];
{
  gluOrtho2D((GLdouble)v[0], (GLdouble)v[1], (GLdouble)v[2], (GLdouble)v[3]);
}

void glPointSizefv(v)
  eusfloat_t v[1];
{
  glPointSize((GLfloat)v[0]);
}

void glClearIndexfv(v)
  eusfloat_t v[1];
{
  glClearIndex((GLfloat)v[0]);
}

eusinteger_t alloctessinfo(vert, tp, tcoord, np, ncoord)
  eusfloat_t   vert[3];
  eusinteger_t tp;
  eusfloat_t   tcoord[2];
  eusinteger_t np;
  eusfloat_t   ncoord[2];
{
  struct tessinfo *i;
  int len = sizeof (struct tessinfo);

  if (!(i = (void *) malloc(len))) {
    perror("alloctessinfo: malloc");
    exit(1);
  }

#if 0
  printf("alloctessinfo: received vert: %05.3f %05.3f %05.3f tcoord[%d]: %05.3f %05.3f ncoord[%d]: %05.3f %05.3f  %05.3f\n",
	 vert[0], vert[1], vert[2], 
	 tp, tcoord[0], tcoord[1],
	 np, ncoord[0], ncoord[1], ncoord[2]);
#endif

  bzero(i, len);

  i->vert[0] = (GLdouble)vert[0];
  i->vert[1] = (GLdouble)vert[1];
  i->vert[2] = (GLdouble)vert[2];

  if (i->tp = tp) {
    i->tcoord[0] = (GLdouble)tcoord[0];
    i->tcoord[1] = (GLdouble)tcoord[1];
  }

  if (i->np = np) {
    i->ncoord[0] = (GLdouble)ncoord[0];
    i->ncoord[1] = (GLdouble)ncoord[1];
    i->ncoord[2] = (GLdouble)ncoord[2];
  }

  return (eusinteger_t)i;
}

void tess_vertex_cb(i)
  eusinteger_t i;
{
  glVertex3dv(((struct tessinfo *)i)->vert);
  if (((struct tessinfo *)i)->tp)
    glTexCoord2dv(((struct tessinfo *)i)->tcoord);
}

void glDepthRangefv(clamp)
  eusfloat_t clamp[2];
{
  glDepthRange((GLclampd)clamp[0], (GLclampd)clamp[1]);
}

#if 0 /* GL_EXT_polygon_offset */
void glPolygonOffsetEXTfv(v)
  eusfloat_t v[2];
{
  glPolygonOffsetEXT((GLfloat)v[0], (GLfloat)v[1]);
}
#endif

#if (WORD_SIZE == 64)
void glPointSized (double d) {
  glPointSize((float)d);
}
void glLineWidthd (double d) {
  glLineWidth((float)d);
}
void gluNurbsPropertyd(GLUnurbs* nurb, GLenum property, double value) {
  gluNurbsProperty(nurb, property, (GLfloat)value);
}
#endif
