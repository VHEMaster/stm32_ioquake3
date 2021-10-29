/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/
/*
** QGL.H
*/

#ifndef __QGL_H__
#define __QGL_H__
/*
#ifdef VCMODS_NOSDL
#include <GLES/gl.h>
*/

#ifdef VCMODS_OPENGLES
//#include <GLES/gl.h>
# include "SDL_opengl.h"
# include "OpenGL.h"


#define qglActiveTextureARB glDrv_glActiveTexture
#define qglClientActiveTextureARB glDrv_glClientActiveTexture
#define qglMultiTexCoord2fARB glDrv_glMultiTexCoord2f

extern void (* qglLockArraysEXT) (GLint first, GLsizei count);
extern void (* qglUnlockArraysEXT) (void);

#else
#ifdef USE_LOCAL_HEADERS


# include "SDL_opengl.h"
# include "OpenGL.h"

#define qglActiveTextureARB glDrv_glActiveTexture
#define qglClientActiveTextureARB glDrv_glClientActiveTexture
#define qglMultiTexCoord2fARB glDrv_glMultiTexCoord2f

extern void (* qglLockArraysEXT) (GLint first, GLsizei count);
extern void (* qglUnlockArraysEXT) (void);




#else
#	include <SDL_opengl.h>
#endif

/*
extern void (APIENTRYP qglActiveTextureARB) (GLenum texture);
extern void (APIENTRYP qglClientActiveTextureARB) (GLenum texture);
extern void (APIENTRYP qglMultiTexCoord2fARB) (GLenum target, GLfloat s, GLfloat t);

extern void (APIENTRYP qglLockArraysEXT) (GLint first, GLsizei count);
extern void (APIENTRYP qglUnlockArraysEXT) (void);
*/
#endif


//===========================================================================

