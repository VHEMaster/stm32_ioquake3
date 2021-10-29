#ifndef MCC_FUNCTIONS_H_
#define MCC_FUNCTIONS_H_
#include "mcc.h"
#include "OpenGL.h"
#include "Wiggle.h"

typedef enum
{
  MCC_INVALID = 0,
  MCC_glDrv_glAccum = 1000,
  MCC_glDrv_glAlphaFunc,
  MCC_glDrv_glBegin,
  MCC_glDrv_glBitmap,
  MCC_glDrv_glBlendFunc,
  MCC_glDrv_glCallList,
  MCC_glDrv_glCallLists,
  MCC_glDrv_glClear,
  MCC_glDrv_glClearAccum,
  MCC_glDrv_glClearColor,
  MCC_glDrv_glClearDepth,
  MCC_glDrv_glClearIndex,
  MCC_glDrv_glClearStencil,
  MCC_glDrv_glClipPlane,
  MCC_glDrv_glColor3b,
  MCC_glDrv_glColor3bv,
  MCC_glDrv_glColor3d,
  MCC_glDrv_glColor3dv,
  MCC_glDrv_glColor3f,
  MCC_glDrv_glColor3fv,
  MCC_glDrv_glColor3i,
  MCC_glDrv_glColor3iv,
  MCC_glDrv_glColor3s,
  MCC_glDrv_glColor3sv,
  MCC_glDrv_glColor3ub,
  MCC_glDrv_glColor3ubv,
  MCC_glDrv_glColor3ui,
  MCC_glDrv_glColor3uiv,
  MCC_glDrv_glColor3us,
  MCC_glDrv_glColor3usv,
  MCC_glDrv_glColor4b,
  MCC_glDrv_glColor4bv,
  MCC_glDrv_glColor4d,
  MCC_glDrv_glColor4dv,
  MCC_glDrv_glColor4f,
  MCC_glDrv_glColor4fv,
  MCC_glDrv_glColor4i,
  MCC_glDrv_glColor4iv,
  MCC_glDrv_glColor4s,
  MCC_glDrv_glColor4sv,
  MCC_glDrv_glColor4ub,
  MCC_glDrv_glColor4ubv,
  MCC_glDrv_glColor4ui,
  MCC_glDrv_glColor4uiv,
  MCC_glDrv_glColor4us,
  MCC_glDrv_glColor4usv,
  MCC_glDrv_glColorMask,
  MCC_glDrv_glColorMaterial,
  MCC_glDrv_glCopyPixels,
  MCC_glDrv_glCullFace,
  MCC_glDrv_glDeleteLists,
  MCC_glDrv_glDepthFunc,
  MCC_glDrv_glDepthMask,
  MCC_glDrv_glDepthRange,
  MCC_glDrv_glDisable,
  MCC_glDrv_glDrawBuffer,
  MCC_glDrv_glDrawPixels,
  MCC_glDrv_glEdgeFlag,
  MCC_glDrv_glEdgeFlagv,
  MCC_glDrv_glEnable,
  MCC_glDrv_glEnd,
  MCC_glDrv_glEndList,
  MCC_glDrv_glEvalCoord1d,
  MCC_glDrv_glEvalCoord1dv,
  MCC_glDrv_glEvalCoord1f,
  MCC_glDrv_glEvalCoord1fv,
  MCC_glDrv_glEvalCoord2d,
  MCC_glDrv_glEvalCoord2dv,
  MCC_glDrv_glEvalCoord2f,
  MCC_glDrv_glEvalCoord2fv,
  MCC_glDrv_glEvalMesh1,
  MCC_glDrv_glEvalMesh2,
  MCC_glDrv_glEvalPoint1,
  MCC_glDrv_glEvalPoint2,
  MCC_glDrv_glFeedbackBuffer,
  MCC_glDrv_glFinish,
  MCC_glDrv_glFlush,
  MCC_glDrv_glFogf,
  MCC_glDrv_glFogfv,
  MCC_glDrv_glFogi,
  MCC_glDrv_glFogiv,
  MCC_glDrv_glFrontFace,
  MCC_glDrv_glFrustum,
  MCC_glDrv_glGenLists,
  MCC_glDrv_glGetBooleanv,
  MCC_glDrv_glGetClipPlane,
  MCC_glDrv_glGetDoublev,
  MCC_glDrv_glGetError,
  MCC_glDrv_glGetFloatv,
  MCC_glDrv_glGetIntegerv,
  MCC_glDrv_glGetLightfv,
  MCC_glDrv_glGetLightiv,
  MCC_glDrv_glGetMapdv,
  MCC_glDrv_glGetMapfv,
  MCC_glDrv_glGetMapiv,
  MCC_glDrv_glGetMaterialfv,
  MCC_glDrv_glGetMaterialiv,
  MCC_glDrv_glGetPixelMapfv,
  MCC_glDrv_glGetPixelMapuiv,
  MCC_glDrv_glGetPixelMapusv,
  MCC_glDrv_glGetPolygonStipple,
  MCC_glDrv_glGetString,
  MCC_glDrv_glGetTexEnvfv,
  MCC_glDrv_glGetTexEnviv,
  MCC_glDrv_glGetTexGendv,
  MCC_glDrv_glGetTexGenfv,
  MCC_glDrv_glGetTexGeniv,
  MCC_glDrv_glGetTexImage,
  MCC_glDrv_glGetTexLevelParameterfv,
  MCC_glDrv_glGetTexLevelParameteriv,
  MCC_glDrv_glGetTexParameterfv,
  MCC_glDrv_glGetTexParameteriv,
  MCC_glDrv_glHint,
  MCC_glDrv_glIndexMask,
  MCC_glDrv_glIndexd,
  MCC_glDrv_glIndexdv,
  MCC_glDrv_glIndexf,
  MCC_glDrv_glIndexfv,
  MCC_glDrv_glIndexi,
  MCC_glDrv_glIndexiv,
  MCC_glDrv_glIndexs,
  MCC_glDrv_glIndexsv,
  MCC_glDrv_glInitNames,
  MCC_glDrv_glIsEnabled,
  MCC_glDrv_glIsList,
  MCC_glDrv_glLightModelf,
  MCC_glDrv_glLightModelfv,
  MCC_glDrv_glLightModeli,
  MCC_glDrv_glLightModeliv,
  MCC_glDrv_glLightf,
  MCC_glDrv_glLightfv,
  MCC_glDrv_glLighti,
  MCC_glDrv_glLightiv,
  MCC_glDrv_glLineStipple,
  MCC_glDrv_glLineWidth,
  MCC_glDrv_glListBase,
  MCC_glDrv_glLoadIdentity,
  MCC_glDrv_glLoadMatrixd,
  MCC_glDrv_glLoadMatrixf,
  MCC_glDrv_glLoadName,
  MCC_glDrv_glLogicOp,
  MCC_glDrv_glMap1d,
  MCC_glDrv_glMap1f,
  MCC_glDrv_glMap2d,
  MCC_glDrv_glMap2f,
  MCC_glDrv_glMapGrid1d,
  MCC_glDrv_glMapGrid1f,
  MCC_glDrv_glMapGrid2d,
  MCC_glDrv_glMapGrid2f,
  MCC_glDrv_glMaterialf,
  MCC_glDrv_glMaterialfv,
  MCC_glDrv_glMateriali,
  MCC_glDrv_glMaterialiv,
  MCC_glDrv_glMatrixMode,
  MCC_glDrv_glMultMatrixd,
  MCC_glDrv_glMultMatrixf,
  MCC_glDrv_glNewList,
  MCC_glDrv_glNormal3b,
  MCC_glDrv_glNormal3bv,
  MCC_glDrv_glNormal3d,
  MCC_glDrv_glNormal3dv,
  MCC_glDrv_glNormal3f,
  MCC_glDrv_glNormal3fv,
  MCC_glDrv_glNormal3i,
  MCC_glDrv_glNormal3iv,
  MCC_glDrv_glNormal3s,
  MCC_glDrv_glNormal3sv,
  MCC_glDrv_glOrtho,
  MCC_glDrv_glPassThrough,
  MCC_glDrv_glPixelMapfv,
  MCC_glDrv_glPixelMapuiv,
  MCC_glDrv_glPixelMapusv,
  MCC_glDrv_glPixelStoref,
  MCC_glDrv_glPixelStorei,
  MCC_glDrv_glPixelTransferf,
  MCC_glDrv_glPixelTransferi,
  MCC_glDrv_glPixelZoom,
  MCC_glDrv_glPointSize,
  MCC_glDrv_glPolygonMode,
  MCC_glDrv_glPolygonStipple,
  MCC_glDrv_glPopAttrib,
  MCC_glDrv_glPopMatrix,
  MCC_glDrv_glPopName,
  MCC_glDrv_glPushAttrib,
  MCC_glDrv_glPushMatrix,
  MCC_glDrv_glPushName,
  MCC_glDrv_glRasterPos2d,
  MCC_glDrv_glRasterPos2dv,
  MCC_glDrv_glRasterPos2f,
  MCC_glDrv_glRasterPos2fv,
  MCC_glDrv_glRasterPos2i,
  MCC_glDrv_glRasterPos2iv,
  MCC_glDrv_glRasterPos2s,
  MCC_glDrv_glRasterPos2sv,
  MCC_glDrv_glRasterPos3d,
  MCC_glDrv_glRasterPos3dv,
  MCC_glDrv_glRasterPos3f,
  MCC_glDrv_glRasterPos3fv,
  MCC_glDrv_glRasterPos3i,
  MCC_glDrv_glRasterPos3iv,
  MCC_glDrv_glRasterPos3s,
  MCC_glDrv_glRasterPos3sv,
  MCC_glDrv_glRasterPos4d,
  MCC_glDrv_glRasterPos4dv,
  MCC_glDrv_glRasterPos4f,
  MCC_glDrv_glRasterPos4fv,
  MCC_glDrv_glRasterPos4i,
  MCC_glDrv_glRasterPos4iv,
  MCC_glDrv_glRasterPos4s,
  MCC_glDrv_glRasterPos4sv,
  MCC_glDrv_glReadBuffer,
  MCC_glDrv_glReadPixels,
  MCC_glDrv_glRectd,
  MCC_glDrv_glRectdv,
  MCC_glDrv_glRectf,
  MCC_glDrv_glRectfv,
  MCC_glDrv_glRecti,
  MCC_glDrv_glRectiv,
  MCC_glDrv_glRects,
  MCC_glDrv_glRectsv,
  MCC_glDrv_glRenderMode,
  MCC_glDrv_glRotated,
  MCC_glDrv_glRotatef,
  MCC_glDrv_glScaled,
  MCC_glDrv_glScalef,
  MCC_glDrv_glScissor,
  MCC_glDrv_glSelectBuffer,
  MCC_glDrv_glShadeModel,
  MCC_glDrv_glStencilFunc,
  MCC_glDrv_glStencilMask,
  MCC_glDrv_glStencilOp,
  MCC_glDrv_glTexCoord1d,
  MCC_glDrv_glTexCoord1dv,
  MCC_glDrv_glTexCoord1f,
  MCC_glDrv_glTexCoord1fv,
  MCC_glDrv_glTexCoord1i,
  MCC_glDrv_glTexCoord1iv,
  MCC_glDrv_glTexCoord1s,
  MCC_glDrv_glTexCoord1sv,
  MCC_glDrv_glTexCoord2d,
  MCC_glDrv_glTexCoord2dv,
  MCC_glDrv_glTexCoord2f,
  MCC_glDrv_glTexCoord2fv,
  MCC_glDrv_glTexCoord2i,
  MCC_glDrv_glTexCoord2iv,
  MCC_glDrv_glTexCoord2s,
  MCC_glDrv_glTexCoord2sv,
  MCC_glDrv_glTexCoord3d,
  MCC_glDrv_glTexCoord3dv,
  MCC_glDrv_glTexCoord3f,
  MCC_glDrv_glTexCoord3fv,
  MCC_glDrv_glTexCoord3i,
  MCC_glDrv_glTexCoord3iv,
  MCC_glDrv_glTexCoord3s,
  MCC_glDrv_glTexCoord3sv,
  MCC_glDrv_glTexCoord4d,
  MCC_glDrv_glTexCoord4dv,
  MCC_glDrv_glTexCoord4f,
  MCC_glDrv_glTexCoord4fv,
  MCC_glDrv_glTexCoord4i,
  MCC_glDrv_glTexCoord4iv,
  MCC_glDrv_glTexCoord4s,
  MCC_glDrv_glTexCoord4sv,
  MCC_glDrv_glTexEnvf,
  MCC_glDrv_glTexEnvfv,
  MCC_glDrv_glTexEnvi,
  MCC_glDrv_glTexEnviv,
  MCC_glDrv_glTexGend,
  MCC_glDrv_glTexGendv,
  MCC_glDrv_glTexGenf,
  MCC_glDrv_glTexGenfv,
  MCC_glDrv_glTexGeni,
  MCC_glDrv_glTexGeniv,
  MCC_glDrv_glTexImage1D,
  MCC_glDrv_glTexImage2D,
  MCC_glDrv_glTexParameterf,
  MCC_glDrv_glTexParameterfv,
  MCC_glDrv_glTexParameteri,
  MCC_glDrv_glTexParameteriv,
  MCC_glDrv_glTranslated,
  MCC_glDrv_glTranslatef,
  MCC_glDrv_glVertex2d,
  MCC_glDrv_glVertex2dv,
  MCC_glDrv_glVertex2f,
  MCC_glDrv_glVertex2fv,
  MCC_glDrv_glVertex2i,
  MCC_glDrv_glVertex2iv,
  MCC_glDrv_glVertex2s,
  MCC_glDrv_glVertex2sv,
  MCC_glDrv_glVertex3d,
  MCC_glDrv_glVertex3dv,
  MCC_glDrv_glVertex3f,
  MCC_glDrv_glVertex3fv,
  MCC_glDrv_glVertex3i,
  MCC_glDrv_glVertex3iv,
  MCC_glDrv_glVertex3s,
  MCC_glDrv_glVertex3sv,
  MCC_glDrv_glVertex4d,
  MCC_glDrv_glVertex4dv,
  MCC_glDrv_glVertex4f,
  MCC_glDrv_glVertex4fv,
  MCC_glDrv_glVertex4i,
  MCC_glDrv_glVertex4iv,
  MCC_glDrv_glVertex4s,
  MCC_glDrv_glVertex4sv,
  MCC_glDrv_glViewport,
  MCC_glDrv_glAreTexturesResident,
  MCC_glDrv_glArrayElement,
  MCC_glDrv_glBindTexture,
  MCC_glDrv_glColorPointer,
  MCC_glDrv_glCopyTexImage1D,
  MCC_glDrv_glCopyTexImage2D,
  MCC_glDrv_glCopyTexSubImage1D,
  MCC_glDrv_glCopyTexSubImage2D,
  MCC_glDrv_glDeleteTextures,
  MCC_glDrv_glDisableClientState,
  MCC_glDrv_glDrawArrays,
  MCC_glDrv_glDrawElements,
  MCC_glDrv_glEdgeFlagPointer,
  MCC_glDrv_glEnableClientState,
  MCC_glDrv_glGenTextures,
  MCC_glDrv_glGetPointerv,
  MCC_glDrv_glIsTexture,
  MCC_glDrv_glIndexPointer,
  MCC_glDrv_glIndexub,
  MCC_glDrv_glIndexubv,
  MCC_glDrv_glInterleavedArrays,
  MCC_glDrv_glNormalPointer,
  MCC_glDrv_glPolygonOffset,
  MCC_glDrv_glPopClientAttrib,
  MCC_glDrv_glPrioritizeTextures,
  MCC_glDrv_glPushClientAttrib,
  MCC_glDrv_glTexCoordPointer,
  MCC_glDrv_glTexSubImage1D,
  MCC_glDrv_glTexSubImage2D,
  MCC_glDrv_glVertexPointer,
  MCC_glDrv_glDrawRangeElements,
  MCC_glDrv_glTexImage3D,
  MCC_glDrv_glTexSubImage3D,
  MCC_glDrv_glCopyTexSubImage3D,
  MCC_glDrv_glActiveTexture,
  MCC_glDrv_glSampleCoverage,
  MCC_glDrv_glCompressedTexImage3D,
  MCC_glDrv_glCompressedTexImage2D,
  MCC_glDrv_glCompressedTexImage1D,
  MCC_glDrv_glCompressedTexSubImage3D,
  MCC_glDrv_glCompressedTexSubImage2D,
  MCC_glDrv_glCompressedTexSubImage1D,
  MCC_glDrv_glGetCompressedTexImage,
  MCC_glDrv_glClientActiveTexture,
  MCC_glDrv_glMultiTexCoord1d,
  MCC_glDrv_glMultiTexCoord1dv,
  MCC_glDrv_glMultiTexCoord1f,
  MCC_glDrv_glMultiTexCoord1fv,
  MCC_glDrv_glMultiTexCoord1i,
  MCC_glDrv_glMultiTexCoord1iv,
  MCC_glDrv_glMultiTexCoord1s,
  MCC_glDrv_glMultiTexCoord1sv,
  MCC_glDrv_glMultiTexCoord2d,
  MCC_glDrv_glMultiTexCoord2dv,
  MCC_glDrv_glMultiTexCoord2f,
  MCC_glDrv_glMultiTexCoord2fv,
  MCC_glDrv_glMultiTexCoord2i,
  MCC_glDrv_glMultiTexCoord2iv,
  MCC_glDrv_glMultiTexCoord2s,
  MCC_glDrv_glMultiTexCoord2sv,
  MCC_glDrv_glMultiTexCoord3d,
  MCC_glDrv_glMultiTexCoord3dv,
  MCC_glDrv_glMultiTexCoord3f,
  MCC_glDrv_glMultiTexCoord3fv,
  MCC_glDrv_glMultiTexCoord3i,
  MCC_glDrv_glMultiTexCoord3iv,
  MCC_glDrv_glMultiTexCoord3s,
  MCC_glDrv_glMultiTexCoord3sv,
  MCC_glDrv_glMultiTexCoord4d,
  MCC_glDrv_glMultiTexCoord4dv,
  MCC_glDrv_glMultiTexCoord4f,
  MCC_glDrv_glMultiTexCoord4fv,
  MCC_glDrv_glMultiTexCoord4i,
  MCC_glDrv_glMultiTexCoord4iv,
  MCC_glDrv_glMultiTexCoord4s,
  MCC_glDrv_glMultiTexCoord4sv,
  MCC_glDrv_glLoadTransposeMatrixf,
  MCC_glDrv_glLoadTransposeMatrixd,
  MCC_glDrv_glMultTransposeMatrixf,
  MCC_glDrv_glMultTransposeMatrixd,
  MCC_glDrv_glLockArrays,
  MCC_glDrv_glUnlockArrays,
  MCC_glDrv_wglChoosePixelFormat,
  MCC_glDrv_wglCopyContext,
  MCC_glDrv_wglCreateContext,
  MCC_glDrv_wglCreateLayerContext,
  MCC_glDrv_wglDeleteContext,
  MCC_glDrv_wglDescribeLayerPlane,
  MCC_glDrv_wglDescribePixelFormat,
  MCC_glDrv_wglGetCurrentContext,
  MCC_glDrv_wglGetCurrentDC,
  MCC_glDrv_wglGetLayerPaletteEntries,
  MCC_glDrv_wglGetPixelFormat,
  MCC_glDrv_wglGetProcAddress,
  MCC_glDrv_wglMakeCurrent,
  MCC_glDrv_wglRealizeLayerPalette,
  MCC_glDrv_wglSetLayerPaletteEntries,
  MCC_glDrv_wglSetPixelFormat,
  MCC_glDrv_wglShareLists,
  MCC_glDrv_wglSwapBuffers,
  MCC_glDrv_wglSwapLayerBuffers,
  MCC_glDrv_wglUseFontBitmapsA,
  MCC_glDrv_wglUseFontBitmapsW,
  MCC_glDrv_wglUseFontOutlinesA,
  MCC_glDrv_wglUseFontOutlinesW,
  MCC_glDrv_wglSetDeviceGammaRamp,
  MCC_glDrv_wglGetDeviceGammaRamp,
  MCC_glDrv_wglGetExtensionsString,
} MCC_Functions;

