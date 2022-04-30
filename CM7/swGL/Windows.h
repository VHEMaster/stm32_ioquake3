/*
 * Windows.h
 *
 *  Created on: 2 июл. 2020 г.
 *      Author: VHEMaster
 */

#ifndef SWGL_WINDOWS_H_
#define SWGL_WINDOWS_H_

#ifdef __cplusplus
extern "C" {
#endif

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


extern void GetClientRect(HWND hwnd, RECT * rect);

extern HDC WindowFromDC(HWND hwnd);

extern int SetDIBitsToDevice(
		  HDC              hdc,
		  int              xDest,
		  int              yDest,
		  DWORD            w,
		  DWORD            h,
		  int              xSrc,
		  int              ySrc,
		  UINT             StartScan,
		  UINT             cLines,
		  const VOID       *lpvBits,
		  const BITMAPINFO *lpbmi,
		  UINT             ColorUse
		);

#if SWGL_USE_HARDWARE_GAMMA == 1
extern BYTE SetDeviceGammaRamp(HDC hdc, LPVOID lpRamp);
extern BYTE GetDeviceGammaRamp(HDC hdc, LPVOID lpRamp);
#endif

#ifdef __cplusplus
}
#endif
#endif /* SWGL_WINDOWS_H_ */
