#ifndef INC_WIGGLE_H_
#define INC_WIGGLE_H_

#include "OpenGL.h"

typedef unsigned int UINT;
typedef unsigned int HANDLE;
typedef unsigned int HWND;
typedef unsigned int HGLRC;
typedef unsigned long DWORD;
typedef unsigned int HDC;
typedef long LONG;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef float FLOAT;
typedef void* LPVOID;
typedef void* PROC;
typedef void VOID;


//glDrv_wglSwapLayerBuffers, planes
#define WGL_SWAP_MAIN_PLANE 1

//dwFlags
#define PFD_DRAW_TO_WINDOW 1
#define PFD_DOUBLEBUFFER 2
#define PFD_SUPPORT_OPENGL 4

//iPixelType
#define PFD_TYPE_RGBA 1


//biCompression
#define BI_RGB 1
#define DIB_RGB_COLORS 1


typedef DWORD COLORREF;
typedef DWORD* LPCOLORREF;

typedef const char *LPCSTR, *PCSTR;
typedef LPCSTR LPCTSTR;


typedef struct _POINTFLOAT {
  FLOAT x;
  FLOAT y;
} POINTFLOAT, *PPOINTFLOAT;

typedef struct tagLAYERPLANEDESCRIPTOR {
  WORD     nSize;
  WORD     nVersion;
  DWORD    dwFlags;
  BYTE     iPixelType;
  BYTE     cColorBits;
  BYTE     cRedBits;
  BYTE     cRedShift;
  BYTE     cGreenBits;
  BYTE     cGreenShift;
  BYTE     cBlueBits;
  BYTE     cBlueShift;
  BYTE     cAlphaBits;
  BYTE     cAlphaShift;
  BYTE     cAccumBits;
  BYTE     cAccumRedBits;
  BYTE     cAccumGreenBits;
  BYTE     cAccumBlueBits;
  BYTE     cAccumAlphaBits;
  BYTE     cDepthBits;
  BYTE     cStencilBits;
  BYTE     cAuxBuffers;
  BYTE     iLayerPlane;
  BYTE     bReserved;
  COLORREF crTransparent;
} LAYERPLANEDESCRIPTOR, *PLAYERPLANEDESCRIPTOR, *LPLAYERPLANEDESCRIPTOR;

typedef struct tagPIXELFORMATDESCRIPTOR {
  WORD  nSize;
  WORD  nVersion;
  DWORD dwFlags;
  BYTE  iPixelType;
  BYTE  cColorBits;
  BYTE  cRedBits;
  BYTE  cRedShift;
  BYTE  cGreenBits;
  BYTE  cGreenShift;
  BYTE  cBlueBits;
  BYTE  cBlueShift;
  BYTE  cAlphaBits;
  BYTE  cAlphaShift;
  BYTE  cAccumBits;
  BYTE  cAccumRedBits;
  BYTE  cAccumGreenBits;
  BYTE  cAccumBlueBits;
  BYTE  cAccumAlphaBits;
  BYTE  cDepthBits;
  BYTE  cStencilBits;
  BYTE  cAuxBuffers;
  BYTE  iLayerType;
  BYTE  bReserved;
  DWORD dwLayerMask;
  DWORD dwVisibleMask;
  DWORD dwDamageMask;
} PIXELFORMATDESCRIPTOR, *PPIXELFORMATDESCRIPTOR, *LPPIXELFORMATDESCRIPTOR;


typedef struct tagBITMAPINFOHEADER {
  DWORD biSize;
  LONG  biWidth;
  LONG  biHeight;
  WORD  biPlanes;
  WORD  biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG  biXPelsPerMeter;
  LONG  biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagRGBQUAD {
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
} RGBQUAD;

typedef struct tagBITMAPINFO {
  BITMAPINFOHEADER bmiHeader;
  RGBQUAD          bmiColors[1];
} BITMAPINFO, *LPBITMAPINFO, *PBITMAPINFO;

typedef struct _GLYPHMETRICSFLOAT {
  FLOAT      gmfBlackBoxX;
  FLOAT      gmfBlackBoxY;
  POINTFLOAT gmfptGlyphOrigin;
  FLOAT      gmfCellIncX;
  FLOAT      gmfCellIncY;
} GLYPHMETRICSFLOAT, *PGLYPHMETRICSFLOAT, *LPGLYPHMETRICSFLOAT;
typedef struct tagRECT {
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
} RECT, *PRECT, *NPRECT, *LPRECT;

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


#endif /* INC_WIGGLE_H_ */