typedef struct
{
  GLenum op;
  GLfloat value;
} MCC_glDrv_glAccumArgs;


typedef struct
{
  GLenum func;
  GLclampf ref;
} MCC_glDrv_glAlphaFuncArgs;


typedef struct
{
  GLenum mode;
} MCC_glDrv_glBeginArgs;


typedef struct
{
  GLsizei width;
  GLsizei height;
  GLfloat xOrig;
  GLfloat yOrig;
  GLfloat xMove;
  GLfloat yMove;
  const GLubyte *bitmap;
} MCC_glDrv_glBitmapArgs;


typedef struct
{
  GLenum srcFactor;
  GLenum dstFactor;
} MCC_glDrv_glBlendFuncArgs;


typedef struct
{
  GLuint list;
} MCC_glDrv_glCallListArgs;


typedef struct
{
  GLsizei n;
  GLenum type;
  const GLvoid *lists;
} MCC_glDrv_glCallListsArgs;


typedef struct
{
  GLbitfield mask;
} MCC_glDrv_glClearArgs;


typedef struct
{
  GLfloat red;
  GLfloat green;
  GLfloat blue;
  GLfloat alpha;
} MCC_glDrv_glClearAccumArgs;


typedef struct
{
  GLclampf red;
  GLclampf green;
  GLclampf blue;
  GLclampf alpha;
} MCC_glDrv_glClearColorArgs;


