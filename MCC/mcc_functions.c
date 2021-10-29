#include "mcc_functions.h"

#define MCC_TIMEOUT 5000

#ifdef CORE_CM4

SWGLAPI void STDCALL glDrv_glAccum(GLenum op, GLfloat value)
{
  MCC_glDrv_glAccumArgs arguments = { op, value };
  MCC_Send(MCC_glDrv_glAccum, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glAlphaFunc(GLenum func, GLclampf ref)
{
  MCC_glDrv_glAlphaFuncArgs arguments = { func, ref };
  MCC_Send(MCC_glDrv_glAlphaFunc, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glBegin(GLenum mode)
{
  MCC_glDrv_glBeginArgs arguments = { mode };
  MCC_Send(MCC_glDrv_glBegin, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glBitmap(GLsizei width, GLsizei height, GLfloat xOrig, GLfloat yOrig, GLfloat xMove, GLfloat yMove, const GLubyte *bitmap)
{
  MCC_glDrv_glBitmapArgs arguments = { width, height, xOrig, yOrig, xMove, yMove, bitmap };
  MCC_Send(MCC_glDrv_glBitmap, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glBlendFunc(GLenum srcFactor, GLenum dstFactor)
{
  MCC_glDrv_glBlendFuncArgs arguments = { srcFactor, dstFactor };
  MCC_Send(MCC_glDrv_glBlendFunc, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glCallList(GLuint list)
{
  MCC_glDrv_glCallListArgs arguments = { list };
  MCC_Send(MCC_glDrv_glCallList, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glCallLists(GLsizei n, GLenum type, const GLvoid *lists)
{
  MCC_glDrv_glCallListsArgs arguments = { n, type, lists };
  MCC_Send(MCC_glDrv_glCallLists, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glClear(GLbitfield mask)
{
  MCC_glDrv_glClearArgs arguments = { mask };
  MCC_Send(MCC_glDrv_glClear, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
  MCC_glDrv_glClearAccumArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glClearAccum, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
  MCC_glDrv_glClearColorArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glClearColor, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glClearDepth(GLclampd depth)
{
  MCC_glDrv_glClearDepthArgs arguments = { depth };
  MCC_Send(MCC_glDrv_glClearDepth, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glClearIndex(GLfloat c)
{
  MCC_glDrv_glClearIndexArgs arguments = { c };
  MCC_Send(MCC_glDrv_glClearIndex, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glClearStencil(GLint s)
{
  MCC_glDrv_glClearStencilArgs arguments = { s };
  MCC_Send(MCC_glDrv_glClearStencil, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glClipPlane(GLenum plane, const GLdouble *equation)
{
  MCC_glDrv_glClipPlaneArgs arguments = { plane, equation };
  MCC_Send(MCC_glDrv_glClipPlane, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glColor3b(GLbyte red, GLbyte green, GLbyte blue)
{
  MCC_glDrv_glColor3bArgs arguments = { red, green, blue };
  MCC_Send(MCC_glDrv_glColor3b, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3bv(const GLbyte *v)
{
  MCC_glDrv_glColor3bArgs arguments = { v[0], v[1], v[2] };
  MCC_Send(MCC_glDrv_glColor3b, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3d(GLdouble red, GLdouble green, GLdouble blue)
{
  MCC_glDrv_glColor3dArgs arguments = { red, green, blue };
  MCC_Send(MCC_glDrv_glColor3d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3dv(const GLdouble *v)
{
  MCC_glDrv_glColor3dArgs arguments = { v[0], v[1], v[2] };
  MCC_Send(MCC_glDrv_glColor3d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
  MCC_glDrv_glColor3fArgs arguments = { red, green, blue };
  MCC_Send(MCC_glDrv_glColor3f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3fv(const GLfloat *v)
{
  MCC_glDrv_glColor3fArgs arguments = { v[0], v[1], v[2] };
  MCC_Send(MCC_glDrv_glColor3f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3i(GLint red, GLint green, GLint blue)
{
  MCC_glDrv_glColor3iArgs arguments = { red, green, blue };
  MCC_Send(MCC_glDrv_glColor3i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3iv(const GLint *v)
{
  MCC_glDrv_glColor3iArgs arguments = { v[0], v[1], v[2] };
  MCC_Send(MCC_glDrv_glColor3i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3s(GLshort red, GLshort green, GLshort blue)
{
  MCC_glDrv_glColor3sArgs arguments = { red, green, blue };
  MCC_Send(MCC_glDrv_glColor3s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3sv(const GLshort *v)
{
  MCC_glDrv_glColor3sArgs arguments = { v[0], v[1], v[2] };
  MCC_Send(MCC_glDrv_glColor3s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
  MCC_glDrv_glColor3ubArgs arguments = { red, green, blue };
  MCC_Send(MCC_glDrv_glColor3ub, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3ubv(const GLubyte *v)
{
  MCC_glDrv_glColor3ubArgs arguments = { v[0], v[1], v[2] };
  MCC_Send(MCC_glDrv_glColor3ub, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3ui(GLuint red, GLuint green, GLuint blue)
{
  MCC_glDrv_glColor3uiArgs arguments = { red, green, blue };
  MCC_Send(MCC_glDrv_glColor3ui, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3uiv(const GLuint *v)
{
  MCC_glDrv_glColor3uiArgs arguments = { v[0], v[1], v[2] };
  MCC_Send(MCC_glDrv_glColor3ui, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3us(GLushort red, GLushort green, GLushort blue)
{
  MCC_glDrv_glColor3usArgs arguments = { red, green, blue };
  MCC_Send(MCC_glDrv_glColor3us, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor3usv(const GLushort *v)
{
  MCC_glDrv_glColor3usArgs arguments = { v[0], v[1], v[2] };
  MCC_Send(MCC_glDrv_glColor3us, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha)
{
  MCC_glDrv_glColor4bArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glColor4b, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4bv(const GLbyte *v)
{
  MCC_glDrv_glColor4bArgs arguments = { v[0], v[1], v[2], v[3] };
  MCC_Send(MCC_glDrv_glColor4b, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha)
{
  MCC_glDrv_glColor4dArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glColor4d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4dv(const GLdouble *v)
{
  MCC_glDrv_glColor4dArgs arguments = { v[0], v[1], v[2], v[3] };
  MCC_Send(MCC_glDrv_glColor4d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
  MCC_glDrv_glColor4fArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glColor4f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4fv(const GLfloat *v)
{
  MCC_glDrv_glColor4fArgs arguments = { v[0], v[1], v[2], v[3] };
  MCC_Send(MCC_glDrv_glColor4f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4i(GLint red, GLint green, GLint blue, GLint alpha)
{
  MCC_glDrv_glColor4iArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glColor4i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4iv(const GLint *v)
{
  MCC_glDrv_glColor4iArgs arguments = { v[0], v[1], v[2], v[3] };
  MCC_Send(MCC_glDrv_glColor4i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha)
{
  MCC_glDrv_glColor4sArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glColor4s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4sv(const GLshort *v)
{
  MCC_glDrv_glColor4sArgs arguments = { v[0], v[1], v[2], v[3] };
  MCC_Send(MCC_glDrv_glColor4s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
  MCC_glDrv_glColor4ubArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glColor4ub, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4ubv(const GLubyte *v)
{
  MCC_glDrv_glColor4ubArgs arguments = { v[0], v[1], v[2], v[3] };
  MCC_Send(MCC_glDrv_glColor4ub, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha)
{
  MCC_glDrv_glColor4uiArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glColor4ui, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4uiv(const GLuint *v)
{
  MCC_glDrv_glColor4uiArgs arguments = { v[0], v[1], v[2], v[3] };
  MCC_Send(MCC_glDrv_glColor4ui, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha)
{
  MCC_glDrv_glColor4usArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glColor4us, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColor4usv(const GLushort *v)
{
  MCC_glDrv_glColor4usArgs arguments = { v[0], v[1], v[2], v[3] };
  MCC_Send(MCC_glDrv_glColor4us, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
  MCC_glDrv_glColorMaskArgs arguments = { red, green, blue, alpha };
  MCC_Send(MCC_glDrv_glColorMask, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColorMaterial(GLenum face, GLenum mode)
{
  MCC_glDrv_glColorMaterialArgs arguments = { face, mode };
  MCC_Send(MCC_glDrv_glColorMaterial, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type)
{
  MCC_glDrv_glCopyPixelsArgs arguments = { x, y, width, height, type };
  MCC_Send(MCC_glDrv_glCopyPixels, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glCullFace(GLenum mode)
{
  MCC_glDrv_glCullFaceArgs arguments = { mode };
  MCC_Send(MCC_glDrv_glCullFace, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDeleteLists(GLuint list, GLsizei range)
{
  MCC_glDrv_glDeleteListsArgs arguments = { list, range };
  MCC_Send(MCC_glDrv_glDeleteLists, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDepthFunc(GLenum func)
{
  MCC_glDrv_glDepthFuncArgs arguments = { func };
  MCC_Send(MCC_glDrv_glDepthFunc, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDepthMask(GLboolean flag)
{
  MCC_glDrv_glDepthMaskArgs arguments = { flag };
  MCC_Send(MCC_glDrv_glDepthMask, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDepthRange(GLclampd zNear, GLclampd zFar)
{
  MCC_glDrv_glDepthRangeArgs arguments = { zNear, zFar };
  MCC_Send(MCC_glDrv_glDepthRange, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDisable(GLenum cap)
{
  MCC_glDrv_glDisableArgs arguments = { cap };
  MCC_Send(MCC_glDrv_glDisable, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDrawBuffer(GLenum mode)
{
  MCC_glDrv_glDrawBufferArgs arguments = { mode };
  MCC_Send(MCC_glDrv_glDrawBuffer, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
  MCC_glDrv_glDrawPixelsArgs arguments = { width, height, format, type, pixels };
  MCC_Send(MCC_glDrv_glDrawPixels, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glEdgeFlag(GLboolean flag)
{
  MCC_glDrv_glEdgeFlagArgs arguments = { flag };
  MCC_Send(MCC_glDrv_glEdgeFlag, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEdgeFlagv(const GLboolean *flag)
{
  MCC_glDrv_glEdgeFlagvArgs arguments = { flag };
  MCC_Send(MCC_glDrv_glEdgeFlagv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glEnable(GLenum cap)
{
  MCC_glDrv_glEnableArgs arguments = { cap };
  MCC_Send(MCC_glDrv_glEnable, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEnd(void)
{
  MCC_glDrv_glEndArgs arguments = {  };
  MCC_Send(MCC_glDrv_glEnd, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEndList(void)
{
  MCC_glDrv_glEndListArgs arguments = {  };
  MCC_Send(MCC_glDrv_glEndList, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEvalCoord1d(GLdouble u)
{
  MCC_glDrv_glEvalCoord1dArgs arguments = { u };
  MCC_Send(MCC_glDrv_glEvalCoord1d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEvalCoord1dv(const GLdouble *u)
{
  MCC_glDrv_glEvalCoord1dvArgs arguments = { u };
  MCC_Send(MCC_glDrv_glEvalCoord1dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glEvalCoord1f(GLfloat u)
{
  MCC_glDrv_glEvalCoord1fArgs arguments = { u };
  MCC_Send(MCC_glDrv_glEvalCoord1f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEvalCoord1fv(const GLfloat *u)
{
  MCC_glDrv_glEvalCoord1fvArgs arguments = { u };
  MCC_Send(MCC_glDrv_glEvalCoord1fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glEvalCoord2d(GLdouble u, GLdouble v)
{
  MCC_glDrv_glEvalCoord2dArgs arguments = { u, v };
  MCC_Send(MCC_glDrv_glEvalCoord2d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEvalCoord2dv(const GLdouble *u)
{
  MCC_glDrv_glEvalCoord2dvArgs arguments = { u };
  MCC_Send(MCC_glDrv_glEvalCoord2dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glEvalCoord2f(GLfloat u, GLfloat v)
{
  MCC_glDrv_glEvalCoord2fArgs arguments = { u, v };
  MCC_Send(MCC_glDrv_glEvalCoord2f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEvalCoord2fv(const GLfloat *u)
{
  MCC_glDrv_glEvalCoord2fvArgs arguments = { u };
  MCC_Send(MCC_glDrv_glEvalCoord2fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glEvalMesh1(GLenum mode, GLint i1, GLint i2)
{
  MCC_glDrv_glEvalMesh1Args arguments = { mode, i1, i2 };
  MCC_Send(MCC_glDrv_glEvalMesh1, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2)
{
  MCC_glDrv_glEvalMesh2Args arguments = { mode, i1, i2, j1, j2 };
  MCC_Send(MCC_glDrv_glEvalMesh2, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEvalPoint1(GLint i)
{
  MCC_glDrv_glEvalPoint1Args arguments = { i };
  MCC_Send(MCC_glDrv_glEvalPoint1, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glEvalPoint2(GLint i, GLint j)
{
  MCC_glDrv_glEvalPoint2Args arguments = { i, j };
  MCC_Send(MCC_glDrv_glEvalPoint2, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer)
{
  MCC_glDrv_glFeedbackBufferArgs arguments = { size, type, buffer };
  MCC_Send(MCC_glDrv_glFeedbackBuffer, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glFinish(void)
{
  MCC_glDrv_glFinishArgs arguments = {  };
  MCC_Send(MCC_glDrv_glFinish, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glFlush(void)
{
  MCC_glDrv_glFlushArgs arguments = {  };
  MCC_Send(MCC_glDrv_glFlush, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glFogf(GLenum pname, GLfloat param)
{
  MCC_glDrv_glFogfArgs arguments = { pname, param };
  MCC_Send(MCC_glDrv_glFogf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glFogfv(GLenum pname, const GLfloat *params)
{
  MCC_glDrv_glFogfvArgs arguments = { pname, params };
  MCC_Send(MCC_glDrv_glFogfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glFogi(GLenum pname, GLint param)
{
  MCC_glDrv_glFogiArgs arguments = { pname, param };
  MCC_Send(MCC_glDrv_glFogi, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glFogiv(GLenum pname, const GLint *params)
{
  MCC_glDrv_glFogivArgs arguments = { pname, params };
  MCC_Send(MCC_glDrv_glFogiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glFrontFace(GLenum mode)
{
  MCC_glDrv_glFrontFaceArgs arguments = { mode };
  MCC_Send(MCC_glDrv_glFrontFace, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
  MCC_glDrv_glFrustumArgs arguments = { left, right, bottom, top, zNear, zFar };
  MCC_Send(MCC_glDrv_glFrustum, &arguments, sizeof(arguments));
}

SWGLAPI GLuint STDCALL glDrv_glGenLists(GLsizei range)
{
  MCC_glDrv_glGenListsArgs arguments = { range };
  MCC_Send(MCC_glDrv_glGenLists, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLuint)((int)MCC_GetReturnPointer());
}

SWGLAPI void STDCALL glDrv_glGetBooleanv(GLenum pname, GLboolean *params)
{
  MCC_glDrv_glGetBooleanvArgs arguments = { pname, params };
  MCC_Send(MCC_glDrv_glGetBooleanv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetClipPlane(GLenum plane, GLdouble *equation)
{
  MCC_glDrv_glGetClipPlaneArgs arguments = { plane, equation };
  MCC_Send(MCC_glDrv_glGetClipPlane, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetDoublev(GLenum pname, GLdouble *params)
{
  MCC_glDrv_glGetDoublevArgs arguments = { pname, params };
  MCC_Send(MCC_glDrv_glGetDoublev, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI GLenum STDCALL glDrv_glGetError(void)
{
  MCC_glDrv_glGetErrorArgs arguments = {  };
  MCC_Send(MCC_glDrv_glGetError, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLenum)((int)MCC_GetReturnPointer());
}

SWGLAPI void STDCALL glDrv_glGetFloatv(GLenum pname, GLfloat *params)
{
  MCC_glDrv_glGetFloatvArgs arguments = { pname, params };
  MCC_Send(MCC_glDrv_glGetFloatv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetIntegerv(GLenum pname, GLint *params)
{
  MCC_glDrv_glGetIntegervArgs arguments = { pname, params };
  MCC_Send(MCC_glDrv_glGetIntegerv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetLightfv(GLenum light, GLenum pname, GLfloat *params)
{
  MCC_glDrv_glGetLightfvArgs arguments = { light, pname, params };
  MCC_Send(MCC_glDrv_glGetLightfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetLightiv(GLenum light, GLenum pname, GLint *params)
{
  MCC_glDrv_glGetLightivArgs arguments = { light, pname, params };
  MCC_Send(MCC_glDrv_glGetLightiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetMapdv(GLenum target, GLenum query, GLdouble *v)
{
  MCC_glDrv_glGetMapdvArgs arguments = { target, query, v };
  MCC_Send(MCC_glDrv_glGetMapdv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetMapfv(GLenum target, GLenum query, GLfloat *v)
{
  MCC_glDrv_glGetMapfvArgs arguments = { target, query, v };
  MCC_Send(MCC_glDrv_glGetMapfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetMapiv(GLenum target, GLenum query, GLint *v)
{
  MCC_glDrv_glGetMapivArgs arguments = { target, query, v };
  MCC_Send(MCC_glDrv_glGetMapiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params)
{
  MCC_glDrv_glGetMaterialfvArgs arguments = { face, pname, params };
  MCC_Send(MCC_glDrv_glGetMaterialfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetMaterialiv(GLenum face, GLenum pname, GLint *params)
{
  MCC_glDrv_glGetMaterialivArgs arguments = { face, pname, params };
  MCC_Send(MCC_glDrv_glGetMaterialiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetPixelMapfv(GLenum map, GLfloat *values)
{
  MCC_glDrv_glGetPixelMapfvArgs arguments = { map, values };
  MCC_Send(MCC_glDrv_glGetPixelMapfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetPixelMapuiv(GLenum map, GLuint *values)
{
  MCC_glDrv_glGetPixelMapuivArgs arguments = { map, values };
  MCC_Send(MCC_glDrv_glGetPixelMapuiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetPixelMapusv(GLenum map, GLushort *values)
{
  MCC_glDrv_glGetPixelMapusvArgs arguments = { map, values };
  MCC_Send(MCC_glDrv_glGetPixelMapusv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetPolygonStipple(GLubyte *mask)
{
  MCC_glDrv_glGetPolygonStippleArgs arguments = { mask };
  MCC_Send(MCC_glDrv_glGetPolygonStipple, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI const GLubyte * STDCALL glDrv_glGetString(GLenum name)
{
  MCC_glDrv_glGetStringArgs arguments = { name };
  MCC_Send(MCC_glDrv_glGetString, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (const GLubyte *)((int)MCC_GetReturnPointer());
}

SWGLAPI void STDCALL glDrv_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params)
{
  MCC_glDrv_glGetTexEnvfvArgs arguments = { target, pname, params };
  MCC_Send(MCC_glDrv_glGetTexEnvfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetTexEnviv(GLenum target, GLenum pname, GLint *params)
{
  MCC_glDrv_glGetTexEnvivArgs arguments = { target, pname, params };
  MCC_Send(MCC_glDrv_glGetTexEnviv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params)
{
  MCC_glDrv_glGetTexGendvArgs arguments = { coord, pname, params };
  MCC_Send(MCC_glDrv_glGetTexGendv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params)
{
  MCC_glDrv_glGetTexGenfvArgs arguments = { coord, pname, params };
  MCC_Send(MCC_glDrv_glGetTexGenfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetTexGeniv(GLenum coord, GLenum pname, GLint *params)
{
  MCC_glDrv_glGetTexGenivArgs arguments = { coord, pname, params };
  MCC_Send(MCC_glDrv_glGetTexGeniv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
{
  MCC_glDrv_glGetTexImageArgs arguments = { target, level, format, type, pixels };
  MCC_Send(MCC_glDrv_glGetTexImage, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params)
{
  MCC_glDrv_glGetTexLevelParameterfvArgs arguments = { target, level, pname, params };
  MCC_Send(MCC_glDrv_glGetTexLevelParameterfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params)
{
  MCC_glDrv_glGetTexLevelParameterivArgs arguments = { target, level, pname, params };
  MCC_Send(MCC_glDrv_glGetTexLevelParameteriv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
  MCC_glDrv_glGetTexParameterfvArgs arguments = { target, pname, params };
  MCC_Send(MCC_glDrv_glGetTexParameterfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
  MCC_glDrv_glGetTexParameterivArgs arguments = { target, pname, params };
  MCC_Send(MCC_glDrv_glGetTexParameteriv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glHint(GLenum target, GLenum mode)
{
  MCC_glDrv_glHintArgs arguments = { target, mode };
  MCC_Send(MCC_glDrv_glHint, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glIndexMask(GLuint mask)
{
  MCC_glDrv_glIndexMaskArgs arguments = { mask };
  MCC_Send(MCC_glDrv_glIndexMask, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glIndexd(GLdouble c)
{
  MCC_glDrv_glIndexdArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexd, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glIndexdv(const GLdouble *c)
{
  MCC_glDrv_glIndexdvArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexdv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glIndexf(GLfloat c)
{
  MCC_glDrv_glIndexfArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glIndexfv(const GLfloat *c)
{
  MCC_glDrv_glIndexfvArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glIndexi(GLint c)
{
  MCC_glDrv_glIndexiArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexi, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glIndexiv(const GLint *c)
{
  MCC_glDrv_glIndexivArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glIndexs(GLshort c)
{
  MCC_glDrv_glIndexsArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexs, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glIndexsv(const GLshort *c)
{
  MCC_glDrv_glIndexsvArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexsv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glInitNames(void)
{
  MCC_glDrv_glInitNamesArgs arguments = {  };
  MCC_Send(MCC_glDrv_glInitNames, &arguments, sizeof(arguments));
}

SWGLAPI GLboolean STDCALL glDrv_glIsEnabled(GLenum cap)
{
  MCC_glDrv_glIsEnabledArgs arguments = { cap };
  MCC_Send(MCC_glDrv_glIsEnabled, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_glIsList(GLuint list)
{
  MCC_glDrv_glIsListArgs arguments = { list };
  MCC_Send(MCC_glDrv_glIsList, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI void STDCALL glDrv_glLightModelf(GLenum pname, GLfloat param)
{
  MCC_glDrv_glLightModelfArgs arguments = { pname, param };
  MCC_Send(MCC_glDrv_glLightModelf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glLightModelfv(GLenum pname, const GLfloat *params)
{
  MCC_glDrv_glLightModelfvArgs arguments = { pname, params };
  MCC_Send(MCC_glDrv_glLightModelfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glLightModeli(GLenum pname, GLint param)
{
  MCC_glDrv_glLightModeliArgs arguments = { pname, param };
  MCC_Send(MCC_glDrv_glLightModeli, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glLightModeliv(GLenum pname, const GLint *params)
{
  MCC_glDrv_glLightModelivArgs arguments = { pname, params };
  MCC_Send(MCC_glDrv_glLightModeliv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glLightf(GLenum light, GLenum pname, GLfloat param)
{
  MCC_glDrv_glLightfArgs arguments = { light, pname, param };
  MCC_Send(MCC_glDrv_glLightf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glLightfv(GLenum light, GLenum pname, const GLfloat *params)
{
  MCC_glDrv_glLightfvArgs arguments = { light, pname, params };
  MCC_Send(MCC_glDrv_glLightfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glLighti(GLenum light, GLenum pname, GLint param)
{
  MCC_glDrv_glLightiArgs arguments = { light, pname, param };
  MCC_Send(MCC_glDrv_glLighti, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glLightiv(GLenum light, GLenum pname, const GLint *params)
{
  MCC_glDrv_glLightivArgs arguments = { light, pname, params };
  MCC_Send(MCC_glDrv_glLightiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glLineStipple(GLint factor, GLushort pattern)
{
  MCC_glDrv_glLineStippleArgs arguments = { factor, pattern };
  MCC_Send(MCC_glDrv_glLineStipple, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glLineWidth(GLfloat width)
{
  MCC_glDrv_glLineWidthArgs arguments = { width };
  MCC_Send(MCC_glDrv_glLineWidth, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glListBase(GLuint base)
{
  MCC_glDrv_glListBaseArgs arguments = { base };
  MCC_Send(MCC_glDrv_glListBase, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glLoadIdentity(void)
{
  MCC_glDrv_glLoadIdentityArgs arguments = {  };
  MCC_Send(MCC_glDrv_glLoadIdentity, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glLoadMatrixd(const GLdouble *m)
{
  MCC_glDrv_glLoadMatrixdArgs arguments = { m };
  MCC_Send(MCC_glDrv_glLoadMatrixd, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glLoadMatrixf(const GLfloat *m)
{
  MCC_glDrv_glLoadMatrixfArgs arguments = { m };
  MCC_Send(MCC_glDrv_glLoadMatrixf, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glLoadName(GLuint name)
{
  MCC_glDrv_glLoadNameArgs arguments = { name };
  MCC_Send(MCC_glDrv_glLoadName, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glLogicOp(GLenum opcode)
{
  MCC_glDrv_glLogicOpArgs arguments = { opcode };
  MCC_Send(MCC_glDrv_glLogicOp, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
{
  MCC_glDrv_glMap1dArgs arguments = { target, u1, u2, stride, order, points };
  MCC_Send(MCC_glDrv_glMap1d, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
{
  MCC_glDrv_glMap1fArgs arguments = { target, u1, u2, stride, order, points };
  MCC_Send(MCC_glDrv_glMap1f, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
{
  MCC_glDrv_glMap2dArgs arguments = { target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points };
  MCC_Send(MCC_glDrv_glMap2d, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
{
  MCC_glDrv_glMap2fArgs arguments = { target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points };
  MCC_Send(MCC_glDrv_glMap2f, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2)
{
  MCC_glDrv_glMapGrid1dArgs arguments = { un, u1, u2 };
  MCC_Send(MCC_glDrv_glMapGrid1d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMapGrid1f(GLint un, GLfloat u1, GLfloat u2)
{
  MCC_glDrv_glMapGrid1fArgs arguments = { un, u1, u2 };
  MCC_Send(MCC_glDrv_glMapGrid1f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2)
{
  MCC_glDrv_glMapGrid2dArgs arguments = { un, u1, u2, vn, v1, v2 };
  MCC_Send(MCC_glDrv_glMapGrid2d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2)
{
  MCC_glDrv_glMapGrid2fArgs arguments = { un, u1, u2, vn, v1, v2 };
  MCC_Send(MCC_glDrv_glMapGrid2f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMaterialf(GLenum face, GLenum pname, GLfloat param)
{
  MCC_glDrv_glMaterialfArgs arguments = { face, pname, param };
  MCC_Send(MCC_glDrv_glMaterialf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params)
{
  MCC_glDrv_glMaterialfvArgs arguments = { face, pname, params };
  MCC_Send(MCC_glDrv_glMaterialfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMateriali(GLenum face, GLenum pname, GLint param)
{
  MCC_glDrv_glMaterialiArgs arguments = { face, pname, param };
  MCC_Send(MCC_glDrv_glMateriali, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMaterialiv(GLenum face, GLenum pname, const GLint *params)
{
  MCC_glDrv_glMaterialivArgs arguments = { face, pname, params };
  MCC_Send(MCC_glDrv_glMaterialiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMatrixMode(GLenum mode)
{
  MCC_glDrv_glMatrixModeArgs arguments = { mode };
  MCC_Send(MCC_glDrv_glMatrixMode, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultMatrixd(const GLdouble *m)
{
  MCC_glDrv_glMultMatrixdArgs arguments = { m };
  MCC_Send(MCC_glDrv_glMultMatrixd, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultMatrixf(const GLfloat *m)
{
  MCC_glDrv_glMultMatrixfArgs arguments = { m };
  MCC_Send(MCC_glDrv_glMultMatrixf, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glNewList(GLuint list, GLenum mode)
{
  MCC_glDrv_glNewListArgs arguments = { list, mode };
  MCC_Send(MCC_glDrv_glNewList, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz)
{
  MCC_glDrv_glNormal3bArgs arguments = { nx, ny, nz };
  MCC_Send(MCC_glDrv_glNormal3b, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glNormal3bv(const GLbyte *v)
{
  MCC_glDrv_glNormal3bvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glNormal3bv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz)
{
  MCC_glDrv_glNormal3dArgs arguments = { nx, ny, nz };
  MCC_Send(MCC_glDrv_glNormal3d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glNormal3dv(const GLdouble *v)
{
  MCC_glDrv_glNormal3dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glNormal3dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz)
{
  MCC_glDrv_glNormal3fArgs arguments = { nx, ny, nz };
  MCC_Send(MCC_glDrv_glNormal3f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glNormal3fv(const GLfloat *v)
{
  MCC_glDrv_glNormal3fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glNormal3fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glNormal3i(GLint nx, GLint ny, GLint nz)
{
  MCC_glDrv_glNormal3iArgs arguments = { nx, ny, nz };
  MCC_Send(MCC_glDrv_glNormal3i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glNormal3iv(const GLint *v)
{
  MCC_glDrv_glNormal3ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glNormal3iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glNormal3s(GLshort nx, GLshort ny, GLshort nz)
{
  MCC_glDrv_glNormal3sArgs arguments = { nx, ny, nz };
  MCC_Send(MCC_glDrv_glNormal3s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glNormal3sv(const GLshort *v)
{
  MCC_glDrv_glNormal3svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glNormal3sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
  MCC_glDrv_glOrthoArgs arguments = { left, right, bottom, top, zNear, zFar };
  MCC_Send(MCC_glDrv_glOrtho, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPassThrough(GLfloat token)
{
  MCC_glDrv_glPassThroughArgs arguments = { token };
  MCC_Send(MCC_glDrv_glPassThrough, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values)
{
  MCC_glDrv_glPixelMapfvArgs arguments = { map, mapsize, values };
  MCC_Send(MCC_glDrv_glPixelMapfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values)
{
  MCC_glDrv_glPixelMapuivArgs arguments = { map, mapsize, values };
  MCC_Send(MCC_glDrv_glPixelMapuiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values)
{
  MCC_glDrv_glPixelMapusvArgs arguments = { map, mapsize, values };
  MCC_Send(MCC_glDrv_glPixelMapusv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glPixelStoref(GLenum pname, GLfloat param)
{
  MCC_glDrv_glPixelStorefArgs arguments = { pname, param };
  MCC_Send(MCC_glDrv_glPixelStoref, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPixelStorei(GLenum pname, GLint param)
{
  MCC_glDrv_glPixelStoreiArgs arguments = { pname, param };
  MCC_Send(MCC_glDrv_glPixelStorei, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPixelTransferf(GLenum pname, GLfloat param)
{
  MCC_glDrv_glPixelTransferfArgs arguments = { pname, param };
  MCC_Send(MCC_glDrv_glPixelTransferf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPixelTransferi(GLenum pname, GLint param)
{
  MCC_glDrv_glPixelTransferiArgs arguments = { pname, param };
  MCC_Send(MCC_glDrv_glPixelTransferi, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPixelZoom(GLfloat xfactor, GLfloat yfactor)
{
  MCC_glDrv_glPixelZoomArgs arguments = { xfactor, yfactor };
  MCC_Send(MCC_glDrv_glPixelZoom, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPointSize(GLfloat size)
{
  MCC_glDrv_glPointSizeArgs arguments = { size };
  MCC_Send(MCC_glDrv_glPointSize, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPolygonMode(GLenum face, GLenum mode)
{
  MCC_glDrv_glPolygonModeArgs arguments = { face, mode };
  MCC_Send(MCC_glDrv_glPolygonMode, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPolygonStipple(const GLubyte *mask)
{
  MCC_glDrv_glPolygonStippleArgs arguments = { mask };
  MCC_Send(MCC_glDrv_glPolygonStipple, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glPopAttrib(void)
{
  MCC_glDrv_glPopAttribArgs arguments = {  };
  MCC_Send(MCC_glDrv_glPopAttrib, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPopMatrix(void)
{
  MCC_glDrv_glPopMatrixArgs arguments = {  };
  MCC_Send(MCC_glDrv_glPopMatrix, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPopName(void)
{
  MCC_glDrv_glPopNameArgs arguments = {  };
  MCC_Send(MCC_glDrv_glPopName, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPushAttrib(GLbitfield mask)
{
  MCC_glDrv_glPushAttribArgs arguments = { mask };
  MCC_Send(MCC_glDrv_glPushAttrib, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPushMatrix(void)
{
  MCC_glDrv_glPushMatrixArgs arguments = {  };
  MCC_Send(MCC_glDrv_glPushMatrix, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPushName(GLuint name)
{
  MCC_glDrv_glPushNameArgs arguments = { name };
  MCC_Send(MCC_glDrv_glPushName, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos2d(GLdouble x, GLdouble y)
{
  MCC_glDrv_glRasterPos2dArgs arguments = { x, y };
  MCC_Send(MCC_glDrv_glRasterPos2d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos2dv(const GLdouble *v)
{
  MCC_glDrv_glRasterPos2dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos2dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos2f(GLfloat x, GLfloat y)
{
  MCC_glDrv_glRasterPos2fArgs arguments = { x, y };
  MCC_Send(MCC_glDrv_glRasterPos2f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos2fv(const GLfloat *v)
{
  MCC_glDrv_glRasterPos2fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos2fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos2i(GLint x, GLint y)
{
  MCC_glDrv_glRasterPos2iArgs arguments = { x, y };
  MCC_Send(MCC_glDrv_glRasterPos2i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos2iv(const GLint *v)
{
  MCC_glDrv_glRasterPos2ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos2iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos2s(GLshort x, GLshort y)
{
  MCC_glDrv_glRasterPos2sArgs arguments = { x, y };
  MCC_Send(MCC_glDrv_glRasterPos2s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos2sv(const GLshort *v)
{
  MCC_glDrv_glRasterPos2svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos2sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos3d(GLdouble x, GLdouble y, GLdouble z)
{
  MCC_glDrv_glRasterPos3dArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glRasterPos3d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos3dv(const GLdouble *v)
{
  MCC_glDrv_glRasterPos3dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos3dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z)
{
  MCC_glDrv_glRasterPos3fArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glRasterPos3f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos3fv(const GLfloat *v)
{
  MCC_glDrv_glRasterPos3fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos3fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos3i(GLint x, GLint y, GLint z)
{
  MCC_glDrv_glRasterPos3iArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glRasterPos3i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos3iv(const GLint *v)
{
  MCC_glDrv_glRasterPos3ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos3iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos3s(GLshort x, GLshort y, GLshort z)
{
  MCC_glDrv_glRasterPos3sArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glRasterPos3s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos3sv(const GLshort *v)
{
  MCC_glDrv_glRasterPos3svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos3sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
  MCC_glDrv_glRasterPos4dArgs arguments = { x, y, z, w };
  MCC_Send(MCC_glDrv_glRasterPos4d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos4dv(const GLdouble *v)
{
  MCC_glDrv_glRasterPos4dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos4dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
  MCC_glDrv_glRasterPos4fArgs arguments = { x, y, z, w };
  MCC_Send(MCC_glDrv_glRasterPos4f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos4fv(const GLfloat *v)
{
  MCC_glDrv_glRasterPos4fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos4fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos4i(GLint x, GLint y, GLint z, GLint w)
{
  MCC_glDrv_glRasterPos4iArgs arguments = { x, y, z, w };
  MCC_Send(MCC_glDrv_glRasterPos4i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos4iv(const GLint *v)
{
  MCC_glDrv_glRasterPos4ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos4iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
  MCC_glDrv_glRasterPos4sArgs arguments = { x, y, z, w };
  MCC_Send(MCC_glDrv_glRasterPos4s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRasterPos4sv(const GLshort *v)
{
  MCC_glDrv_glRasterPos4svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glRasterPos4sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glReadBuffer(GLenum mode)
{
  MCC_glDrv_glReadBufferArgs arguments = { mode };
  MCC_Send(MCC_glDrv_glReadBuffer, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
  MCC_glDrv_glReadPixelsArgs arguments = { x, y, width, height, format, type, pixels };
  MCC_Send(MCC_glDrv_glReadPixels, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
{
  MCC_glDrv_glRectdArgs arguments = { x1, y1, x2, y2 };
  MCC_Send(MCC_glDrv_glRectd, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRectdv(const GLdouble *v1, const GLdouble *v2)
{
  MCC_glDrv_glRectdvArgs arguments = { v1, v2 };
  MCC_Send(MCC_glDrv_glRectdv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
  MCC_glDrv_glRectfArgs arguments = { x1, y1, x2, y2 };
  MCC_Send(MCC_glDrv_glRectf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRectfv(const GLfloat *v1, const GLfloat *v2)
{
  MCC_glDrv_glRectfvArgs arguments = { v1, v2 };
  MCC_Send(MCC_glDrv_glRectfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRecti(GLint x1, GLint y1, GLint x2, GLint y2)
{
  MCC_glDrv_glRectiArgs arguments = { x1, y1, x2, y2 };
  MCC_Send(MCC_glDrv_glRecti, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRectiv(const GLint *v1, const GLint *v2)
{
  MCC_glDrv_glRectivArgs arguments = { v1, v2 };
  MCC_Send(MCC_glDrv_glRectiv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2)
{
  MCC_glDrv_glRectsArgs arguments = { x1, y1, x2, y2 };
  MCC_Send(MCC_glDrv_glRects, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRectsv(const GLshort *v1, const GLshort *v2)
{
  MCC_glDrv_glRectsvArgs arguments = { v1, v2 };
  MCC_Send(MCC_glDrv_glRectsv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI GLint STDCALL glDrv_glRenderMode(GLenum mode)
{
  MCC_glDrv_glRenderModeArgs arguments = { mode };
  MCC_Send(MCC_glDrv_glRenderMode, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLint)((int)MCC_GetReturnPointer());
}

SWGLAPI void STDCALL glDrv_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
  MCC_glDrv_glRotatedArgs arguments = { angle, x, y, z };
  MCC_Send(MCC_glDrv_glRotated, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
  MCC_glDrv_glRotatefArgs arguments = { angle, x, y, z };
  MCC_Send(MCC_glDrv_glRotatef, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glScaled(GLdouble x, GLdouble y, GLdouble z)
{
  MCC_glDrv_glScaledArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glScaled, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glScalef(GLfloat x, GLfloat y, GLfloat z)
{
  MCC_glDrv_glScalefArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glScalef, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
  MCC_glDrv_glScissorArgs arguments = { x, y, width, height };
  MCC_Send(MCC_glDrv_glScissor, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glSelectBuffer(GLsizei size, GLuint *buffer)
{
  MCC_glDrv_glSelectBufferArgs arguments = { size, buffer };
  MCC_Send(MCC_glDrv_glSelectBuffer, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glShadeModel(GLenum mode)
{
  MCC_glDrv_glShadeModelArgs arguments = { mode };
  MCC_Send(MCC_glDrv_glShadeModel, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
  MCC_glDrv_glStencilFuncArgs arguments = { func, ref, mask };
  MCC_Send(MCC_glDrv_glStencilFunc, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glStencilMask(GLuint mask)
{
  MCC_glDrv_glStencilMaskArgs arguments = { mask };
  MCC_Send(MCC_glDrv_glStencilMask, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
  MCC_glDrv_glStencilOpArgs arguments = { fail, zfail, zpass };
  MCC_Send(MCC_glDrv_glStencilOp, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord1d(GLdouble s)
{
  MCC_glDrv_glTexCoord1dArgs arguments = { s };
  MCC_Send(MCC_glDrv_glTexCoord1d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord1dv(const GLdouble *v)
{
  MCC_glDrv_glTexCoord1dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord1dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord1f(GLfloat s)
{
  MCC_glDrv_glTexCoord1fArgs arguments = { s };
  MCC_Send(MCC_glDrv_glTexCoord1f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord1fv(const GLfloat *v)
{
  MCC_glDrv_glTexCoord1fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord1fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord1i(GLint s)
{
  MCC_glDrv_glTexCoord1iArgs arguments = { s };
  MCC_Send(MCC_glDrv_glTexCoord1i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord1iv(const GLint *v)
{
  MCC_glDrv_glTexCoord1ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord1iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord1s(GLshort s)
{
  MCC_glDrv_glTexCoord1sArgs arguments = { s };
  MCC_Send(MCC_glDrv_glTexCoord1s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord1sv(const GLshort *v)
{
  MCC_glDrv_glTexCoord1svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord1sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord2d(GLdouble s, GLdouble t)
{
  MCC_glDrv_glTexCoord2dArgs arguments = { s, t };
  MCC_Send(MCC_glDrv_glTexCoord2d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord2dv(const GLdouble *v)
{
  MCC_glDrv_glTexCoord2dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord2dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord2f(GLfloat s, GLfloat t)
{
  MCC_glDrv_glTexCoord2fArgs arguments = { s, t };
  MCC_Send(MCC_glDrv_glTexCoord2f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord2fv(const GLfloat *v)
{
  MCC_glDrv_glTexCoord2fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord2fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord2i(GLint s, GLint t)
{
  MCC_glDrv_glTexCoord2iArgs arguments = { s, t };
  MCC_Send(MCC_glDrv_glTexCoord2i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord2iv(const GLint *v)
{
  MCC_glDrv_glTexCoord2ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord2iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord2s(GLshort s, GLshort t)
{
  MCC_glDrv_glTexCoord2sArgs arguments = { s, t };
  MCC_Send(MCC_glDrv_glTexCoord2s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord2sv(const GLshort *v)
{
  MCC_glDrv_glTexCoord2svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord2sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord3d(GLdouble s, GLdouble t, GLdouble r)
{
  MCC_glDrv_glTexCoord3dArgs arguments = { s, t, r };
  MCC_Send(MCC_glDrv_glTexCoord3d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord3dv(const GLdouble *v)
{
  MCC_glDrv_glTexCoord3dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord3dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r)
{
  MCC_glDrv_glTexCoord3fArgs arguments = { s, t, r };
  MCC_Send(MCC_glDrv_glTexCoord3f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord3fv(const GLfloat *v)
{
  MCC_glDrv_glTexCoord3fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord3fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord3i(GLint s, GLint t, GLint r)
{
  MCC_glDrv_glTexCoord3iArgs arguments = { s, t, r };
  MCC_Send(MCC_glDrv_glTexCoord3i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord3iv(const GLint *v)
{
  MCC_glDrv_glTexCoord3ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord3iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord3s(GLshort s, GLshort t, GLshort r)
{
  MCC_glDrv_glTexCoord3sArgs arguments = { s, t, r };
  MCC_Send(MCC_glDrv_glTexCoord3s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord3sv(const GLshort *v)
{
  MCC_glDrv_glTexCoord3svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord3sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
  MCC_glDrv_glTexCoord4dArgs arguments = { s, t, r, q };
  MCC_Send(MCC_glDrv_glTexCoord4d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord4dv(const GLdouble *v)
{
  MCC_glDrv_glTexCoord4dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord4dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
  MCC_glDrv_glTexCoord4fArgs arguments = { s, t, r, q };
  MCC_Send(MCC_glDrv_glTexCoord4f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord4fv(const GLfloat *v)
{
  MCC_glDrv_glTexCoord4fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord4fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord4i(GLint s, GLint t, GLint r, GLint q)
{
  MCC_glDrv_glTexCoord4iArgs arguments = { s, t, r, q };
  MCC_Send(MCC_glDrv_glTexCoord4i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord4iv(const GLint *v)
{
  MCC_glDrv_glTexCoord4ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord4iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q)
{
  MCC_glDrv_glTexCoord4sArgs arguments = { s, t, r, q };
  MCC_Send(MCC_glDrv_glTexCoord4s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoord4sv(const GLshort *v)
{
  MCC_glDrv_glTexCoord4svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glTexCoord4sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexEnvf(GLenum target, GLenum pname, GLfloat param)
{
  MCC_glDrv_glTexEnvfArgs arguments = { target, pname, param };
  MCC_Send(MCC_glDrv_glTexEnvf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params)
{
  MCC_glDrv_glTexEnvfvArgs arguments = { target, pname, params };
  MCC_Send(MCC_glDrv_glTexEnvfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexEnvi(GLenum target, GLenum pname, GLint param)
{
  MCC_glDrv_glTexEnviArgs arguments = { target, pname, param };
  MCC_Send(MCC_glDrv_glTexEnvi, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexEnviv(GLenum target, GLenum pname, const GLint *params)
{
  MCC_glDrv_glTexEnvivArgs arguments = { target, pname, params };
  MCC_Send(MCC_glDrv_glTexEnviv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexGend(GLenum coord, GLenum pname, GLdouble param)
{
  MCC_glDrv_glTexGendArgs arguments = { coord, pname, param };
  MCC_Send(MCC_glDrv_glTexGend, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexGendv(GLenum coord, GLenum pname, const GLdouble *params)
{
  MCC_glDrv_glTexGendvArgs arguments = { coord, pname, params };
  MCC_Send(MCC_glDrv_glTexGendv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexGenf(GLenum coord, GLenum pname, GLfloat param)
{
  MCC_glDrv_glTexGenfArgs arguments = { coord, pname, param };
  MCC_Send(MCC_glDrv_glTexGenf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params)
{
  MCC_glDrv_glTexGenfvArgs arguments = { coord, pname, params };
  MCC_Send(MCC_glDrv_glTexGenfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexGeni(GLenum coord, GLenum pname, GLint param)
{
  MCC_glDrv_glTexGeniArgs arguments = { coord, pname, param };
  MCC_Send(MCC_glDrv_glTexGeni, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexGeniv(GLenum coord, GLenum pname, const GLint *params)
{
  MCC_glDrv_glTexGenivArgs arguments = { coord, pname, params };
  MCC_Send(MCC_glDrv_glTexGeniv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
  MCC_glDrv_glTexImage1DArgs arguments = { target, level, internalformat, width, border, format, type, pixels };
  MCC_Send(MCC_glDrv_glTexImage1D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
  MCC_glDrv_glTexImage2DArgs arguments = { target, level, internalformat, width, height, border, format, type, pixels };
  MCC_Send(MCC_glDrv_glTexImage2D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
  MCC_glDrv_glTexParameterfArgs arguments = { target, pname, param };
  MCC_Send(MCC_glDrv_glTexParameterf, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
  MCC_glDrv_glTexParameterfvArgs arguments = { target, pname, params };
  MCC_Send(MCC_glDrv_glTexParameterfv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexParameteri(GLenum target, GLenum pname, GLint param)
{
  MCC_glDrv_glTexParameteriArgs arguments = { target, pname, param };
  MCC_Send(MCC_glDrv_glTexParameteri, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexParameteriv(GLenum target, GLenum pname, const GLint *params)
{
  MCC_glDrv_glTexParameterivArgs arguments = { target, pname, params };
  MCC_Send(MCC_glDrv_glTexParameteriv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTranslated(GLdouble x, GLdouble y, GLdouble z)
{
  MCC_glDrv_glTranslatedArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glTranslated, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
  MCC_glDrv_glTranslatefArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glTranslatef, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex2d(GLdouble x, GLdouble y)
{
  MCC_glDrv_glVertex2dArgs arguments = { x, y };
  MCC_Send(MCC_glDrv_glVertex2d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex2dv(const GLdouble *v)
{
  MCC_glDrv_glVertex2dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex2dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex2f(GLfloat x, GLfloat y)
{
  MCC_glDrv_glVertex2fArgs arguments = { x, y };
  MCC_Send(MCC_glDrv_glVertex2f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex2fv(const GLfloat *v)
{
  MCC_glDrv_glVertex2fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex2fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex2i(GLint x, GLint y)
{
  MCC_glDrv_glVertex2iArgs arguments = { x, y };
  MCC_Send(MCC_glDrv_glVertex2i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex2iv(const GLint *v)
{
  MCC_glDrv_glVertex2ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex2iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex2s(GLshort x, GLshort y)
{
  MCC_glDrv_glVertex2sArgs arguments = { x, y };
  MCC_Send(MCC_glDrv_glVertex2s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex2sv(const GLshort *v)
{
  MCC_glDrv_glVertex2svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex2sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex3d(GLdouble x, GLdouble y, GLdouble z)
{
  MCC_glDrv_glVertex3dArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glVertex3d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex3dv(const GLdouble *v)
{
  MCC_glDrv_glVertex3dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex3dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
  MCC_glDrv_glVertex3fArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glVertex3f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex3fv(const GLfloat *v)
{
  MCC_glDrv_glVertex3fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex3fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex3i(GLint x, GLint y, GLint z)
{
  MCC_glDrv_glVertex3iArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glVertex3i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex3iv(const GLint *v)
{
  MCC_glDrv_glVertex3ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex3iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex3s(GLshort x, GLshort y, GLshort z)
{
  MCC_glDrv_glVertex3sArgs arguments = { x, y, z };
  MCC_Send(MCC_glDrv_glVertex3s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex3sv(const GLshort *v)
{
  MCC_glDrv_glVertex3svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex3sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
  MCC_glDrv_glVertex4dArgs arguments = { x, y, z, w };
  MCC_Send(MCC_glDrv_glVertex4d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex4dv(const GLdouble *v)
{
  MCC_glDrv_glVertex4dvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex4dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
  MCC_glDrv_glVertex4fArgs arguments = { x, y, z, w };
  MCC_Send(MCC_glDrv_glVertex4f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex4fv(const GLfloat *v)
{
  MCC_glDrv_glVertex4fvArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex4fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex4i(GLint x, GLint y, GLint z, GLint w)
{
  MCC_glDrv_glVertex4iArgs arguments = { x, y, z, w };
  MCC_Send(MCC_glDrv_glVertex4i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex4iv(const GLint *v)
{
  MCC_glDrv_glVertex4ivArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex4iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
  MCC_glDrv_glVertex4sArgs arguments = { x, y, z, w };
  MCC_Send(MCC_glDrv_glVertex4s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glVertex4sv(const GLshort *v)
{
  MCC_glDrv_glVertex4svArgs arguments = { v };
  MCC_Send(MCC_glDrv_glVertex4sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
  MCC_glDrv_glViewportArgs arguments = { x, y, width, height };
  MCC_Send(MCC_glDrv_glViewport, &arguments, sizeof(arguments));
}

SWGLAPI GLboolean STDCALL glDrv_glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences)
{
  MCC_glDrv_glAreTexturesResidentArgs arguments = { n, textures, residences };
  MCC_Send(MCC_glDrv_glAreTexturesResident, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI void STDCALL glDrv_glArrayElement(GLint i)
{
  MCC_glDrv_glArrayElementArgs arguments = { i };
  MCC_Send(MCC_glDrv_glArrayElement, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glBindTexture(GLenum target, GLuint texture)
{
  MCC_glDrv_glBindTextureArgs arguments = { target, texture };
  MCC_Send(MCC_glDrv_glBindTexture, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
  MCC_glDrv_glColorPointerArgs arguments = { size, type, stride, pointer };
  MCC_Send(MCC_glDrv_glColorPointer, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border)
{
  MCC_glDrv_glCopyTexImage1DArgs arguments = { target, level, internalFormat, x, y, width, border };
  MCC_Send(MCC_glDrv_glCopyTexImage1D, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
  MCC_glDrv_glCopyTexImage2DArgs arguments = { target, level, internalFormat, x, y, width, height, border };
  MCC_Send(MCC_glDrv_glCopyTexImage2D, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
  MCC_glDrv_glCopyTexSubImage1DArgs arguments = { target, level, xoffset, x, y, width };
  MCC_Send(MCC_glDrv_glCopyTexSubImage1D, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
  MCC_glDrv_glCopyTexSubImage2DArgs arguments = { target, level, xoffset, yoffset, x, y, width, height };
  MCC_Send(MCC_glDrv_glCopyTexSubImage2D, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDeleteTextures(GLsizei n, const GLuint *textures)
{
  MCC_glDrv_glDeleteTexturesArgs arguments = { n, textures };
  MCC_Send(MCC_glDrv_glDeleteTextures, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glDisableClientState(GLenum cap)
{
  MCC_glDrv_glDisableClientStateArgs arguments = { cap };
  MCC_Send(MCC_glDrv_glDisableClientState, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
  MCC_glDrv_glDrawArraysArgs arguments = { mode, first, count };
  MCC_Send(MCC_glDrv_glDrawArrays, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
  MCC_glDrv_glDrawElementsArgs arguments = { mode, count, type, indices };
  MCC_Send(MCC_glDrv_glDrawElements, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glEdgeFlagPointer(GLsizei stride, const GLvoid *pointer)
{
  MCC_glDrv_glEdgeFlagPointerArgs arguments = { stride, pointer };
  MCC_Send(MCC_glDrv_glEdgeFlagPointer, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glEnableClientState(GLenum cap)
{
  MCC_glDrv_glEnableClientStateArgs arguments = { cap };
  MCC_Send(MCC_glDrv_glEnableClientState, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glGenTextures(GLsizei n, GLuint *textures)
{
  MCC_glDrv_glGenTexturesArgs arguments = { n, textures };
  MCC_Send(MCC_glDrv_glGenTextures, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetPointerv(GLenum pname, GLvoid **params)
{
  MCC_glDrv_glGetPointervArgs arguments = { pname, params };
  MCC_Send(MCC_glDrv_glGetPointerv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI GLboolean STDCALL glDrv_glIsTexture(GLuint texture)
{
  MCC_glDrv_glIsTextureArgs arguments = { texture };
  MCC_Send(MCC_glDrv_glIsTexture, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI void STDCALL glDrv_glIndexPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
  MCC_glDrv_glIndexPointerArgs arguments = { type, stride, pointer };
  MCC_Send(MCC_glDrv_glIndexPointer, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glIndexub(GLubyte c)
{
  MCC_glDrv_glIndexubArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexub, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glIndexubv(const GLubyte *c)
{
  MCC_glDrv_glIndexubvArgs arguments = { c };
  MCC_Send(MCC_glDrv_glIndexubv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer)
{
  MCC_glDrv_glInterleavedArraysArgs arguments = { format, stride, pointer };
  MCC_Send(MCC_glDrv_glInterleavedArrays, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
  MCC_glDrv_glNormalPointerArgs arguments = { type, stride, pointer };
  MCC_Send(MCC_glDrv_glNormalPointer, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glPolygonOffset(GLfloat factor, GLfloat units)
{
  MCC_glDrv_glPolygonOffsetArgs arguments = { factor, units };
  MCC_Send(MCC_glDrv_glPolygonOffset, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPopClientAttrib(void)
{
  MCC_glDrv_glPopClientAttribArgs arguments = {  };
  MCC_Send(MCC_glDrv_glPopClientAttrib, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities)
{
  MCC_glDrv_glPrioritizeTexturesArgs arguments = { n, textures, priorities };
  MCC_Send(MCC_glDrv_glPrioritizeTextures, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glPushClientAttrib(GLbitfield mask)
{
  MCC_glDrv_glPushClientAttribArgs arguments = { mask };
  MCC_Send(MCC_glDrv_glPushClientAttrib, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
  MCC_glDrv_glTexCoordPointerArgs arguments = { size, type, stride, pointer };
  MCC_Send(MCC_glDrv_glTexCoordPointer, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
  MCC_glDrv_glTexSubImage1DArgs arguments = { target, level, xoffset, width, format, type, pixels };
  MCC_Send(MCC_glDrv_glTexSubImage1D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
  MCC_glDrv_glTexSubImage2DArgs arguments = { target, level, xoffset, yoffset, width, height, format, type, pixels };
  MCC_Send(MCC_glDrv_glTexSubImage2D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
  MCC_glDrv_glVertexPointerArgs arguments = { size, type, stride, pointer };
  MCC_Send(MCC_glDrv_glVertexPointer, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
{
  MCC_glDrv_glDrawRangeElementsArgs arguments = { mode, start, end, count, type, indices };
  MCC_Send(MCC_glDrv_glDrawRangeElements, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *data)
{
  MCC_glDrv_glTexImage3DArgs arguments = { target, level, internalFormat, width, height, depth, border, format, type, data };
  MCC_Send(MCC_glDrv_glTexImage3D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
  MCC_glDrv_glTexSubImage3DArgs arguments = { target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels };
  MCC_Send(MCC_glDrv_glTexSubImage3D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
  MCC_glDrv_glCopyTexSubImage3DArgs arguments = { target, level, xoffset, yoffset, zoffset, x, y, width, height };
  MCC_Send(MCC_glDrv_glCopyTexSubImage3D, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glActiveTexture(GLenum texture)
{
  MCC_glDrv_glActiveTextureArgs arguments = { texture };
  MCC_Send(MCC_glDrv_glActiveTexture, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glSampleCoverage(GLfloat value, GLboolean invert)
{
  MCC_glDrv_glSampleCoverageArgs arguments = { value, invert };
  MCC_Send(MCC_glDrv_glSampleCoverage, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data)
{
  MCC_glDrv_glCompressedTexImage3DArgs arguments = { target, level, internalformat, width, height, depth, border, imageSize, data };
  MCC_Send(MCC_glDrv_glCompressedTexImage3D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data)
{
  MCC_glDrv_glCompressedTexImage2DArgs arguments = { target, level, internalformat, width, height, border, imageSize, data };
  MCC_Send(MCC_glDrv_glCompressedTexImage2D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data)
{
  MCC_glDrv_glCompressedTexImage1DArgs arguments = { target, level, internalformat, width, border, imageSize, data };
  MCC_Send(MCC_glDrv_glCompressedTexImage1D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data)
{
  MCC_glDrv_glCompressedTexSubImage3DArgs arguments = { target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data };
  MCC_Send(MCC_glDrv_glCompressedTexSubImage3D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data)
{
  MCC_glDrv_glCompressedTexSubImage2DArgs arguments = { target, level, xoffset, yoffset, width, height, format, imageSize, data };
  MCC_Send(MCC_glDrv_glCompressedTexSubImage2D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data)
{
  MCC_glDrv_glCompressedTexSubImage1DArgs arguments = { target, level, xoffset, width, format, imageSize, data };
  MCC_Send(MCC_glDrv_glCompressedTexSubImage1D, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glGetCompressedTexImage(GLenum target, GLint level, GLvoid *pixels)
{
  MCC_glDrv_glGetCompressedTexImageArgs arguments = { target, level, pixels };
  MCC_Send(MCC_glDrv_glGetCompressedTexImage, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glClientActiveTexture(GLenum texture)
{
  MCC_glDrv_glClientActiveTextureArgs arguments = { texture };
  MCC_Send(MCC_glDrv_glClientActiveTexture, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord1d(GLenum target, GLdouble s)
{
  MCC_glDrv_glMultiTexCoord1dArgs arguments = { target, s };
  MCC_Send(MCC_glDrv_glMultiTexCoord1d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord1dv(GLenum target, const GLdouble *v)
{
  MCC_glDrv_glMultiTexCoord1dvArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord1dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord1f(GLenum target, GLfloat s)
{
  MCC_glDrv_glMultiTexCoord1fArgs arguments = { target, s };
  MCC_Send(MCC_glDrv_glMultiTexCoord1f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord1fv(GLenum target, const GLfloat *v)
{
  MCC_glDrv_glMultiTexCoord1fvArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord1fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord1i(GLenum target, GLint s)
{
  MCC_glDrv_glMultiTexCoord1iArgs arguments = { target, s };
  MCC_Send(MCC_glDrv_glMultiTexCoord1i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord1iv(GLenum target, const GLint *v)
{
  MCC_glDrv_glMultiTexCoord1ivArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord1iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord1s(GLenum target, GLshort s)
{
  MCC_glDrv_glMultiTexCoord1sArgs arguments = { target, s };
  MCC_Send(MCC_glDrv_glMultiTexCoord1s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord1sv(GLenum target, const GLshort *v)
{
  MCC_glDrv_glMultiTexCoord1svArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord1sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t)
{
  MCC_glDrv_glMultiTexCoord2dArgs arguments = { target, s, t };
  MCC_Send(MCC_glDrv_glMultiTexCoord2d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord2dv(GLenum target, const GLdouble *v)
{
  MCC_glDrv_glMultiTexCoord2dvArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord2dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t)
{
  MCC_glDrv_glMultiTexCoord2fArgs arguments = { target, s, t };
  MCC_Send(MCC_glDrv_glMultiTexCoord2f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord2fv(GLenum target, const GLfloat *v)
{
  MCC_glDrv_glMultiTexCoord2fvArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord2fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord2i(GLenum target, GLint s, GLint t)
{
  MCC_glDrv_glMultiTexCoord2iArgs arguments = { target, s, t };
  MCC_Send(MCC_glDrv_glMultiTexCoord2i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord2iv(GLenum target, const GLint *v)
{
  MCC_glDrv_glMultiTexCoord2ivArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord2iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord2s(GLenum target, GLshort s, GLshort t)
{
  MCC_glDrv_glMultiTexCoord2sArgs arguments = { target, s, t };
  MCC_Send(MCC_glDrv_glMultiTexCoord2s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord2sv(GLenum target, const GLshort *v)
{
  MCC_glDrv_glMultiTexCoord2svArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord2sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
  MCC_glDrv_glMultiTexCoord3dArgs arguments = { target, s, t, r };
  MCC_Send(MCC_glDrv_glMultiTexCoord3d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord3dv(GLenum target, const GLdouble *v)
{
  MCC_glDrv_glMultiTexCoord3dvArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord3dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
  MCC_glDrv_glMultiTexCoord3fArgs arguments = { target, s, t, r };
  MCC_Send(MCC_glDrv_glMultiTexCoord3f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord3fv(GLenum target, const GLfloat *v)
{
  MCC_glDrv_glMultiTexCoord3fvArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord3fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r)
{
  MCC_glDrv_glMultiTexCoord3iArgs arguments = { target, s, t, r };
  MCC_Send(MCC_glDrv_glMultiTexCoord3i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord3iv(GLenum target, const GLint *v)
{
  MCC_glDrv_glMultiTexCoord3ivArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord3iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r)
{
  MCC_glDrv_glMultiTexCoord3sArgs arguments = { target, s, t, r };
  MCC_Send(MCC_glDrv_glMultiTexCoord3s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord3sv(GLenum target, const GLshort *v)
{
  MCC_glDrv_glMultiTexCoord3svArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord3sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
  MCC_glDrv_glMultiTexCoord4dArgs arguments = { target, s, t, r, q };
  MCC_Send(MCC_glDrv_glMultiTexCoord4d, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord4dv(GLenum target, const GLdouble *v)
{
  MCC_glDrv_glMultiTexCoord4dvArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord4dv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
  MCC_glDrv_glMultiTexCoord4fArgs arguments = { target, s, t, r, q };
  MCC_Send(MCC_glDrv_glMultiTexCoord4f, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord4fv(GLenum target, const GLfloat *v)
{
  MCC_glDrv_glMultiTexCoord4fvArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord4fv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q)
{
  MCC_glDrv_glMultiTexCoord4iArgs arguments = { target, s, t, r, q };
  MCC_Send(MCC_glDrv_glMultiTexCoord4i, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord4iv(GLenum target, const GLint *v)
{
  MCC_glDrv_glMultiTexCoord4ivArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord4iv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
  MCC_glDrv_glMultiTexCoord4sArgs arguments = { target, s, t, r, q };
  MCC_Send(MCC_glDrv_glMultiTexCoord4s, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glMultiTexCoord4sv(GLenum target, const GLshort *v)
{
  MCC_glDrv_glMultiTexCoord4svArgs arguments = { target, v };
  MCC_Send(MCC_glDrv_glMultiTexCoord4sv, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glLoadTransposeMatrixf(const GLfloat *m)
{
  MCC_glDrv_glLoadTransposeMatrixfArgs arguments = { m };
  MCC_Send(MCC_glDrv_glLoadTransposeMatrixf, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glLoadTransposeMatrixd(const GLdouble *m)
{
  MCC_glDrv_glLoadTransposeMatrixdArgs arguments = { m };
  MCC_Send(MCC_glDrv_glLoadTransposeMatrixd, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultTransposeMatrixf(const GLfloat *m)
{
  MCC_glDrv_glMultTransposeMatrixfArgs arguments = { m };
  MCC_Send(MCC_glDrv_glMultTransposeMatrixf, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glMultTransposeMatrixd(const GLdouble *m)
{
  MCC_glDrv_glMultTransposeMatrixdArgs arguments = { m };
  MCC_Send(MCC_glDrv_glMultTransposeMatrixd, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
}

SWGLAPI void STDCALL glDrv_glLockArrays(GLint first, GLsizei count)
{
  MCC_glDrv_glLockArraysArgs arguments = { first, count };
  MCC_Send(MCC_glDrv_glLockArrays, &arguments, sizeof(arguments));
}

SWGLAPI void STDCALL glDrv_glUnlockArrays()
{
  MCC_glDrv_glUnlockArraysArgs arguments = {  };
  MCC_Send(MCC_glDrv_glUnlockArrays, &arguments, sizeof(arguments));
}

SWGLAPI GLint STDCALL glDrv_wglChoosePixelFormat(HDC hdc, const PIXELFORMATDESCRIPTOR *ppfd)
{
  MCC_glDrv_wglChoosePixelFormatArgs arguments = { hdc, ppfd };
  MCC_Send(MCC_glDrv_wglChoosePixelFormat, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLint)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglCopyContext(HGLRC hglrc, HGLRC hglrc2, UINT i)
{
  MCC_glDrv_wglCopyContextArgs arguments = { hglrc, hglrc2, i };
  MCC_Send(MCC_glDrv_wglCopyContext, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI HGLRC STDCALL glDrv_wglCreateContext(HDC hdc)
{
  MCC_glDrv_wglCreateContextArgs arguments = { hdc };
  MCC_Send(MCC_glDrv_wglCreateContext, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (HGLRC)((int)MCC_GetReturnPointer());
}

SWGLAPI HGLRC STDCALL glDrv_wglCreateLayerContext(HDC hdc, int iLayerPlane)
{
  MCC_glDrv_wglCreateLayerContextArgs arguments = { hdc, iLayerPlane };
  MCC_Send(MCC_glDrv_wglCreateLayerContext, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (HGLRC)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglDeleteContext(HGLRC hglrc)
{
  MCC_glDrv_wglDeleteContextArgs arguments = { hglrc };
  MCC_Send(MCC_glDrv_wglDeleteContext, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglDescribeLayerPlane(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nBytes, LPLAYERPLANEDESCRIPTOR plpd)
{
  MCC_glDrv_wglDescribeLayerPlaneArgs arguments = { hdc, iPixelFormat, iLayerPlane, nBytes, plpd };
  MCC_Send(MCC_glDrv_wglDescribeLayerPlane, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLint STDCALL glDrv_wglDescribePixelFormat(HDC hdc, int iPixelFormat, UINT nBytes, LPPIXELFORMATDESCRIPTOR ppfd)
{
  MCC_glDrv_wglDescribePixelFormatArgs arguments = { hdc, iPixelFormat, nBytes, ppfd };
  MCC_Send(MCC_glDrv_wglDescribePixelFormat, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLint)((int)MCC_GetReturnPointer());
}

SWGLAPI HGLRC STDCALL glDrv_wglGetCurrentContext()
{
  MCC_glDrv_wglGetCurrentContextArgs arguments = {  };
  MCC_Send(MCC_glDrv_wglGetCurrentContext, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (HDC)((int)MCC_GetReturnPointer());
}

SWGLAPI HDC STDCALL glDrv_wglGetCurrentDC()
{
  MCC_glDrv_wglGetCurrentDCArgs arguments = {  };
  MCC_Send(MCC_glDrv_wglGetCurrentDC, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (HDC)((int)MCC_GetReturnPointer());
}

SWGLAPI GLint STDCALL glDrv_wglGetLayerPaletteEntries(HDC hdc, int iLayerPlane, int iStart, int cEntries, COLORREF *pcr)
{
  MCC_glDrv_wglGetLayerPaletteEntriesArgs arguments = { hdc, iLayerPlane, iStart, cEntries, pcr };
  MCC_Send(MCC_glDrv_wglGetLayerPaletteEntries, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLint)((int)MCC_GetReturnPointer());
}

SWGLAPI GLint STDCALL glDrv_wglGetPixelFormat(HDC hdc)
{
  MCC_glDrv_wglGetPixelFormatArgs arguments = { hdc };
  MCC_Send(MCC_glDrv_wglGetPixelFormat, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLint)((int)MCC_GetReturnPointer());
}

SWGLAPI PROC STDCALL glDrv_wglGetProcAddress(LPCSTR s)
{
  MCC_glDrv_wglGetProcAddressArgs arguments = { s };
  MCC_Send(MCC_glDrv_wglGetProcAddress, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (PROC)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglMakeCurrent(HDC hdc, HGLRC hglrc)
{
  MCC_glDrv_wglMakeCurrentArgs arguments = { hdc, hglrc };
  MCC_Send(MCC_glDrv_wglMakeCurrent, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglRealizeLayerPalette(HDC hdc, int iLayerPlane, GLboolean b)
{
  MCC_glDrv_wglRealizeLayerPaletteArgs arguments = { hdc, iLayerPlane, b };
  MCC_Send(MCC_glDrv_wglRealizeLayerPalette, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLint STDCALL glDrv_wglSetLayerPaletteEntries(HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF *pcr)
{
  MCC_glDrv_wglSetLayerPaletteEntriesArgs arguments = { hdc, iLayerPlane, iStart, cEntries, pcr };
  MCC_Send(MCC_glDrv_wglSetLayerPaletteEntries, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLint)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglSetPixelFormat(HDC hdc, int format, const PIXELFORMATDESCRIPTOR *ppfd)
{
  MCC_glDrv_wglSetPixelFormatArgs arguments = { hdc, format, ppfd };
  MCC_Send(MCC_glDrv_wglSetPixelFormat, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglShareLists(HGLRC hglrc, HGLRC hglrc2)
{
  MCC_glDrv_wglShareListsArgs arguments = { hglrc, hglrc2 };
  MCC_Send(MCC_glDrv_wglShareLists, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglSwapBuffers(HDC hdc)
{
  MCC_glDrv_wglSwapBuffersArgs arguments = { hdc };
  MCC_Send(MCC_glDrv_wglSwapBuffers, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglSwapLayerBuffers(HDC hdc, UINT planes)
{
  MCC_glDrv_wglSwapLayerBuffersArgs arguments = { hdc, planes };
  MCC_Send(MCC_glDrv_wglSwapLayerBuffers, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglUseFontBitmapsA(HDC hdc, DWORD dw1, DWORD dw2, DWORD dw3)
{
  MCC_glDrv_wglUseFontBitmapsAArgs arguments = { hdc, dw1, dw2, dw3 };
  MCC_Send(MCC_glDrv_wglUseFontBitmapsA, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglUseFontBitmapsW(HDC hdc, DWORD dw1, DWORD dw2, DWORD dw3)
{
  MCC_glDrv_wglUseFontBitmapsWArgs arguments = { hdc, dw1, dw2, dw3 };
  MCC_Send(MCC_glDrv_wglUseFontBitmapsW, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglUseFontOutlinesA(HDC hdc, DWORD dw1, DWORD dw2, DWORD dw3, FLOAT f1, FLOAT f2, int i, LPGLYPHMETRICSFLOAT pgmf)
{
  MCC_glDrv_wglUseFontOutlinesAArgs arguments = { hdc, dw1, dw2, dw3, f1, f2, i, pgmf };
  MCC_Send(MCC_glDrv_wglUseFontOutlinesA, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglUseFontOutlinesW(HDC hdc, DWORD dw1, DWORD dw2, DWORD dw3, FLOAT f1, FLOAT f2, int i, LPGLYPHMETRICSFLOAT pgmf)
{
  MCC_glDrv_wglUseFontOutlinesWArgs arguments = { hdc, dw1, dw2, dw3, f1, f2, i, pgmf };
  MCC_Send(MCC_glDrv_wglUseFontOutlinesW, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglSetDeviceGammaRamp(HDC hdc, LPVOID lpRamp)
{
  MCC_glDrv_wglSetDeviceGammaRampArgs arguments = { hdc, lpRamp };
  MCC_Send(MCC_glDrv_wglSetDeviceGammaRamp, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI GLboolean STDCALL glDrv_wglGetDeviceGammaRamp(HDC hdc, LPVOID lpRamp)
{
  MCC_glDrv_wglGetDeviceGammaRampArgs arguments = { hdc, lpRamp };
  MCC_Send(MCC_glDrv_wglGetDeviceGammaRamp, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (GLboolean)((int)MCC_GetReturnPointer());
}

SWGLAPI const char * STDCALL glDrv_wglGetExtensionsString(HDC hdc)
{
  MCC_glDrv_wglGetExtensionsStringArgs arguments = { hdc };
  MCC_Send(MCC_glDrv_wglGetExtensionsString, &arguments, sizeof(arguments));
  MCC_Flush(MCC_TIMEOUT);
  return (char*)MCC_GetReturnPointer();
}

#endif



#ifdef CORE_CM7

#define CHECKSIZE(x) if(sizeof(x)!=argsize)break

static char argBuffer[512];


void MCC_HandleOpenGL(void)
{

  short prodid;
  short argsize;
  if(MCC_Receive(&prodid, argBuffer, &argsize) == MCC_Ok)
  {
    switch(prodid)
    {
      case MCC_glDrv_glAccum :
        CHECKSIZE(MCC_glDrv_glAccumArgs);
        MCC_glDrv_glAccumArgs * glDrv_glAccumArg = (MCC_glDrv_glAccumArgs *)argBuffer;
        glDrv_glAccum(glDrv_glAccumArg->op, glDrv_glAccumArg->value);
        break;
      case MCC_glDrv_glAlphaFunc :
        CHECKSIZE(MCC_glDrv_glAlphaFuncArgs);
        MCC_glDrv_glAlphaFuncArgs * glDrv_glAlphaFuncArg = (MCC_glDrv_glAlphaFuncArgs *)argBuffer;
        glDrv_glAlphaFunc(glDrv_glAlphaFuncArg->func, glDrv_glAlphaFuncArg->ref);
        break;
      case MCC_glDrv_glBegin :
        CHECKSIZE(MCC_glDrv_glBeginArgs);
        MCC_glDrv_glBeginArgs * glDrv_glBeginArg = (MCC_glDrv_glBeginArgs *)argBuffer;
        glDrv_glBegin(glDrv_glBeginArg->mode);
        break;
      case MCC_glDrv_glBitmap :
        CHECKSIZE(MCC_glDrv_glBitmapArgs);
        MCC_glDrv_glBitmapArgs * glDrv_glBitmapArg = (MCC_glDrv_glBitmapArgs *)argBuffer;
        glDrv_glBitmap(glDrv_glBitmapArg->width, glDrv_glBitmapArg->height, glDrv_glBitmapArg->xOrig, glDrv_glBitmapArg->yOrig, glDrv_glBitmapArg->xMove, glDrv_glBitmapArg->yMove, glDrv_glBitmapArg->bitmap);
        break;
      case MCC_glDrv_glBlendFunc :
        CHECKSIZE(MCC_glDrv_glBlendFuncArgs);
        MCC_glDrv_glBlendFuncArgs * glDrv_glBlendFuncArg = (MCC_glDrv_glBlendFuncArgs *)argBuffer;
        glDrv_glBlendFunc(glDrv_glBlendFuncArg->srcFactor, glDrv_glBlendFuncArg->dstFactor);
        break;
      case MCC_glDrv_glCallList :
        CHECKSIZE(MCC_glDrv_glCallListArgs);
        MCC_glDrv_glCallListArgs * glDrv_glCallListArg = (MCC_glDrv_glCallListArgs *)argBuffer;
        glDrv_glCallList(glDrv_glCallListArg->list);
        break;
      case MCC_glDrv_glCallLists :
        CHECKSIZE(MCC_glDrv_glCallListsArgs);
        MCC_glDrv_glCallListsArgs * glDrv_glCallListsArg = (MCC_glDrv_glCallListsArgs *)argBuffer;
        glDrv_glCallLists(glDrv_glCallListsArg->n, glDrv_glCallListsArg->type, glDrv_glCallListsArg->lists);
        break;
      case MCC_glDrv_glClear :
        CHECKSIZE(MCC_glDrv_glClearArgs);
        MCC_glDrv_glClearArgs * glDrv_glClearArg = (MCC_glDrv_glClearArgs *)argBuffer;
        glDrv_glClear(glDrv_glClearArg->mask);
        break;
      case MCC_glDrv_glClearAccum :
        CHECKSIZE(MCC_glDrv_glClearAccumArgs);
        MCC_glDrv_glClearAccumArgs * glDrv_glClearAccumArg = (MCC_glDrv_glClearAccumArgs *)argBuffer;
        glDrv_glClearAccum(glDrv_glClearAccumArg->red, glDrv_glClearAccumArg->green, glDrv_glClearAccumArg->blue, glDrv_glClearAccumArg->alpha);
        break;
      case MCC_glDrv_glClearColor :
        CHECKSIZE(MCC_glDrv_glClearColorArgs);
        MCC_glDrv_glClearColorArgs * glDrv_glClearColorArg = (MCC_glDrv_glClearColorArgs *)argBuffer;
        glDrv_glClearColor(glDrv_glClearColorArg->red, glDrv_glClearColorArg->green, glDrv_glClearColorArg->blue, glDrv_glClearColorArg->alpha);
        break;
      case MCC_glDrv_glClearDepth :
        CHECKSIZE(MCC_glDrv_glClearDepthArgs);
        MCC_glDrv_glClearDepthArgs * glDrv_glClearDepthArg = (MCC_glDrv_glClearDepthArgs *)argBuffer;
        glDrv_glClearDepth(glDrv_glClearDepthArg->depth);
        break;
      case MCC_glDrv_glClearIndex :
        CHECKSIZE(MCC_glDrv_glClearIndexArgs);
        MCC_glDrv_glClearIndexArgs * glDrv_glClearIndexArg = (MCC_glDrv_glClearIndexArgs *)argBuffer;
        glDrv_glClearIndex(glDrv_glClearIndexArg->c);
        break;
      case MCC_glDrv_glClearStencil :
        CHECKSIZE(MCC_glDrv_glClearStencilArgs);
        MCC_glDrv_glClearStencilArgs * glDrv_glClearStencilArg = (MCC_glDrv_glClearStencilArgs *)argBuffer;
        glDrv_glClearStencil(glDrv_glClearStencilArg->s);
        break;
      case MCC_glDrv_glClipPlane :
        CHECKSIZE(MCC_glDrv_glClipPlaneArgs);
        MCC_glDrv_glClipPlaneArgs * glDrv_glClipPlaneArg = (MCC_glDrv_glClipPlaneArgs *)argBuffer;
        glDrv_glClipPlane(glDrv_glClipPlaneArg->plane, glDrv_glClipPlaneArg->equation);
        break;
      case MCC_glDrv_glColor3b :
        CHECKSIZE(MCC_glDrv_glColor3bArgs);
        MCC_glDrv_glColor3bArgs * glDrv_glColor3bArg = (MCC_glDrv_glColor3bArgs *)argBuffer;
        glDrv_glColor3b(glDrv_glColor3bArg->red, glDrv_glColor3bArg->green, glDrv_glColor3bArg->blue);
        break;
      case MCC_glDrv_glColor3bv :
        CHECKSIZE(MCC_glDrv_glColor3bvArgs);
        MCC_glDrv_glColor3bvArgs * glDrv_glColor3bvArg = (MCC_glDrv_glColor3bvArgs *)argBuffer;
        glDrv_glColor3bv(glDrv_glColor3bvArg->v);
        break;
      case MCC_glDrv_glColor3d :
        CHECKSIZE(MCC_glDrv_glColor3dArgs);
        MCC_glDrv_glColor3dArgs * glDrv_glColor3dArg = (MCC_glDrv_glColor3dArgs *)argBuffer;
        glDrv_glColor3d(glDrv_glColor3dArg->red, glDrv_glColor3dArg->green, glDrv_glColor3dArg->blue);
        break;
      case MCC_glDrv_glColor3dv :
        CHECKSIZE(MCC_glDrv_glColor3dvArgs);
        MCC_glDrv_glColor3dvArgs * glDrv_glColor3dvArg = (MCC_glDrv_glColor3dvArgs *)argBuffer;
        glDrv_glColor3dv(glDrv_glColor3dvArg->v);
        break;
      case MCC_glDrv_glColor3f :
        CHECKSIZE(MCC_glDrv_glColor3fArgs);
        MCC_glDrv_glColor3fArgs * glDrv_glColor3fArg = (MCC_glDrv_glColor3fArgs *)argBuffer;
        glDrv_glColor3f(glDrv_glColor3fArg->red, glDrv_glColor3fArg->green, glDrv_glColor3fArg->blue);
        break;
      case MCC_glDrv_glColor3fv :
        CHECKSIZE(MCC_glDrv_glColor3fvArgs);
        MCC_glDrv_glColor3fvArgs * glDrv_glColor3fvArg = (MCC_glDrv_glColor3fvArgs *)argBuffer;
        glDrv_glColor3fv(glDrv_glColor3fvArg->v);
        break;
      case MCC_glDrv_glColor3i :
        CHECKSIZE(MCC_glDrv_glColor3iArgs);
        MCC_glDrv_glColor3iArgs * glDrv_glColor3iArg = (MCC_glDrv_glColor3iArgs *)argBuffer;
        glDrv_glColor3i(glDrv_glColor3iArg->red, glDrv_glColor3iArg->green, glDrv_glColor3iArg->blue);
        break;
      case MCC_glDrv_glColor3iv :
        CHECKSIZE(MCC_glDrv_glColor3ivArgs);
        MCC_glDrv_glColor3ivArgs * glDrv_glColor3ivArg = (MCC_glDrv_glColor3ivArgs *)argBuffer;
        glDrv_glColor3iv(glDrv_glColor3ivArg->v);
        break;
      case MCC_glDrv_glColor3s :
        CHECKSIZE(MCC_glDrv_glColor3sArgs);
        MCC_glDrv_glColor3sArgs * glDrv_glColor3sArg = (MCC_glDrv_glColor3sArgs *)argBuffer;
        glDrv_glColor3s(glDrv_glColor3sArg->red, glDrv_glColor3sArg->green, glDrv_glColor3sArg->blue);
        break;
      case MCC_glDrv_glColor3sv :
        CHECKSIZE(MCC_glDrv_glColor3svArgs);
        MCC_glDrv_glColor3svArgs * glDrv_glColor3svArg = (MCC_glDrv_glColor3svArgs *)argBuffer;
        glDrv_glColor3sv(glDrv_glColor3svArg->v);
        break;
      case MCC_glDrv_glColor3ub :
        CHECKSIZE(MCC_glDrv_glColor3ubArgs);
        MCC_glDrv_glColor3ubArgs * glDrv_glColor3ubArg = (MCC_glDrv_glColor3ubArgs *)argBuffer;
        glDrv_glColor3ub(glDrv_glColor3ubArg->red, glDrv_glColor3ubArg->green, glDrv_glColor3ubArg->blue);
        break;
      case MCC_glDrv_glColor3ubv :
        CHECKSIZE(MCC_glDrv_glColor3ubvArgs);
        MCC_glDrv_glColor3ubvArgs * glDrv_glColor3ubvArg = (MCC_glDrv_glColor3ubvArgs *)argBuffer;
        glDrv_glColor3ubv(glDrv_glColor3ubvArg->v);
        break;
      case MCC_glDrv_glColor3ui :
        CHECKSIZE(MCC_glDrv_glColor3uiArgs);
        MCC_glDrv_glColor3uiArgs * glDrv_glColor3uiArg = (MCC_glDrv_glColor3uiArgs *)argBuffer;
        glDrv_glColor3ui(glDrv_glColor3uiArg->red, glDrv_glColor3uiArg->green, glDrv_glColor3uiArg->blue);
        break;
      case MCC_glDrv_glColor3uiv :
        CHECKSIZE(MCC_glDrv_glColor3uivArgs);
        MCC_glDrv_glColor3uivArgs * glDrv_glColor3uivArg = (MCC_glDrv_glColor3uivArgs *)argBuffer;
        glDrv_glColor3uiv(glDrv_glColor3uivArg->v);
        break;
      case MCC_glDrv_glColor3us :
        CHECKSIZE(MCC_glDrv_glColor3usArgs);
        MCC_glDrv_glColor3usArgs * glDrv_glColor3usArg = (MCC_glDrv_glColor3usArgs *)argBuffer;
        glDrv_glColor3us(glDrv_glColor3usArg->red, glDrv_glColor3usArg->green, glDrv_glColor3usArg->blue);
        break;
      case MCC_glDrv_glColor3usv :
        CHECKSIZE(MCC_glDrv_glColor3usvArgs);
        MCC_glDrv_glColor3usvArgs * glDrv_glColor3usvArg = (MCC_glDrv_glColor3usvArgs *)argBuffer;
        glDrv_glColor3usv(glDrv_glColor3usvArg->v);
        break;
      case MCC_glDrv_glColor4b :
        CHECKSIZE(MCC_glDrv_glColor4bArgs);
        MCC_glDrv_glColor4bArgs * glDrv_glColor4bArg = (MCC_glDrv_glColor4bArgs *)argBuffer;
        glDrv_glColor4b(glDrv_glColor4bArg->red, glDrv_glColor4bArg->green, glDrv_glColor4bArg->blue, glDrv_glColor4bArg->alpha);
        break;
      case MCC_glDrv_glColor4bv :
        CHECKSIZE(MCC_glDrv_glColor4bvArgs);
        MCC_glDrv_glColor4bvArgs * glDrv_glColor4bvArg = (MCC_glDrv_glColor4bvArgs *)argBuffer;
        glDrv_glColor4bv(glDrv_glColor4bvArg->v);
        break;
      case MCC_glDrv_glColor4d :
        CHECKSIZE(MCC_glDrv_glColor4dArgs);
        MCC_glDrv_glColor4dArgs * glDrv_glColor4dArg = (MCC_glDrv_glColor4dArgs *)argBuffer;
        glDrv_glColor4d(glDrv_glColor4dArg->red, glDrv_glColor4dArg->green, glDrv_glColor4dArg->blue, glDrv_glColor4dArg->alpha);
        break;
      case MCC_glDrv_glColor4dv :
        CHECKSIZE(MCC_glDrv_glColor4dvArgs);
        MCC_glDrv_glColor4dvArgs * glDrv_glColor4dvArg = (MCC_glDrv_glColor4dvArgs *)argBuffer;
        glDrv_glColor4dv(glDrv_glColor4dvArg->v);
        break;
      case MCC_glDrv_glColor4f :
        CHECKSIZE(MCC_glDrv_glColor4fArgs);
        MCC_glDrv_glColor4fArgs * glDrv_glColor4fArg = (MCC_glDrv_glColor4fArgs *)argBuffer;
        glDrv_glColor4f(glDrv_glColor4fArg->red, glDrv_glColor4fArg->green, glDrv_glColor4fArg->blue, glDrv_glColor4fArg->alpha);
        break;
      case MCC_glDrv_glColor4fv :
        CHECKSIZE(MCC_glDrv_glColor4fvArgs);
        MCC_glDrv_glColor4fvArgs * glDrv_glColor4fvArg = (MCC_glDrv_glColor4fvArgs *)argBuffer;
        glDrv_glColor4fv(glDrv_glColor4fvArg->v);
        break;
      case MCC_glDrv_glColor4i :
        CHECKSIZE(MCC_glDrv_glColor4iArgs);
        MCC_glDrv_glColor4iArgs * glDrv_glColor4iArg = (MCC_glDrv_glColor4iArgs *)argBuffer;
        glDrv_glColor4i(glDrv_glColor4iArg->red, glDrv_glColor4iArg->green, glDrv_glColor4iArg->blue, glDrv_glColor4iArg->alpha);
        break;
      case MCC_glDrv_glColor4iv :
        CHECKSIZE(MCC_glDrv_glColor4ivArgs);
        MCC_glDrv_glColor4ivArgs * glDrv_glColor4ivArg = (MCC_glDrv_glColor4ivArgs *)argBuffer;
        glDrv_glColor4iv(glDrv_glColor4ivArg->v);
        break;
      case MCC_glDrv_glColor4s :
        CHECKSIZE(MCC_glDrv_glColor4sArgs);
        MCC_glDrv_glColor4sArgs * glDrv_glColor4sArg = (MCC_glDrv_glColor4sArgs *)argBuffer;
        glDrv_glColor4s(glDrv_glColor4sArg->red, glDrv_glColor4sArg->green, glDrv_glColor4sArg->blue, glDrv_glColor4sArg->alpha);
        break;
      case MCC_glDrv_glColor4sv :
        CHECKSIZE(MCC_glDrv_glColor4svArgs);
        MCC_glDrv_glColor4svArgs * glDrv_glColor4svArg = (MCC_glDrv_glColor4svArgs *)argBuffer;
        glDrv_glColor4sv(glDrv_glColor4svArg->v);
        break;
      case MCC_glDrv_glColor4ub :
        CHECKSIZE(MCC_glDrv_glColor4ubArgs);
        MCC_glDrv_glColor4ubArgs * glDrv_glColor4ubArg = (MCC_glDrv_glColor4ubArgs *)argBuffer;
        glDrv_glColor4ub(glDrv_glColor4ubArg->red, glDrv_glColor4ubArg->green, glDrv_glColor4ubArg->blue, glDrv_glColor4ubArg->alpha);
        break;
      case MCC_glDrv_glColor4ubv :
        CHECKSIZE(MCC_glDrv_glColor4ubvArgs);
        MCC_glDrv_glColor4ubvArgs * glDrv_glColor4ubvArg = (MCC_glDrv_glColor4ubvArgs *)argBuffer;
        glDrv_glColor4ubv(glDrv_glColor4ubvArg->v);
        break;
      case MCC_glDrv_glColor4ui :
        CHECKSIZE(MCC_glDrv_glColor4uiArgs);
        MCC_glDrv_glColor4uiArgs * glDrv_glColor4uiArg = (MCC_glDrv_glColor4uiArgs *)argBuffer;
        glDrv_glColor4ui(glDrv_glColor4uiArg->red, glDrv_glColor4uiArg->green, glDrv_glColor4uiArg->blue, glDrv_glColor4uiArg->alpha);
        break;
      case MCC_glDrv_glColor4uiv :
        CHECKSIZE(MCC_glDrv_glColor4uivArgs);
        MCC_glDrv_glColor4uivArgs * glDrv_glColor4uivArg = (MCC_glDrv_glColor4uivArgs *)argBuffer;
        glDrv_glColor4uiv(glDrv_glColor4uivArg->v);
        break;
      case MCC_glDrv_glColor4us :
        CHECKSIZE(MCC_glDrv_glColor4usArgs);
        MCC_glDrv_glColor4usArgs * glDrv_glColor4usArg = (MCC_glDrv_glColor4usArgs *)argBuffer;
        glDrv_glColor4us(glDrv_glColor4usArg->red, glDrv_glColor4usArg->green, glDrv_glColor4usArg->blue, glDrv_glColor4usArg->alpha);
        break;
      case MCC_glDrv_glColor4usv :
        CHECKSIZE(MCC_glDrv_glColor4usvArgs);
        MCC_glDrv_glColor4usvArgs * glDrv_glColor4usvArg = (MCC_glDrv_glColor4usvArgs *)argBuffer;
        glDrv_glColor4usv(glDrv_glColor4usvArg->v);
        break;
      case MCC_glDrv_glColorMask :
        CHECKSIZE(MCC_glDrv_glColorMaskArgs);
        MCC_glDrv_glColorMaskArgs * glDrv_glColorMaskArg = (MCC_glDrv_glColorMaskArgs *)argBuffer;
        glDrv_glColorMask(glDrv_glColorMaskArg->red, glDrv_glColorMaskArg->green, glDrv_glColorMaskArg->blue, glDrv_glColorMaskArg->alpha);
        break;
      case MCC_glDrv_glColorMaterial :
        CHECKSIZE(MCC_glDrv_glColorMaterialArgs);
        MCC_glDrv_glColorMaterialArgs * glDrv_glColorMaterialArg = (MCC_glDrv_glColorMaterialArgs *)argBuffer;
        glDrv_glColorMaterial(glDrv_glColorMaterialArg->face, glDrv_glColorMaterialArg->mode);
        break;
      case MCC_glDrv_glCopyPixels :
        CHECKSIZE(MCC_glDrv_glCopyPixelsArgs);
        MCC_glDrv_glCopyPixelsArgs * glDrv_glCopyPixelsArg = (MCC_glDrv_glCopyPixelsArgs *)argBuffer;
        glDrv_glCopyPixels(glDrv_glCopyPixelsArg->x, glDrv_glCopyPixelsArg->y, glDrv_glCopyPixelsArg->width, glDrv_glCopyPixelsArg->height, glDrv_glCopyPixelsArg->type);
        break;
      case MCC_glDrv_glCullFace :
        CHECKSIZE(MCC_glDrv_glCullFaceArgs);
        MCC_glDrv_glCullFaceArgs * glDrv_glCullFaceArg = (MCC_glDrv_glCullFaceArgs *)argBuffer;
        glDrv_glCullFace(glDrv_glCullFaceArg->mode);
        break;
      case MCC_glDrv_glDeleteLists :
        CHECKSIZE(MCC_glDrv_glDeleteListsArgs);
        MCC_glDrv_glDeleteListsArgs * glDrv_glDeleteListsArg = (MCC_glDrv_glDeleteListsArgs *)argBuffer;
        glDrv_glDeleteLists(glDrv_glDeleteListsArg->list, glDrv_glDeleteListsArg->range);
        break;
      case MCC_glDrv_glDepthFunc :
        CHECKSIZE(MCC_glDrv_glDepthFuncArgs);
        MCC_glDrv_glDepthFuncArgs * glDrv_glDepthFuncArg = (MCC_glDrv_glDepthFuncArgs *)argBuffer;
        glDrv_glDepthFunc(glDrv_glDepthFuncArg->func);
        break;
      case MCC_glDrv_glDepthMask :
        CHECKSIZE(MCC_glDrv_glDepthMaskArgs);
        MCC_glDrv_glDepthMaskArgs * glDrv_glDepthMaskArg = (MCC_glDrv_glDepthMaskArgs *)argBuffer;
        glDrv_glDepthMask(glDrv_glDepthMaskArg->flag);
        break;
      case MCC_glDrv_glDepthRange :
        CHECKSIZE(MCC_glDrv_glDepthRangeArgs);
        MCC_glDrv_glDepthRangeArgs * glDrv_glDepthRangeArg = (MCC_glDrv_glDepthRangeArgs *)argBuffer;
        glDrv_glDepthRange(glDrv_glDepthRangeArg->zNear, glDrv_glDepthRangeArg->zFar);
        break;
      case MCC_glDrv_glDisable :
        CHECKSIZE(MCC_glDrv_glDisableArgs);
        MCC_glDrv_glDisableArgs * glDrv_glDisableArg = (MCC_glDrv_glDisableArgs *)argBuffer;
        glDrv_glDisable(glDrv_glDisableArg->cap);
        break;
      case MCC_glDrv_glDrawBuffer :
        CHECKSIZE(MCC_glDrv_glDrawBufferArgs);
        MCC_glDrv_glDrawBufferArgs * glDrv_glDrawBufferArg = (MCC_glDrv_glDrawBufferArgs *)argBuffer;
        glDrv_glDrawBuffer(glDrv_glDrawBufferArg->mode);
        break;
      case MCC_glDrv_glDrawPixels :
        CHECKSIZE(MCC_glDrv_glDrawPixelsArgs);
        MCC_glDrv_glDrawPixelsArgs * glDrv_glDrawPixelsArg = (MCC_glDrv_glDrawPixelsArgs *)argBuffer;
        glDrv_glDrawPixels(glDrv_glDrawPixelsArg->width, glDrv_glDrawPixelsArg->height, glDrv_glDrawPixelsArg->format, glDrv_glDrawPixelsArg->type, glDrv_glDrawPixelsArg->pixels);
        break;
      case MCC_glDrv_glEdgeFlag :
        CHECKSIZE(MCC_glDrv_glEdgeFlagArgs);
        MCC_glDrv_glEdgeFlagArgs * glDrv_glEdgeFlagArg = (MCC_glDrv_glEdgeFlagArgs *)argBuffer;
        glDrv_glEdgeFlag(glDrv_glEdgeFlagArg->flag);
        break;
      case MCC_glDrv_glEdgeFlagv :
        CHECKSIZE(MCC_glDrv_glEdgeFlagvArgs);
        MCC_glDrv_glEdgeFlagvArgs * glDrv_glEdgeFlagvArg = (MCC_glDrv_glEdgeFlagvArgs *)argBuffer;
        glDrv_glEdgeFlagv(glDrv_glEdgeFlagvArg->flag);
        break;
      case MCC_glDrv_glEnable :
        CHECKSIZE(MCC_glDrv_glEnableArgs);
        MCC_glDrv_glEnableArgs * glDrv_glEnableArg = (MCC_glDrv_glEnableArgs *)argBuffer;
        glDrv_glEnable(glDrv_glEnableArg->cap);
        break;
      case MCC_glDrv_glEnd :
        CHECKSIZE(MCC_glDrv_glEndArgs);
        MCC_glDrv_glEndArgs * glDrv_glEndArg = (MCC_glDrv_glEndArgs *)argBuffer;
        glDrv_glEnd();
        break;
      case MCC_glDrv_glEndList :
        CHECKSIZE(MCC_glDrv_glEndListArgs);
        MCC_glDrv_glEndListArgs * glDrv_glEndListArg = (MCC_glDrv_glEndListArgs *)argBuffer;
        glDrv_glEndList();
        break;
      case MCC_glDrv_glEvalCoord1d :
        CHECKSIZE(MCC_glDrv_glEvalCoord1dArgs);
        MCC_glDrv_glEvalCoord1dArgs * glDrv_glEvalCoord1dArg = (MCC_glDrv_glEvalCoord1dArgs *)argBuffer;
        glDrv_glEvalCoord1d(glDrv_glEvalCoord1dArg->u);
        break;
      case MCC_glDrv_glEvalCoord1dv :
        CHECKSIZE(MCC_glDrv_glEvalCoord1dvArgs);
        MCC_glDrv_glEvalCoord1dvArgs * glDrv_glEvalCoord1dvArg = (MCC_glDrv_glEvalCoord1dvArgs *)argBuffer;
        glDrv_glEvalCoord1dv(glDrv_glEvalCoord1dvArg->u);
        break;
      case MCC_glDrv_glEvalCoord1f :
        CHECKSIZE(MCC_glDrv_glEvalCoord1fArgs);
        MCC_glDrv_glEvalCoord1fArgs * glDrv_glEvalCoord1fArg = (MCC_glDrv_glEvalCoord1fArgs *)argBuffer;
        glDrv_glEvalCoord1f(glDrv_glEvalCoord1fArg->u);
        break;
      case MCC_glDrv_glEvalCoord1fv :
        CHECKSIZE(MCC_glDrv_glEvalCoord1fvArgs);
        MCC_glDrv_glEvalCoord1fvArgs * glDrv_glEvalCoord1fvArg = (MCC_glDrv_glEvalCoord1fvArgs *)argBuffer;
        glDrv_glEvalCoord1fv(glDrv_glEvalCoord1fvArg->u);
        break;
      case MCC_glDrv_glEvalCoord2d :
        CHECKSIZE(MCC_glDrv_glEvalCoord2dArgs);
        MCC_glDrv_glEvalCoord2dArgs * glDrv_glEvalCoord2dArg = (MCC_glDrv_glEvalCoord2dArgs *)argBuffer;
        glDrv_glEvalCoord2d(glDrv_glEvalCoord2dArg->u, glDrv_glEvalCoord2dArg->v);
        break;
      case MCC_glDrv_glEvalCoord2dv :
        CHECKSIZE(MCC_glDrv_glEvalCoord2dvArgs);
        MCC_glDrv_glEvalCoord2dvArgs * glDrv_glEvalCoord2dvArg = (MCC_glDrv_glEvalCoord2dvArgs *)argBuffer;
        glDrv_glEvalCoord2dv(glDrv_glEvalCoord2dvArg->u);
        break;
      case MCC_glDrv_glEvalCoord2f :
        CHECKSIZE(MCC_glDrv_glEvalCoord2fArgs);
        MCC_glDrv_glEvalCoord2fArgs * glDrv_glEvalCoord2fArg = (MCC_glDrv_glEvalCoord2fArgs *)argBuffer;
        glDrv_glEvalCoord2f(glDrv_glEvalCoord2fArg->u, glDrv_glEvalCoord2fArg->v);
        break;
      case MCC_glDrv_glEvalCoord2fv :
        CHECKSIZE(MCC_glDrv_glEvalCoord2fvArgs);
        MCC_glDrv_glEvalCoord2fvArgs * glDrv_glEvalCoord2fvArg = (MCC_glDrv_glEvalCoord2fvArgs *)argBuffer;
        glDrv_glEvalCoord2fv(glDrv_glEvalCoord2fvArg->u);
        break;
      case MCC_glDrv_glEvalMesh1 :
        CHECKSIZE(MCC_glDrv_glEvalMesh1Args);
        MCC_glDrv_glEvalMesh1Args * glDrv_glEvalMesh1Arg = (MCC_glDrv_glEvalMesh1Args *)argBuffer;
        glDrv_glEvalMesh1(glDrv_glEvalMesh1Arg->mode, glDrv_glEvalMesh1Arg->i1, glDrv_glEvalMesh1Arg->i2);
        break;
      case MCC_glDrv_glEvalMesh2 :
        CHECKSIZE(MCC_glDrv_glEvalMesh2Args);
        MCC_glDrv_glEvalMesh2Args * glDrv_glEvalMesh2Arg = (MCC_glDrv_glEvalMesh2Args *)argBuffer;
        glDrv_glEvalMesh2(glDrv_glEvalMesh2Arg->mode, glDrv_glEvalMesh2Arg->i1, glDrv_glEvalMesh2Arg->i2, glDrv_glEvalMesh2Arg->j1, glDrv_glEvalMesh2Arg->j2);
        break;
      case MCC_glDrv_glEvalPoint1 :
        CHECKSIZE(MCC_glDrv_glEvalPoint1Args);
        MCC_glDrv_glEvalPoint1Args * glDrv_glEvalPoint1Arg = (MCC_glDrv_glEvalPoint1Args *)argBuffer;
        glDrv_glEvalPoint1(glDrv_glEvalPoint1Arg->i);
        break;
      case MCC_glDrv_glEvalPoint2 :
        CHECKSIZE(MCC_glDrv_glEvalPoint2Args);
        MCC_glDrv_glEvalPoint2Args * glDrv_glEvalPoint2Arg = (MCC_glDrv_glEvalPoint2Args *)argBuffer;
        glDrv_glEvalPoint2(glDrv_glEvalPoint2Arg->i, glDrv_glEvalPoint2Arg->j);
        break;
      case MCC_glDrv_glFeedbackBuffer :
        CHECKSIZE(MCC_glDrv_glFeedbackBufferArgs);
        MCC_glDrv_glFeedbackBufferArgs * glDrv_glFeedbackBufferArg = (MCC_glDrv_glFeedbackBufferArgs *)argBuffer;
        glDrv_glFeedbackBuffer(glDrv_glFeedbackBufferArg->size, glDrv_glFeedbackBufferArg->type, glDrv_glFeedbackBufferArg->buffer);
        break;
      case MCC_glDrv_glFinish :
        CHECKSIZE(MCC_glDrv_glFinishArgs);
        MCC_glDrv_glFinishArgs * glDrv_glFinishArg = (MCC_glDrv_glFinishArgs *)argBuffer;
        glDrv_glFinish();
        break;
      case MCC_glDrv_glFlush :
        CHECKSIZE(MCC_glDrv_glFlushArgs);
        MCC_glDrv_glFlushArgs * glDrv_glFlushArg = (MCC_glDrv_glFlushArgs *)argBuffer;
        glDrv_glFlush();
        break;
      case MCC_glDrv_glFogf :
        CHECKSIZE(MCC_glDrv_glFogfArgs);
        MCC_glDrv_glFogfArgs * glDrv_glFogfArg = (MCC_glDrv_glFogfArgs *)argBuffer;
        glDrv_glFogf(glDrv_glFogfArg->pname, glDrv_glFogfArg->param);
        break;
      case MCC_glDrv_glFogfv :
        CHECKSIZE(MCC_glDrv_glFogfvArgs);
        MCC_glDrv_glFogfvArgs * glDrv_glFogfvArg = (MCC_glDrv_glFogfvArgs *)argBuffer;
        glDrv_glFogfv(glDrv_glFogfvArg->pname, glDrv_glFogfvArg->params);
        break;
      case MCC_glDrv_glFogi :
        CHECKSIZE(MCC_glDrv_glFogiArgs);
        MCC_glDrv_glFogiArgs * glDrv_glFogiArg = (MCC_glDrv_glFogiArgs *)argBuffer;
        glDrv_glFogi(glDrv_glFogiArg->pname, glDrv_glFogiArg->param);
        break;
      case MCC_glDrv_glFogiv :
        CHECKSIZE(MCC_glDrv_glFogivArgs);
        MCC_glDrv_glFogivArgs * glDrv_glFogivArg = (MCC_glDrv_glFogivArgs *)argBuffer;
        glDrv_glFogiv(glDrv_glFogivArg->pname, glDrv_glFogivArg->params);
        break;
      case MCC_glDrv_glFrontFace :
        CHECKSIZE(MCC_glDrv_glFrontFaceArgs);
        MCC_glDrv_glFrontFaceArgs * glDrv_glFrontFaceArg = (MCC_glDrv_glFrontFaceArgs *)argBuffer;
        glDrv_glFrontFace(glDrv_glFrontFaceArg->mode);
        break;
      case MCC_glDrv_glFrustum :
        CHECKSIZE(MCC_glDrv_glFrustumArgs);
        MCC_glDrv_glFrustumArgs * glDrv_glFrustumArg = (MCC_glDrv_glFrustumArgs *)argBuffer;
        glDrv_glFrustum(glDrv_glFrustumArg->left, glDrv_glFrustumArg->right, glDrv_glFrustumArg->bottom, glDrv_glFrustumArg->top, glDrv_glFrustumArg->zNear, glDrv_glFrustumArg->zFar);
        break;
      case MCC_glDrv_glGenLists :
        CHECKSIZE(MCC_glDrv_glGenListsArgs);
        MCC_glDrv_glGenListsArgs * glDrv_glGenListsArg = (MCC_glDrv_glGenListsArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_glGenLists(glDrv_glGenListsArg->range));
        break;
      case MCC_glDrv_glGetBooleanv :
        CHECKSIZE(MCC_glDrv_glGetBooleanvArgs);
        MCC_glDrv_glGetBooleanvArgs * glDrv_glGetBooleanvArg = (MCC_glDrv_glGetBooleanvArgs *)argBuffer;
        glDrv_glGetBooleanv(glDrv_glGetBooleanvArg->pname, glDrv_glGetBooleanvArg->params);
        break;
      case MCC_glDrv_glGetClipPlane :
        CHECKSIZE(MCC_glDrv_glGetClipPlaneArgs);
        MCC_glDrv_glGetClipPlaneArgs * glDrv_glGetClipPlaneArg = (MCC_glDrv_glGetClipPlaneArgs *)argBuffer;
        glDrv_glGetClipPlane(glDrv_glGetClipPlaneArg->plane, glDrv_glGetClipPlaneArg->equation);
        break;
      case MCC_glDrv_glGetDoublev :
        CHECKSIZE(MCC_glDrv_glGetDoublevArgs);
        MCC_glDrv_glGetDoublevArgs * glDrv_glGetDoublevArg = (MCC_glDrv_glGetDoublevArgs *)argBuffer;
        glDrv_glGetDoublev(glDrv_glGetDoublevArg->pname, glDrv_glGetDoublevArg->params);
        break;
      case MCC_glDrv_glGetError :
        CHECKSIZE(MCC_glDrv_glGetErrorArgs);
        MCC_glDrv_glGetErrorArgs * glDrv_glGetErrorArg = (MCC_glDrv_glGetErrorArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_glGetError());
        break;
      case MCC_glDrv_glGetFloatv :
        CHECKSIZE(MCC_glDrv_glGetFloatvArgs);
        MCC_glDrv_glGetFloatvArgs * glDrv_glGetFloatvArg = (MCC_glDrv_glGetFloatvArgs *)argBuffer;
        glDrv_glGetFloatv(glDrv_glGetFloatvArg->pname, glDrv_glGetFloatvArg->params);
        break;
      case MCC_glDrv_glGetIntegerv :
        CHECKSIZE(MCC_glDrv_glGetIntegervArgs);
        MCC_glDrv_glGetIntegervArgs * glDrv_glGetIntegervArg = (MCC_glDrv_glGetIntegervArgs *)argBuffer;
        glDrv_glGetIntegerv(glDrv_glGetIntegervArg->pname, glDrv_glGetIntegervArg->params);
        break;
      case MCC_glDrv_glGetLightfv :
        CHECKSIZE(MCC_glDrv_glGetLightfvArgs);
        MCC_glDrv_glGetLightfvArgs * glDrv_glGetLightfvArg = (MCC_glDrv_glGetLightfvArgs *)argBuffer;
        glDrv_glGetLightfv(glDrv_glGetLightfvArg->light, glDrv_glGetLightfvArg->pname, glDrv_glGetLightfvArg->params);
        break;
      case MCC_glDrv_glGetLightiv :
        CHECKSIZE(MCC_glDrv_glGetLightivArgs);
        MCC_glDrv_glGetLightivArgs * glDrv_glGetLightivArg = (MCC_glDrv_glGetLightivArgs *)argBuffer;
        glDrv_glGetLightiv(glDrv_glGetLightivArg->light, glDrv_glGetLightivArg->pname, glDrv_glGetLightivArg->params);
        break;
      case MCC_glDrv_glGetMapdv :
        CHECKSIZE(MCC_glDrv_glGetMapdvArgs);
        MCC_glDrv_glGetMapdvArgs * glDrv_glGetMapdvArg = (MCC_glDrv_glGetMapdvArgs *)argBuffer;
        glDrv_glGetMapdv(glDrv_glGetMapdvArg->target, glDrv_glGetMapdvArg->query, glDrv_glGetMapdvArg->v);
        break;
      case MCC_glDrv_glGetMapfv :
        CHECKSIZE(MCC_glDrv_glGetMapfvArgs);
        MCC_glDrv_glGetMapfvArgs * glDrv_glGetMapfvArg = (MCC_glDrv_glGetMapfvArgs *)argBuffer;
        glDrv_glGetMapfv(glDrv_glGetMapfvArg->target, glDrv_glGetMapfvArg->query, glDrv_glGetMapfvArg->v);
        break;
      case MCC_glDrv_glGetMapiv :
        CHECKSIZE(MCC_glDrv_glGetMapivArgs);
        MCC_glDrv_glGetMapivArgs * glDrv_glGetMapivArg = (MCC_glDrv_glGetMapivArgs *)argBuffer;
        glDrv_glGetMapiv(glDrv_glGetMapivArg->target, glDrv_glGetMapivArg->query, glDrv_glGetMapivArg->v);
        break;
      case MCC_glDrv_glGetMaterialfv :
        CHECKSIZE(MCC_glDrv_glGetMaterialfvArgs);
        MCC_glDrv_glGetMaterialfvArgs * glDrv_glGetMaterialfvArg = (MCC_glDrv_glGetMaterialfvArgs *)argBuffer;
        glDrv_glGetMaterialfv(glDrv_glGetMaterialfvArg->face, glDrv_glGetMaterialfvArg->pname, glDrv_glGetMaterialfvArg->params);
        break;
      case MCC_glDrv_glGetMaterialiv :
        CHECKSIZE(MCC_glDrv_glGetMaterialivArgs);
        MCC_glDrv_glGetMaterialivArgs * glDrv_glGetMaterialivArg = (MCC_glDrv_glGetMaterialivArgs *)argBuffer;
        glDrv_glGetMaterialiv(glDrv_glGetMaterialivArg->face, glDrv_glGetMaterialivArg->pname, glDrv_glGetMaterialivArg->params);
        break;
      case MCC_glDrv_glGetPixelMapfv :
        CHECKSIZE(MCC_glDrv_glGetPixelMapfvArgs);
        MCC_glDrv_glGetPixelMapfvArgs * glDrv_glGetPixelMapfvArg = (MCC_glDrv_glGetPixelMapfvArgs *)argBuffer;
        glDrv_glGetPixelMapfv(glDrv_glGetPixelMapfvArg->map, glDrv_glGetPixelMapfvArg->values);
        break;
      case MCC_glDrv_glGetPixelMapuiv :
        CHECKSIZE(MCC_glDrv_glGetPixelMapuivArgs);
        MCC_glDrv_glGetPixelMapuivArgs * glDrv_glGetPixelMapuivArg = (MCC_glDrv_glGetPixelMapuivArgs *)argBuffer;
        glDrv_glGetPixelMapuiv(glDrv_glGetPixelMapuivArg->map, glDrv_glGetPixelMapuivArg->values);
        break;
      case MCC_glDrv_glGetPixelMapusv :
        CHECKSIZE(MCC_glDrv_glGetPixelMapusvArgs);
        MCC_glDrv_glGetPixelMapusvArgs * glDrv_glGetPixelMapusvArg = (MCC_glDrv_glGetPixelMapusvArgs *)argBuffer;
        glDrv_glGetPixelMapusv(glDrv_glGetPixelMapusvArg->map, glDrv_glGetPixelMapusvArg->values);
        break;
      case MCC_glDrv_glGetPolygonStipple :
        CHECKSIZE(MCC_glDrv_glGetPolygonStippleArgs);
        MCC_glDrv_glGetPolygonStippleArgs * glDrv_glGetPolygonStippleArg = (MCC_glDrv_glGetPolygonStippleArgs *)argBuffer;
        glDrv_glGetPolygonStipple(glDrv_glGetPolygonStippleArg->mask);
        break;
      case MCC_glDrv_glGetString :
        CHECKSIZE(MCC_glDrv_glGetStringArgs);
        MCC_glDrv_glGetStringArgs * MCC_glDrv_glGetStringArg = (MCC_glDrv_glGetStringArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_glGetString(  MCC_glDrv_glGetStringArg->name));
        break;
      case MCC_glDrv_glGetTexEnvfv :
        CHECKSIZE(MCC_glDrv_glGetTexEnvfvArgs);
        MCC_glDrv_glGetTexEnvfvArgs * glDrv_glGetTexEnvfvArg = (MCC_glDrv_glGetTexEnvfvArgs *)argBuffer;
        glDrv_glGetTexEnvfv(glDrv_glGetTexEnvfvArg->target, glDrv_glGetTexEnvfvArg->pname, glDrv_glGetTexEnvfvArg->params);
        break;
      case MCC_glDrv_glGetTexEnviv :
        CHECKSIZE(MCC_glDrv_glGetTexEnvivArgs);
        MCC_glDrv_glGetTexEnvivArgs * glDrv_glGetTexEnvivArg = (MCC_glDrv_glGetTexEnvivArgs *)argBuffer;
        glDrv_glGetTexEnviv(glDrv_glGetTexEnvivArg->target, glDrv_glGetTexEnvivArg->pname, glDrv_glGetTexEnvivArg->params);
        break;
      case MCC_glDrv_glGetTexGendv :
        CHECKSIZE(MCC_glDrv_glGetTexGendvArgs);
        MCC_glDrv_glGetTexGendvArgs * glDrv_glGetTexGendvArg = (MCC_glDrv_glGetTexGendvArgs *)argBuffer;
        glDrv_glGetTexGendv(glDrv_glGetTexGendvArg->coord, glDrv_glGetTexGendvArg->pname, glDrv_glGetTexGendvArg->params);
        break;
      case MCC_glDrv_glGetTexGenfv :
        CHECKSIZE(MCC_glDrv_glGetTexGenfvArgs);
        MCC_glDrv_glGetTexGenfvArgs * glDrv_glGetTexGenfvArg = (MCC_glDrv_glGetTexGenfvArgs *)argBuffer;
        glDrv_glGetTexGenfv(glDrv_glGetTexGenfvArg->coord, glDrv_glGetTexGenfvArg->pname, glDrv_glGetTexGenfvArg->params);
        break;
      case MCC_glDrv_glGetTexGeniv :
        CHECKSIZE(MCC_glDrv_glGetTexGenivArgs);
        MCC_glDrv_glGetTexGenivArgs * glDrv_glGetTexGenivArg = (MCC_glDrv_glGetTexGenivArgs *)argBuffer;
        glDrv_glGetTexGeniv(glDrv_glGetTexGenivArg->coord, glDrv_glGetTexGenivArg->pname, glDrv_glGetTexGenivArg->params);
        break;
      case MCC_glDrv_glGetTexImage :
        CHECKSIZE(MCC_glDrv_glGetTexImageArgs);
        MCC_glDrv_glGetTexImageArgs * glDrv_glGetTexImageArg = (MCC_glDrv_glGetTexImageArgs *)argBuffer;
        glDrv_glGetTexImage(glDrv_glGetTexImageArg->target, glDrv_glGetTexImageArg->level, glDrv_glGetTexImageArg->format, glDrv_glGetTexImageArg->type, glDrv_glGetTexImageArg->pixels);
        break;
      case MCC_glDrv_glGetTexLevelParameterfv :
        CHECKSIZE(MCC_glDrv_glGetTexLevelParameterfvArgs);
        MCC_glDrv_glGetTexLevelParameterfvArgs * glDrv_glGetTexLevelParameterfvArg = (MCC_glDrv_glGetTexLevelParameterfvArgs *)argBuffer;
        glDrv_glGetTexLevelParameterfv(glDrv_glGetTexLevelParameterfvArg->target, glDrv_glGetTexLevelParameterfvArg->level, glDrv_glGetTexLevelParameterfvArg->pname, glDrv_glGetTexLevelParameterfvArg->params);
        break;
      case MCC_glDrv_glGetTexLevelParameteriv :
        CHECKSIZE(MCC_glDrv_glGetTexLevelParameterivArgs);
        MCC_glDrv_glGetTexLevelParameterivArgs * glDrv_glGetTexLevelParameterivArg = (MCC_glDrv_glGetTexLevelParameterivArgs *)argBuffer;
        glDrv_glGetTexLevelParameteriv(glDrv_glGetTexLevelParameterivArg->target, glDrv_glGetTexLevelParameterivArg->level, glDrv_glGetTexLevelParameterivArg->pname, glDrv_glGetTexLevelParameterivArg->params);
        break;
      case MCC_glDrv_glGetTexParameterfv :
        CHECKSIZE(MCC_glDrv_glGetTexParameterfvArgs);
        MCC_glDrv_glGetTexParameterfvArgs * glDrv_glGetTexParameterfvArg = (MCC_glDrv_glGetTexParameterfvArgs *)argBuffer;
        glDrv_glGetTexParameterfv(glDrv_glGetTexParameterfvArg->target, glDrv_glGetTexParameterfvArg->pname, glDrv_glGetTexParameterfvArg->params);
        break;
      case MCC_glDrv_glGetTexParameteriv :
        CHECKSIZE(MCC_glDrv_glGetTexParameterivArgs);
        MCC_glDrv_glGetTexParameterivArgs * glDrv_glGetTexParameterivArg = (MCC_glDrv_glGetTexParameterivArgs *)argBuffer;
        glDrv_glGetTexParameteriv(glDrv_glGetTexParameterivArg->target, glDrv_glGetTexParameterivArg->pname, glDrv_glGetTexParameterivArg->params);
        break;
      case MCC_glDrv_glHint :
        CHECKSIZE(MCC_glDrv_glHintArgs);
        MCC_glDrv_glHintArgs * glDrv_glHintArg = (MCC_glDrv_glHintArgs *)argBuffer;
        glDrv_glHint(glDrv_glHintArg->target, glDrv_glHintArg->mode);
        break;
      case MCC_glDrv_glIndexMask :
        CHECKSIZE(MCC_glDrv_glIndexMaskArgs);
        MCC_glDrv_glIndexMaskArgs * glDrv_glIndexMaskArg = (MCC_glDrv_glIndexMaskArgs *)argBuffer;
        glDrv_glIndexMask(glDrv_glIndexMaskArg->mask);
        break;
      case MCC_glDrv_glIndexd :
        CHECKSIZE(MCC_glDrv_glIndexdArgs);
        MCC_glDrv_glIndexdArgs * glDrv_glIndexdArg = (MCC_glDrv_glIndexdArgs *)argBuffer;
        glDrv_glIndexd(glDrv_glIndexdArg->c);
        break;
      case MCC_glDrv_glIndexdv :
        CHECKSIZE(MCC_glDrv_glIndexdvArgs);
        MCC_glDrv_glIndexdvArgs * glDrv_glIndexdvArg = (MCC_glDrv_glIndexdvArgs *)argBuffer;
        glDrv_glIndexdv(glDrv_glIndexdvArg->c);
        break;
      case MCC_glDrv_glIndexf :
        CHECKSIZE(MCC_glDrv_glIndexfArgs);
        MCC_glDrv_glIndexfArgs * glDrv_glIndexfArg = (MCC_glDrv_glIndexfArgs *)argBuffer;
        glDrv_glIndexf(glDrv_glIndexfArg->c);
        break;
      case MCC_glDrv_glIndexfv :
        CHECKSIZE(MCC_glDrv_glIndexfvArgs);
        MCC_glDrv_glIndexfvArgs * glDrv_glIndexfvArg = (MCC_glDrv_glIndexfvArgs *)argBuffer;
        glDrv_glIndexfv(glDrv_glIndexfvArg->c);
        break;
      case MCC_glDrv_glIndexi :
        CHECKSIZE(MCC_glDrv_glIndexiArgs);
        MCC_glDrv_glIndexiArgs * glDrv_glIndexiArg = (MCC_glDrv_glIndexiArgs *)argBuffer;
        glDrv_glIndexi(glDrv_glIndexiArg->c);
        break;
      case MCC_glDrv_glIndexiv :
        CHECKSIZE(MCC_glDrv_glIndexivArgs);
        MCC_glDrv_glIndexivArgs * glDrv_glIndexivArg = (MCC_glDrv_glIndexivArgs *)argBuffer;
        glDrv_glIndexiv(glDrv_glIndexivArg->c);
        break;
      case MCC_glDrv_glIndexs :
        CHECKSIZE(MCC_glDrv_glIndexsArgs);
        MCC_glDrv_glIndexsArgs * glDrv_glIndexsArg = (MCC_glDrv_glIndexsArgs *)argBuffer;
        glDrv_glIndexs(glDrv_glIndexsArg->c);
        break;
      case MCC_glDrv_glIndexsv :
        CHECKSIZE(MCC_glDrv_glIndexsvArgs);
        MCC_glDrv_glIndexsvArgs * glDrv_glIndexsvArg = (MCC_glDrv_glIndexsvArgs *)argBuffer;
        glDrv_glIndexsv(glDrv_glIndexsvArg->c);
        break;
      case MCC_glDrv_glInitNames :
        CHECKSIZE(MCC_glDrv_glInitNamesArgs);
        MCC_glDrv_glInitNamesArgs * glDrv_glInitNamesArg = (MCC_glDrv_glInitNamesArgs *)argBuffer;
        glDrv_glInitNames();
        break;
      case MCC_glDrv_glIsEnabled :
        CHECKSIZE(MCC_glDrv_glIsEnabledArgs);
        MCC_glDrv_glIsEnabledArgs * glDrv_glIsEnabledArg = (MCC_glDrv_glIsEnabledArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_glIsEnabled(glDrv_glIsEnabledArg->cap));
        break;
      case MCC_glDrv_glIsList :
        CHECKSIZE(MCC_glDrv_glIsListArgs);
        MCC_glDrv_glIsListArgs * glDrv_glIsListArg = (MCC_glDrv_glIsListArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_glIsList(glDrv_glIsListArg->list));
        break;
      case MCC_glDrv_glLightModelf :
        CHECKSIZE(MCC_glDrv_glLightModelfArgs);
        MCC_glDrv_glLightModelfArgs * glDrv_glLightModelfArg = (MCC_glDrv_glLightModelfArgs *)argBuffer;
        glDrv_glLightModelf(glDrv_glLightModelfArg->pname, glDrv_glLightModelfArg->param);
        break;
      case MCC_glDrv_glLightModelfv :
        CHECKSIZE(MCC_glDrv_glLightModelfvArgs);
        MCC_glDrv_glLightModelfvArgs * glDrv_glLightModelfvArg = (MCC_glDrv_glLightModelfvArgs *)argBuffer;
        glDrv_glLightModelfv(glDrv_glLightModelfvArg->pname, glDrv_glLightModelfvArg->params);
        break;
      case MCC_glDrv_glLightModeli :
        CHECKSIZE(MCC_glDrv_glLightModeliArgs);
        MCC_glDrv_glLightModeliArgs * glDrv_glLightModeliArg = (MCC_glDrv_glLightModeliArgs *)argBuffer;
        glDrv_glLightModeli(glDrv_glLightModeliArg->pname, glDrv_glLightModeliArg->param);
        break;
      case MCC_glDrv_glLightModeliv :
        CHECKSIZE(MCC_glDrv_glLightModelivArgs);
        MCC_glDrv_glLightModelivArgs * glDrv_glLightModelivArg = (MCC_glDrv_glLightModelivArgs *)argBuffer;
        glDrv_glLightModeliv(glDrv_glLightModelivArg->pname, glDrv_glLightModelivArg->params);
        break;
      case MCC_glDrv_glLightf :
        CHECKSIZE(MCC_glDrv_glLightfArgs);
        MCC_glDrv_glLightfArgs * glDrv_glLightfArg = (MCC_glDrv_glLightfArgs *)argBuffer;
        glDrv_glLightf(glDrv_glLightfArg->light, glDrv_glLightfArg->pname, glDrv_glLightfArg->param);
        break;
      case MCC_glDrv_glLightfv :
        CHECKSIZE(MCC_glDrv_glLightfvArgs);
        MCC_glDrv_glLightfvArgs * glDrv_glLightfvArg = (MCC_glDrv_glLightfvArgs *)argBuffer;
        glDrv_glLightfv(glDrv_glLightfvArg->light, glDrv_glLightfvArg->pname, glDrv_glLightfvArg->params);
        break;
      case MCC_glDrv_glLighti :
        CHECKSIZE(MCC_glDrv_glLightiArgs);
        MCC_glDrv_glLightiArgs * glDrv_glLightiArg = (MCC_glDrv_glLightiArgs *)argBuffer;
        glDrv_glLighti(glDrv_glLightiArg->light, glDrv_glLightiArg->pname, glDrv_glLightiArg->param);
        break;
      case MCC_glDrv_glLightiv :
        CHECKSIZE(MCC_glDrv_glLightivArgs);
        MCC_glDrv_glLightivArgs * glDrv_glLightivArg = (MCC_glDrv_glLightivArgs *)argBuffer;
        glDrv_glLightiv(glDrv_glLightivArg->light, glDrv_glLightivArg->pname, glDrv_glLightivArg->params);
        break;
      case MCC_glDrv_glLineStipple :
        CHECKSIZE(MCC_glDrv_glLineStippleArgs);
        MCC_glDrv_glLineStippleArgs * glDrv_glLineStippleArg = (MCC_glDrv_glLineStippleArgs *)argBuffer;
        glDrv_glLineStipple(glDrv_glLineStippleArg->factor, glDrv_glLineStippleArg->pattern);
        break;
      case MCC_glDrv_glLineWidth :
        CHECKSIZE(MCC_glDrv_glLineWidthArgs);
        MCC_glDrv_glLineWidthArgs * glDrv_glLineWidthArg = (MCC_glDrv_glLineWidthArgs *)argBuffer;
        glDrv_glLineWidth(glDrv_glLineWidthArg->width);
        break;
      case MCC_glDrv_glListBase :
        CHECKSIZE(MCC_glDrv_glListBaseArgs);
        MCC_glDrv_glListBaseArgs * glDrv_glListBaseArg = (MCC_glDrv_glListBaseArgs *)argBuffer;
        glDrv_glListBase(glDrv_glListBaseArg->base);
        break;
      case MCC_glDrv_glLoadIdentity :
        CHECKSIZE(MCC_glDrv_glLoadIdentityArgs);
        MCC_glDrv_glLoadIdentityArgs * glDrv_glLoadIdentityArg = (MCC_glDrv_glLoadIdentityArgs *)argBuffer;
        glDrv_glLoadIdentity();
        break;
      case MCC_glDrv_glLoadMatrixd :
        CHECKSIZE(MCC_glDrv_glLoadMatrixdArgs);
        MCC_glDrv_glLoadMatrixdArgs * glDrv_glLoadMatrixdArg = (MCC_glDrv_glLoadMatrixdArgs *)argBuffer;
        glDrv_glLoadMatrixd(glDrv_glLoadMatrixdArg->m);
        break;
      case MCC_glDrv_glLoadMatrixf :
        CHECKSIZE(MCC_glDrv_glLoadMatrixfArgs);
        MCC_glDrv_glLoadMatrixfArgs * glDrv_glLoadMatrixfArg = (MCC_glDrv_glLoadMatrixfArgs *)argBuffer;
        glDrv_glLoadMatrixf(glDrv_glLoadMatrixfArg->m);
        break;
      case MCC_glDrv_glLoadName :
        CHECKSIZE(MCC_glDrv_glLoadNameArgs);
        MCC_glDrv_glLoadNameArgs * glDrv_glLoadNameArg = (MCC_glDrv_glLoadNameArgs *)argBuffer;
        glDrv_glLoadName(glDrv_glLoadNameArg->name);
        break;
      case MCC_glDrv_glLogicOp :
        CHECKSIZE(MCC_glDrv_glLogicOpArgs);
        MCC_glDrv_glLogicOpArgs * glDrv_glLogicOpArg = (MCC_glDrv_glLogicOpArgs *)argBuffer;
        glDrv_glLogicOp(glDrv_glLogicOpArg->opcode);
        break;
      case MCC_glDrv_glMap1d :
        CHECKSIZE(MCC_glDrv_glMap1dArgs);
        MCC_glDrv_glMap1dArgs * glDrv_glMap1dArg = (MCC_glDrv_glMap1dArgs *)argBuffer;
        glDrv_glMap1d(glDrv_glMap1dArg->target, glDrv_glMap1dArg->u1, glDrv_glMap1dArg->u2, glDrv_glMap1dArg->stride, glDrv_glMap1dArg->order, glDrv_glMap1dArg->points);
        break;
      case MCC_glDrv_glMap1f :
        CHECKSIZE(MCC_glDrv_glMap1fArgs);
        MCC_glDrv_glMap1fArgs * glDrv_glMap1fArg = (MCC_glDrv_glMap1fArgs *)argBuffer;
        glDrv_glMap1f(glDrv_glMap1fArg->target, glDrv_glMap1fArg->u1, glDrv_glMap1fArg->u2, glDrv_glMap1fArg->stride, glDrv_glMap1fArg->order, glDrv_glMap1fArg->points);
        break;
      case MCC_glDrv_glMap2d :
        CHECKSIZE(MCC_glDrv_glMap2dArgs);
        MCC_glDrv_glMap2dArgs * glDrv_glMap2dArg = (MCC_glDrv_glMap2dArgs *)argBuffer;
        glDrv_glMap2d(glDrv_glMap2dArg->target, glDrv_glMap2dArg->u1, glDrv_glMap2dArg->u2, glDrv_glMap2dArg->ustride, glDrv_glMap2dArg->uorder, glDrv_glMap2dArg->v1, glDrv_glMap2dArg->v2, glDrv_glMap2dArg->vstride, glDrv_glMap2dArg->vorder, glDrv_glMap2dArg->points);
        break;
      case MCC_glDrv_glMap2f :
        CHECKSIZE(MCC_glDrv_glMap2fArgs);
        MCC_glDrv_glMap2fArgs * glDrv_glMap2fArg = (MCC_glDrv_glMap2fArgs *)argBuffer;
        glDrv_glMap2f(glDrv_glMap2fArg->target, glDrv_glMap2fArg->u1, glDrv_glMap2fArg->u2, glDrv_glMap2fArg->ustride, glDrv_glMap2fArg->uorder, glDrv_glMap2fArg->v1, glDrv_glMap2fArg->v2, glDrv_glMap2fArg->vstride, glDrv_glMap2fArg->vorder, glDrv_glMap2fArg->points);
        break;
      case MCC_glDrv_glMapGrid1d :
        CHECKSIZE(MCC_glDrv_glMapGrid1dArgs);
        MCC_glDrv_glMapGrid1dArgs * glDrv_glMapGrid1dArg = (MCC_glDrv_glMapGrid1dArgs *)argBuffer;
        glDrv_glMapGrid1d(glDrv_glMapGrid1dArg->un, glDrv_glMapGrid1dArg->u1, glDrv_glMapGrid1dArg->u2);
        break;
      case MCC_glDrv_glMapGrid1f :
        CHECKSIZE(MCC_glDrv_glMapGrid1fArgs);
        MCC_glDrv_glMapGrid1fArgs * glDrv_glMapGrid1fArg = (MCC_glDrv_glMapGrid1fArgs *)argBuffer;
        glDrv_glMapGrid1f(glDrv_glMapGrid1fArg->un, glDrv_glMapGrid1fArg->u1, glDrv_glMapGrid1fArg->u2);
        break;
      case MCC_glDrv_glMapGrid2d :
        CHECKSIZE(MCC_glDrv_glMapGrid2dArgs);
        MCC_glDrv_glMapGrid2dArgs * glDrv_glMapGrid2dArg = (MCC_glDrv_glMapGrid2dArgs *)argBuffer;
        glDrv_glMapGrid2d(glDrv_glMapGrid2dArg->un, glDrv_glMapGrid2dArg->u1, glDrv_glMapGrid2dArg->u2, glDrv_glMapGrid2dArg->vn, glDrv_glMapGrid2dArg->v1, glDrv_glMapGrid2dArg->v2);
        break;
      case MCC_glDrv_glMapGrid2f :
        CHECKSIZE(MCC_glDrv_glMapGrid2fArgs);
        MCC_glDrv_glMapGrid2fArgs * glDrv_glMapGrid2fArg = (MCC_glDrv_glMapGrid2fArgs *)argBuffer;
        glDrv_glMapGrid2f(glDrv_glMapGrid2fArg->un, glDrv_glMapGrid2fArg->u1, glDrv_glMapGrid2fArg->u2, glDrv_glMapGrid2fArg->vn, glDrv_glMapGrid2fArg->v1, glDrv_glMapGrid2fArg->v2);
        break;
      case MCC_glDrv_glMaterialf :
        CHECKSIZE(MCC_glDrv_glMaterialfArgs);
        MCC_glDrv_glMaterialfArgs * glDrv_glMaterialfArg = (MCC_glDrv_glMaterialfArgs *)argBuffer;
        glDrv_glMaterialf(glDrv_glMaterialfArg->face, glDrv_glMaterialfArg->pname, glDrv_glMaterialfArg->param);
        break;
      case MCC_glDrv_glMaterialfv :
        CHECKSIZE(MCC_glDrv_glMaterialfvArgs);
        MCC_glDrv_glMaterialfvArgs * glDrv_glMaterialfvArg = (MCC_glDrv_glMaterialfvArgs *)argBuffer;
        glDrv_glMaterialfv(glDrv_glMaterialfvArg->face, glDrv_glMaterialfvArg->pname, glDrv_glMaterialfvArg->params);
        break;
      case MCC_glDrv_glMateriali :
        CHECKSIZE(MCC_glDrv_glMaterialiArgs);
        MCC_glDrv_glMaterialiArgs * glDrv_glMaterialiArg = (MCC_glDrv_glMaterialiArgs *)argBuffer;
        glDrv_glMateriali(glDrv_glMaterialiArg->face, glDrv_glMaterialiArg->pname, glDrv_glMaterialiArg->param);
        break;
      case MCC_glDrv_glMaterialiv :
        CHECKSIZE(MCC_glDrv_glMaterialivArgs);
        MCC_glDrv_glMaterialivArgs * glDrv_glMaterialivArg = (MCC_glDrv_glMaterialivArgs *)argBuffer;
        glDrv_glMaterialiv(glDrv_glMaterialivArg->face, glDrv_glMaterialivArg->pname, glDrv_glMaterialivArg->params);
        break;
      case MCC_glDrv_glMatrixMode :
        CHECKSIZE(MCC_glDrv_glMatrixModeArgs);
        MCC_glDrv_glMatrixModeArgs * glDrv_glMatrixModeArg = (MCC_glDrv_glMatrixModeArgs *)argBuffer;
        glDrv_glMatrixMode(glDrv_glMatrixModeArg->mode);
        break;
      case MCC_glDrv_glMultMatrixd :
        CHECKSIZE(MCC_glDrv_glMultMatrixdArgs);
        MCC_glDrv_glMultMatrixdArgs * glDrv_glMultMatrixdArg = (MCC_glDrv_glMultMatrixdArgs *)argBuffer;
        glDrv_glMultMatrixd(glDrv_glMultMatrixdArg->m);
        break;
      case MCC_glDrv_glMultMatrixf :
        CHECKSIZE(MCC_glDrv_glMultMatrixfArgs);
        MCC_glDrv_glMultMatrixfArgs * glDrv_glMultMatrixfArg = (MCC_glDrv_glMultMatrixfArgs *)argBuffer;
        glDrv_glMultMatrixf(glDrv_glMultMatrixfArg->m);
        break;
      case MCC_glDrv_glNewList :
        CHECKSIZE(MCC_glDrv_glNewListArgs);
        MCC_glDrv_glNewListArgs * glDrv_glNewListArg = (MCC_glDrv_glNewListArgs *)argBuffer;
        glDrv_glNewList(glDrv_glNewListArg->list, glDrv_glNewListArg->mode);
        break;
      case MCC_glDrv_glNormal3b :
        CHECKSIZE(MCC_glDrv_glNormal3bArgs);
        MCC_glDrv_glNormal3bArgs * glDrv_glNormal3bArg = (MCC_glDrv_glNormal3bArgs *)argBuffer;
        glDrv_glNormal3b(glDrv_glNormal3bArg->nx, glDrv_glNormal3bArg->ny, glDrv_glNormal3bArg->nz);
        break;
      case MCC_glDrv_glNormal3bv :
        CHECKSIZE(MCC_glDrv_glNormal3bvArgs);
        MCC_glDrv_glNormal3bvArgs * glDrv_glNormal3bvArg = (MCC_glDrv_glNormal3bvArgs *)argBuffer;
        glDrv_glNormal3bv(glDrv_glNormal3bvArg->v);
        break;
      case MCC_glDrv_glNormal3d :
        CHECKSIZE(MCC_glDrv_glNormal3dArgs);
        MCC_glDrv_glNormal3dArgs * glDrv_glNormal3dArg = (MCC_glDrv_glNormal3dArgs *)argBuffer;
        glDrv_glNormal3d(glDrv_glNormal3dArg->nx, glDrv_glNormal3dArg->ny, glDrv_glNormal3dArg->nz);
        break;
      case MCC_glDrv_glNormal3dv :
        CHECKSIZE(MCC_glDrv_glNormal3dvArgs);
        MCC_glDrv_glNormal3dvArgs * glDrv_glNormal3dvArg = (MCC_glDrv_glNormal3dvArgs *)argBuffer;
        glDrv_glNormal3dv(glDrv_glNormal3dvArg->v);
        break;
      case MCC_glDrv_glNormal3f :
        CHECKSIZE(MCC_glDrv_glNormal3fArgs);
        MCC_glDrv_glNormal3fArgs * glDrv_glNormal3fArg = (MCC_glDrv_glNormal3fArgs *)argBuffer;
        glDrv_glNormal3f(glDrv_glNormal3fArg->nx, glDrv_glNormal3fArg->ny, glDrv_glNormal3fArg->nz);
        break;
      case MCC_glDrv_glNormal3fv :
        CHECKSIZE(MCC_glDrv_glNormal3fvArgs);
        MCC_glDrv_glNormal3fvArgs * glDrv_glNormal3fvArg = (MCC_glDrv_glNormal3fvArgs *)argBuffer;
        glDrv_glNormal3fv(glDrv_glNormal3fvArg->v);
        break;
      case MCC_glDrv_glNormal3i :
        CHECKSIZE(MCC_glDrv_glNormal3iArgs);
        MCC_glDrv_glNormal3iArgs * glDrv_glNormal3iArg = (MCC_glDrv_glNormal3iArgs *)argBuffer;
        glDrv_glNormal3i(glDrv_glNormal3iArg->nx, glDrv_glNormal3iArg->ny, glDrv_glNormal3iArg->nz);
        break;
      case MCC_glDrv_glNormal3iv :
        CHECKSIZE(MCC_glDrv_glNormal3ivArgs);
        MCC_glDrv_glNormal3ivArgs * glDrv_glNormal3ivArg = (MCC_glDrv_glNormal3ivArgs *)argBuffer;
        glDrv_glNormal3iv(glDrv_glNormal3ivArg->v);
        break;
      case MCC_glDrv_glNormal3s :
        CHECKSIZE(MCC_glDrv_glNormal3sArgs);
        MCC_glDrv_glNormal3sArgs * glDrv_glNormal3sArg = (MCC_glDrv_glNormal3sArgs *)argBuffer;
        glDrv_glNormal3s(glDrv_glNormal3sArg->nx, glDrv_glNormal3sArg->ny, glDrv_glNormal3sArg->nz);
        break;
      case MCC_glDrv_glNormal3sv :
        CHECKSIZE(MCC_glDrv_glNormal3svArgs);
        MCC_glDrv_glNormal3svArgs * glDrv_glNormal3svArg = (MCC_glDrv_glNormal3svArgs *)argBuffer;
        glDrv_glNormal3sv(glDrv_glNormal3svArg->v);
        break;
      case MCC_glDrv_glOrtho :
        CHECKSIZE(MCC_glDrv_glOrthoArgs);
        MCC_glDrv_glOrthoArgs * glDrv_glOrthoArg = (MCC_glDrv_glOrthoArgs *)argBuffer;
        glDrv_glOrtho(glDrv_glOrthoArg->left, glDrv_glOrthoArg->right, glDrv_glOrthoArg->bottom, glDrv_glOrthoArg->top, glDrv_glOrthoArg->zNear, glDrv_glOrthoArg->zFar);
        break;
      case MCC_glDrv_glPassThrough :
        CHECKSIZE(MCC_glDrv_glPassThroughArgs);
        MCC_glDrv_glPassThroughArgs * glDrv_glPassThroughArg = (MCC_glDrv_glPassThroughArgs *)argBuffer;
        glDrv_glPassThrough(glDrv_glPassThroughArg->token);
        break;
      case MCC_glDrv_glPixelMapfv :
        CHECKSIZE(MCC_glDrv_glPixelMapfvArgs);
        MCC_glDrv_glPixelMapfvArgs * glDrv_glPixelMapfvArg = (MCC_glDrv_glPixelMapfvArgs *)argBuffer;
        glDrv_glPixelMapfv(glDrv_glPixelMapfvArg->map, glDrv_glPixelMapfvArg->mapsize, glDrv_glPixelMapfvArg->values);
        break;
      case MCC_glDrv_glPixelMapuiv :
        CHECKSIZE(MCC_glDrv_glPixelMapuivArgs);
        MCC_glDrv_glPixelMapuivArgs * glDrv_glPixelMapuivArg = (MCC_glDrv_glPixelMapuivArgs *)argBuffer;
        glDrv_glPixelMapuiv(glDrv_glPixelMapuivArg->map, glDrv_glPixelMapuivArg->mapsize, glDrv_glPixelMapuivArg->values);
        break;
      case MCC_glDrv_glPixelMapusv :
        CHECKSIZE(MCC_glDrv_glPixelMapusvArgs);
        MCC_glDrv_glPixelMapusvArgs * glDrv_glPixelMapusvArg = (MCC_glDrv_glPixelMapusvArgs *)argBuffer;
        glDrv_glPixelMapusv(glDrv_glPixelMapusvArg->map, glDrv_glPixelMapusvArg->mapsize, glDrv_glPixelMapusvArg->values);
        break;
      case MCC_glDrv_glPixelStoref :
        CHECKSIZE(MCC_glDrv_glPixelStorefArgs);
        MCC_glDrv_glPixelStorefArgs * glDrv_glPixelStorefArg = (MCC_glDrv_glPixelStorefArgs *)argBuffer;
        glDrv_glPixelStoref(glDrv_glPixelStorefArg->pname, glDrv_glPixelStorefArg->param);
        break;
      case MCC_glDrv_glPixelStorei :
        CHECKSIZE(MCC_glDrv_glPixelStoreiArgs);
        MCC_glDrv_glPixelStoreiArgs * glDrv_glPixelStoreiArg = (MCC_glDrv_glPixelStoreiArgs *)argBuffer;
        glDrv_glPixelStorei(glDrv_glPixelStoreiArg->pname, glDrv_glPixelStoreiArg->param);
        break;
      case MCC_glDrv_glPixelTransferf :
        CHECKSIZE(MCC_glDrv_glPixelTransferfArgs);
        MCC_glDrv_glPixelTransferfArgs * glDrv_glPixelTransferfArg = (MCC_glDrv_glPixelTransferfArgs *)argBuffer;
        glDrv_glPixelTransferf(glDrv_glPixelTransferfArg->pname, glDrv_glPixelTransferfArg->param);
        break;
      case MCC_glDrv_glPixelTransferi :
        CHECKSIZE(MCC_glDrv_glPixelTransferiArgs);
        MCC_glDrv_glPixelTransferiArgs * glDrv_glPixelTransferiArg = (MCC_glDrv_glPixelTransferiArgs *)argBuffer;
        glDrv_glPixelTransferi(glDrv_glPixelTransferiArg->pname, glDrv_glPixelTransferiArg->param);
        break;
      case MCC_glDrv_glPixelZoom :
        CHECKSIZE(MCC_glDrv_glPixelZoomArgs);
        MCC_glDrv_glPixelZoomArgs * glDrv_glPixelZoomArg = (MCC_glDrv_glPixelZoomArgs *)argBuffer;
        glDrv_glPixelZoom(glDrv_glPixelZoomArg->xfactor, glDrv_glPixelZoomArg->yfactor);
        break;
      case MCC_glDrv_glPointSize :
        CHECKSIZE(MCC_glDrv_glPointSizeArgs);
        MCC_glDrv_glPointSizeArgs * glDrv_glPointSizeArg = (MCC_glDrv_glPointSizeArgs *)argBuffer;
        glDrv_glPointSize(glDrv_glPointSizeArg->size);
        break;
      case MCC_glDrv_glPolygonMode :
        CHECKSIZE(MCC_glDrv_glPolygonModeArgs);
        MCC_glDrv_glPolygonModeArgs * glDrv_glPolygonModeArg = (MCC_glDrv_glPolygonModeArgs *)argBuffer;
        glDrv_glPolygonMode(glDrv_glPolygonModeArg->face, glDrv_glPolygonModeArg->mode);
        break;
      case MCC_glDrv_glPolygonStipple :
        CHECKSIZE(MCC_glDrv_glPolygonStippleArgs);
        MCC_glDrv_glPolygonStippleArgs * glDrv_glPolygonStippleArg = (MCC_glDrv_glPolygonStippleArgs *)argBuffer;
        glDrv_glPolygonStipple(glDrv_glPolygonStippleArg->mask);
        break;
      case MCC_glDrv_glPopAttrib :
        CHECKSIZE(MCC_glDrv_glPopAttribArgs);
        MCC_glDrv_glPopAttribArgs * glDrv_glPopAttribArg = (MCC_glDrv_glPopAttribArgs *)argBuffer;
        glDrv_glPopAttrib();
        break;
      case MCC_glDrv_glPopMatrix :
        CHECKSIZE(MCC_glDrv_glPopMatrixArgs);
        MCC_glDrv_glPopMatrixArgs * glDrv_glPopMatrixArg = (MCC_glDrv_glPopMatrixArgs *)argBuffer;
        glDrv_glPopMatrix();
        break;
      case MCC_glDrv_glPopName :
        CHECKSIZE(MCC_glDrv_glPopNameArgs);
        MCC_glDrv_glPopNameArgs * glDrv_glPopNameArg = (MCC_glDrv_glPopNameArgs *)argBuffer;
        glDrv_glPopName();
        break;
      case MCC_glDrv_glPushAttrib :
        CHECKSIZE(MCC_glDrv_glPushAttribArgs);
        MCC_glDrv_glPushAttribArgs * glDrv_glPushAttribArg = (MCC_glDrv_glPushAttribArgs *)argBuffer;
        glDrv_glPushAttrib(glDrv_glPushAttribArg->mask);
        break;
      case MCC_glDrv_glPushMatrix :
        CHECKSIZE(MCC_glDrv_glPushMatrixArgs);
        MCC_glDrv_glPushMatrixArgs * glDrv_glPushMatrixArg = (MCC_glDrv_glPushMatrixArgs *)argBuffer;
        glDrv_glPushMatrix();
        break;
      case MCC_glDrv_glPushName :
        CHECKSIZE(MCC_glDrv_glPushNameArgs);
        MCC_glDrv_glPushNameArgs * glDrv_glPushNameArg = (MCC_glDrv_glPushNameArgs *)argBuffer;
        glDrv_glPushName(glDrv_glPushNameArg->name);
        break;
      case MCC_glDrv_glRasterPos2d :
        CHECKSIZE(MCC_glDrv_glRasterPos2dArgs);
        MCC_glDrv_glRasterPos2dArgs * glDrv_glRasterPos2dArg = (MCC_glDrv_glRasterPos2dArgs *)argBuffer;
        glDrv_glRasterPos2d(glDrv_glRasterPos2dArg->x, glDrv_glRasterPos2dArg->y);
        break;
      case MCC_glDrv_glRasterPos2dv :
        CHECKSIZE(MCC_glDrv_glRasterPos2dvArgs);
        MCC_glDrv_glRasterPos2dvArgs * glDrv_glRasterPos2dvArg = (MCC_glDrv_glRasterPos2dvArgs *)argBuffer;
        glDrv_glRasterPos2dv(glDrv_glRasterPos2dvArg->v);
        break;
      case MCC_glDrv_glRasterPos2f :
        CHECKSIZE(MCC_glDrv_glRasterPos2fArgs);
        MCC_glDrv_glRasterPos2fArgs * glDrv_glRasterPos2fArg = (MCC_glDrv_glRasterPos2fArgs *)argBuffer;
        glDrv_glRasterPos2f(glDrv_glRasterPos2fArg->x, glDrv_glRasterPos2fArg->y);
        break;
      case MCC_glDrv_glRasterPos2fv :
        CHECKSIZE(MCC_glDrv_glRasterPos2fvArgs);
        MCC_glDrv_glRasterPos2fvArgs * glDrv_glRasterPos2fvArg = (MCC_glDrv_glRasterPos2fvArgs *)argBuffer;
        glDrv_glRasterPos2fv(glDrv_glRasterPos2fvArg->v);
        break;
      case MCC_glDrv_glRasterPos2i :
        CHECKSIZE(MCC_glDrv_glRasterPos2iArgs);
        MCC_glDrv_glRasterPos2iArgs * glDrv_glRasterPos2iArg = (MCC_glDrv_glRasterPos2iArgs *)argBuffer;
        glDrv_glRasterPos2i(glDrv_glRasterPos2iArg->x, glDrv_glRasterPos2iArg->y);
        break;
      case MCC_glDrv_glRasterPos2iv :
        CHECKSIZE(MCC_glDrv_glRasterPos2ivArgs);
        MCC_glDrv_glRasterPos2ivArgs * glDrv_glRasterPos2ivArg = (MCC_glDrv_glRasterPos2ivArgs *)argBuffer;
        glDrv_glRasterPos2iv(glDrv_glRasterPos2ivArg->v);
        break;
      case MCC_glDrv_glRasterPos2s :
        CHECKSIZE(MCC_glDrv_glRasterPos2sArgs);
        MCC_glDrv_glRasterPos2sArgs * glDrv_glRasterPos2sArg = (MCC_glDrv_glRasterPos2sArgs *)argBuffer;
        glDrv_glRasterPos2s(glDrv_glRasterPos2sArg->x, glDrv_glRasterPos2sArg->y);
        break;
      case MCC_glDrv_glRasterPos2sv :
        CHECKSIZE(MCC_glDrv_glRasterPos2svArgs);
        MCC_glDrv_glRasterPos2svArgs * glDrv_glRasterPos2svArg = (MCC_glDrv_glRasterPos2svArgs *)argBuffer;
        glDrv_glRasterPos2sv(glDrv_glRasterPos2svArg->v);
        break;
      case MCC_glDrv_glRasterPos3d :
        CHECKSIZE(MCC_glDrv_glRasterPos3dArgs);
        MCC_glDrv_glRasterPos3dArgs * glDrv_glRasterPos3dArg = (MCC_glDrv_glRasterPos3dArgs *)argBuffer;
        glDrv_glRasterPos3d(glDrv_glRasterPos3dArg->x, glDrv_glRasterPos3dArg->y, glDrv_glRasterPos3dArg->z);
        break;
      case MCC_glDrv_glRasterPos3dv :
        CHECKSIZE(MCC_glDrv_glRasterPos3dvArgs);
        MCC_glDrv_glRasterPos3dvArgs * glDrv_glRasterPos3dvArg = (MCC_glDrv_glRasterPos3dvArgs *)argBuffer;
        glDrv_glRasterPos3dv(glDrv_glRasterPos3dvArg->v);
        break;
      case MCC_glDrv_glRasterPos3f :
        CHECKSIZE(MCC_glDrv_glRasterPos3fArgs);
        MCC_glDrv_glRasterPos3fArgs * glDrv_glRasterPos3fArg = (MCC_glDrv_glRasterPos3fArgs *)argBuffer;
        glDrv_glRasterPos3f(glDrv_glRasterPos3fArg->x, glDrv_glRasterPos3fArg->y, glDrv_glRasterPos3fArg->z);
        break;
      case MCC_glDrv_glRasterPos3fv :
        CHECKSIZE(MCC_glDrv_glRasterPos3fvArgs);
        MCC_glDrv_glRasterPos3fvArgs * glDrv_glRasterPos3fvArg = (MCC_glDrv_glRasterPos3fvArgs *)argBuffer;
        glDrv_glRasterPos3fv(glDrv_glRasterPos3fvArg->v);
        break;
      case MCC_glDrv_glRasterPos3i :
        CHECKSIZE(MCC_glDrv_glRasterPos3iArgs);
        MCC_glDrv_glRasterPos3iArgs * glDrv_glRasterPos3iArg = (MCC_glDrv_glRasterPos3iArgs *)argBuffer;
        glDrv_glRasterPos3i(glDrv_glRasterPos3iArg->x, glDrv_glRasterPos3iArg->y, glDrv_glRasterPos3iArg->z);
        break;
      case MCC_glDrv_glRasterPos3iv :
        CHECKSIZE(MCC_glDrv_glRasterPos3ivArgs);
        MCC_glDrv_glRasterPos3ivArgs * glDrv_glRasterPos3ivArg = (MCC_glDrv_glRasterPos3ivArgs *)argBuffer;
        glDrv_glRasterPos3iv(glDrv_glRasterPos3ivArg->v);
        break;
      case MCC_glDrv_glRasterPos3s :
        CHECKSIZE(MCC_glDrv_glRasterPos3sArgs);
        MCC_glDrv_glRasterPos3sArgs * glDrv_glRasterPos3sArg = (MCC_glDrv_glRasterPos3sArgs *)argBuffer;
        glDrv_glRasterPos3s(glDrv_glRasterPos3sArg->x, glDrv_glRasterPos3sArg->y, glDrv_glRasterPos3sArg->z);
        break;
      case MCC_glDrv_glRasterPos3sv :
        CHECKSIZE(MCC_glDrv_glRasterPos3svArgs);
        MCC_glDrv_glRasterPos3svArgs * glDrv_glRasterPos3svArg = (MCC_glDrv_glRasterPos3svArgs *)argBuffer;
        glDrv_glRasterPos3sv(glDrv_glRasterPos3svArg->v);
        break;
      case MCC_glDrv_glRasterPos4d :
        CHECKSIZE(MCC_glDrv_glRasterPos4dArgs);
        MCC_glDrv_glRasterPos4dArgs * glDrv_glRasterPos4dArg = (MCC_glDrv_glRasterPos4dArgs *)argBuffer;
        glDrv_glRasterPos4d(glDrv_glRasterPos4dArg->x, glDrv_glRasterPos4dArg->y, glDrv_glRasterPos4dArg->z, glDrv_glRasterPos4dArg->w);
        break;
      case MCC_glDrv_glRasterPos4dv :
        CHECKSIZE(MCC_glDrv_glRasterPos4dvArgs);
        MCC_glDrv_glRasterPos4dvArgs * glDrv_glRasterPos4dvArg = (MCC_glDrv_glRasterPos4dvArgs *)argBuffer;
        glDrv_glRasterPos4dv(glDrv_glRasterPos4dvArg->v);
        break;
      case MCC_glDrv_glRasterPos4f :
        CHECKSIZE(MCC_glDrv_glRasterPos4fArgs);
        MCC_glDrv_glRasterPos4fArgs * glDrv_glRasterPos4fArg = (MCC_glDrv_glRasterPos4fArgs *)argBuffer;
        glDrv_glRasterPos4f(glDrv_glRasterPos4fArg->x, glDrv_glRasterPos4fArg->y, glDrv_glRasterPos4fArg->z, glDrv_glRasterPos4fArg->w);
        break;
      case MCC_glDrv_glRasterPos4fv :
        CHECKSIZE(MCC_glDrv_glRasterPos4fvArgs);
        MCC_glDrv_glRasterPos4fvArgs * glDrv_glRasterPos4fvArg = (MCC_glDrv_glRasterPos4fvArgs *)argBuffer;
        glDrv_glRasterPos4fv(glDrv_glRasterPos4fvArg->v);
        break;
      case MCC_glDrv_glRasterPos4i :
        CHECKSIZE(MCC_glDrv_glRasterPos4iArgs);
        MCC_glDrv_glRasterPos4iArgs * glDrv_glRasterPos4iArg = (MCC_glDrv_glRasterPos4iArgs *)argBuffer;
        glDrv_glRasterPos4i(glDrv_glRasterPos4iArg->x, glDrv_glRasterPos4iArg->y, glDrv_glRasterPos4iArg->z, glDrv_glRasterPos4iArg->w);
        break;
      case MCC_glDrv_glRasterPos4iv :
        CHECKSIZE(MCC_glDrv_glRasterPos4ivArgs);
        MCC_glDrv_glRasterPos4ivArgs * glDrv_glRasterPos4ivArg = (MCC_glDrv_glRasterPos4ivArgs *)argBuffer;
        glDrv_glRasterPos4iv(glDrv_glRasterPos4ivArg->v);
        break;
      case MCC_glDrv_glRasterPos4s :
        CHECKSIZE(MCC_glDrv_glRasterPos4sArgs);
        MCC_glDrv_glRasterPos4sArgs * glDrv_glRasterPos4sArg = (MCC_glDrv_glRasterPos4sArgs *)argBuffer;
        glDrv_glRasterPos4s(glDrv_glRasterPos4sArg->x, glDrv_glRasterPos4sArg->y, glDrv_glRasterPos4sArg->z, glDrv_glRasterPos4sArg->w);
        break;
      case MCC_glDrv_glRasterPos4sv :
        CHECKSIZE(MCC_glDrv_glRasterPos4svArgs);
        MCC_glDrv_glRasterPos4svArgs * glDrv_glRasterPos4svArg = (MCC_glDrv_glRasterPos4svArgs *)argBuffer;
        glDrv_glRasterPos4sv(glDrv_glRasterPos4svArg->v);
        break;
      case MCC_glDrv_glReadBuffer :
        CHECKSIZE(MCC_glDrv_glReadBufferArgs);
        MCC_glDrv_glReadBufferArgs * glDrv_glReadBufferArg = (MCC_glDrv_glReadBufferArgs *)argBuffer;
        glDrv_glReadBuffer(glDrv_glReadBufferArg->mode);
        break;
      case MCC_glDrv_glReadPixels :
        CHECKSIZE(MCC_glDrv_glReadPixelsArgs);
        MCC_glDrv_glReadPixelsArgs * glDrv_glReadPixelsArg = (MCC_glDrv_glReadPixelsArgs *)argBuffer;
        glDrv_glReadPixels(glDrv_glReadPixelsArg->x, glDrv_glReadPixelsArg->y, glDrv_glReadPixelsArg->width, glDrv_glReadPixelsArg->height, glDrv_glReadPixelsArg->format, glDrv_glReadPixelsArg->type, glDrv_glReadPixelsArg->pixels);
        break;
      case MCC_glDrv_glRectd :
        CHECKSIZE(MCC_glDrv_glRectdArgs);
        MCC_glDrv_glRectdArgs * glDrv_glRectdArg = (MCC_glDrv_glRectdArgs *)argBuffer;
        glDrv_glRectd(glDrv_glRectdArg->x1, glDrv_glRectdArg->y1, glDrv_glRectdArg->x2, glDrv_glRectdArg->y2);
        break;
      case MCC_glDrv_glRectdv :
        CHECKSIZE(MCC_glDrv_glRectdvArgs);
        MCC_glDrv_glRectdvArgs * glDrv_glRectdvArg = (MCC_glDrv_glRectdvArgs *)argBuffer;
        glDrv_glRectdv(glDrv_glRectdvArg->v1, glDrv_glRectdvArg->v2);
        break;
      case MCC_glDrv_glRectf :
        CHECKSIZE(MCC_glDrv_glRectfArgs);
        MCC_glDrv_glRectfArgs * glDrv_glRectfArg = (MCC_glDrv_glRectfArgs *)argBuffer;
        glDrv_glRectf(glDrv_glRectfArg->x1, glDrv_glRectfArg->y1, glDrv_glRectfArg->x2, glDrv_glRectfArg->y2);
        break;
      case MCC_glDrv_glRectfv :
        CHECKSIZE(MCC_glDrv_glRectfvArgs);
        MCC_glDrv_glRectfvArgs * glDrv_glRectfvArg = (MCC_glDrv_glRectfvArgs *)argBuffer;
        glDrv_glRectfv(glDrv_glRectfvArg->v1, glDrv_glRectfvArg->v2);
        break;
      case MCC_glDrv_glRecti :
        CHECKSIZE(MCC_glDrv_glRectiArgs);
        MCC_glDrv_glRectiArgs * glDrv_glRectiArg = (MCC_glDrv_glRectiArgs *)argBuffer;
        glDrv_glRecti(glDrv_glRectiArg->x1, glDrv_glRectiArg->y1, glDrv_glRectiArg->x2, glDrv_glRectiArg->y2);
        break;
      case MCC_glDrv_glRectiv :
        CHECKSIZE(MCC_glDrv_glRectivArgs);
        MCC_glDrv_glRectivArgs * glDrv_glRectivArg = (MCC_glDrv_glRectivArgs *)argBuffer;
        glDrv_glRectiv(glDrv_glRectivArg->v1, glDrv_glRectivArg->v2);
        break;
      case MCC_glDrv_glRects :
        CHECKSIZE(MCC_glDrv_glRectsArgs);
        MCC_glDrv_glRectsArgs * glDrv_glRectsArg = (MCC_glDrv_glRectsArgs *)argBuffer;
        glDrv_glRects(glDrv_glRectsArg->x1, glDrv_glRectsArg->y1, glDrv_glRectsArg->x2, glDrv_glRectsArg->y2);
        break;
      case MCC_glDrv_glRectsv :
        CHECKSIZE(MCC_glDrv_glRectsvArgs);
        MCC_glDrv_glRectsvArgs * glDrv_glRectsvArg = (MCC_glDrv_glRectsvArgs *)argBuffer;
        glDrv_glRectsv(glDrv_glRectsvArg->v1, glDrv_glRectsvArg->v2);
        break;
      case MCC_glDrv_glRenderMode :
        CHECKSIZE(MCC_glDrv_glRenderModeArgs);
        MCC_glDrv_glRenderModeArgs * glDrv_glRenderModeArg = (MCC_glDrv_glRenderModeArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_glRenderMode(glDrv_glRenderModeArg->mode));
        break;
      case MCC_glDrv_glRotated :
        CHECKSIZE(MCC_glDrv_glRotatedArgs);
        MCC_glDrv_glRotatedArgs * glDrv_glRotatedArg = (MCC_glDrv_glRotatedArgs *)argBuffer;
        glDrv_glRotated(glDrv_glRotatedArg->angle, glDrv_glRotatedArg->x, glDrv_glRotatedArg->y, glDrv_glRotatedArg->z);
        break;
      case MCC_glDrv_glRotatef :
        CHECKSIZE(MCC_glDrv_glRotatefArgs);
        MCC_glDrv_glRotatefArgs * glDrv_glRotatefArg = (MCC_glDrv_glRotatefArgs *)argBuffer;
        glDrv_glRotatef(glDrv_glRotatefArg->angle, glDrv_glRotatefArg->x, glDrv_glRotatefArg->y, glDrv_glRotatefArg->z);
        break;
      case MCC_glDrv_glScaled :
        CHECKSIZE(MCC_glDrv_glScaledArgs);
        MCC_glDrv_glScaledArgs * glDrv_glScaledArg = (MCC_glDrv_glScaledArgs *)argBuffer;
        glDrv_glScaled(glDrv_glScaledArg->x, glDrv_glScaledArg->y, glDrv_glScaledArg->z);
        break;
      case MCC_glDrv_glScalef :
        CHECKSIZE(MCC_glDrv_glScalefArgs);
        MCC_glDrv_glScalefArgs * glDrv_glScalefArg = (MCC_glDrv_glScalefArgs *)argBuffer;
        glDrv_glScalef(glDrv_glScalefArg->x, glDrv_glScalefArg->y, glDrv_glScalefArg->z);
        break;
      case MCC_glDrv_glScissor :
        CHECKSIZE(MCC_glDrv_glScissorArgs);
        MCC_glDrv_glScissorArgs * glDrv_glScissorArg = (MCC_glDrv_glScissorArgs *)argBuffer;
        glDrv_glScissor(glDrv_glScissorArg->x, glDrv_glScissorArg->y, glDrv_glScissorArg->width, glDrv_glScissorArg->height);
        break;
      case MCC_glDrv_glSelectBuffer :
        CHECKSIZE(MCC_glDrv_glSelectBufferArgs);
        MCC_glDrv_glSelectBufferArgs * glDrv_glSelectBufferArg = (MCC_glDrv_glSelectBufferArgs *)argBuffer;
        glDrv_glSelectBuffer(glDrv_glSelectBufferArg->size, glDrv_glSelectBufferArg->buffer);
        break;
      case MCC_glDrv_glShadeModel :
        CHECKSIZE(MCC_glDrv_glShadeModelArgs);
        MCC_glDrv_glShadeModelArgs * glDrv_glShadeModelArg = (MCC_glDrv_glShadeModelArgs *)argBuffer;
        glDrv_glShadeModel(glDrv_glShadeModelArg->mode);
        break;
      case MCC_glDrv_glStencilFunc :
        CHECKSIZE(MCC_glDrv_glStencilFuncArgs);
        MCC_glDrv_glStencilFuncArgs * glDrv_glStencilFuncArg = (MCC_glDrv_glStencilFuncArgs *)argBuffer;
        glDrv_glStencilFunc(glDrv_glStencilFuncArg->func, glDrv_glStencilFuncArg->ref, glDrv_glStencilFuncArg->mask);
        break;
      case MCC_glDrv_glStencilMask :
        CHECKSIZE(MCC_glDrv_glStencilMaskArgs);
        MCC_glDrv_glStencilMaskArgs * glDrv_glStencilMaskArg = (MCC_glDrv_glStencilMaskArgs *)argBuffer;
        glDrv_glStencilMask(glDrv_glStencilMaskArg->mask);
        break;
      case MCC_glDrv_glStencilOp :
        CHECKSIZE(MCC_glDrv_glStencilOpArgs);
        MCC_glDrv_glStencilOpArgs * glDrv_glStencilOpArg = (MCC_glDrv_glStencilOpArgs *)argBuffer;
        glDrv_glStencilOp(glDrv_glStencilOpArg->fail, glDrv_glStencilOpArg->zfail, glDrv_glStencilOpArg->zpass);
        break;
      case MCC_glDrv_glTexCoord1d :
        CHECKSIZE(MCC_glDrv_glTexCoord1dArgs);
        MCC_glDrv_glTexCoord1dArgs * glDrv_glTexCoord1dArg = (MCC_glDrv_glTexCoord1dArgs *)argBuffer;
        glDrv_glTexCoord1d(glDrv_glTexCoord1dArg->s);
        break;
      case MCC_glDrv_glTexCoord1dv :
        CHECKSIZE(MCC_glDrv_glTexCoord1dvArgs);
        MCC_glDrv_glTexCoord1dvArgs * glDrv_glTexCoord1dvArg = (MCC_glDrv_glTexCoord1dvArgs *)argBuffer;
        glDrv_glTexCoord1dv(glDrv_glTexCoord1dvArg->v);
        break;
      case MCC_glDrv_glTexCoord1f :
        CHECKSIZE(MCC_glDrv_glTexCoord1fArgs);
        MCC_glDrv_glTexCoord1fArgs * glDrv_glTexCoord1fArg = (MCC_glDrv_glTexCoord1fArgs *)argBuffer;
        glDrv_glTexCoord1f(glDrv_glTexCoord1fArg->s);
        break;
      case MCC_glDrv_glTexCoord1fv :
        CHECKSIZE(MCC_glDrv_glTexCoord1fvArgs);
        MCC_glDrv_glTexCoord1fvArgs * glDrv_glTexCoord1fvArg = (MCC_glDrv_glTexCoord1fvArgs *)argBuffer;
        glDrv_glTexCoord1fv(glDrv_glTexCoord1fvArg->v);
        break;
      case MCC_glDrv_glTexCoord1i :
        CHECKSIZE(MCC_glDrv_glTexCoord1iArgs);
        MCC_glDrv_glTexCoord1iArgs * glDrv_glTexCoord1iArg = (MCC_glDrv_glTexCoord1iArgs *)argBuffer;
        glDrv_glTexCoord1i(glDrv_glTexCoord1iArg->s);
        break;
      case MCC_glDrv_glTexCoord1iv :
        CHECKSIZE(MCC_glDrv_glTexCoord1ivArgs);
        MCC_glDrv_glTexCoord1ivArgs * glDrv_glTexCoord1ivArg = (MCC_glDrv_glTexCoord1ivArgs *)argBuffer;
        glDrv_glTexCoord1iv(glDrv_glTexCoord1ivArg->v);
        break;
      case MCC_glDrv_glTexCoord1s :
        CHECKSIZE(MCC_glDrv_glTexCoord1sArgs);
        MCC_glDrv_glTexCoord1sArgs * glDrv_glTexCoord1sArg = (MCC_glDrv_glTexCoord1sArgs *)argBuffer;
        glDrv_glTexCoord1s(glDrv_glTexCoord1sArg->s);
        break;
      case MCC_glDrv_glTexCoord1sv :
        CHECKSIZE(MCC_glDrv_glTexCoord1svArgs);
        MCC_glDrv_glTexCoord1svArgs * glDrv_glTexCoord1svArg = (MCC_glDrv_glTexCoord1svArgs *)argBuffer;
        glDrv_glTexCoord1sv(glDrv_glTexCoord1svArg->v);
        break;
      case MCC_glDrv_glTexCoord2d :
        CHECKSIZE(MCC_glDrv_glTexCoord2dArgs);
        MCC_glDrv_glTexCoord2dArgs * glDrv_glTexCoord2dArg = (MCC_glDrv_glTexCoord2dArgs *)argBuffer;
        glDrv_glTexCoord2d(glDrv_glTexCoord2dArg->s, glDrv_glTexCoord2dArg->t);
        break;
      case MCC_glDrv_glTexCoord2dv :
        CHECKSIZE(MCC_glDrv_glTexCoord2dvArgs);
        MCC_glDrv_glTexCoord2dvArgs * glDrv_glTexCoord2dvArg = (MCC_glDrv_glTexCoord2dvArgs *)argBuffer;
        glDrv_glTexCoord2dv(glDrv_glTexCoord2dvArg->v);
        break;
      case MCC_glDrv_glTexCoord2f :
        CHECKSIZE(MCC_glDrv_glTexCoord2fArgs);
        MCC_glDrv_glTexCoord2fArgs * glDrv_glTexCoord2fArg = (MCC_glDrv_glTexCoord2fArgs *)argBuffer;
        glDrv_glTexCoord2f(glDrv_glTexCoord2fArg->s, glDrv_glTexCoord2fArg->t);
        break;
      case MCC_glDrv_glTexCoord2fv :
        CHECKSIZE(MCC_glDrv_glTexCoord2fvArgs);
        MCC_glDrv_glTexCoord2fvArgs * glDrv_glTexCoord2fvArg = (MCC_glDrv_glTexCoord2fvArgs *)argBuffer;
        glDrv_glTexCoord2fv(glDrv_glTexCoord2fvArg->v);
        break;
      case MCC_glDrv_glTexCoord2i :
        CHECKSIZE(MCC_glDrv_glTexCoord2iArgs);
        MCC_glDrv_glTexCoord2iArgs * glDrv_glTexCoord2iArg = (MCC_glDrv_glTexCoord2iArgs *)argBuffer;
        glDrv_glTexCoord2i(glDrv_glTexCoord2iArg->s, glDrv_glTexCoord2iArg->t);
        break;
      case MCC_glDrv_glTexCoord2iv :
        CHECKSIZE(MCC_glDrv_glTexCoord2ivArgs);
        MCC_glDrv_glTexCoord2ivArgs * glDrv_glTexCoord2ivArg = (MCC_glDrv_glTexCoord2ivArgs *)argBuffer;
        glDrv_glTexCoord2iv(glDrv_glTexCoord2ivArg->v);
        break;
      case MCC_glDrv_glTexCoord2s :
        CHECKSIZE(MCC_glDrv_glTexCoord2sArgs);
        MCC_glDrv_glTexCoord2sArgs * glDrv_glTexCoord2sArg = (MCC_glDrv_glTexCoord2sArgs *)argBuffer;
        glDrv_glTexCoord2s(glDrv_glTexCoord2sArg->s, glDrv_glTexCoord2sArg->t);
        break;
      case MCC_glDrv_glTexCoord2sv :
        CHECKSIZE(MCC_glDrv_glTexCoord2svArgs);
        MCC_glDrv_glTexCoord2svArgs * glDrv_glTexCoord2svArg = (MCC_glDrv_glTexCoord2svArgs *)argBuffer;
        glDrv_glTexCoord2sv(glDrv_glTexCoord2svArg->v);
        break;
      case MCC_glDrv_glTexCoord3d :
        CHECKSIZE(MCC_glDrv_glTexCoord3dArgs);
        MCC_glDrv_glTexCoord3dArgs * glDrv_glTexCoord3dArg = (MCC_glDrv_glTexCoord3dArgs *)argBuffer;
        glDrv_glTexCoord3d(glDrv_glTexCoord3dArg->s, glDrv_glTexCoord3dArg->t, glDrv_glTexCoord3dArg->r);
        break;
      case MCC_glDrv_glTexCoord3dv :
        CHECKSIZE(MCC_glDrv_glTexCoord3dvArgs);
        MCC_glDrv_glTexCoord3dvArgs * glDrv_glTexCoord3dvArg = (MCC_glDrv_glTexCoord3dvArgs *)argBuffer;
        glDrv_glTexCoord3dv(glDrv_glTexCoord3dvArg->v);
        break;
      case MCC_glDrv_glTexCoord3f :
        CHECKSIZE(MCC_glDrv_glTexCoord3fArgs);
        MCC_glDrv_glTexCoord3fArgs * glDrv_glTexCoord3fArg = (MCC_glDrv_glTexCoord3fArgs *)argBuffer;
        glDrv_glTexCoord3f(glDrv_glTexCoord3fArg->s, glDrv_glTexCoord3fArg->t, glDrv_glTexCoord3fArg->r);
        break;
      case MCC_glDrv_glTexCoord3fv :
        CHECKSIZE(MCC_glDrv_glTexCoord3fvArgs);
        MCC_glDrv_glTexCoord3fvArgs * glDrv_glTexCoord3fvArg = (MCC_glDrv_glTexCoord3fvArgs *)argBuffer;
        glDrv_glTexCoord3fv(glDrv_glTexCoord3fvArg->v);
        break;
      case MCC_glDrv_glTexCoord3i :
        CHECKSIZE(MCC_glDrv_glTexCoord3iArgs);
        MCC_glDrv_glTexCoord3iArgs * glDrv_glTexCoord3iArg = (MCC_glDrv_glTexCoord3iArgs *)argBuffer;
        glDrv_glTexCoord3i(glDrv_glTexCoord3iArg->s, glDrv_glTexCoord3iArg->t, glDrv_glTexCoord3iArg->r);
        break;
      case MCC_glDrv_glTexCoord3iv :
        CHECKSIZE(MCC_glDrv_glTexCoord3ivArgs);
        MCC_glDrv_glTexCoord3ivArgs * glDrv_glTexCoord3ivArg = (MCC_glDrv_glTexCoord3ivArgs *)argBuffer;
        glDrv_glTexCoord3iv(glDrv_glTexCoord3ivArg->v);
        break;
      case MCC_glDrv_glTexCoord3s :
        CHECKSIZE(MCC_glDrv_glTexCoord3sArgs);
        MCC_glDrv_glTexCoord3sArgs * glDrv_glTexCoord3sArg = (MCC_glDrv_glTexCoord3sArgs *)argBuffer;
        glDrv_glTexCoord3s(glDrv_glTexCoord3sArg->s, glDrv_glTexCoord3sArg->t, glDrv_glTexCoord3sArg->r);
        break;
      case MCC_glDrv_glTexCoord3sv :
        CHECKSIZE(MCC_glDrv_glTexCoord3svArgs);
        MCC_glDrv_glTexCoord3svArgs * glDrv_glTexCoord3svArg = (MCC_glDrv_glTexCoord3svArgs *)argBuffer;
        glDrv_glTexCoord3sv(glDrv_glTexCoord3svArg->v);
        break;
      case MCC_glDrv_glTexCoord4d :
        CHECKSIZE(MCC_glDrv_glTexCoord4dArgs);
        MCC_glDrv_glTexCoord4dArgs * glDrv_glTexCoord4dArg = (MCC_glDrv_glTexCoord4dArgs *)argBuffer;
        glDrv_glTexCoord4d(glDrv_glTexCoord4dArg->s, glDrv_glTexCoord4dArg->t, glDrv_glTexCoord4dArg->r, glDrv_glTexCoord4dArg->q);
        break;
      case MCC_glDrv_glTexCoord4dv :
        CHECKSIZE(MCC_glDrv_glTexCoord4dvArgs);
        MCC_glDrv_glTexCoord4dvArgs * glDrv_glTexCoord4dvArg = (MCC_glDrv_glTexCoord4dvArgs *)argBuffer;
        glDrv_glTexCoord4dv(glDrv_glTexCoord4dvArg->v);
        break;
      case MCC_glDrv_glTexCoord4f :
        CHECKSIZE(MCC_glDrv_glTexCoord4fArgs);
        MCC_glDrv_glTexCoord4fArgs * glDrv_glTexCoord4fArg = (MCC_glDrv_glTexCoord4fArgs *)argBuffer;
        glDrv_glTexCoord4f(glDrv_glTexCoord4fArg->s, glDrv_glTexCoord4fArg->t, glDrv_glTexCoord4fArg->r, glDrv_glTexCoord4fArg->q);
        break;
      case MCC_glDrv_glTexCoord4fv :
        CHECKSIZE(MCC_glDrv_glTexCoord4fvArgs);
        MCC_glDrv_glTexCoord4fvArgs * glDrv_glTexCoord4fvArg = (MCC_glDrv_glTexCoord4fvArgs *)argBuffer;
        glDrv_glTexCoord4fv(glDrv_glTexCoord4fvArg->v);
        break;
      case MCC_glDrv_glTexCoord4i :
        CHECKSIZE(MCC_glDrv_glTexCoord4iArgs);
        MCC_glDrv_glTexCoord4iArgs * glDrv_glTexCoord4iArg = (MCC_glDrv_glTexCoord4iArgs *)argBuffer;
        glDrv_glTexCoord4i(glDrv_glTexCoord4iArg->s, glDrv_glTexCoord4iArg->t, glDrv_glTexCoord4iArg->r, glDrv_glTexCoord4iArg->q);
        break;
      case MCC_glDrv_glTexCoord4iv :
        CHECKSIZE(MCC_glDrv_glTexCoord4ivArgs);
        MCC_glDrv_glTexCoord4ivArgs * glDrv_glTexCoord4ivArg = (MCC_glDrv_glTexCoord4ivArgs *)argBuffer;
        glDrv_glTexCoord4iv(glDrv_glTexCoord4ivArg->v);
        break;
      case MCC_glDrv_glTexCoord4s :
        CHECKSIZE(MCC_glDrv_glTexCoord4sArgs);
        MCC_glDrv_glTexCoord4sArgs * glDrv_glTexCoord4sArg = (MCC_glDrv_glTexCoord4sArgs *)argBuffer;
        glDrv_glTexCoord4s(glDrv_glTexCoord4sArg->s, glDrv_glTexCoord4sArg->t, glDrv_glTexCoord4sArg->r, glDrv_glTexCoord4sArg->q);
        break;
      case MCC_glDrv_glTexCoord4sv :
        CHECKSIZE(MCC_glDrv_glTexCoord4svArgs);
        MCC_glDrv_glTexCoord4svArgs * glDrv_glTexCoord4svArg = (MCC_glDrv_glTexCoord4svArgs *)argBuffer;
        glDrv_glTexCoord4sv(glDrv_glTexCoord4svArg->v);
        break;
      case MCC_glDrv_glTexEnvf :
        CHECKSIZE(MCC_glDrv_glTexEnvfArgs);
        MCC_glDrv_glTexEnvfArgs * glDrv_glTexEnvfArg = (MCC_glDrv_glTexEnvfArgs *)argBuffer;
        glDrv_glTexEnvf(glDrv_glTexEnvfArg->target, glDrv_glTexEnvfArg->pname, glDrv_glTexEnvfArg->param);
        break;
      case MCC_glDrv_glTexEnvfv :
        CHECKSIZE(MCC_glDrv_glTexEnvfvArgs);
        MCC_glDrv_glTexEnvfvArgs * glDrv_glTexEnvfvArg = (MCC_glDrv_glTexEnvfvArgs *)argBuffer;
        glDrv_glTexEnvfv(glDrv_glTexEnvfvArg->target, glDrv_glTexEnvfvArg->pname, glDrv_glTexEnvfvArg->params);
        break;
      case MCC_glDrv_glTexEnvi :
        CHECKSIZE(MCC_glDrv_glTexEnviArgs);
        MCC_glDrv_glTexEnviArgs * glDrv_glTexEnviArg = (MCC_glDrv_glTexEnviArgs *)argBuffer;
        glDrv_glTexEnvi(glDrv_glTexEnviArg->target, glDrv_glTexEnviArg->pname, glDrv_glTexEnviArg->param);
        break;
      case MCC_glDrv_glTexEnviv :
        CHECKSIZE(MCC_glDrv_glTexEnvivArgs);
        MCC_glDrv_glTexEnvivArgs * glDrv_glTexEnvivArg = (MCC_glDrv_glTexEnvivArgs *)argBuffer;
        glDrv_glTexEnviv(glDrv_glTexEnvivArg->target, glDrv_glTexEnvivArg->pname, glDrv_glTexEnvivArg->params);
        break;
      case MCC_glDrv_glTexGend :
        CHECKSIZE(MCC_glDrv_glTexGendArgs);
        MCC_glDrv_glTexGendArgs * glDrv_glTexGendArg = (MCC_glDrv_glTexGendArgs *)argBuffer;
        glDrv_glTexGend(glDrv_glTexGendArg->coord, glDrv_glTexGendArg->pname, glDrv_glTexGendArg->param);
        break;
      case MCC_glDrv_glTexGendv :
        CHECKSIZE(MCC_glDrv_glTexGendvArgs);
        MCC_glDrv_glTexGendvArgs * glDrv_glTexGendvArg = (MCC_glDrv_glTexGendvArgs *)argBuffer;
        glDrv_glTexGendv(glDrv_glTexGendvArg->coord, glDrv_glTexGendvArg->pname, glDrv_glTexGendvArg->params);
        break;
      case MCC_glDrv_glTexGenf :
        CHECKSIZE(MCC_glDrv_glTexGenfArgs);
        MCC_glDrv_glTexGenfArgs * glDrv_glTexGenfArg = (MCC_glDrv_glTexGenfArgs *)argBuffer;
        glDrv_glTexGenf(glDrv_glTexGenfArg->coord, glDrv_glTexGenfArg->pname, glDrv_glTexGenfArg->param);
        break;
      case MCC_glDrv_glTexGenfv :
        CHECKSIZE(MCC_glDrv_glTexGenfvArgs);
        MCC_glDrv_glTexGenfvArgs * glDrv_glTexGenfvArg = (MCC_glDrv_glTexGenfvArgs *)argBuffer;
        glDrv_glTexGenfv(glDrv_glTexGenfvArg->coord, glDrv_glTexGenfvArg->pname, glDrv_glTexGenfvArg->params);
        break;
      case MCC_glDrv_glTexGeni :
        CHECKSIZE(MCC_glDrv_glTexGeniArgs);
        MCC_glDrv_glTexGeniArgs * glDrv_glTexGeniArg = (MCC_glDrv_glTexGeniArgs *)argBuffer;
        glDrv_glTexGeni(glDrv_glTexGeniArg->coord, glDrv_glTexGeniArg->pname, glDrv_glTexGeniArg->param);
        break;
      case MCC_glDrv_glTexGeniv :
        CHECKSIZE(MCC_glDrv_glTexGenivArgs);
        MCC_glDrv_glTexGenivArgs * glDrv_glTexGenivArg = (MCC_glDrv_glTexGenivArgs *)argBuffer;
        glDrv_glTexGeniv(glDrv_glTexGenivArg->coord, glDrv_glTexGenivArg->pname, glDrv_glTexGenivArg->params);
        break;
      case MCC_glDrv_glTexImage1D :
        CHECKSIZE(MCC_glDrv_glTexImage1DArgs);
        MCC_glDrv_glTexImage1DArgs * glDrv_glTexImage1DArg = (MCC_glDrv_glTexImage1DArgs *)argBuffer;
        glDrv_glTexImage1D(glDrv_glTexImage1DArg->target, glDrv_glTexImage1DArg->level, glDrv_glTexImage1DArg->internalformat, glDrv_glTexImage1DArg->width, glDrv_glTexImage1DArg->border, glDrv_glTexImage1DArg->format, glDrv_glTexImage1DArg->type, glDrv_glTexImage1DArg->pixels);
        break;
      case MCC_glDrv_glTexImage2D :
        CHECKSIZE(MCC_glDrv_glTexImage2DArgs);
        MCC_glDrv_glTexImage2DArgs * glDrv_glTexImage2DArg = (MCC_glDrv_glTexImage2DArgs *)argBuffer;
        glDrv_glTexImage2D(glDrv_glTexImage2DArg->target, glDrv_glTexImage2DArg->level, glDrv_glTexImage2DArg->internalformat, glDrv_glTexImage2DArg->width, glDrv_glTexImage2DArg->height, glDrv_glTexImage2DArg->border, glDrv_glTexImage2DArg->format, glDrv_glTexImage2DArg->type, glDrv_glTexImage2DArg->pixels);
        break;
      case MCC_glDrv_glTexParameterf :
        CHECKSIZE(MCC_glDrv_glTexParameterfArgs);
        MCC_glDrv_glTexParameterfArgs * glDrv_glTexParameterfArg = (MCC_glDrv_glTexParameterfArgs *)argBuffer;
        glDrv_glTexParameterf(glDrv_glTexParameterfArg->target, glDrv_glTexParameterfArg->pname, glDrv_glTexParameterfArg->param);
        break;
      case MCC_glDrv_glTexParameterfv :
        CHECKSIZE(MCC_glDrv_glTexParameterfvArgs);
        MCC_glDrv_glTexParameterfvArgs * glDrv_glTexParameterfvArg = (MCC_glDrv_glTexParameterfvArgs *)argBuffer;
        glDrv_glTexParameterfv(glDrv_glTexParameterfvArg->target, glDrv_glTexParameterfvArg->pname, glDrv_glTexParameterfvArg->params);
        break;
      case MCC_glDrv_glTexParameteri :
        CHECKSIZE(MCC_glDrv_glTexParameteriArgs);
        MCC_glDrv_glTexParameteriArgs * glDrv_glTexParameteriArg = (MCC_glDrv_glTexParameteriArgs *)argBuffer;
        glDrv_glTexParameteri(glDrv_glTexParameteriArg->target, glDrv_glTexParameteriArg->pname, glDrv_glTexParameteriArg->param);
        break;
      case MCC_glDrv_glTexParameteriv :
        CHECKSIZE(MCC_glDrv_glTexParameterivArgs);
        MCC_glDrv_glTexParameterivArgs * glDrv_glTexParameterivArg = (MCC_glDrv_glTexParameterivArgs *)argBuffer;
        glDrv_glTexParameteriv(glDrv_glTexParameterivArg->target, glDrv_glTexParameterivArg->pname, glDrv_glTexParameterivArg->params);
        break;
      case MCC_glDrv_glTranslated :
        CHECKSIZE(MCC_glDrv_glTranslatedArgs);
        MCC_glDrv_glTranslatedArgs * glDrv_glTranslatedArg = (MCC_glDrv_glTranslatedArgs *)argBuffer;
        glDrv_glTranslated(glDrv_glTranslatedArg->x, glDrv_glTranslatedArg->y, glDrv_glTranslatedArg->z);
        break;
      case MCC_glDrv_glTranslatef :
        CHECKSIZE(MCC_glDrv_glTranslatefArgs);
        MCC_glDrv_glTranslatefArgs * glDrv_glTranslatefArg = (MCC_glDrv_glTranslatefArgs *)argBuffer;
        glDrv_glTranslatef(glDrv_glTranslatefArg->x, glDrv_glTranslatefArg->y, glDrv_glTranslatefArg->z);
        break;
      case MCC_glDrv_glVertex2d :
        CHECKSIZE(MCC_glDrv_glVertex2dArgs);
        MCC_glDrv_glVertex2dArgs * glDrv_glVertex2dArg = (MCC_glDrv_glVertex2dArgs *)argBuffer;
        glDrv_glVertex2d(glDrv_glVertex2dArg->x, glDrv_glVertex2dArg->y);
        break;
      case MCC_glDrv_glVertex2dv :
        CHECKSIZE(MCC_glDrv_glVertex2dvArgs);
        MCC_glDrv_glVertex2dvArgs * glDrv_glVertex2dvArg = (MCC_glDrv_glVertex2dvArgs *)argBuffer;
        glDrv_glVertex2dv(glDrv_glVertex2dvArg->v);
        break;
      case MCC_glDrv_glVertex2f :
        CHECKSIZE(MCC_glDrv_glVertex2fArgs);
        MCC_glDrv_glVertex2fArgs * glDrv_glVertex2fArg = (MCC_glDrv_glVertex2fArgs *)argBuffer;
        glDrv_glVertex2f(glDrv_glVertex2fArg->x, glDrv_glVertex2fArg->y);
        break;
      case MCC_glDrv_glVertex2fv :
        CHECKSIZE(MCC_glDrv_glVertex2fvArgs);
        MCC_glDrv_glVertex2fvArgs * glDrv_glVertex2fvArg = (MCC_glDrv_glVertex2fvArgs *)argBuffer;
        glDrv_glVertex2fv(glDrv_glVertex2fvArg->v);
        break;
      case MCC_glDrv_glVertex2i :
        CHECKSIZE(MCC_glDrv_glVertex2iArgs);
        MCC_glDrv_glVertex2iArgs * glDrv_glVertex2iArg = (MCC_glDrv_glVertex2iArgs *)argBuffer;
        glDrv_glVertex2i(glDrv_glVertex2iArg->x, glDrv_glVertex2iArg->y);
        break;
      case MCC_glDrv_glVertex2iv :
        CHECKSIZE(MCC_glDrv_glVertex2ivArgs);
        MCC_glDrv_glVertex2ivArgs * glDrv_glVertex2ivArg = (MCC_glDrv_glVertex2ivArgs *)argBuffer;
        glDrv_glVertex2iv(glDrv_glVertex2ivArg->v);
        break;
      case MCC_glDrv_glVertex2s :
        CHECKSIZE(MCC_glDrv_glVertex2sArgs);
        MCC_glDrv_glVertex2sArgs * glDrv_glVertex2sArg = (MCC_glDrv_glVertex2sArgs *)argBuffer;
        glDrv_glVertex2s(glDrv_glVertex2sArg->x, glDrv_glVertex2sArg->y);
        break;
      case MCC_glDrv_glVertex2sv :
        CHECKSIZE(MCC_glDrv_glVertex2svArgs);
        MCC_glDrv_glVertex2svArgs * glDrv_glVertex2svArg = (MCC_glDrv_glVertex2svArgs *)argBuffer;
        glDrv_glVertex2sv(glDrv_glVertex2svArg->v);
        break;
      case MCC_glDrv_glVertex3d :
        CHECKSIZE(MCC_glDrv_glVertex3dArgs);
        MCC_glDrv_glVertex3dArgs * glDrv_glVertex3dArg = (MCC_glDrv_glVertex3dArgs *)argBuffer;
        glDrv_glVertex3d(glDrv_glVertex3dArg->x, glDrv_glVertex3dArg->y, glDrv_glVertex3dArg->z);
        break;
      case MCC_glDrv_glVertex3dv :
        CHECKSIZE(MCC_glDrv_glVertex3dvArgs);
        MCC_glDrv_glVertex3dvArgs * glDrv_glVertex3dvArg = (MCC_glDrv_glVertex3dvArgs *)argBuffer;
        glDrv_glVertex3dv(glDrv_glVertex3dvArg->v);
        break;
      case MCC_glDrv_glVertex3f :
        CHECKSIZE(MCC_glDrv_glVertex3fArgs);
        MCC_glDrv_glVertex3fArgs * glDrv_glVertex3fArg = (MCC_glDrv_glVertex3fArgs *)argBuffer;
        glDrv_glVertex3f(glDrv_glVertex3fArg->x, glDrv_glVertex3fArg->y, glDrv_glVertex3fArg->z);
        break;
      case MCC_glDrv_glVertex3fv :
        CHECKSIZE(MCC_glDrv_glVertex3fvArgs);
        MCC_glDrv_glVertex3fvArgs * glDrv_glVertex3fvArg = (MCC_glDrv_glVertex3fvArgs *)argBuffer;
        glDrv_glVertex3fv(glDrv_glVertex3fvArg->v);
        break;
      case MCC_glDrv_glVertex3i :
        CHECKSIZE(MCC_glDrv_glVertex3iArgs);
        MCC_glDrv_glVertex3iArgs * glDrv_glVertex3iArg = (MCC_glDrv_glVertex3iArgs *)argBuffer;
        glDrv_glVertex3i(glDrv_glVertex3iArg->x, glDrv_glVertex3iArg->y, glDrv_glVertex3iArg->z);
        break;
      case MCC_glDrv_glVertex3iv :
        CHECKSIZE(MCC_glDrv_glVertex3ivArgs);
        MCC_glDrv_glVertex3ivArgs * glDrv_glVertex3ivArg = (MCC_glDrv_glVertex3ivArgs *)argBuffer;
        glDrv_glVertex3iv(glDrv_glVertex3ivArg->v);
        break;
      case MCC_glDrv_glVertex3s :
        CHECKSIZE(MCC_glDrv_glVertex3sArgs);
        MCC_glDrv_glVertex3sArgs * glDrv_glVertex3sArg = (MCC_glDrv_glVertex3sArgs *)argBuffer;
        glDrv_glVertex3s(glDrv_glVertex3sArg->x, glDrv_glVertex3sArg->y, glDrv_glVertex3sArg->z);
        break;
      case MCC_glDrv_glVertex3sv :
        CHECKSIZE(MCC_glDrv_glVertex3svArgs);
        MCC_glDrv_glVertex3svArgs * glDrv_glVertex3svArg = (MCC_glDrv_glVertex3svArgs *)argBuffer;
        glDrv_glVertex3sv(glDrv_glVertex3svArg->v);
        break;
      case MCC_glDrv_glVertex4d :
        CHECKSIZE(MCC_glDrv_glVertex4dArgs);
        MCC_glDrv_glVertex4dArgs * glDrv_glVertex4dArg = (MCC_glDrv_glVertex4dArgs *)argBuffer;
        glDrv_glVertex4d(glDrv_glVertex4dArg->x, glDrv_glVertex4dArg->y, glDrv_glVertex4dArg->z, glDrv_glVertex4dArg->w);
        break;
      case MCC_glDrv_glVertex4dv :
        CHECKSIZE(MCC_glDrv_glVertex4dvArgs);
        MCC_glDrv_glVertex4dvArgs * glDrv_glVertex4dvArg = (MCC_glDrv_glVertex4dvArgs *)argBuffer;
        glDrv_glVertex4dv(glDrv_glVertex4dvArg->v);
        break;
      case MCC_glDrv_glVertex4f :
        CHECKSIZE(MCC_glDrv_glVertex4fArgs);
        MCC_glDrv_glVertex4fArgs * glDrv_glVertex4fArg = (MCC_glDrv_glVertex4fArgs *)argBuffer;
        glDrv_glVertex4f(glDrv_glVertex4fArg->x, glDrv_glVertex4fArg->y, glDrv_glVertex4fArg->z, glDrv_glVertex4fArg->w);
        break;
      case MCC_glDrv_glVertex4fv :
        CHECKSIZE(MCC_glDrv_glVertex4fvArgs);
        MCC_glDrv_glVertex4fvArgs * glDrv_glVertex4fvArg = (MCC_glDrv_glVertex4fvArgs *)argBuffer;
        glDrv_glVertex4fv(glDrv_glVertex4fvArg->v);
        break;
      case MCC_glDrv_glVertex4i :
        CHECKSIZE(MCC_glDrv_glVertex4iArgs);
        MCC_glDrv_glVertex4iArgs * glDrv_glVertex4iArg = (MCC_glDrv_glVertex4iArgs *)argBuffer;
        glDrv_glVertex4i(glDrv_glVertex4iArg->x, glDrv_glVertex4iArg->y, glDrv_glVertex4iArg->z, glDrv_glVertex4iArg->w);
        break;
      case MCC_glDrv_glVertex4iv :
        CHECKSIZE(MCC_glDrv_glVertex4ivArgs);
        MCC_glDrv_glVertex4ivArgs * glDrv_glVertex4ivArg = (MCC_glDrv_glVertex4ivArgs *)argBuffer;
        glDrv_glVertex4iv(glDrv_glVertex4ivArg->v);
        break;
      case MCC_glDrv_glVertex4s :
        CHECKSIZE(MCC_glDrv_glVertex4sArgs);
        MCC_glDrv_glVertex4sArgs * glDrv_glVertex4sArg = (MCC_glDrv_glVertex4sArgs *)argBuffer;
        glDrv_glVertex4s(glDrv_glVertex4sArg->x, glDrv_glVertex4sArg->y, glDrv_glVertex4sArg->z, glDrv_glVertex4sArg->w);
        break;
      case MCC_glDrv_glVertex4sv :
        CHECKSIZE(MCC_glDrv_glVertex4svArgs);
        MCC_glDrv_glVertex4svArgs * glDrv_glVertex4svArg = (MCC_glDrv_glVertex4svArgs *)argBuffer;
        glDrv_glVertex4sv(glDrv_glVertex4svArg->v);
        break;
      case MCC_glDrv_glViewport :
        CHECKSIZE(MCC_glDrv_glViewportArgs);
        MCC_glDrv_glViewportArgs * glDrv_glViewportArg = (MCC_glDrv_glViewportArgs *)argBuffer;
        glDrv_glViewport(glDrv_glViewportArg->x, glDrv_glViewportArg->y, glDrv_glViewportArg->width, glDrv_glViewportArg->height);
        break;
      case MCC_glDrv_glAreTexturesResident :
        CHECKSIZE(MCC_glDrv_glAreTexturesResidentArgs);
        MCC_glDrv_glAreTexturesResidentArgs * glDrv_glAreTexturesResidentArg = (MCC_glDrv_glAreTexturesResidentArgs *)argBuffer;
        glDrv_glAreTexturesResident(glDrv_glAreTexturesResidentArg->n, glDrv_glAreTexturesResidentArg->textures, glDrv_glAreTexturesResidentArg->residences);
        break;
      case MCC_glDrv_glArrayElement :
        CHECKSIZE(MCC_glDrv_glArrayElementArgs);
        MCC_glDrv_glArrayElementArgs * glDrv_glArrayElementArg = (MCC_glDrv_glArrayElementArgs *)argBuffer;
        glDrv_glArrayElement(glDrv_glArrayElementArg->i);
        break;
      case MCC_glDrv_glBindTexture :
        CHECKSIZE(MCC_glDrv_glBindTextureArgs);
        MCC_glDrv_glBindTextureArgs * glDrv_glBindTextureArg = (MCC_glDrv_glBindTextureArgs *)argBuffer;
        glDrv_glBindTexture(glDrv_glBindTextureArg->target, glDrv_glBindTextureArg->texture);
        break;
      case MCC_glDrv_glColorPointer :
        CHECKSIZE(MCC_glDrv_glColorPointerArgs);
        MCC_glDrv_glColorPointerArgs * glDrv_glColorPointerArg = (MCC_glDrv_glColorPointerArgs *)argBuffer;
        glDrv_glColorPointer(glDrv_glColorPointerArg->size, glDrv_glColorPointerArg->type, glDrv_glColorPointerArg->stride, glDrv_glColorPointerArg->pointer);
        break;
      case MCC_glDrv_glCopyTexImage1D :
        CHECKSIZE(MCC_glDrv_glCopyTexImage1DArgs);
        MCC_glDrv_glCopyTexImage1DArgs * glDrv_glCopyTexImage1DArg = (MCC_glDrv_glCopyTexImage1DArgs *)argBuffer;
        glDrv_glCopyTexImage1D(glDrv_glCopyTexImage1DArg->target, glDrv_glCopyTexImage1DArg->level, glDrv_glCopyTexImage1DArg->internalFormat, glDrv_glCopyTexImage1DArg->x, glDrv_glCopyTexImage1DArg->y, glDrv_glCopyTexImage1DArg->width, glDrv_glCopyTexImage1DArg->border);
        break;
      case MCC_glDrv_glCopyTexImage2D :
        CHECKSIZE(MCC_glDrv_glCopyTexImage2DArgs);
        MCC_glDrv_glCopyTexImage2DArgs * glDrv_glCopyTexImage2DArg = (MCC_glDrv_glCopyTexImage2DArgs *)argBuffer;
        glDrv_glCopyTexImage2D(glDrv_glCopyTexImage2DArg->target, glDrv_glCopyTexImage2DArg->level, glDrv_glCopyTexImage2DArg->internalFormat, glDrv_glCopyTexImage2DArg->x, glDrv_glCopyTexImage2DArg->y, glDrv_glCopyTexImage2DArg->width, glDrv_glCopyTexImage2DArg->height, glDrv_glCopyTexImage2DArg->border);
        break;
      case MCC_glDrv_glCopyTexSubImage1D :
        CHECKSIZE(MCC_glDrv_glCopyTexSubImage1DArgs);
        MCC_glDrv_glCopyTexSubImage1DArgs * glDrv_glCopyTexSubImage1DArg = (MCC_glDrv_glCopyTexSubImage1DArgs *)argBuffer;
        glDrv_glCopyTexSubImage1D(glDrv_glCopyTexSubImage1DArg->target, glDrv_glCopyTexSubImage1DArg->level, glDrv_glCopyTexSubImage1DArg->xoffset, glDrv_glCopyTexSubImage1DArg->x, glDrv_glCopyTexSubImage1DArg->y, glDrv_glCopyTexSubImage1DArg->width);
        break;
      case MCC_glDrv_glCopyTexSubImage2D :
        CHECKSIZE(MCC_glDrv_glCopyTexSubImage2DArgs);
        MCC_glDrv_glCopyTexSubImage2DArgs * glDrv_glCopyTexSubImage2DArg = (MCC_glDrv_glCopyTexSubImage2DArgs *)argBuffer;
        glDrv_glCopyTexSubImage2D(glDrv_glCopyTexSubImage2DArg->target, glDrv_glCopyTexSubImage2DArg->level, glDrv_glCopyTexSubImage2DArg->xoffset, glDrv_glCopyTexSubImage2DArg->yoffset, glDrv_glCopyTexSubImage2DArg->x, glDrv_glCopyTexSubImage2DArg->y, glDrv_glCopyTexSubImage2DArg->width, glDrv_glCopyTexSubImage2DArg->height);
        break;
      case MCC_glDrv_glDeleteTextures :
        CHECKSIZE(MCC_glDrv_glDeleteTexturesArgs);
        MCC_glDrv_glDeleteTexturesArgs * glDrv_glDeleteTexturesArg = (MCC_glDrv_glDeleteTexturesArgs *)argBuffer;
        glDrv_glDeleteTextures(glDrv_glDeleteTexturesArg->n, glDrv_glDeleteTexturesArg->textures);
        break;
      case MCC_glDrv_glDisableClientState :
        CHECKSIZE(MCC_glDrv_glDisableClientStateArgs);
        MCC_glDrv_glDisableClientStateArgs * glDrv_glDisableClientStateArg = (MCC_glDrv_glDisableClientStateArgs *)argBuffer;
        glDrv_glDisableClientState(glDrv_glDisableClientStateArg->cap);
        break;
      case MCC_glDrv_glDrawArrays :
        CHECKSIZE(MCC_glDrv_glDrawArraysArgs);
        MCC_glDrv_glDrawArraysArgs * glDrv_glDrawArraysArg = (MCC_glDrv_glDrawArraysArgs *)argBuffer;
        glDrv_glDrawArrays(glDrv_glDrawArraysArg->mode, glDrv_glDrawArraysArg->first, glDrv_glDrawArraysArg->count);
        break;
      case MCC_glDrv_glDrawElements :
        CHECKSIZE(MCC_glDrv_glDrawElementsArgs);
        MCC_glDrv_glDrawElementsArgs * glDrv_glDrawElementsArg = (MCC_glDrv_glDrawElementsArgs *)argBuffer;
        glDrv_glDrawElements(glDrv_glDrawElementsArg->mode, glDrv_glDrawElementsArg->count, glDrv_glDrawElementsArg->type, glDrv_glDrawElementsArg->indices);
        break;
      case MCC_glDrv_glEdgeFlagPointer :
        CHECKSIZE(MCC_glDrv_glEdgeFlagPointerArgs);
        MCC_glDrv_glEdgeFlagPointerArgs * glDrv_glEdgeFlagPointerArg = (MCC_glDrv_glEdgeFlagPointerArgs *)argBuffer;
        glDrv_glEdgeFlagPointer(glDrv_glEdgeFlagPointerArg->stride, glDrv_glEdgeFlagPointerArg->pointer);
        break;
      case MCC_glDrv_glEnableClientState :
        CHECKSIZE(MCC_glDrv_glEnableClientStateArgs);
        MCC_glDrv_glEnableClientStateArgs * glDrv_glEnableClientStateArg = (MCC_glDrv_glEnableClientStateArgs *)argBuffer;
        glDrv_glEnableClientState(glDrv_glEnableClientStateArg->cap);
        break;
      case MCC_glDrv_glGenTextures :
        CHECKSIZE(MCC_glDrv_glGenTexturesArgs);
        MCC_glDrv_glGenTexturesArgs * glDrv_glGenTexturesArg = (MCC_glDrv_glGenTexturesArgs *)argBuffer;
        glDrv_glGenTextures(glDrv_glGenTexturesArg->n, glDrv_glGenTexturesArg->textures);
        break;
      case MCC_glDrv_glGetPointerv :
        CHECKSIZE(MCC_glDrv_glGetPointervArgs);
        MCC_glDrv_glGetPointervArgs * glDrv_glGetPointervArg = (MCC_glDrv_glGetPointervArgs *)argBuffer;
        glDrv_glGetPointerv(glDrv_glGetPointervArg->pname, glDrv_glGetPointervArg->params);
        break;
      case MCC_glDrv_glIsTexture :
        CHECKSIZE(MCC_glDrv_glIsTextureArgs);
        MCC_glDrv_glIsTextureArgs * glDrv_glIsTextureArg = (MCC_glDrv_glIsTextureArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_glIsTexture(glDrv_glIsTextureArg->texture));
        break;
      case MCC_glDrv_glIndexPointer :
        CHECKSIZE(MCC_glDrv_glIndexPointerArgs);
        MCC_glDrv_glIndexPointerArgs * glDrv_glIndexPointerArg = (MCC_glDrv_glIndexPointerArgs *)argBuffer;
        glDrv_glIndexPointer(glDrv_glIndexPointerArg->type, glDrv_glIndexPointerArg->stride, glDrv_glIndexPointerArg->pointer);
        break;
      case MCC_glDrv_glIndexub :
        CHECKSIZE(MCC_glDrv_glIndexubArgs);
        MCC_glDrv_glIndexubArgs * glDrv_glIndexubArg = (MCC_glDrv_glIndexubArgs *)argBuffer;
        glDrv_glIndexub(glDrv_glIndexubArg->c);
        break;
      case MCC_glDrv_glIndexubv :
        CHECKSIZE(MCC_glDrv_glIndexubvArgs);
        MCC_glDrv_glIndexubvArgs * glDrv_glIndexubvArg = (MCC_glDrv_glIndexubvArgs *)argBuffer;
        glDrv_glIndexubv(glDrv_glIndexubvArg->c);
        break;
      case MCC_glDrv_glInterleavedArrays :
        CHECKSIZE(MCC_glDrv_glInterleavedArraysArgs);
        MCC_glDrv_glInterleavedArraysArgs * glDrv_glInterleavedArraysArg = (MCC_glDrv_glInterleavedArraysArgs *)argBuffer;
        glDrv_glInterleavedArrays(glDrv_glInterleavedArraysArg->format, glDrv_glInterleavedArraysArg->stride, glDrv_glInterleavedArraysArg->pointer);
        break;
      case MCC_glDrv_glNormalPointer :
        CHECKSIZE(MCC_glDrv_glNormalPointerArgs);
        MCC_glDrv_glNormalPointerArgs * glDrv_glNormalPointerArg = (MCC_glDrv_glNormalPointerArgs *)argBuffer;
        glDrv_glNormalPointer(glDrv_glNormalPointerArg->type, glDrv_glNormalPointerArg->stride, glDrv_glNormalPointerArg->pointer);
        break;
      case MCC_glDrv_glPolygonOffset :
        CHECKSIZE(MCC_glDrv_glPolygonOffsetArgs);
        MCC_glDrv_glPolygonOffsetArgs * glDrv_glPolygonOffsetArg = (MCC_glDrv_glPolygonOffsetArgs *)argBuffer;
        glDrv_glPolygonOffset(glDrv_glPolygonOffsetArg->factor, glDrv_glPolygonOffsetArg->units);
        break;
      case MCC_glDrv_glPopClientAttrib :
        CHECKSIZE(MCC_glDrv_glPopClientAttribArgs);
        MCC_glDrv_glPopClientAttribArgs * glDrv_glPopClientAttribArg = (MCC_glDrv_glPopClientAttribArgs *)argBuffer;
        glDrv_glPopClientAttrib();
        break;
      case MCC_glDrv_glPrioritizeTextures :
        CHECKSIZE(MCC_glDrv_glPrioritizeTexturesArgs);
        MCC_glDrv_glPrioritizeTexturesArgs * glDrv_glPrioritizeTexturesArg = (MCC_glDrv_glPrioritizeTexturesArgs *)argBuffer;
        glDrv_glPrioritizeTextures(glDrv_glPrioritizeTexturesArg->n, glDrv_glPrioritizeTexturesArg->textures, glDrv_glPrioritizeTexturesArg->priorities);
        break;
      case MCC_glDrv_glPushClientAttrib :
        CHECKSIZE(MCC_glDrv_glPushClientAttribArgs);
        MCC_glDrv_glPushClientAttribArgs * glDrv_glPushClientAttribArg = (MCC_glDrv_glPushClientAttribArgs *)argBuffer;
        glDrv_glPushClientAttrib(glDrv_glPushClientAttribArg->mask);
        break;
      case MCC_glDrv_glTexCoordPointer :
        CHECKSIZE(MCC_glDrv_glTexCoordPointerArgs);
        MCC_glDrv_glTexCoordPointerArgs * glDrv_glTexCoordPointerArg = (MCC_glDrv_glTexCoordPointerArgs *)argBuffer;
        glDrv_glTexCoordPointer(glDrv_glTexCoordPointerArg->size, glDrv_glTexCoordPointerArg->type, glDrv_glTexCoordPointerArg->stride, glDrv_glTexCoordPointerArg->pointer);
        break;
      case MCC_glDrv_glTexSubImage1D :
        CHECKSIZE(MCC_glDrv_glTexSubImage1DArgs);
        MCC_glDrv_glTexSubImage1DArgs * glDrv_glTexSubImage1DArg = (MCC_glDrv_glTexSubImage1DArgs *)argBuffer;
        glDrv_glTexSubImage1D(glDrv_glTexSubImage1DArg->target, glDrv_glTexSubImage1DArg->level, glDrv_glTexSubImage1DArg->xoffset, glDrv_glTexSubImage1DArg->width, glDrv_glTexSubImage1DArg->format, glDrv_glTexSubImage1DArg->type, glDrv_glTexSubImage1DArg->pixels);
        break;
      case MCC_glDrv_glTexSubImage2D :
        CHECKSIZE(MCC_glDrv_glTexSubImage2DArgs);
        MCC_glDrv_glTexSubImage2DArgs * glDrv_glTexSubImage2DArg = (MCC_glDrv_glTexSubImage2DArgs *)argBuffer;
        glDrv_glTexSubImage2D(glDrv_glTexSubImage2DArg->target, glDrv_glTexSubImage2DArg->level, glDrv_glTexSubImage2DArg->xoffset, glDrv_glTexSubImage2DArg->yoffset, glDrv_glTexSubImage2DArg->width, glDrv_glTexSubImage2DArg->height, glDrv_glTexSubImage2DArg->format, glDrv_glTexSubImage2DArg->type, glDrv_glTexSubImage2DArg->pixels);
        break;
      case MCC_glDrv_glVertexPointer :
        CHECKSIZE(MCC_glDrv_glVertexPointerArgs);
        MCC_glDrv_glVertexPointerArgs * glDrv_glVertexPointerArg = (MCC_glDrv_glVertexPointerArgs *)argBuffer;
        glDrv_glVertexPointer(glDrv_glVertexPointerArg->size, glDrv_glVertexPointerArg->type, glDrv_glVertexPointerArg->stride, glDrv_glVertexPointerArg->pointer);
        break;
      case MCC_glDrv_glDrawRangeElements :
        CHECKSIZE(MCC_glDrv_glDrawRangeElementsArgs);
        MCC_glDrv_glDrawRangeElementsArgs * glDrv_glDrawRangeElementsArg = (MCC_glDrv_glDrawRangeElementsArgs *)argBuffer;
        glDrv_glDrawRangeElements(glDrv_glDrawRangeElementsArg->mode, glDrv_glDrawRangeElementsArg->start, glDrv_glDrawRangeElementsArg->end, glDrv_glDrawRangeElementsArg->count, glDrv_glDrawRangeElementsArg->type, glDrv_glDrawRangeElementsArg->indices);
        break;
      case MCC_glDrv_glTexImage3D :
        CHECKSIZE(MCC_glDrv_glTexImage3DArgs);
        MCC_glDrv_glTexImage3DArgs * glDrv_glTexImage3DArg = (MCC_glDrv_glTexImage3DArgs *)argBuffer;
        glDrv_glTexImage3D(glDrv_glTexImage3DArg->target, glDrv_glTexImage3DArg->level, glDrv_glTexImage3DArg->internalFormat, glDrv_glTexImage3DArg->width, glDrv_glTexImage3DArg->height, glDrv_glTexImage3DArg->depth, glDrv_glTexImage3DArg->border, glDrv_glTexImage3DArg->format, glDrv_glTexImage3DArg->type, glDrv_glTexImage3DArg->data);
        break;
      case MCC_glDrv_glTexSubImage3D :
        CHECKSIZE(MCC_glDrv_glTexSubImage3DArgs);
        MCC_glDrv_glTexSubImage3DArgs * glDrv_glTexSubImage3DArg = (MCC_glDrv_glTexSubImage3DArgs *)argBuffer;
        glDrv_glTexSubImage3D(glDrv_glTexSubImage3DArg->target, glDrv_glTexSubImage3DArg->level, glDrv_glTexSubImage3DArg->xoffset, glDrv_glTexSubImage3DArg->yoffset, glDrv_glTexSubImage3DArg->zoffset, glDrv_glTexSubImage3DArg->width, glDrv_glTexSubImage3DArg->height, glDrv_glTexSubImage3DArg->depth, glDrv_glTexSubImage3DArg->format, glDrv_glTexSubImage3DArg->type, glDrv_glTexSubImage3DArg->pixels);
        break;
      case MCC_glDrv_glCopyTexSubImage3D :
        CHECKSIZE(MCC_glDrv_glCopyTexSubImage3DArgs);
        MCC_glDrv_glCopyTexSubImage3DArgs * glDrv_glCopyTexSubImage3DArg = (MCC_glDrv_glCopyTexSubImage3DArgs *)argBuffer;
        glDrv_glCopyTexSubImage3D(glDrv_glCopyTexSubImage3DArg->target, glDrv_glCopyTexSubImage3DArg->level, glDrv_glCopyTexSubImage3DArg->xoffset, glDrv_glCopyTexSubImage3DArg->yoffset, glDrv_glCopyTexSubImage3DArg->zoffset, glDrv_glCopyTexSubImage3DArg->x, glDrv_glCopyTexSubImage3DArg->y, glDrv_glCopyTexSubImage3DArg->width, glDrv_glCopyTexSubImage3DArg->height);
        break;
      case MCC_glDrv_glActiveTexture :
        CHECKSIZE(MCC_glDrv_glActiveTextureArgs);
        MCC_glDrv_glActiveTextureArgs * glDrv_glActiveTextureArg = (MCC_glDrv_glActiveTextureArgs *)argBuffer;
        glDrv_glActiveTexture(glDrv_glActiveTextureArg->texture);
        break;
      case MCC_glDrv_glSampleCoverage :
        CHECKSIZE(MCC_glDrv_glSampleCoverageArgs);
        MCC_glDrv_glSampleCoverageArgs * glDrv_glSampleCoverageArg = (MCC_glDrv_glSampleCoverageArgs *)argBuffer;
        glDrv_glSampleCoverage(glDrv_glSampleCoverageArg->value, glDrv_glSampleCoverageArg->invert);
        break;
      case MCC_glDrv_glCompressedTexImage3D :
        CHECKSIZE(MCC_glDrv_glCompressedTexImage3DArgs);
        MCC_glDrv_glCompressedTexImage3DArgs * glDrv_glCompressedTexImage3DArg = (MCC_glDrv_glCompressedTexImage3DArgs *)argBuffer;
        glDrv_glCompressedTexImage3D(glDrv_glCompressedTexImage3DArg->target, glDrv_glCompressedTexImage3DArg->level, glDrv_glCompressedTexImage3DArg->internalformat, glDrv_glCompressedTexImage3DArg->width, glDrv_glCompressedTexImage3DArg->height, glDrv_glCompressedTexImage3DArg->depth, glDrv_glCompressedTexImage3DArg->border, glDrv_glCompressedTexImage3DArg->imageSize, glDrv_glCompressedTexImage3DArg->data);
        break;
      case MCC_glDrv_glCompressedTexImage2D :
        CHECKSIZE(MCC_glDrv_glCompressedTexImage2DArgs);
        MCC_glDrv_glCompressedTexImage2DArgs * glDrv_glCompressedTexImage2DArg = (MCC_glDrv_glCompressedTexImage2DArgs *)argBuffer;
        glDrv_glCompressedTexImage2D(glDrv_glCompressedTexImage2DArg->target, glDrv_glCompressedTexImage2DArg->level, glDrv_glCompressedTexImage2DArg->internalformat, glDrv_glCompressedTexImage2DArg->width, glDrv_glCompressedTexImage2DArg->height, glDrv_glCompressedTexImage2DArg->border, glDrv_glCompressedTexImage2DArg->imageSize, glDrv_glCompressedTexImage2DArg->data);
        break;
      case MCC_glDrv_glCompressedTexImage1D :
        CHECKSIZE(MCC_glDrv_glCompressedTexImage1DArgs);
        MCC_glDrv_glCompressedTexImage1DArgs * glDrv_glCompressedTexImage1DArg = (MCC_glDrv_glCompressedTexImage1DArgs *)argBuffer;
        glDrv_glCompressedTexImage1D(glDrv_glCompressedTexImage1DArg->target, glDrv_glCompressedTexImage1DArg->level, glDrv_glCompressedTexImage1DArg->internalformat, glDrv_glCompressedTexImage1DArg->width, glDrv_glCompressedTexImage1DArg->border, glDrv_glCompressedTexImage1DArg->imageSize, glDrv_glCompressedTexImage1DArg->data);
        break;
      case MCC_glDrv_glCompressedTexSubImage3D :
        CHECKSIZE(MCC_glDrv_glCompressedTexSubImage3DArgs);
        MCC_glDrv_glCompressedTexSubImage3DArgs * glDrv_glCompressedTexSubImage3DArg = (MCC_glDrv_glCompressedTexSubImage3DArgs *)argBuffer;
        glDrv_glCompressedTexSubImage3D(glDrv_glCompressedTexSubImage3DArg->target, glDrv_glCompressedTexSubImage3DArg->level, glDrv_glCompressedTexSubImage3DArg->xoffset, glDrv_glCompressedTexSubImage3DArg->yoffset, glDrv_glCompressedTexSubImage3DArg->zoffset, glDrv_glCompressedTexSubImage3DArg->width, glDrv_glCompressedTexSubImage3DArg->height, glDrv_glCompressedTexSubImage3DArg->depth, glDrv_glCompressedTexSubImage3DArg->format, glDrv_glCompressedTexSubImage3DArg->imageSize, glDrv_glCompressedTexSubImage3DArg->data);
        break;
      case MCC_glDrv_glCompressedTexSubImage2D :
        CHECKSIZE(MCC_glDrv_glCompressedTexSubImage2DArgs);
        MCC_glDrv_glCompressedTexSubImage2DArgs * glDrv_glCompressedTexSubImage2DArg = (MCC_glDrv_glCompressedTexSubImage2DArgs *)argBuffer;
        glDrv_glCompressedTexSubImage2D(glDrv_glCompressedTexSubImage2DArg->target, glDrv_glCompressedTexSubImage2DArg->level, glDrv_glCompressedTexSubImage2DArg->xoffset, glDrv_glCompressedTexSubImage2DArg->yoffset, glDrv_glCompressedTexSubImage2DArg->width, glDrv_glCompressedTexSubImage2DArg->height, glDrv_glCompressedTexSubImage2DArg->format, glDrv_glCompressedTexSubImage2DArg->imageSize, glDrv_glCompressedTexSubImage2DArg->data);
        break;
      case MCC_glDrv_glCompressedTexSubImage1D :
        CHECKSIZE(MCC_glDrv_glCompressedTexSubImage1DArgs);
        MCC_glDrv_glCompressedTexSubImage1DArgs * glDrv_glCompressedTexSubImage1DArg = (MCC_glDrv_glCompressedTexSubImage1DArgs *)argBuffer;
        glDrv_glCompressedTexSubImage1D(glDrv_glCompressedTexSubImage1DArg->target, glDrv_glCompressedTexSubImage1DArg->level, glDrv_glCompressedTexSubImage1DArg->xoffset, glDrv_glCompressedTexSubImage1DArg->width, glDrv_glCompressedTexSubImage1DArg->format, glDrv_glCompressedTexSubImage1DArg->imageSize, glDrv_glCompressedTexSubImage1DArg->data);
        break;
      case MCC_glDrv_glGetCompressedTexImage :
        CHECKSIZE(MCC_glDrv_glGetCompressedTexImageArgs);
        MCC_glDrv_glGetCompressedTexImageArgs * glDrv_glGetCompressedTexImageArg = (MCC_glDrv_glGetCompressedTexImageArgs *)argBuffer;
        glDrv_glGetCompressedTexImage(glDrv_glGetCompressedTexImageArg->target, glDrv_glGetCompressedTexImageArg->level, glDrv_glGetCompressedTexImageArg->pixels);
        break;
      case MCC_glDrv_glClientActiveTexture :
        CHECKSIZE(MCC_glDrv_glClientActiveTextureArgs);
        MCC_glDrv_glClientActiveTextureArgs * glDrv_glClientActiveTextureArg = (MCC_glDrv_glClientActiveTextureArgs *)argBuffer;
        glDrv_glClientActiveTexture(glDrv_glClientActiveTextureArg->texture);
        break;
      case MCC_glDrv_glMultiTexCoord1d :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord1dArgs);
        MCC_glDrv_glMultiTexCoord1dArgs * glDrv_glMultiTexCoord1dArg = (MCC_glDrv_glMultiTexCoord1dArgs *)argBuffer;
        glDrv_glMultiTexCoord1d(glDrv_glMultiTexCoord1dArg->target, glDrv_glMultiTexCoord1dArg->s);
        break;
      case MCC_glDrv_glMultiTexCoord1dv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord1dvArgs);
        MCC_glDrv_glMultiTexCoord1dvArgs * glDrv_glMultiTexCoord1dvArg = (MCC_glDrv_glMultiTexCoord1dvArgs *)argBuffer;
        glDrv_glMultiTexCoord1dv(glDrv_glMultiTexCoord1dvArg->target, glDrv_glMultiTexCoord1dvArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord1f :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord1fArgs);
        MCC_glDrv_glMultiTexCoord1fArgs * glDrv_glMultiTexCoord1fArg = (MCC_glDrv_glMultiTexCoord1fArgs *)argBuffer;
        glDrv_glMultiTexCoord1f(glDrv_glMultiTexCoord1fArg->target, glDrv_glMultiTexCoord1fArg->s);
        break;
      case MCC_glDrv_glMultiTexCoord1fv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord1fvArgs);
        MCC_glDrv_glMultiTexCoord1fvArgs * glDrv_glMultiTexCoord1fvArg = (MCC_glDrv_glMultiTexCoord1fvArgs *)argBuffer;
        glDrv_glMultiTexCoord1fv(glDrv_glMultiTexCoord1fvArg->target, glDrv_glMultiTexCoord1fvArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord1i :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord1iArgs);
        MCC_glDrv_glMultiTexCoord1iArgs * glDrv_glMultiTexCoord1iArg = (MCC_glDrv_glMultiTexCoord1iArgs *)argBuffer;
        glDrv_glMultiTexCoord1i(glDrv_glMultiTexCoord1iArg->target, glDrv_glMultiTexCoord1iArg->s);
        break;
      case MCC_glDrv_glMultiTexCoord1iv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord1ivArgs);
        MCC_glDrv_glMultiTexCoord1ivArgs * glDrv_glMultiTexCoord1ivArg = (MCC_glDrv_glMultiTexCoord1ivArgs *)argBuffer;
        glDrv_glMultiTexCoord1iv(glDrv_glMultiTexCoord1ivArg->target, glDrv_glMultiTexCoord1ivArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord1s :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord1sArgs);
        MCC_glDrv_glMultiTexCoord1sArgs * glDrv_glMultiTexCoord1sArg = (MCC_glDrv_glMultiTexCoord1sArgs *)argBuffer;
        glDrv_glMultiTexCoord1s(glDrv_glMultiTexCoord1sArg->target, glDrv_glMultiTexCoord1sArg->s);
        break;
      case MCC_glDrv_glMultiTexCoord1sv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord1svArgs);
        MCC_glDrv_glMultiTexCoord1svArgs * glDrv_glMultiTexCoord1svArg = (MCC_glDrv_glMultiTexCoord1svArgs *)argBuffer;
        glDrv_glMultiTexCoord1sv(glDrv_glMultiTexCoord1svArg->target, glDrv_glMultiTexCoord1svArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord2d :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord2dArgs);
        MCC_glDrv_glMultiTexCoord2dArgs * glDrv_glMultiTexCoord2dArg = (MCC_glDrv_glMultiTexCoord2dArgs *)argBuffer;
        glDrv_glMultiTexCoord2d(glDrv_glMultiTexCoord2dArg->target, glDrv_glMultiTexCoord2dArg->s, glDrv_glMultiTexCoord2dArg->t);
        break;
      case MCC_glDrv_glMultiTexCoord2dv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord2dvArgs);
        MCC_glDrv_glMultiTexCoord2dvArgs * glDrv_glMultiTexCoord2dvArg = (MCC_glDrv_glMultiTexCoord2dvArgs *)argBuffer;
        glDrv_glMultiTexCoord2dv(glDrv_glMultiTexCoord2dvArg->target, glDrv_glMultiTexCoord2dvArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord2f :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord2fArgs);
        MCC_glDrv_glMultiTexCoord2fArgs * glDrv_glMultiTexCoord2fArg = (MCC_glDrv_glMultiTexCoord2fArgs *)argBuffer;
        glDrv_glMultiTexCoord2f(glDrv_glMultiTexCoord2fArg->target, glDrv_glMultiTexCoord2fArg->s, glDrv_glMultiTexCoord2fArg->t);
        break;
      case MCC_glDrv_glMultiTexCoord2fv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord2fvArgs);
        MCC_glDrv_glMultiTexCoord2fvArgs * glDrv_glMultiTexCoord2fvArg = (MCC_glDrv_glMultiTexCoord2fvArgs *)argBuffer;
        glDrv_glMultiTexCoord2fv(glDrv_glMultiTexCoord2fvArg->target, glDrv_glMultiTexCoord2fvArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord2i :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord2iArgs);
        MCC_glDrv_glMultiTexCoord2iArgs * glDrv_glMultiTexCoord2iArg = (MCC_glDrv_glMultiTexCoord2iArgs *)argBuffer;
        glDrv_glMultiTexCoord2i(glDrv_glMultiTexCoord2iArg->target, glDrv_glMultiTexCoord2iArg->s, glDrv_glMultiTexCoord2iArg->t);
        break;
      case MCC_glDrv_glMultiTexCoord2iv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord2ivArgs);
        MCC_glDrv_glMultiTexCoord2ivArgs * glDrv_glMultiTexCoord2ivArg = (MCC_glDrv_glMultiTexCoord2ivArgs *)argBuffer;
        glDrv_glMultiTexCoord2iv(glDrv_glMultiTexCoord2ivArg->target, glDrv_glMultiTexCoord2ivArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord2s :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord2sArgs);
        MCC_glDrv_glMultiTexCoord2sArgs * glDrv_glMultiTexCoord2sArg = (MCC_glDrv_glMultiTexCoord2sArgs *)argBuffer;
        glDrv_glMultiTexCoord2s(glDrv_glMultiTexCoord2sArg->target, glDrv_glMultiTexCoord2sArg->s, glDrv_glMultiTexCoord2sArg->t);
        break;
      case MCC_glDrv_glMultiTexCoord2sv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord2svArgs);
        MCC_glDrv_glMultiTexCoord2svArgs * glDrv_glMultiTexCoord2svArg = (MCC_glDrv_glMultiTexCoord2svArgs *)argBuffer;
        glDrv_glMultiTexCoord2sv(glDrv_glMultiTexCoord2svArg->target, glDrv_glMultiTexCoord2svArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord3d :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord3dArgs);
        MCC_glDrv_glMultiTexCoord3dArgs * glDrv_glMultiTexCoord3dArg = (MCC_glDrv_glMultiTexCoord3dArgs *)argBuffer;
        glDrv_glMultiTexCoord3d(glDrv_glMultiTexCoord3dArg->target, glDrv_glMultiTexCoord3dArg->s, glDrv_glMultiTexCoord3dArg->t, glDrv_glMultiTexCoord3dArg->r);
        break;
      case MCC_glDrv_glMultiTexCoord3dv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord3dvArgs);
        MCC_glDrv_glMultiTexCoord3dvArgs * glDrv_glMultiTexCoord3dvArg = (MCC_glDrv_glMultiTexCoord3dvArgs *)argBuffer;
        glDrv_glMultiTexCoord3dv(glDrv_glMultiTexCoord3dvArg->target, glDrv_glMultiTexCoord3dvArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord3f :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord3fArgs);
        MCC_glDrv_glMultiTexCoord3fArgs * glDrv_glMultiTexCoord3fArg = (MCC_glDrv_glMultiTexCoord3fArgs *)argBuffer;
        glDrv_glMultiTexCoord3f(glDrv_glMultiTexCoord3fArg->target, glDrv_glMultiTexCoord3fArg->s, glDrv_glMultiTexCoord3fArg->t, glDrv_glMultiTexCoord3fArg->r);
        break;
      case MCC_glDrv_glMultiTexCoord3fv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord3fvArgs);
        MCC_glDrv_glMultiTexCoord3fvArgs * glDrv_glMultiTexCoord3fvArg = (MCC_glDrv_glMultiTexCoord3fvArgs *)argBuffer;
        glDrv_glMultiTexCoord3fv(glDrv_glMultiTexCoord3fvArg->target, glDrv_glMultiTexCoord3fvArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord3i :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord3iArgs);
        MCC_glDrv_glMultiTexCoord3iArgs * glDrv_glMultiTexCoord3iArg = (MCC_glDrv_glMultiTexCoord3iArgs *)argBuffer;
        glDrv_glMultiTexCoord3i(glDrv_glMultiTexCoord3iArg->target, glDrv_glMultiTexCoord3iArg->s, glDrv_glMultiTexCoord3iArg->t, glDrv_glMultiTexCoord3iArg->r);
        break;
      case MCC_glDrv_glMultiTexCoord3iv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord3ivArgs);
        MCC_glDrv_glMultiTexCoord3ivArgs * glDrv_glMultiTexCoord3ivArg = (MCC_glDrv_glMultiTexCoord3ivArgs *)argBuffer;
        glDrv_glMultiTexCoord3iv(glDrv_glMultiTexCoord3ivArg->target, glDrv_glMultiTexCoord3ivArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord3s :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord3sArgs);
        MCC_glDrv_glMultiTexCoord3sArgs * glDrv_glMultiTexCoord3sArg = (MCC_glDrv_glMultiTexCoord3sArgs *)argBuffer;
        glDrv_glMultiTexCoord3s(glDrv_glMultiTexCoord3sArg->target, glDrv_glMultiTexCoord3sArg->s, glDrv_glMultiTexCoord3sArg->t, glDrv_glMultiTexCoord3sArg->r);
        break;
      case MCC_glDrv_glMultiTexCoord3sv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord3svArgs);
        MCC_glDrv_glMultiTexCoord3svArgs * glDrv_glMultiTexCoord3svArg = (MCC_glDrv_glMultiTexCoord3svArgs *)argBuffer;
        glDrv_glMultiTexCoord3sv(glDrv_glMultiTexCoord3svArg->target, glDrv_glMultiTexCoord3svArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord4d :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord4dArgs);
        MCC_glDrv_glMultiTexCoord4dArgs * glDrv_glMultiTexCoord4dArg = (MCC_glDrv_glMultiTexCoord4dArgs *)argBuffer;
        glDrv_glMultiTexCoord4d(glDrv_glMultiTexCoord4dArg->target, glDrv_glMultiTexCoord4dArg->s, glDrv_glMultiTexCoord4dArg->t, glDrv_glMultiTexCoord4dArg->r, glDrv_glMultiTexCoord4dArg->q);
        break;
      case MCC_glDrv_glMultiTexCoord4dv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord4dvArgs);
        MCC_glDrv_glMultiTexCoord4dvArgs * glDrv_glMultiTexCoord4dvArg = (MCC_glDrv_glMultiTexCoord4dvArgs *)argBuffer;
        glDrv_glMultiTexCoord4dv(glDrv_glMultiTexCoord4dvArg->target, glDrv_glMultiTexCoord4dvArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord4f :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord4fArgs);
        MCC_glDrv_glMultiTexCoord4fArgs * glDrv_glMultiTexCoord4fArg = (MCC_glDrv_glMultiTexCoord4fArgs *)argBuffer;
        glDrv_glMultiTexCoord4f(glDrv_glMultiTexCoord4fArg->target, glDrv_glMultiTexCoord4fArg->s, glDrv_glMultiTexCoord4fArg->t, glDrv_glMultiTexCoord4fArg->r, glDrv_glMultiTexCoord4fArg->q);
        break;
      case MCC_glDrv_glMultiTexCoord4fv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord4fvArgs);
        MCC_glDrv_glMultiTexCoord4fvArgs * glDrv_glMultiTexCoord4fvArg = (MCC_glDrv_glMultiTexCoord4fvArgs *)argBuffer;
        glDrv_glMultiTexCoord4fv(glDrv_glMultiTexCoord4fvArg->target, glDrv_glMultiTexCoord4fvArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord4i :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord4iArgs);
        MCC_glDrv_glMultiTexCoord4iArgs * glDrv_glMultiTexCoord4iArg = (MCC_glDrv_glMultiTexCoord4iArgs *)argBuffer;
        glDrv_glMultiTexCoord4i(glDrv_glMultiTexCoord4iArg->target, glDrv_glMultiTexCoord4iArg->s, glDrv_glMultiTexCoord4iArg->t, glDrv_glMultiTexCoord4iArg->r, glDrv_glMultiTexCoord4iArg->q);
        break;
      case MCC_glDrv_glMultiTexCoord4iv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord4ivArgs);
        MCC_glDrv_glMultiTexCoord4ivArgs * glDrv_glMultiTexCoord4ivArg = (MCC_glDrv_glMultiTexCoord4ivArgs *)argBuffer;
        glDrv_glMultiTexCoord4iv(glDrv_glMultiTexCoord4ivArg->target, glDrv_glMultiTexCoord4ivArg->v);
        break;
      case MCC_glDrv_glMultiTexCoord4s :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord4sArgs);
        MCC_glDrv_glMultiTexCoord4sArgs * glDrv_glMultiTexCoord4sArg = (MCC_glDrv_glMultiTexCoord4sArgs *)argBuffer;
        glDrv_glMultiTexCoord4s(glDrv_glMultiTexCoord4sArg->target, glDrv_glMultiTexCoord4sArg->s, glDrv_glMultiTexCoord4sArg->t, glDrv_glMultiTexCoord4sArg->r, glDrv_glMultiTexCoord4sArg->q);
        break;
      case MCC_glDrv_glMultiTexCoord4sv :
        CHECKSIZE(MCC_glDrv_glMultiTexCoord4svArgs);
        MCC_glDrv_glMultiTexCoord4svArgs * glDrv_glMultiTexCoord4svArg = (MCC_glDrv_glMultiTexCoord4svArgs *)argBuffer;
        glDrv_glMultiTexCoord4sv(glDrv_glMultiTexCoord4svArg->target, glDrv_glMultiTexCoord4svArg->v);
        break;
      case MCC_glDrv_glLoadTransposeMatrixf :
        CHECKSIZE(MCC_glDrv_glLoadTransposeMatrixfArgs);
        MCC_glDrv_glLoadTransposeMatrixfArgs * glDrv_glLoadTransposeMatrixfArg = (MCC_glDrv_glLoadTransposeMatrixfArgs *)argBuffer;
        glDrv_glLoadTransposeMatrixf(glDrv_glLoadTransposeMatrixfArg->m);
        break;
      case MCC_glDrv_glLoadTransposeMatrixd :
        CHECKSIZE(MCC_glDrv_glLoadTransposeMatrixdArgs);
        MCC_glDrv_glLoadTransposeMatrixdArgs * glDrv_glLoadTransposeMatrixdArg = (MCC_glDrv_glLoadTransposeMatrixdArgs *)argBuffer;
        glDrv_glLoadTransposeMatrixd(glDrv_glLoadTransposeMatrixdArg->m);
        break;
      case MCC_glDrv_glMultTransposeMatrixf :
        CHECKSIZE(MCC_glDrv_glMultTransposeMatrixfArgs);
        MCC_glDrv_glMultTransposeMatrixfArgs * glDrv_glMultTransposeMatrixfArg = (MCC_glDrv_glMultTransposeMatrixfArgs *)argBuffer;
        glDrv_glMultTransposeMatrixf(glDrv_glMultTransposeMatrixfArg->m);
        break;
      case MCC_glDrv_glMultTransposeMatrixd :
        CHECKSIZE(MCC_glDrv_glMultTransposeMatrixdArgs);
        MCC_glDrv_glMultTransposeMatrixdArgs * glDrv_glMultTransposeMatrixdArg = (MCC_glDrv_glMultTransposeMatrixdArgs *)argBuffer;
        glDrv_glMultTransposeMatrixd(glDrv_glMultTransposeMatrixdArg->m);
        break;
      case MCC_glDrv_glLockArrays :
        CHECKSIZE(MCC_glDrv_glLockArraysArgs);
        MCC_glDrv_glLockArraysArgs * glDrv_glLockArraysArg = (MCC_glDrv_glLockArraysArgs *)argBuffer;
        glDrv_glLockArrays(glDrv_glLockArraysArg->first, glDrv_glLockArraysArg->count);
        break;
      case MCC_glDrv_glUnlockArrays :
        CHECKSIZE(MCC_glDrv_glUnlockArraysArgs);
        MCC_glDrv_glUnlockArraysArgs * glDrv_glUnlockArraysArg = (MCC_glDrv_glUnlockArraysArgs *)argBuffer;
        glDrv_glUnlockArrays();
        break;
      case MCC_glDrv_wglChoosePixelFormat :
        CHECKSIZE(MCC_glDrv_wglChoosePixelFormatArgs);
        MCC_glDrv_wglChoosePixelFormatArgs * glDrv_wglChoosePixelFormatArg = (MCC_glDrv_wglChoosePixelFormatArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglChoosePixelFormat(glDrv_wglChoosePixelFormatArg->hdc, glDrv_wglChoosePixelFormatArg->ppfd));
        break;
      case MCC_glDrv_wglCopyContext :
        CHECKSIZE(MCC_glDrv_wglCopyContextArgs);
        MCC_glDrv_wglCopyContextArgs * glDrv_wglCopyContextArg = (MCC_glDrv_wglCopyContextArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglCopyContext(glDrv_wglCopyContextArg->hglrc, glDrv_wglCopyContextArg->hglrc2, glDrv_wglCopyContextArg->i));
        break;
      case MCC_glDrv_wglCreateContext :
        CHECKSIZE(MCC_glDrv_wglCreateContextArgs);
        MCC_glDrv_wglCreateContextArgs * glDrv_wglCreateContextArg = (MCC_glDrv_wglCreateContextArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglCreateContext(glDrv_wglCreateContextArg->hdc));
        break;
      case MCC_glDrv_wglCreateLayerContext :
        CHECKSIZE(MCC_glDrv_wglCreateLayerContextArgs);
        MCC_glDrv_wglCreateLayerContextArgs * glDrv_wglCreateLayerContextArg = (MCC_glDrv_wglCreateLayerContextArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglCreateLayerContext(glDrv_wglCreateLayerContextArg->hdc, glDrv_wglCreateLayerContextArg->iLayerPlane));
        break;
      case MCC_glDrv_wglDeleteContext :
        CHECKSIZE(MCC_glDrv_wglDeleteContextArgs);
        MCC_glDrv_wglDeleteContextArgs * glDrv_wglDeleteContextArg = (MCC_glDrv_wglDeleteContextArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglDeleteContext(glDrv_wglDeleteContextArg->hglrc));
        break;
      case MCC_glDrv_wglDescribeLayerPlane :
        CHECKSIZE(MCC_glDrv_wglDescribeLayerPlaneArgs);
        MCC_glDrv_wglDescribeLayerPlaneArgs * glDrv_wglDescribeLayerPlaneArg = (MCC_glDrv_wglDescribeLayerPlaneArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglDescribeLayerPlane(glDrv_wglDescribeLayerPlaneArg->hdc, glDrv_wglDescribeLayerPlaneArg->iPixelFormat, glDrv_wglDescribeLayerPlaneArg->iLayerPlane, glDrv_wglDescribeLayerPlaneArg->nBytes, glDrv_wglDescribeLayerPlaneArg->plpd));
        break;
      case MCC_glDrv_wglDescribePixelFormat :
        CHECKSIZE(MCC_glDrv_wglDescribePixelFormatArgs);
        MCC_glDrv_wglDescribePixelFormatArgs * glDrv_wglDescribePixelFormatArg = (MCC_glDrv_wglDescribePixelFormatArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglDescribePixelFormat(glDrv_wglDescribePixelFormatArg->hdc, glDrv_wglDescribePixelFormatArg->iPixelFormat, glDrv_wglDescribePixelFormatArg->nBytes, glDrv_wglDescribePixelFormatArg->ppfd));
        break;
      case MCC_glDrv_wglGetCurrentContext :
        CHECKSIZE(MCC_glDrv_wglGetCurrentContextArgs);
        MCC_glDrv_wglGetCurrentContextArgs * glDrv_wglGetCurrentContextArg = (MCC_glDrv_wglGetCurrentContextArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglGetCurrentContext());
        break;
      case MCC_glDrv_wglGetCurrentDC :
        CHECKSIZE(MCC_glDrv_wglGetCurrentDCArgs);
        MCC_glDrv_wglGetCurrentDCArgs * glDrv_wglGetCurrentDCArg = (MCC_glDrv_wglGetCurrentDCArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglGetCurrentDC());
        break;
      case MCC_glDrv_wglGetLayerPaletteEntries :
        CHECKSIZE(MCC_glDrv_wglGetLayerPaletteEntriesArgs);
        MCC_glDrv_wglGetLayerPaletteEntriesArgs * glDrv_wglGetLayerPaletteEntriesArg = (MCC_glDrv_wglGetLayerPaletteEntriesArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglGetLayerPaletteEntries(glDrv_wglGetLayerPaletteEntriesArg->hdc, glDrv_wglGetLayerPaletteEntriesArg->iLayerPlane, glDrv_wglGetLayerPaletteEntriesArg->iStart, glDrv_wglGetLayerPaletteEntriesArg->cEntries, glDrv_wglGetLayerPaletteEntriesArg->pcr));
        break;
      case MCC_glDrv_wglGetPixelFormat :
        CHECKSIZE(MCC_glDrv_wglGetPixelFormatArgs);
        MCC_glDrv_wglGetPixelFormatArgs * glDrv_wglGetPixelFormatArg = (MCC_glDrv_wglGetPixelFormatArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglGetPixelFormat(glDrv_wglGetPixelFormatArg->hdc));
        break;
      case MCC_glDrv_wglGetProcAddress :
        CHECKSIZE(MCC_glDrv_wglGetProcAddressArgs);
        MCC_glDrv_wglGetProcAddressArgs * glDrv_wglGetProcAddressArg = (MCC_glDrv_wglGetProcAddressArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglGetProcAddress(glDrv_wglGetProcAddressArg->s));
        break;
      case MCC_glDrv_wglMakeCurrent :
        CHECKSIZE(MCC_glDrv_wglMakeCurrentArgs);
        MCC_glDrv_wglMakeCurrentArgs * glDrv_wglMakeCurrentArg = (MCC_glDrv_wglMakeCurrentArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglMakeCurrent(glDrv_wglMakeCurrentArg->hdc, glDrv_wglMakeCurrentArg->hglrc));
        break;
      case MCC_glDrv_wglRealizeLayerPalette :
        CHECKSIZE(MCC_glDrv_wglRealizeLayerPaletteArgs);
        MCC_glDrv_wglRealizeLayerPaletteArgs * glDrv_wglRealizeLayerPaletteArg = (MCC_glDrv_wglRealizeLayerPaletteArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglRealizeLayerPalette(glDrv_wglRealizeLayerPaletteArg->hdc, glDrv_wglRealizeLayerPaletteArg->iLayerPlane, glDrv_wglRealizeLayerPaletteArg->b));
        break;
      case MCC_glDrv_wglSetLayerPaletteEntries :
        CHECKSIZE(MCC_glDrv_wglSetLayerPaletteEntriesArgs);
        MCC_glDrv_wglSetLayerPaletteEntriesArgs * glDrv_wglSetLayerPaletteEntriesArg = (MCC_glDrv_wglSetLayerPaletteEntriesArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglSetLayerPaletteEntries(glDrv_wglSetLayerPaletteEntriesArg->hdc, glDrv_wglSetLayerPaletteEntriesArg->iLayerPlane, glDrv_wglSetLayerPaletteEntriesArg->iStart, glDrv_wglSetLayerPaletteEntriesArg->cEntries, glDrv_wglSetLayerPaletteEntriesArg->pcr));
        break;
      case MCC_glDrv_wglSetPixelFormat :
        CHECKSIZE(MCC_glDrv_wglSetPixelFormatArgs);
        MCC_glDrv_wglSetPixelFormatArgs * glDrv_wglSetPixelFormatArg = (MCC_glDrv_wglSetPixelFormatArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglSetPixelFormat(glDrv_wglSetPixelFormatArg->hdc, glDrv_wglSetPixelFormatArg->format, glDrv_wglSetPixelFormatArg->ppfd));
        break;
      case MCC_glDrv_wglShareLists :
        CHECKSIZE(MCC_glDrv_wglShareListsArgs);
        MCC_glDrv_wglShareListsArgs * glDrv_wglShareListsArg = (MCC_glDrv_wglShareListsArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglShareLists(glDrv_wglShareListsArg->hglrc, glDrv_wglShareListsArg->hglrc2));
        break;
      case MCC_glDrv_wglSwapBuffers :
        CHECKSIZE(MCC_glDrv_wglSwapBuffersArgs);
        MCC_glDrv_wglSwapBuffersArgs * glDrv_wglSwapBuffersArg = (MCC_glDrv_wglSwapBuffersArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglSwapBuffers(glDrv_wglSwapBuffersArg->hdc));
        break;
      case MCC_glDrv_wglSwapLayerBuffers :
        CHECKSIZE(MCC_glDrv_wglSwapLayerBuffersArgs);
        MCC_glDrv_wglSwapLayerBuffersArgs * glDrv_wglSwapLayerBuffersArg = (MCC_glDrv_wglSwapLayerBuffersArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglSwapLayerBuffers(glDrv_wglSwapLayerBuffersArg->hdc, glDrv_wglSwapLayerBuffersArg->planes));
        break;
      case MCC_glDrv_wglUseFontBitmapsA :
        CHECKSIZE(MCC_glDrv_wglUseFontBitmapsAArgs);
        MCC_glDrv_wglUseFontBitmapsAArgs * glDrv_wglUseFontBitmapsAArg = (MCC_glDrv_wglUseFontBitmapsAArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglUseFontBitmapsA(glDrv_wglUseFontBitmapsAArg->hdc, glDrv_wglUseFontBitmapsAArg->dw1, glDrv_wglUseFontBitmapsAArg->dw2, glDrv_wglUseFontBitmapsAArg->dw3));
        break;
      case MCC_glDrv_wglUseFontBitmapsW :
        CHECKSIZE(MCC_glDrv_wglUseFontBitmapsWArgs);
        MCC_glDrv_wglUseFontBitmapsWArgs * glDrv_wglUseFontBitmapsWArg = (MCC_glDrv_wglUseFontBitmapsWArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglUseFontBitmapsW(glDrv_wglUseFontBitmapsWArg->hdc, glDrv_wglUseFontBitmapsWArg->dw1, glDrv_wglUseFontBitmapsWArg->dw2, glDrv_wglUseFontBitmapsWArg->dw3));
        break;
      case MCC_glDrv_wglUseFontOutlinesA :
        CHECKSIZE(MCC_glDrv_wglUseFontOutlinesAArgs);
        MCC_glDrv_wglUseFontOutlinesAArgs * glDrv_wglUseFontOutlinesAArg = (MCC_glDrv_wglUseFontOutlinesAArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglUseFontOutlinesA(glDrv_wglUseFontOutlinesAArg->hdc, glDrv_wglUseFontOutlinesAArg->dw1, glDrv_wglUseFontOutlinesAArg->dw2, glDrv_wglUseFontOutlinesAArg->dw3, glDrv_wglUseFontOutlinesAArg->f1, glDrv_wglUseFontOutlinesAArg->f2, glDrv_wglUseFontOutlinesAArg->i, glDrv_wglUseFontOutlinesAArg->pgmf));
        break;
      case MCC_glDrv_wglUseFontOutlinesW :
        CHECKSIZE(MCC_glDrv_wglUseFontOutlinesWArgs);
        MCC_glDrv_wglUseFontOutlinesWArgs * glDrv_wglUseFontOutlinesWArg = (MCC_glDrv_wglUseFontOutlinesWArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglUseFontOutlinesW(glDrv_wglUseFontOutlinesWArg->hdc, glDrv_wglUseFontOutlinesWArg->dw1, glDrv_wglUseFontOutlinesWArg->dw2, glDrv_wglUseFontOutlinesWArg->dw3, glDrv_wglUseFontOutlinesWArg->f1, glDrv_wglUseFontOutlinesWArg->f2, glDrv_wglUseFontOutlinesWArg->i, glDrv_wglUseFontOutlinesWArg->pgmf));
        break;
      case MCC_glDrv_wglSetDeviceGammaRamp :
        CHECKSIZE(MCC_glDrv_wglSetDeviceGammaRampArgs);
        MCC_glDrv_wglSetDeviceGammaRampArgs * glDrv_wglSetDeviceGammaRampArg = (MCC_glDrv_wglSetDeviceGammaRampArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglSetDeviceGammaRamp(glDrv_wglSetDeviceGammaRampArg->hdc, glDrv_wglSetDeviceGammaRampArg->lpRamp));
        break;
      case MCC_glDrv_wglGetDeviceGammaRamp :
        CHECKSIZE(MCC_glDrv_wglGetDeviceGammaRampArgs);
        MCC_glDrv_wglGetDeviceGammaRampArgs * glDrv_wglGetDeviceGammaRampArg = (MCC_glDrv_wglGetDeviceGammaRampArgs *)argBuffer;
        MCC_ReturnPointer = (void*)((int)glDrv_wglGetDeviceGammaRamp(glDrv_wglGetDeviceGammaRampArg->hdc, glDrv_wglGetDeviceGammaRampArg->lpRamp));
        break;
      case MCC_glDrv_wglGetExtensionsString :
        CHECKSIZE(MCC_glDrv_wglGetExtensionsStringArgs);
        MCC_glDrv_wglGetExtensionsStringArgs * glDrv_wglGetExtensionsStringArg = (MCC_glDrv_wglGetExtensionsStringArgs *)argBuffer;
        MCC_ReturnPointer = (void*)glDrv_wglGetExtensionsString(glDrv_wglGetExtensionsStringArg->hdc);
        break;
      default:
        break;
    }
  }
}

#endif