#define qglAccum glDrv_glAccum
#define qglAlphaFunc glDrv_glAlphaFunc
#define qglAreTexturesResident glDrv_glAreTexturesResident
#define qglArrayElement glDrv_glArrayElement
#define qglBegin glDrv_glBegin
#define qglBindTexture glDrv_glBindTexture
#define qglBitmap glDrv_glBitmap
#define qglBlendFunc glDrv_glBlendFunc
#define qglCallList glDrv_glCallList
#define qglCallLists glDrv_glCallLists
#ifdef VCMODS_DEPTH
#define qglClear myglClear
#else
#define qglClear glDrv_glClear
#endif
#define qglClearAccum glDrv_glClearAccum
#define qglClearColor glDrv_glClearColor
#ifdef VCMODS_OPENGLES
#define qglClearDepth glDrv_glClearDepth
#else
#define qglClearDepth glDrv_glClearDepth
#endif
#define qglClearIndex glDrv_glClearIndex
#define qglClearStencil glDrv_glClearStencil
#ifdef VCMODS_OPENGLES
#define qglClipPlane glDrv_glClipPlane
#else
#define qglClipPlane glDrv_glClipPlane
#endif
#define qglColor3b glDrv_glColor3b
#define qglColor3bv glDrv_glColor3bv
#define qglColor3d glDrv_glColor3d
#define qglColor3dv glDrv_glColor3dv
#define qglColor3f glDrv_glColor3f
#define qglColor3fv glDrv_glColor3fv
#define qglColor3i glDrv_glColor3i
#define qglColor3iv glDrv_glColor3iv
#define qglColor3s glDrv_glColor3s
#define qglColor3sv glDrv_glColor3sv
#define qglColor3ub glDrv_glColor3ub
#define qglColor3ubv glDrv_glColor3ubv
#define qglColor3ui glDrv_glColor3ui
#define qglColor3uiv glDrv_glColor3uiv
#define qglColor3us glDrv_glColor3us
#define qglColor3usv glDrv_glColor3usv
#define qglColor4b glDrv_glColor4b
#define qglColor4bv glDrv_glColor4bv
#define qglColor4d glDrv_glColor4d
#define qglColor4dv glDrv_glColor4dv
#define qglColor4f glDrv_glColor4f
#define qglColor4fv glDrv_glColor4fv
#define qglColor4i glDrv_glColor4i
#define qglColor4iv glDrv_glColor4iv
#define qglColor4s glDrv_glColor4s
#define qglColor4sv glDrv_glColor4sv
#define qglColor4ub glDrv_glColor4ub
#define qglColor4ubv glDrv_glColor4ubv
#define qglColor4ui glDrv_glColor4ui
#define qglColor4uiv glDrv_glColor4uiv
#define qglColor4us glDrv_glColor4us
#define qglColor4usv glDrv_glColor4usv
#define qglColorMask glDrv_glColorMask
#define qglColorMaterial glDrv_glColorMaterial
#define qglColorPointer glDrv_glColorPointer
#define qglCopyPixels glDrv_glCopyPixels
#define qglCopyTexImage1D glDrv_glCopyTexImage1D
#define qglCopyTexImage2D glDrv_glCopyTexImage2D
#define qglCopyTexSubImage1D glDrv_glCopyTexSubImage1D
#define qglCopyTexSubImage2D glDrv_glCopyTexSubImage2D
#define qglCullFace glDrv_glCullFace
#define qglDeleteLists glDrv_glDeleteLists
#define qglDeleteTextures glDrv_glDeleteTextures
#define qglDepthFunc glDrv_glDepthFunc
#define qglDepthMask glDrv_glDepthMask
#ifdef VCMODS_OPENGLES
#define qglDepthRange glDrv_glDepthRange
#else
#define qglDepthRange glDrv_glDepthRange
#endif
#define qglDisable glDrv_glDisable
#define qglDisableClientState glDrv_glDisableClientState
#define qglDrawArrays glDrv_glDrawArrays
#define qglDrawBuffer glDrv_glDrawBuffer
#define qglDrawElements glDrv_glDrawElements
#define qglDrawPixels glDrv_glDrawPixels
#define qglEdgeFlag glDrv_glEdgeFlag
#define qglEdgeFlagPointer glDrv_glEdgeFlagPointer
#define qglEdgeFlagv glDrv_glEdgeFlagv
#define qglEnable glDrv_glEnable
#define qglEnableClientState glDrv_glEnableClientState
#define qglEnd glDrv_glEnd
#define qglEndList glDrv_glEndList
#define qglEvalCoord1d glDrv_glEvalCoord1d
#define qglEvalCoord1dv glDrv_glEvalCoord1dv
#define qglEvalCoord1f glDrv_glEvalCoord1f
#define qglEvalCoord1fv glDrv_glEvalCoord1fv
#define qglEvalCoord2d glDrv_glEvalCoord2d
#define qglEvalCoord2dv glDrv_glEvalCoord2dv
#define qglEvalCoord2f glDrv_glEvalCoord2f
#define qglEvalCoord2fv glDrv_glEvalCoord2fv
#define qglEvalMesh1 glDrv_glEvalMesh1
#define qglEvalMesh2 glDrv_glEvalMesh2
#define qglEvalPoint1 glDrv_glEvalPoint1
#define qglEvalPoint2 glDrv_glEvalPoint2
#define qglFeedbackBuffer glDrv_glFeedbackBuffer
#define qglFinish glDrv_glFinish
#define qglFlush glDrv_glFlush
#define qglFogf glDrv_glFogf
#define qglFogfv glDrv_glFogfv
#define qglFogi glDrv_glFogi
#define qglFogiv glDrv_glFogiv
#define qglFrontFace glDrv_glFrontFace
#define qglFrustum glDrv_glFrustum
#define qglGenLists glDrv_glGenLists
#define qglGenTextures glDrv_glGenTextures
#define qglGetBooleanv glDrv_glGetBooleanv
#define qglGetClipPlane glDrv_glGetClipPlane
#define qglGetDoublev glDrv_glGetDoublev
#define qglGetError glDrv_glGetError
#define qglGetFloatv glDrv_glGetFloatv
#define qglGetIntegerv glDrv_glGetIntegerv
#define qglGetLightfv glDrv_glGetLightfv
#define qglGetLightiv glDrv_glGetLightiv
#define qglGetMapdv glDrv_glGetMapdv
#define qglGetMapfv glDrv_glGetMapfv
#define qglGetMapiv glDrv_glGetMapiv
#define qglGetMaterialfv glDrv_glGetMaterialfv
#define qglGetMaterialiv glDrv_glGetMaterialiv
#define qglGetPixelMapfv glDrv_glGetPixelMapfv
#define qglGetPixelMapuiv glDrv_glGetPixelMapuiv
#define qglGetPixelMapusv glDrv_glGetPixelMapusv
#define qglGetPointerv glDrv_glGetPointerv
#define qglGetPolygonStipple glDrv_glGetPolygonStipple
#define qglGetString glDrv_glGetString
#define qglGetTexGendv glDrv_glGetTexGendv
#define qglGetTexGenfv glDrv_glGetTexGenfv
#define qglGetTexGeniv glDrv_glGetTexGeniv
#define qglGetTexImage glDrv_glGetTexImage
#define qglGetTexLevelParameterfv glDrv_glGetTexLevelParameterfv
#define qglGetTexLevelParameteriv glDrv_glGetTexLevelParameteriv
#define qglGetTexParameterfv glDrv_glGetTexParameterfv
#define qglGetTexParameteriv glDrv_glGetTexParameteriv
#define qglHint glDrv_glHint
#define qglIndexMask glDrv_glIndexMask
#define qglIndexPointer glDrv_glIndexPointer
#define qglIndexd glDrv_glIndexd
#define qglIndexdv glDrv_glIndexdv
#define qglIndexf glDrv_glIndexf
#define qglIndexfv glDrv_glIndexfv
#define qglIndexi glDrv_glIndexi
#define qglIndexiv glDrv_glIndexiv
#define qglIndexs glDrv_glIndexs
#define qglIndexsv glDrv_glIndexsv
#define qglIndexub glDrv_glIndexub
#define qglIndexubv glDrv_glIndexubv
#define qglInitNames glDrv_glInitNames
#define qglInterleavedArrays glDrv_glInterleavedArrays
#define qglIsEnabled glDrv_glIsEnabled
#define qglIsList glDrv_glIsList
#define qglIsTexture glDrv_glIsTexture
#define qglLightModelf glDrv_glLightModelf
#define qglLightModelfv glDrv_glLightModelfv
#define qglLightModeli glDrv_glLightModeli
#define qglLightModeliv glDrv_glLightModeliv
#define qglLightf glDrv_glLightf
#define qglLightfv glDrv_glLightfv
#define qglLighti glDrv_glLighti
#define qglLightiv glDrv_glLightiv
#define qglLineStipple glDrv_glLineStipple
#define qglLineWidth glDrv_glLineWidth
#define qglListBase glDrv_glListBase
#define qglLoadIdentity glDrv_glLoadIdentity
#define qglLoadMatrixd glDrv_glLoadMatrixd
#define qglLoadMatrixf glDrv_glLoadMatrixf
#define qglLoadName glDrv_glLoadName
#define qglLogicOp glDrv_glLogicOp
#define qglMap1d glDrv_glMap1d
#define qglMap1f glDrv_glMap1f
#define qglMap2d glDrv_glMap2d
#define qglMap2f glDrv_glMap2f
#define qglMapGrid1d glDrv_glMapGrid1d
#define qglMapGrid1f glDrv_glMapGrid1f
#define qglMapGrid2d glDrv_glMapGrid2d
#define qglMapGrid2f glDrv_glMapGrid2f
#define qglMaterialf glDrv_glMaterialf
#define qglMaterialfv glDrv_glMaterialfv
#define qglMateriali glDrv_glMateriali
#define qglMaterialiv glDrv_glMaterialiv
#define qglMatrixMode glDrv_glMatrixMode
#define qglMultMatrixd glDrv_glMultMatrixd
#define qglMultMatrixf glDrv_glMultMatrixf
#define qglNewList glDrv_glNewList
#define qglNormal3b glDrv_glNormal3b
#define qglNormal3bv glDrv_glNormal3bv
#define qglNormal3d glDrv_glNormal3d
#define qglNormal3dv glDrv_glNormal3dv
#define qglNormal3f glDrv_glNormal3f
#define qglNormal3fv glDrv_glNormal3fv
#define qglNormal3i glDrv_glNormal3i
#define qglNormal3iv glDrv_glNormal3iv
#define qglNormal3s glDrv_glNormal3s
#define qglNormal3sv glDrv_glNormal3sv
#define qglNormalPointer glDrv_glNormalPointer
#ifdef VCMODS_OPENGLES
#define qglOrtho glDrv_glOrtho
#else
#define qglOrtho glDrv_glOrtho
#endif
#define qglPassThrough glDrv_glPassThrough
#define qglPixelMapfv glDrv_glPixelMapfv
#define qglPixelMapuiv glDrv_glPixelMapuiv
#define qglPixelMapusv glDrv_glPixelMapusv
#define qglPixelStoref glDrv_glPixelStoref
#define qglPixelStorei glDrv_glPixelStorei
#define qglPixelTransferf glDrv_glPixelTransferf
#define qglPixelTransferi glDrv_glPixelTransferi
#define qglPixelZoom glDrv_glPixelZoom
#define qglPointSize glDrv_glPointSize
#define qglPolygonMode glDrv_glPolygonMode
#define qglPolygonOffset glDrv_glPolygonOffset
#define qglPolygonStipple glDrv_glPolygonStipple
#define qglPopAttrib glDrv_glPopAttrib
#define qglPopClientAttrib glDrv_glPopClientAttrib
#define qglPopMatrix glDrv_glPopMatrix
#define qglPopName glDrv_glPopName
#define qglPrioritizeTextures glDrv_glPrioritizeTextures
#define qglPushAttrib glDrv_glPushAttrib
#define qglPushClientAttrib glDrv_glPushClientAttrib
#define qglPushMatrix glDrv_glPushMatrix
#define qglPushName glDrv_glPushName
#define qglRasterPos2d glDrv_glRasterPos2d
#define qglRasterPos2dv glDrv_glRasterPos2dv
#define qglRasterPos2f glDrv_glRasterPos2f
#define qglRasterPos2fv glDrv_glRasterPos2fv
#define qglRasterPos2i glDrv_glRasterPos2i
#define qglRasterPos2iv glDrv_glRasterPos2iv
#define qglRasterPos2s glDrv_glRasterPos2s
#define qglRasterPos2sv glDrv_glRasterPos2sv
#define qglRasterPos3d glDrv_glRasterPos3d
#define qglRasterPos3dv glDrv_glRasterPos3dv
#define qglRasterPos3f glDrv_glRasterPos3f
#define qglRasterPos3fv glDrv_glRasterPos3fv
#define qglRasterPos3i glDrv_glRasterPos3i
#define qglRasterPos3iv glDrv_glRasterPos3iv
#define qglRasterPos3s glDrv_glRasterPos3s
#define qglRasterPos3sv glDrv_glRasterPos3sv
#define qglRasterPos4d glDrv_glRasterPos4d
#define qglRasterPos4dv glDrv_glRasterPos4dv
#define qglRasterPos4f glDrv_glRasterPos4f
#define qglRasterPos4fv glDrv_glRasterPos4fv
#define qglRasterPos4i glDrv_glRasterPos4i
#define qglRasterPos4iv glDrv_glRasterPos4iv
#define qglRasterPos4s glDrv_glRasterPos4s
#define qglRasterPos4sv glDrv_glRasterPos4sv
#define qglReadBuffer glDrv_glReadBuffer
#define qglReadPixels glDrv_glReadPixels
#define qglRectd glDrv_glRectd
#define qglRectdv glDrv_glRectdv
#define qglRectf glDrv_glRectf
#define qglRectfv glDrv_glRectfv
#define qglRecti glDrv_glRecti
#define qglRectiv glDrv_glRectiv
#define qglRects glDrv_glRects
#define qglRectsv glDrv_glRectsv
#define qglRenderMode glDrv_glRenderMode
#define qglRotated glDrv_glRotated
#define qglRotatef glDrv_glRotatef
#define qglScaled glDrv_glScaled
#define qglScalef glDrv_glScalef
#define qglScissor glDrv_glScissor
#define qglSelectBuffer glDrv_glSelectBuffer
#define qglShadeModel glDrv_glShadeModel
#define qglStencilFunc glDrv_glStencilFunc
#define qglStencilMask glDrv_glStencilMask
#define qglStencilOp glDrv_glStencilOp
#define qglTexCoord1d glDrv_glTexCoord1d
#define qglTexCoord1dv glDrv_glTexCoord1dv
#define qglTexCoord1f glDrv_glTexCoord1f
#define qglTexCoord1fv glDrv_glTexCoord1fv
#define qglTexCoord1i glDrv_glTexCoord1i
#define qglTexCoord1iv glDrv_glTexCoord1iv
#define qglTexCoord1s glDrv_glTexCoord1s
#define qglTexCoord1sv glDrv_glTexCoord1sv
#define qglTexCoord2d glDrv_glTexCoord2d
#define qglTexCoord2dv glDrv_glTexCoord2dv
#define qglTexCoord2f glDrv_glTexCoord2f
#define qglTexCoord2fv glDrv_glTexCoord2fv
#define qglTexCoord2i glDrv_glTexCoord2i
#define qglTexCoord2iv glDrv_glTexCoord2iv
#define qglTexCoord2s glDrv_glTexCoord2s
#define qglTexCoord2sv glDrv_glTexCoord2sv
#define qglTexCoord3d glDrv_glTexCoord3d
#define qglTexCoord3dv glDrv_glTexCoord3dv
#define qglTexCoord3f glDrv_glTexCoord3f
#define qglTexCoord3fv glDrv_glTexCoord3fv
#define qglTexCoord3i glDrv_glTexCoord3i
#define qglTexCoord3iv glDrv_glTexCoord3iv
#define qglTexCoord3s glDrv_glTexCoord3s
#define qglTexCoord3sv glDrv_glTexCoord3sv
#define qglTexCoord4d glDrv_glTexCoord4d
#define qglTexCoord4dv glDrv_glTexCoord4dv
#define qglTexCoord4f glDrv_glTexCoord4f
#define qglTexCoord4fv glDrv_glTexCoord4fv
#define qglTexCoord4i glDrv_glTexCoord4i
#define qglTexCoord4iv glDrv_glTexCoord4iv
#define qglTexCoord4s glDrv_glTexCoord4s
#define qglTexCoord4sv glDrv_glTexCoord4sv
#define qglTexCoordPointer glDrv_glTexCoordPointer
#define qglTexEnvf glDrv_glTexEnvf
#define qglTexEnvfv glDrv_glTexEnvfv
#define qglTexEnvi glDrv_glTexEnvi
#define qglTexEnviv glDrv_glTexEnviv
#define qglTexGend glDrv_glTexGend
#define qglTexGendv glDrv_glTexGendv
#define qglTexGenf glDrv_glTexGenf
#define qglTexGenfv glDrv_glTexGenfv
#define qglTexGeni glDrv_glTexGeni
#define qglTexGeniv glDrv_glTexGeniv
#define qglTexImage1D glDrv_glTexImage1D
#ifdef VCMODS_OPENGLES
#define qglTexImage2D glDrv_glTexImage2D
#else
#define qglTexImage2D glDrv_glTexImage2D
#endif
#define qglTexParameterf glDrv_glTexParameterf
#define qglTexParameterfv glDrv_glTexParameterfv
#define qglTexParameteri glDrv_glTexParameteri
#define qglTexParameteriv glDrv_glTexParameteriv
#define qglTexSubImage1D glDrv_glTexSubImage1D
#define qglTexSubImage2D glDrv_glTexSubImage2D
#define qglTranslated glDrv_glTranslated
#define qglTranslatef glDrv_glTranslatef
#define qglVertex2d glDrv_glVertex2d
#define qglVertex2dv glDrv_glVertex2dv
#define qglVertex2f glDrv_glVertex2f
#define qglVertex2fv glDrv_glVertex2fv
#define qglVertex2i glDrv_glVertex2i
#define qglVertex2iv glDrv_glVertex2iv
#define qglVertex2s glDrv_glVertex2s
#define qglVertex2sv glDrv_glVertex2sv
#define qglVertex3d glDrv_glVertex3d
#define qglVertex3dv glDrv_glVertex3dv
#define qglVertex3f glDrv_glVertex3f
#define qglVertex3fv glDrv_glVertex3fv
#define qglVertex3i glDrv_glVertex3i
#define qglVertex3iv glDrv_glVertex3iv
#define qglVertex3s glDrv_glVertex3s
#define qglVertex3sv glDrv_glVertex3sv
#define qglVertex4d glDrv_glVertex4d
#define qglVertex4dv glDrv_glVertex4dv
#define qglVertex4f glDrv_glVertex4f
#define qglVertex4fv glDrv_glVertex4fv
#define qglVertex4i glDrv_glVertex4i
#define qglVertex4iv glDrv_glVertex4iv
#define qglVertex4s glDrv_glVertex4s
#define qglVertex4sv glDrv_glVertex4sv
#define qglVertexPointer glDrv_glVertexPointer
#define qglViewport glDrv_glViewport

#endif

#ifdef VCMODS_OPENGLES
#ifndef GL_BACK_LEFT
#define GL_BACK_LEFT 0x402
#endif
#ifndef GL_BACK_RIGHT
#define GL_BACK_RIGHT 0x403
#endif
#endif