typedef struct
{
  GLclampd depth;
} MCC_glDrv_glClearDepthArgs;


typedef struct
{
  GLfloat c;
} MCC_glDrv_glClearIndexArgs;


typedef struct
{
  GLint s;
} MCC_glDrv_glClearStencilArgs;


typedef struct
{
  GLenum plane;
  const GLdouble *equation;
} MCC_glDrv_glClipPlaneArgs;


typedef struct
{
  GLbyte red;
  GLbyte green;
  GLbyte blue;
} MCC_glDrv_glColor3bArgs;


typedef struct
{
  const GLbyte *v;
} MCC_glDrv_glColor3bvArgs;


typedef struct
{
  GLdouble red;
  GLdouble green;
  GLdouble blue;
} MCC_glDrv_glColor3dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glColor3dvArgs;


typedef struct
{
  GLfloat red;
  GLfloat green;
  GLfloat blue;
} MCC_glDrv_glColor3fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glColor3fvArgs;


typedef struct
{
  GLint red;
  GLint green;
  GLint blue;
} MCC_glDrv_glColor3iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glColor3ivArgs;


typedef struct
{
  GLshort red;
  GLshort green;
  GLshort blue;
} MCC_glDrv_glColor3sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glColor3svArgs;


typedef struct
{
  GLubyte red;
  GLubyte green;
  GLubyte blue;
} MCC_glDrv_glColor3ubArgs;


typedef struct
{
  const GLubyte *v;
} MCC_glDrv_glColor3ubvArgs;


typedef struct
{
  GLuint red;
  GLuint green;
  GLuint blue;
} MCC_glDrv_glColor3uiArgs;


typedef struct
{
  const GLuint *v;
} MCC_glDrv_glColor3uivArgs;


typedef struct
{
  GLushort red;
  GLushort green;
  GLushort blue;
} MCC_glDrv_glColor3usArgs;


typedef struct
{
  const GLushort *v;
} MCC_glDrv_glColor3usvArgs;


typedef struct
{
  GLbyte red;
  GLbyte green;
  GLbyte blue;
  GLbyte alpha;
} MCC_glDrv_glColor4bArgs;


typedef struct
{
  const GLbyte *v;
} MCC_glDrv_glColor4bvArgs;


typedef struct
{
  GLdouble red;
  GLdouble green;
  GLdouble blue;
  GLdouble alpha;
} MCC_glDrv_glColor4dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glColor4dvArgs;


typedef struct
{
  GLfloat red;
  GLfloat green;
  GLfloat blue;
  GLfloat alpha;
} MCC_glDrv_glColor4fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glColor4fvArgs;


typedef struct
{
  GLint red;
  GLint green;
  GLint blue;
  GLint alpha;
} MCC_glDrv_glColor4iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glColor4ivArgs;


typedef struct
{
  GLshort red;
  GLshort green;
  GLshort blue;
  GLshort alpha;
} MCC_glDrv_glColor4sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glColor4svArgs;


typedef struct
{
  GLubyte red;
  GLubyte green;
  GLubyte blue;
  GLubyte alpha;
} MCC_glDrv_glColor4ubArgs;


typedef struct
{
  const GLubyte *v;
} MCC_glDrv_glColor4ubvArgs;


typedef struct
{
  GLuint red;
  GLuint green;
  GLuint blue;
  GLuint alpha;
} MCC_glDrv_glColor4uiArgs;


typedef struct
{
  const GLuint *v;
} MCC_glDrv_glColor4uivArgs;


typedef struct
{
  GLushort red;
  GLushort green;
  GLushort blue;
  GLushort alpha;
} MCC_glDrv_glColor4usArgs;


typedef struct
{
  const GLushort *v;
} MCC_glDrv_glColor4usvArgs;


typedef struct
{
  GLboolean red;
  GLboolean green;
  GLboolean blue;
  GLboolean alpha;
} MCC_glDrv_glColorMaskArgs;


typedef struct
{
  GLenum face;
  GLenum mode;
} MCC_glDrv_glColorMaterialArgs;


