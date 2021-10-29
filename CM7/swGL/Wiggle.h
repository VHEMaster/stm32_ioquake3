#include "Windows.h"
#include "OpenGL.h"

// Wiggle API
// -------------------------------------------------------
SWGLAPI GLint STDCALL glDrv_wglChoosePixelFormat(HDC hdc, const PIXELFORMATDESCRIPTOR *ppfd);
SWGLAPI GLboolean STDCALL glDrv_wglCopyContext(HGLRC hglrc, HGLRC hglrc2, UINT i);
SWGLAPI HGLRC STDCALL glDrv_wglCreateContext(HDC hdc);
SWGLAPI HGLRC STDCALL glDrv_wglCreateLayerContext(HDC hdc, int iLayerPlane);
SWGLAPI GLboolean STDCALL glDrv_wglDeleteContext(HGLRC hglrc);
SWGLAPI GLboolean STDCALL glDrv_wglDescribeLayerPlane(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nBytes, LPLAYERPLANEDESCRIPTOR plpd);
SWGLAPI GLint STDCALL glDrv_wglDescribePixelFormat(HDC hdc, int iPixelFormat, UINT nBytes, LPPIXELFORMATDESCRIPTOR ppfd);
SWGLAPI HGLRC STDCALL glDrv_wglGetCurrentContext();
SWGLAPI HDC STDCALL glDrv_wglGetCurrentDC();
SWGLAPI GLint STDCALL glDrv_wglGetLayerPaletteEntries(HDC hdc, int iLayerPlane, int iStart, int cEntries, COLORREF *pcr);
SWGLAPI GLint STDCALL glDrv_wglGetPixelFormat(HDC hdc);
SWGLAPI PROC STDCALL glDrv_wglGetProcAddress(LPCSTR s);
SWGLAPI GLboolean STDCALL glDrv_wglMakeCurrent(HDC hdc, HGLRC hglrc);
SWGLAPI GLboolean STDCALL glDrv_wglRealizeLayerPalette(HDC hdc, int iLayerPlane, GLboolean b);
SWGLAPI GLint STDCALL glDrv_wglSetLayerPaletteEntries(HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF *pcr);
SWGLAPI GLboolean STDCALL glDrv_wglSetPixelFormat(HDC hdc, int format, const PIXELFORMATDESCRIPTOR *ppfd);
SWGLAPI GLboolean STDCALL glDrv_wglShareLists(HGLRC hglrc, HGLRC hglrc2);
SWGLAPI GLboolean STDCALL glDrv_wglSwapBuffers(HDC hdc);
SWGLAPI GLboolean STDCALL glDrv_wglSwapLayerBuffers(HDC hdc, UINT planes);
SWGLAPI GLboolean STDCALL glDrv_wglUseFontBitmapsA(HDC hdc, DWORD dw1, DWORD dw2, DWORD dw3);
SWGLAPI GLboolean STDCALL glDrv_wglUseFontBitmapsW(HDC hdc, DWORD dw1, DWORD dw2, DWORD dw3);
SWGLAPI GLboolean STDCALL glDrv_wglUseFontOutlinesA(HDC hdc, DWORD dw1, DWORD dw2, DWORD dw3, FLOAT f1, FLOAT f2, int i, LPGLYPHMETRICSFLOAT pgmf);
SWGLAPI GLboolean STDCALL glDrv_wglUseFontOutlinesW(HDC hdc, DWORD dw1, DWORD dw2, DWORD dw3, FLOAT f1, FLOAT f2, int i, LPGLYPHMETRICSFLOAT pgmf);
// -------------------------------------------------------

// Some extensions
// -------------------------------------------------------
SWGLAPI GLboolean STDCALL glDrv_wglSetDeviceGammaRamp(HDC hdc, LPVOID lpRamp);
SWGLAPI GLboolean STDCALL glDrv_wglGetDeviceGammaRamp(HDC hdc, LPVOID lpRamp);
SWGLAPI const char * STDCALL glDrv_wglGetExtensionsString(HDC hdc);
// -------------------------------------------------------