typedef struct
{
  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
  GLenum type;
} MCC_glDrv_glCopyPixelsArgs;


typedef struct
{
  GLenum mode;
} MCC_glDrv_glCullFaceArgs;


typedef struct
{
  GLuint list;
  GLsizei range;
} MCC_glDrv_glDeleteListsArgs;


typedef struct
{
  GLenum func;
} MCC_glDrv_glDepthFuncArgs;


typedef struct
{
  GLboolean flag;
} MCC_glDrv_glDepthMaskArgs;


typedef struct
{
  GLclampd zNear;
  GLclampd zFar;
} MCC_glDrv_glDepthRangeArgs;


typedef struct
{
  GLenum cap;
} MCC_glDrv_glDisableArgs;


typedef struct
{
  GLenum mode;
} MCC_glDrv_glDrawBufferArgs;


typedef struct
{
  GLsizei width;
  GLsizei height;
  GLenum format;
  GLenum type;
  const GLvoid *pixels;
} MCC_glDrv_glDrawPixelsArgs;


typedef struct
{
  GLboolean flag;
} MCC_glDrv_glEdgeFlagArgs;


typedef struct
{
  const GLboolean *flag;
} MCC_glDrv_glEdgeFlagvArgs;


typedef struct
{
  GLenum cap;
} MCC_glDrv_glEnableArgs;


typedef struct
{

} MCC_glDrv_glEndArgs;


typedef struct
{

} MCC_glDrv_glEndListArgs;


typedef struct
{
  GLdouble u;
} MCC_glDrv_glEvalCoord1dArgs;


typedef struct
{
  const GLdouble *u;
} MCC_glDrv_glEvalCoord1dvArgs;


typedef struct
{
  GLfloat u;
} MCC_glDrv_glEvalCoord1fArgs;


typedef struct
{
  const GLfloat *u;
} MCC_glDrv_glEvalCoord1fvArgs;


typedef struct
{
  GLdouble u;
  GLdouble v;
} MCC_glDrv_glEvalCoord2dArgs;


typedef struct
{
  const GLdouble *u;
} MCC_glDrv_glEvalCoord2dvArgs;


typedef struct
{
  GLfloat u;
  GLfloat v;
} MCC_glDrv_glEvalCoord2fArgs;


typedef struct
{
  const GLfloat *u;
} MCC_glDrv_glEvalCoord2fvArgs;


typedef struct
{
  GLenum mode;
  GLint i1;
  GLint i2;
} MCC_glDrv_glEvalMesh1Args;


typedef struct
{
  GLenum mode;
  GLint i1;
  GLint i2;
  GLint j1;
  GLint j2;
} MCC_glDrv_glEvalMesh2Args;


typedef struct
{
  GLint i;
} MCC_glDrv_glEvalPoint1Args;


typedef struct
{
  GLint i;
  GLint j;
} MCC_glDrv_glEvalPoint2Args;


typedef struct
{
  GLsizei size;
  GLenum type;
  GLfloat *buffer;
} MCC_glDrv_glFeedbackBufferArgs;


typedef struct
{

} MCC_glDrv_glFinishArgs;


typedef struct
{

} MCC_glDrv_glFlushArgs;


typedef struct
{
  GLenum pname;
  GLfloat param;
} MCC_glDrv_glFogfArgs;


typedef struct
{
  GLenum pname;
  const GLfloat *params;
} MCC_glDrv_glFogfvArgs;


typedef struct
{
  GLenum pname;
  GLint param;
} MCC_glDrv_glFogiArgs;


typedef struct
{
  GLenum pname;
  const GLint *params;
} MCC_glDrv_glFogivArgs;


typedef struct
{
  GLenum mode;
} MCC_glDrv_glFrontFaceArgs;


typedef struct
{
  GLdouble left;
  GLdouble right;
  GLdouble bottom;
  GLdouble top;
  GLdouble zNear;
  GLdouble zFar;
} MCC_glDrv_glFrustumArgs;


typedef struct
{
  GLsizei range;
} MCC_glDrv_glGenListsArgs;


typedef struct
{
  GLenum pname;
  GLboolean *params;
} MCC_glDrv_glGetBooleanvArgs;


typedef struct
{
  GLenum plane;
  GLdouble *equation;
} MCC_glDrv_glGetClipPlaneArgs;


typedef struct
{
  GLenum pname;
  GLdouble *params;
} MCC_glDrv_glGetDoublevArgs;


typedef struct
{

} MCC_glDrv_glGetErrorArgs;


typedef struct
{
  GLenum pname;
  GLfloat *params;
} MCC_glDrv_glGetFloatvArgs;


typedef struct
{
  GLenum pname;
  GLint *params;
} MCC_glDrv_glGetIntegervArgs;


typedef struct
{
  GLenum light;
  GLenum pname;
  GLfloat *params;
} MCC_glDrv_glGetLightfvArgs;


typedef struct
{
  GLenum light;
  GLenum pname;
  GLint *params;
} MCC_glDrv_glGetLightivArgs;


typedef struct
{
  GLenum target;
  GLenum query;
  GLdouble *v;
} MCC_glDrv_glGetMapdvArgs;


typedef struct
{
  GLenum target;
  GLenum query;
  GLfloat *v;
} MCC_glDrv_glGetMapfvArgs;


typedef struct
{
  GLenum target;
  GLenum query;
  GLint *v;
} MCC_glDrv_glGetMapivArgs;


typedef struct
{
  GLenum face;
  GLenum pname;
  GLfloat *params;
} MCC_glDrv_glGetMaterialfvArgs;


typedef struct
{
  GLenum face;
  GLenum pname;
  GLint *params;
} MCC_glDrv_glGetMaterialivArgs;


typedef struct
{
  GLenum map;
  GLfloat *values;
} MCC_glDrv_glGetPixelMapfvArgs;


typedef struct
{
  GLenum map;
  GLuint *values;
} MCC_glDrv_glGetPixelMapuivArgs;


typedef struct
{
  GLenum map;
  GLushort *values;
} MCC_glDrv_glGetPixelMapusvArgs;


typedef struct
{
  GLubyte *mask;
} MCC_glDrv_glGetPolygonStippleArgs;


typedef struct
{
  GLenum name;
} MCC_glDrv_glGetStringArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  GLfloat *params;
} MCC_glDrv_glGetTexEnvfvArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  GLint *params;
} MCC_glDrv_glGetTexEnvivArgs;


typedef struct
{
  GLenum coord;
  GLenum pname;
  GLdouble *params;
} MCC_glDrv_glGetTexGendvArgs;


typedef struct
{
  GLenum coord;
  GLenum pname;
  GLfloat *params;
} MCC_glDrv_glGetTexGenfvArgs;


typedef struct
{
  GLenum coord;
  GLenum pname;
  GLint *params;
} MCC_glDrv_glGetTexGenivArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLenum format;
  GLenum type;
  GLvoid *pixels;
} MCC_glDrv_glGetTexImageArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLenum pname;
  GLfloat *params;
} MCC_glDrv_glGetTexLevelParameterfvArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLenum pname;
  GLint *params;
} MCC_glDrv_glGetTexLevelParameterivArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  GLfloat *params;
} MCC_glDrv_glGetTexParameterfvArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  GLint *params;
} MCC_glDrv_glGetTexParameterivArgs;


typedef struct
{
  GLenum target;
  GLenum mode;
} MCC_glDrv_glHintArgs;


typedef struct
{
  GLuint mask;
} MCC_glDrv_glIndexMaskArgs;


typedef struct
{
  GLdouble c;
} MCC_glDrv_glIndexdArgs;


typedef struct
{
  const GLdouble *c;
} MCC_glDrv_glIndexdvArgs;


typedef struct
{
  GLfloat c;
} MCC_glDrv_glIndexfArgs;


typedef struct
{
  const GLfloat *c;
} MCC_glDrv_glIndexfvArgs;


typedef struct
{
  GLint c;
} MCC_glDrv_glIndexiArgs;


typedef struct
{
  const GLint *c;
} MCC_glDrv_glIndexivArgs;


typedef struct
{
  GLshort c;
} MCC_glDrv_glIndexsArgs;


typedef struct
{
  const GLshort *c;
} MCC_glDrv_glIndexsvArgs;


typedef struct
{

} MCC_glDrv_glInitNamesArgs;


typedef struct
{
  GLenum cap;
} MCC_glDrv_glIsEnabledArgs;


typedef struct
{
  GLuint list;
} MCC_glDrv_glIsListArgs;


typedef struct
{
  GLenum pname;
  GLfloat param;
} MCC_glDrv_glLightModelfArgs;


typedef struct
{
  GLenum pname;
  const GLfloat *params;
} MCC_glDrv_glLightModelfvArgs;


typedef struct
{
  GLenum pname;
  GLint param;
} MCC_glDrv_glLightModeliArgs;


typedef struct
{
  GLenum pname;
  const GLint *params;
} MCC_glDrv_glLightModelivArgs;


typedef struct
{
  GLenum light;
  GLenum pname;
  GLfloat param;
} MCC_glDrv_glLightfArgs;


typedef struct
{
  GLenum light;
  GLenum pname;
  const GLfloat *params;
} MCC_glDrv_glLightfvArgs;


typedef struct
{
  GLenum light;
  GLenum pname;
  GLint param;
} MCC_glDrv_glLightiArgs;


typedef struct
{
  GLenum light;
  GLenum pname;
  const GLint *params;
} MCC_glDrv_glLightivArgs;


typedef struct
{
  GLint factor;
  GLushort pattern;
} MCC_glDrv_glLineStippleArgs;


typedef struct
{
  GLfloat width;
} MCC_glDrv_glLineWidthArgs;


typedef struct
{
  GLuint base;
} MCC_glDrv_glListBaseArgs;


typedef struct
{

} MCC_glDrv_glLoadIdentityArgs;


typedef struct
{
  const GLdouble *m;
} MCC_glDrv_glLoadMatrixdArgs;


typedef struct
{
  const GLfloat *m;
} MCC_glDrv_glLoadMatrixfArgs;


typedef struct
{
  GLuint name;
} MCC_glDrv_glLoadNameArgs;


typedef struct
{
  GLenum opcode;
} MCC_glDrv_glLogicOpArgs;


typedef struct
{
  GLenum target;
  GLdouble u1;
  GLdouble u2;
  GLint stride;
  GLint order;
  const GLdouble *points;
} MCC_glDrv_glMap1dArgs;


typedef struct
{
  GLenum target;
  GLfloat u1;
  GLfloat u2;
  GLint stride;
  GLint order;
  const GLfloat *points;
} MCC_glDrv_glMap1fArgs;


typedef struct
{
  GLenum target;
  GLdouble u1;
  GLdouble u2;
  GLint ustride;
  GLint uorder;
  GLdouble v1;
  GLdouble v2;
  GLint vstride;
  GLint vorder;
  const GLdouble *points;
} MCC_glDrv_glMap2dArgs;


typedef struct
{
  GLenum target;
  GLfloat u1;
  GLfloat u2;
  GLint ustride;
  GLint uorder;
  GLfloat v1;
  GLfloat v2;
  GLint vstride;
  GLint vorder;
  const GLfloat *points;
} MCC_glDrv_glMap2fArgs;


typedef struct
{
  GLint un;
  GLdouble u1;
  GLdouble u2;
} MCC_glDrv_glMapGrid1dArgs;


typedef struct
{
  GLint un;
  GLfloat u1;
  GLfloat u2;
} MCC_glDrv_glMapGrid1fArgs;


typedef struct
{
  GLint un;
  GLdouble u1;
  GLdouble u2;
  GLint vn;
  GLdouble v1;
  GLdouble v2;
} MCC_glDrv_glMapGrid2dArgs;


typedef struct
{
  GLint un;
  GLfloat u1;
  GLfloat u2;
  GLint vn;
  GLfloat v1;
  GLfloat v2;
} MCC_glDrv_glMapGrid2fArgs;


typedef struct
{
  GLenum face;
  GLenum pname;
  GLfloat param;
} MCC_glDrv_glMaterialfArgs;


typedef struct
{
  GLenum face;
  GLenum pname;
  const GLfloat *params;
} MCC_glDrv_glMaterialfvArgs;


typedef struct
{
  GLenum face;
  GLenum pname;
  GLint param;
} MCC_glDrv_glMaterialiArgs;


typedef struct
{
  GLenum face;
  GLenum pname;
  const GLint *params;
} MCC_glDrv_glMaterialivArgs;


typedef struct
{
  GLenum mode;
} MCC_glDrv_glMatrixModeArgs;


typedef struct
{
  const GLdouble *m;
} MCC_glDrv_glMultMatrixdArgs;


typedef struct
{
  const GLfloat *m;
} MCC_glDrv_glMultMatrixfArgs;


typedef struct
{
  GLuint list;
  GLenum mode;
} MCC_glDrv_glNewListArgs;


typedef struct
{
  GLbyte nx;
  GLbyte ny;
  GLbyte nz;
} MCC_glDrv_glNormal3bArgs;


typedef struct
{
  const GLbyte *v;
} MCC_glDrv_glNormal3bvArgs;


typedef struct
{
  GLdouble nx;
  GLdouble ny;
  GLdouble nz;
} MCC_glDrv_glNormal3dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glNormal3dvArgs;


typedef struct
{
  GLfloat nx;
  GLfloat ny;
  GLfloat nz;
} MCC_glDrv_glNormal3fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glNormal3fvArgs;


typedef struct
{
  GLint nx;
  GLint ny;
  GLint nz;
} MCC_glDrv_glNormal3iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glNormal3ivArgs;


typedef struct
{
  GLshort nx;
  GLshort ny;
  GLshort nz;
} MCC_glDrv_glNormal3sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glNormal3svArgs;


typedef struct
{
  GLdouble left;
  GLdouble right;
  GLdouble bottom;
  GLdouble top;
  GLdouble zNear;
  GLdouble zFar;
} MCC_glDrv_glOrthoArgs;


typedef struct
{
  GLfloat token;
} MCC_glDrv_glPassThroughArgs;


typedef struct
{
  GLenum map;
  GLsizei mapsize;
  const GLfloat *values;
} MCC_glDrv_glPixelMapfvArgs;


typedef struct
{
  GLenum map;
  GLsizei mapsize;
  const GLuint *values;
} MCC_glDrv_glPixelMapuivArgs;


typedef struct
{
  GLenum map;
  GLsizei mapsize;
  const GLushort *values;
} MCC_glDrv_glPixelMapusvArgs;


typedef struct
{
  GLenum pname;
  GLfloat param;
} MCC_glDrv_glPixelStorefArgs;


typedef struct
{
  GLenum pname;
  GLint param;
} MCC_glDrv_glPixelStoreiArgs;


typedef struct
{
  GLenum pname;
  GLfloat param;
} MCC_glDrv_glPixelTransferfArgs;


typedef struct
{
  GLenum pname;
  GLint param;
} MCC_glDrv_glPixelTransferiArgs;


typedef struct
{
  GLfloat xfactor;
  GLfloat yfactor;
} MCC_glDrv_glPixelZoomArgs;


typedef struct
{
  GLfloat size;
} MCC_glDrv_glPointSizeArgs;


typedef struct
{
  GLenum face;
  GLenum mode;
} MCC_glDrv_glPolygonModeArgs;


typedef struct
{
  const GLubyte *mask;
} MCC_glDrv_glPolygonStippleArgs;


typedef struct
{

} MCC_glDrv_glPopAttribArgs;


typedef struct
{

} MCC_glDrv_glPopMatrixArgs;


typedef struct
{

} MCC_glDrv_glPopNameArgs;


typedef struct
{
  GLbitfield mask;
} MCC_glDrv_glPushAttribArgs;


typedef struct
{

} MCC_glDrv_glPushMatrixArgs;


typedef struct
{
  GLuint name;
} MCC_glDrv_glPushNameArgs;


typedef struct
{
  GLdouble x;
  GLdouble y;
} MCC_glDrv_glRasterPos2dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glRasterPos2dvArgs;


typedef struct
{
  GLfloat x;
  GLfloat y;
} MCC_glDrv_glRasterPos2fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glRasterPos2fvArgs;


typedef struct
{
  GLint x;
  GLint y;
} MCC_glDrv_glRasterPos2iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glRasterPos2ivArgs;


typedef struct
{
  GLshort x;
  GLshort y;
} MCC_glDrv_glRasterPos2sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glRasterPos2svArgs;


typedef struct
{
  GLdouble x;
  GLdouble y;
  GLdouble z;
} MCC_glDrv_glRasterPos3dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glRasterPos3dvArgs;


typedef struct
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
} MCC_glDrv_glRasterPos3fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glRasterPos3fvArgs;


typedef struct
{
  GLint x;
  GLint y;
  GLint z;
} MCC_glDrv_glRasterPos3iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glRasterPos3ivArgs;


typedef struct
{
  GLshort x;
  GLshort y;
  GLshort z;
} MCC_glDrv_glRasterPos3sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glRasterPos3svArgs;


typedef struct
{
  GLdouble x;
  GLdouble y;
  GLdouble z;
  GLdouble w;
} MCC_glDrv_glRasterPos4dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glRasterPos4dvArgs;


typedef struct
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
  GLfloat w;
} MCC_glDrv_glRasterPos4fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glRasterPos4fvArgs;


typedef struct
{
  GLint x;
  GLint y;
  GLint z;
  GLint w;
} MCC_glDrv_glRasterPos4iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glRasterPos4ivArgs;


typedef struct
{
  GLshort x;
  GLshort y;
  GLshort z;
  GLshort w;
} MCC_glDrv_glRasterPos4sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glRasterPos4svArgs;


typedef struct
{
  GLenum mode;
} MCC_glDrv_glReadBufferArgs;


typedef struct
{
  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
  GLenum format;
  GLenum type;
  GLvoid *pixels;
} MCC_glDrv_glReadPixelsArgs;


typedef struct
{
  GLdouble x1;
  GLdouble y1;
  GLdouble x2;
  GLdouble y2;
} MCC_glDrv_glRectdArgs;


typedef struct
{
  const GLdouble *v1;
  const GLdouble *v2;
} MCC_glDrv_glRectdvArgs;


typedef struct
{
  GLfloat x1;
  GLfloat y1;
  GLfloat x2;
  GLfloat y2;
} MCC_glDrv_glRectfArgs;


typedef struct
{
  const GLfloat *v1;
  const GLfloat *v2;
} MCC_glDrv_glRectfvArgs;


typedef struct
{
  GLint x1;
  GLint y1;
  GLint x2;
  GLint y2;
} MCC_glDrv_glRectiArgs;


typedef struct
{
  const GLint *v1;
  const GLint *v2;
} MCC_glDrv_glRectivArgs;


typedef struct
{
  GLshort x1;
  GLshort y1;
  GLshort x2;
  GLshort y2;
} MCC_glDrv_glRectsArgs;


typedef struct
{
  const GLshort *v1;
  const GLshort *v2;
} MCC_glDrv_glRectsvArgs;


typedef struct
{
  GLenum mode;
} MCC_glDrv_glRenderModeArgs;


typedef struct
{
  GLdouble angle;
  GLdouble x;
  GLdouble y;
  GLdouble z;
} MCC_glDrv_glRotatedArgs;


typedef struct
{
  GLfloat angle;
  GLfloat x;
  GLfloat y;
  GLfloat z;
} MCC_glDrv_glRotatefArgs;


typedef struct
{
  GLdouble x;
  GLdouble y;
  GLdouble z;
} MCC_glDrv_glScaledArgs;


typedef struct
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
} MCC_glDrv_glScalefArgs;


typedef struct
{
  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
} MCC_glDrv_glScissorArgs;


typedef struct
{
  GLsizei size;
  GLuint *buffer;
} MCC_glDrv_glSelectBufferArgs;


typedef struct
{
  GLenum mode;
} MCC_glDrv_glShadeModelArgs;


typedef struct
{
  GLenum func;
  GLint ref;
  GLuint mask;
} MCC_glDrv_glStencilFuncArgs;


typedef struct
{
  GLuint mask;
} MCC_glDrv_glStencilMaskArgs;


typedef struct
{
  GLenum fail;
  GLenum zfail;
  GLenum zpass;
} MCC_glDrv_glStencilOpArgs;


typedef struct
{
  GLdouble s;
} MCC_glDrv_glTexCoord1dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glTexCoord1dvArgs;


typedef struct
{
  GLfloat s;
} MCC_glDrv_glTexCoord1fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glTexCoord1fvArgs;


typedef struct
{
  GLint s;
} MCC_glDrv_glTexCoord1iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glTexCoord1ivArgs;


typedef struct
{
  GLshort s;
} MCC_glDrv_glTexCoord1sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glTexCoord1svArgs;


typedef struct
{
  GLdouble s;
  GLdouble t;
} MCC_glDrv_glTexCoord2dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glTexCoord2dvArgs;


typedef struct
{
  GLfloat s;
  GLfloat t;
} MCC_glDrv_glTexCoord2fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glTexCoord2fvArgs;


typedef struct
{
  GLint s;
  GLint t;
} MCC_glDrv_glTexCoord2iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glTexCoord2ivArgs;


typedef struct
{
  GLshort s;
  GLshort t;
} MCC_glDrv_glTexCoord2sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glTexCoord2svArgs;


typedef struct
{
  GLdouble s;
  GLdouble t;
  GLdouble r;
} MCC_glDrv_glTexCoord3dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glTexCoord3dvArgs;


typedef struct
{
  GLfloat s;
  GLfloat t;
  GLfloat r;
} MCC_glDrv_glTexCoord3fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glTexCoord3fvArgs;


typedef struct
{
  GLint s;
  GLint t;
  GLint r;
} MCC_glDrv_glTexCoord3iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glTexCoord3ivArgs;


typedef struct
{
  GLshort s;
  GLshort t;
  GLshort r;
} MCC_glDrv_glTexCoord3sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glTexCoord3svArgs;


typedef struct
{
  GLdouble s;
  GLdouble t;
  GLdouble r;
  GLdouble q;
} MCC_glDrv_glTexCoord4dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glTexCoord4dvArgs;


typedef struct
{
  GLfloat s;
  GLfloat t;
  GLfloat r;
  GLfloat q;
} MCC_glDrv_glTexCoord4fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glTexCoord4fvArgs;


typedef struct
{
  GLint s;
  GLint t;
  GLint r;
  GLint q;
} MCC_glDrv_glTexCoord4iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glTexCoord4ivArgs;


typedef struct
{
  GLshort s;
  GLshort t;
  GLshort r;
  GLshort q;
} MCC_glDrv_glTexCoord4sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glTexCoord4svArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  GLfloat param;
} MCC_glDrv_glTexEnvfArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  const GLfloat *params;
} MCC_glDrv_glTexEnvfvArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  GLint param;
} MCC_glDrv_glTexEnviArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  const GLint *params;
} MCC_glDrv_glTexEnvivArgs;


typedef struct
{
  GLenum coord;
  GLenum pname;
  GLdouble param;
} MCC_glDrv_glTexGendArgs;


typedef struct
{
  GLenum coord;
  GLenum pname;
  const GLdouble *params;
} MCC_glDrv_glTexGendvArgs;


typedef struct
{
  GLenum coord;
  GLenum pname;
  GLfloat param;
} MCC_glDrv_glTexGenfArgs;


typedef struct
{
  GLenum coord;
  GLenum pname;
  const GLfloat *params;
} MCC_glDrv_glTexGenfvArgs;


typedef struct
{
  GLenum coord;
  GLenum pname;
  GLint param;
} MCC_glDrv_glTexGeniArgs;


typedef struct
{
  GLenum coord;
  GLenum pname;
  const GLint *params;
} MCC_glDrv_glTexGenivArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint internalformat;
  GLsizei width;
  GLint border;
  GLenum format;
  GLenum type;
  const GLvoid *pixels;
} MCC_glDrv_glTexImage1DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint internalformat;
  GLsizei width;
  GLsizei height;
  GLint border;
  GLenum format;
  GLenum type;
  const GLvoid *pixels;
} MCC_glDrv_glTexImage2DArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  GLfloat param;
} MCC_glDrv_glTexParameterfArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  const GLfloat *params;
} MCC_glDrv_glTexParameterfvArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  GLint param;
} MCC_glDrv_glTexParameteriArgs;


typedef struct
{
  GLenum target;
  GLenum pname;
  const GLint *params;
} MCC_glDrv_glTexParameterivArgs;


typedef struct
{
  GLdouble x;
  GLdouble y;
  GLdouble z;
} MCC_glDrv_glTranslatedArgs;


typedef struct
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
} MCC_glDrv_glTranslatefArgs;


typedef struct
{
  GLdouble x;
  GLdouble y;
} MCC_glDrv_glVertex2dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glVertex2dvArgs;


typedef struct
{
  GLfloat x;
  GLfloat y;
} MCC_glDrv_glVertex2fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glVertex2fvArgs;


typedef struct
{
  GLint x;
  GLint y;
} MCC_glDrv_glVertex2iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glVertex2ivArgs;


typedef struct
{
  GLshort x;
  GLshort y;
} MCC_glDrv_glVertex2sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glVertex2svArgs;


typedef struct
{
  GLdouble x;
  GLdouble y;
  GLdouble z;
} MCC_glDrv_glVertex3dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glVertex3dvArgs;


typedef struct
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
} MCC_glDrv_glVertex3fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glVertex3fvArgs;


typedef struct
{
  GLint x;
  GLint y;
  GLint z;
} MCC_glDrv_glVertex3iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glVertex3ivArgs;


typedef struct
{
  GLshort x;
  GLshort y;
  GLshort z;
} MCC_glDrv_glVertex3sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glVertex3svArgs;


typedef struct
{
  GLdouble x;
  GLdouble y;
  GLdouble z;
  GLdouble w;
} MCC_glDrv_glVertex4dArgs;


typedef struct
{
  const GLdouble *v;
} MCC_glDrv_glVertex4dvArgs;


typedef struct
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
  GLfloat w;
} MCC_glDrv_glVertex4fArgs;


typedef struct
{
  const GLfloat *v;
} MCC_glDrv_glVertex4fvArgs;


typedef struct
{
  GLint x;
  GLint y;
  GLint z;
  GLint w;
} MCC_glDrv_glVertex4iArgs;


typedef struct
{
  const GLint *v;
} MCC_glDrv_glVertex4ivArgs;


typedef struct
{
  GLshort x;
  GLshort y;
  GLshort z;
  GLshort w;
} MCC_glDrv_glVertex4sArgs;


typedef struct
{
  const GLshort *v;
} MCC_glDrv_glVertex4svArgs;


typedef struct
{
  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
} MCC_glDrv_glViewportArgs;


typedef struct
{
  GLsizei n;
  const GLuint *textures;
  GLboolean *residences;
} MCC_glDrv_glAreTexturesResidentArgs;


typedef struct
{
  GLint i;
} MCC_glDrv_glArrayElementArgs;


typedef struct
{
  GLenum target;
  GLuint texture;
} MCC_glDrv_glBindTextureArgs;


typedef struct
{
  GLint size;
  GLenum type;
  GLsizei stride;
  const GLvoid *pointer;
} MCC_glDrv_glColorPointerArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLenum internalFormat;
  GLint x;
  GLint y;
  GLsizei width;
  GLint border;
} MCC_glDrv_glCopyTexImage1DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLenum internalFormat;
  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
  GLint border;
} MCC_glDrv_glCopyTexImage2DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint xoffset;
  GLint x;
  GLint y;
  GLsizei width;
} MCC_glDrv_glCopyTexSubImage1DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint xoffset;
  GLint yoffset;
  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
} MCC_glDrv_glCopyTexSubImage2DArgs;


typedef struct
{
  GLsizei n;
  const GLuint *textures;
} MCC_glDrv_glDeleteTexturesArgs;


typedef struct
{
  GLenum cap;
} MCC_glDrv_glDisableClientStateArgs;


typedef struct
{
  GLenum mode;
  GLint first;
  GLsizei count;
} MCC_glDrv_glDrawArraysArgs;


typedef struct
{
  GLenum mode;
  GLsizei count;
  GLenum type;
  const GLvoid *indices;
} MCC_glDrv_glDrawElementsArgs;


typedef struct
{
  GLsizei stride;
  const GLvoid *pointer;
} MCC_glDrv_glEdgeFlagPointerArgs;


typedef struct
{
  GLenum cap;
} MCC_glDrv_glEnableClientStateArgs;


typedef struct
{
  GLsizei n;
  GLuint *textures;
} MCC_glDrv_glGenTexturesArgs;


typedef struct
{
  GLenum pname;
  GLvoid **params;
} MCC_glDrv_glGetPointervArgs;


typedef struct
{
  GLuint texture;
} MCC_glDrv_glIsTextureArgs;


typedef struct
{
  GLenum type;
  GLsizei stride;
  const GLvoid *pointer;
} MCC_glDrv_glIndexPointerArgs;


typedef struct
{
  GLubyte c;
} MCC_glDrv_glIndexubArgs;


typedef struct
{
  const GLubyte *c;
} MCC_glDrv_glIndexubvArgs;


typedef struct
{
  GLenum format;
  GLsizei stride;
  const GLvoid *pointer;
} MCC_glDrv_glInterleavedArraysArgs;


typedef struct
{
  GLenum type;
  GLsizei stride;
  const GLvoid *pointer;
} MCC_glDrv_glNormalPointerArgs;


typedef struct
{
  GLfloat factor;
  GLfloat units;
} MCC_glDrv_glPolygonOffsetArgs;


typedef struct
{

} MCC_glDrv_glPopClientAttribArgs;


typedef struct
{
  GLsizei n;
  const GLuint *textures;
  const GLclampf *priorities;
} MCC_glDrv_glPrioritizeTexturesArgs;


typedef struct
{
  GLbitfield mask;
} MCC_glDrv_glPushClientAttribArgs;


typedef struct
{
  GLint size;
  GLenum type;
  GLsizei stride;
  const GLvoid *pointer;
} MCC_glDrv_glTexCoordPointerArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint xoffset;
  GLsizei width;
  GLenum format;
  GLenum type;
  const GLvoid *pixels;
} MCC_glDrv_glTexSubImage1DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint xoffset;
  GLint yoffset;
  GLsizei width;
  GLsizei height;
  GLenum format;
  GLenum type;
  const GLvoid *pixels;
} MCC_glDrv_glTexSubImage2DArgs;


typedef struct
{
  GLint size;
  GLenum type;
  GLsizei stride;
  const GLvoid *pointer;
} MCC_glDrv_glVertexPointerArgs;


typedef struct
{
  GLenum mode;
  GLuint start;
  GLuint end;
  GLsizei count;
  GLenum type;
  const GLvoid *indices;
} MCC_glDrv_glDrawRangeElementsArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint internalFormat;
  GLsizei width;
  GLsizei height;
  GLsizei depth;
  GLint border;
  GLenum format;
  GLenum type;
  const GLvoid *data;
} MCC_glDrv_glTexImage3DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint xoffset;
  GLint yoffset;
  GLint zoffset;
  GLsizei width;
  GLsizei height;
  GLsizei depth;
  GLenum format;
  GLenum type;
  const GLvoid *pixels;
} MCC_glDrv_glTexSubImage3DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint xoffset;
  GLint yoffset;
  GLint zoffset;
  GLint x;
  GLint y;
  GLsizei width;
  GLsizei height;
} MCC_glDrv_glCopyTexSubImage3DArgs;


typedef struct
{
  GLenum texture;
} MCC_glDrv_glActiveTextureArgs;


typedef struct
{
  GLfloat value;
  GLboolean invert;
} MCC_glDrv_glSampleCoverageArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLenum internalformat;
  GLsizei width;
  GLsizei height;
  GLsizei depth;
  GLint border;
  GLsizei imageSize;
  const GLvoid *data;
} MCC_glDrv_glCompressedTexImage3DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLenum internalformat;
  GLsizei width;
  GLsizei height;
  GLint border;
  GLsizei imageSize;
  const GLvoid *data;
} MCC_glDrv_glCompressedTexImage2DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLenum internalformat;
  GLsizei width;
  GLint border;
  GLsizei imageSize;
  const GLvoid *data;
} MCC_glDrv_glCompressedTexImage1DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint xoffset;
  GLint yoffset;
  GLint zoffset;
  GLsizei width;
  GLsizei height;
  GLsizei depth;
  GLenum format;
  GLsizei imageSize;
  const GLvoid *data;
} MCC_glDrv_glCompressedTexSubImage3DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint xoffset;
  GLint yoffset;
  GLsizei width;
  GLsizei height;
  GLenum format;
  GLsizei imageSize;
  const GLvoid *data;
} MCC_glDrv_glCompressedTexSubImage2DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLint xoffset;
  GLsizei width;
  GLenum format;
  GLsizei imageSize;
  const GLvoid *data;
} MCC_glDrv_glCompressedTexSubImage1DArgs;


typedef struct
{
  GLenum target;
  GLint level;
  GLvoid *pixels;
} MCC_glDrv_glGetCompressedTexImageArgs;


typedef struct
{
  GLenum texture;
} MCC_glDrv_glClientActiveTextureArgs;


typedef struct
{
  GLenum target;
  GLdouble s;
} MCC_glDrv_glMultiTexCoord1dArgs;


typedef struct
{
  GLenum target;
  const GLdouble *v;
} MCC_glDrv_glMultiTexCoord1dvArgs;


typedef struct
{
  GLenum target;
  GLfloat s;
} MCC_glDrv_glMultiTexCoord1fArgs;


typedef struct
{
  GLenum target;
  const GLfloat *v;
} MCC_glDrv_glMultiTexCoord1fvArgs;


typedef struct
{
  GLenum target;
  GLint s;
} MCC_glDrv_glMultiTexCoord1iArgs;


typedef struct
{
  GLenum target;
  const GLint *v;
} MCC_glDrv_glMultiTexCoord1ivArgs;


typedef struct
{
  GLenum target;
  GLshort s;
} MCC_glDrv_glMultiTexCoord1sArgs;


typedef struct
{
  GLenum target;
  const GLshort *v;
} MCC_glDrv_glMultiTexCoord1svArgs;


typedef struct
{
  GLenum target;
  GLdouble s;
  GLdouble t;
} MCC_glDrv_glMultiTexCoord2dArgs;


typedef struct
{
  GLenum target;
  const GLdouble *v;
} MCC_glDrv_glMultiTexCoord2dvArgs;


typedef struct
{
  GLenum target;
  GLfloat s;
  GLfloat t;
} MCC_glDrv_glMultiTexCoord2fArgs;


typedef struct
{
  GLenum target;
  const GLfloat *v;
} MCC_glDrv_glMultiTexCoord2fvArgs;


typedef struct
{
  GLenum target;
  GLint s;
  GLint t;
} MCC_glDrv_glMultiTexCoord2iArgs;


typedef struct
{
  GLenum target;
  const GLint *v;
} MCC_glDrv_glMultiTexCoord2ivArgs;


typedef struct
{
  GLenum target;
  GLshort s;
  GLshort t;
} MCC_glDrv_glMultiTexCoord2sArgs;


typedef struct
{
  GLenum target;
  const GLshort *v;
} MCC_glDrv_glMultiTexCoord2svArgs;


typedef struct
{
  GLenum target;
  GLdouble s;
  GLdouble t;
  GLdouble r;
} MCC_glDrv_glMultiTexCoord3dArgs;


typedef struct
{
  GLenum target;
  const GLdouble *v;
} MCC_glDrv_glMultiTexCoord3dvArgs;


typedef struct
{
  GLenum target;
  GLfloat s;
  GLfloat t;
  GLfloat r;
} MCC_glDrv_glMultiTexCoord3fArgs;


typedef struct
{
  GLenum target;
  const GLfloat *v;
} MCC_glDrv_glMultiTexCoord3fvArgs;


typedef struct
{
  GLenum target;
  GLint s;
  GLint t;
  GLint r;
} MCC_glDrv_glMultiTexCoord3iArgs;


typedef struct
{
  GLenum target;
  const GLint *v;
} MCC_glDrv_glMultiTexCoord3ivArgs;


typedef struct
{
  GLenum target;
  GLshort s;
  GLshort t;
  GLshort r;
} MCC_glDrv_glMultiTexCoord3sArgs;


typedef struct
{
  GLenum target;
  const GLshort *v;
} MCC_glDrv_glMultiTexCoord3svArgs;


typedef struct
{
  GLenum target;
  GLdouble s;
  GLdouble t;
  GLdouble r;
  GLdouble q;
} MCC_glDrv_glMultiTexCoord4dArgs;


typedef struct
{
  GLenum target;
  const GLdouble *v;
} MCC_glDrv_glMultiTexCoord4dvArgs;


typedef struct
{
  GLenum target;
  GLfloat s;
  GLfloat t;
  GLfloat r;
  GLfloat q;
} MCC_glDrv_glMultiTexCoord4fArgs;


typedef struct
{
  GLenum target;
  const GLfloat *v;
} MCC_glDrv_glMultiTexCoord4fvArgs;


typedef struct
{
  GLenum target;
  GLint s;
  GLint t;
  GLint r;
  GLint q;
} MCC_glDrv_glMultiTexCoord4iArgs;


typedef struct
{
  GLenum target;
  const GLint *v;
} MCC_glDrv_glMultiTexCoord4ivArgs;


typedef struct
{
  GLenum target;
  GLshort s;
  GLshort t;
  GLshort r;
  GLshort q;
} MCC_glDrv_glMultiTexCoord4sArgs;


typedef struct
{
  GLenum target;
  const GLshort *v;
} MCC_glDrv_glMultiTexCoord4svArgs;


typedef struct
{
  const GLfloat *m;
} MCC_glDrv_glLoadTransposeMatrixfArgs;


typedef struct
{
  const GLdouble *m;
} MCC_glDrv_glLoadTransposeMatrixdArgs;


typedef struct
{
  const GLfloat *m;
} MCC_glDrv_glMultTransposeMatrixfArgs;


typedef struct
{
  const GLdouble *m;
} MCC_glDrv_glMultTransposeMatrixdArgs;


typedef struct
{
  GLint first;
  GLsizei count;
} MCC_glDrv_glLockArraysArgs;


typedef struct
{

} MCC_glDrv_glUnlockArraysArgs;


typedef struct
{
  HDC hdc;
  const PIXELFORMATDESCRIPTOR *ppfd;
} MCC_glDrv_wglChoosePixelFormatArgs;

typedef struct
{
  HGLRC hglrc;
  HGLRC hglrc2;
  UINT i;
} MCC_glDrv_wglCopyContextArgs;

typedef struct
{
  HDC hdc;
} MCC_glDrv_wglCreateContextArgs;

typedef struct
{
  HDC hdc;
  int iLayerPlane;
} MCC_glDrv_wglCreateLayerContextArgs;

typedef struct
{
  HGLRC hglrc;
} MCC_glDrv_wglDeleteContextArgs;

typedef struct
{
  HDC hdc;
  int iPixelFormat;
  int iLayerPlane;
  UINT nBytes;
  LPLAYERPLANEDESCRIPTOR plpd;
} MCC_glDrv_wglDescribeLayerPlaneArgs;

typedef struct
{
  HDC hdc;
  int iPixelFormat;
  UINT nBytes;
  LPPIXELFORMATDESCRIPTOR ppfd;
} MCC_glDrv_wglDescribePixelFormatArgs;

typedef struct
{

} MCC_glDrv_wglGetCurrentContextArgs;

typedef struct
{

} MCC_glDrv_wglGetCurrentDCArgs;

typedef struct
{
  HDC hdc;
  int iLayerPlane;
  int iStart;
  int cEntries;
  COLORREF *pcr;
} MCC_glDrv_wglGetLayerPaletteEntriesArgs;

typedef struct
{
  HDC hdc;
} MCC_glDrv_wglGetPixelFormatArgs;

typedef struct
{
  LPCSTR s;
} MCC_glDrv_wglGetProcAddressArgs;

typedef struct
{
  HDC hdc;
  HGLRC hglrc;
} MCC_glDrv_wglMakeCurrentArgs;

typedef struct
{
  HDC hdc;
  int iLayerPlane;
  GLboolean b;
} MCC_glDrv_wglRealizeLayerPaletteArgs;

typedef struct
{
  HDC hdc;
  int iLayerPlane;
  int iStart;
  int cEntries;
  const COLORREF *pcr;
} MCC_glDrv_wglSetLayerPaletteEntriesArgs;

typedef struct
{
  HDC hdc;
  int format;
  const PIXELFORMATDESCRIPTOR *ppfd;
} MCC_glDrv_wglSetPixelFormatArgs;

typedef struct
{
  HGLRC hglrc;
  HGLRC hglrc2;
} MCC_glDrv_wglShareListsArgs;

typedef struct
{
  HDC hdc;
} MCC_glDrv_wglSwapBuffersArgs;

typedef struct
{
  HDC hdc;
  UINT planes;
} MCC_glDrv_wglSwapLayerBuffersArgs;

typedef struct
{
  HDC hdc;
  DWORD dw1;
  DWORD dw2;
  DWORD dw3;
} MCC_glDrv_wglUseFontBitmapsAArgs;

typedef struct
{
  HDC hdc;
  DWORD dw1;
  DWORD dw2;
  DWORD dw3;
} MCC_glDrv_wglUseFontBitmapsWArgs;

typedef struct
{
  HDC hdc;
  DWORD dw1;
  DWORD dw2;
  DWORD dw3;
  FLOAT f1;
  FLOAT f2;
  int i;
  LPGLYPHMETRICSFLOAT pgmf;
} MCC_glDrv_wglUseFontOutlinesAArgs;

typedef struct
{
  HDC hdc;
  DWORD dw1;
  DWORD dw2;
  DWORD dw3;
  FLOAT f1;
  FLOAT f2;
  int i;
  LPGLYPHMETRICSFLOAT pgmf;
} MCC_glDrv_wglUseFontOutlinesWArgs;

typedef struct
{
  HDC hdc;
  LPVOID lpRamp;
} MCC_glDrv_wglSetDeviceGammaRampArgs;

typedef struct
{
  HDC hdc;
  LPVOID lpRamp;
} MCC_glDrv_wglGetDeviceGammaRampArgs;

typedef struct
{
  HDC hdc;
} MCC_glDrv_wglGetExtensionsStringArgs;



extern void MCC_HandleOpenGL(void);



#endif /* MCC_FUNCTIONS_H_ */
