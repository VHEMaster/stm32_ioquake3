/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2012 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/
#include <string.h>
#include "SDL_config.h"
#include "OpenGL.h"
#include "Wiggle.h"

/* Dummy SDL video driver implementation; this is just enough to make an
 *  SDL-based application THINK it's got a working video driver, for
 *  applications that call SDL_Init(SDL_INIT_VIDEO) when they don't need it,
 *  and also for use as a collection of stubs when porting SDL to a new
 *  platform for which you haven't yet written a valid video driver.
 *
 * This is also a great way to determine bottlenecks: if you think that SDL
 *  is a performance problem for a given platform, enable this driver, and
 *  then see if your application runs faster without video overhead.
 *
 * Initial work by Ryan C. Gordon (icculus@icculus.org). A good portion
 *  of this was cut-and-pasted from Stephane Peter's work in the AAlib
 *  SDL video driver.  Renamed to "DUMMY" by Sam Lantinga.
 */

#include "SDL_video.h"
#include "SDL_mouse.h"
#include "../SDL_sysvideo.h"
#include "../SDL_pixels_c.h"
#include "../../events/SDL_events_c.h"

#include "SDL_nullvideo.h"
#include "SDL_nullevents_c.h"
#include "SDL_nullmouse_c.h"

#define DUMMYVID_DRIVER_NAME "dummy"

/* Initialization/Query functions */
static int DUMMY_VideoInit(_THIS, SDL_PixelFormat *vformat);
static SDL_Rect **DUMMY_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags);
static SDL_Surface *DUMMY_SetVideoMode(_THIS, SDL_Surface *current, int width, int height, int bpp, Uint32 flags);
static int DUMMY_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors);
static void DUMMY_VideoQuit(_THIS);
static void DUMMY_GL_SwapBuffers(_THIS);
static void *DUMMY_GL_GetProcAddress(_THIS, const char *proc);

/* Hardware surface functions */
static int DUMMY_AllocHWSurface(_THIS, SDL_Surface *surface);
static int DUMMY_LockHWSurface(_THIS, SDL_Surface *surface);
static void DUMMY_UnlockHWSurface(_THIS, SDL_Surface *surface);
static void DUMMY_FreeHWSurface(_THIS, SDL_Surface *surface);

/* etc. */
static void DUMMY_UpdateRects(_THIS, int numrects, SDL_Rect *rects);

/* DUMMY driver bootstrap functions */

static int DUMMY_Available(void)
{
	//const char *envr = SDL_getenv("SDL_VIDEODRIVER");
	//if ((envr) && (SDL_strcmp(envr, DUMMYVID_DRIVER_NAME) == 0)) {
		return(1);
	//}

	//return(0);
}

static void DUMMY_DeleteDevice(SDL_VideoDevice *device)
{
	SDL_free(device->hidden);
	SDL_free(device);
}

static SDL_VideoDevice *DUMMY_CreateDevice(int devindex)
{
	SDL_VideoDevice *device;

	/* Initialize all variables that we clean on shutdown */
	device = (SDL_VideoDevice *)SDL_malloc(sizeof(SDL_VideoDevice));
	if ( device ) {
		SDL_memset(device, 0, (sizeof *device));
		device->hidden = (struct SDL_PrivateVideoData *)
				SDL_malloc((sizeof *device->hidden));
	}
	if ( (device == NULL) || (device->hidden == NULL) ) {
		SDL_OutOfMemory();
		if ( device ) {
			SDL_free(device);
		}
		return(0);
	}
	SDL_memset(device->hidden, 0, (sizeof *device->hidden));

	/* Set the function pointers */
	device->VideoInit = DUMMY_VideoInit;
	device->ListModes = DUMMY_ListModes;
	device->SetVideoMode = DUMMY_SetVideoMode;
	device->CreateYUVOverlay = NULL;
	device->SetColors = DUMMY_SetColors;
	device->UpdateRects = DUMMY_UpdateRects;
	device->VideoQuit = DUMMY_VideoQuit;
	device->AllocHWSurface = DUMMY_AllocHWSurface;
	device->CheckHWBlit = NULL;
	device->FillHWRect = NULL;
	device->SetHWColorKey = NULL;
	device->SetHWAlpha = NULL;
	device->LockHWSurface = DUMMY_LockHWSurface;
	device->UnlockHWSurface = DUMMY_UnlockHWSurface;
	device->FlipHWSurface = NULL;
	device->FreeHWSurface = DUMMY_FreeHWSurface;
	device->SetCaption = NULL;
	device->SetIcon = NULL;
	device->IconifyWindow = NULL;
	device->GrabInput = NULL;
	device->GetWMInfo = NULL;
	device->InitOSKeymap = DUMMY_InitOSKeymap;
	device->PumpEvents = DUMMY_PumpEvents;

#if SDL_VIDEO_OPENGL
  //device->GL_LoadLibrary = WIN_GL_LoadLibrary;
  device->GL_GetProcAddress = DUMMY_GL_GetProcAddress;
  //device->GL_GetAttribute = WIN_GL_GetAttribute;
  //device->GL_MakeCurrent = WIN_GL_MakeCurrent;
  device->GL_SwapBuffers = DUMMY_GL_SwapBuffers;
#endif

	device->free = DUMMY_DeleteDevice;

	return device;
}

VideoBootStrap DUMMY_bootstrap = {
	DUMMYVID_DRIVER_NAME, "SDL dummy video driver",
	DUMMY_Available, DUMMY_CreateDevice
};


void DUMMY_GL_SwapBuffers(_THIS)
{
  HDC hdc = glDrv_wglGetCurrentDC();
  glDrv_wglSwapBuffers(hdc);
}

void *DUMMY_GL_GetProcAddress(_THIS, const char *proc)
{
  if(strcmp(proc , "glAccum") == 0) return glDrv_glAccum;
  if(strcmp(proc , "glAlphaFunc") == 0) return glDrv_glAlphaFunc;
  if(strcmp(proc , "glBegin") == 0) return glDrv_glBegin;
  if(strcmp(proc , "glBitmap") == 0) return glDrv_glBitmap;
  if(strcmp(proc , "glBlendFunc") == 0) return glDrv_glBlendFunc;
  if(strcmp(proc , "glCallList") == 0) return glDrv_glCallList;
  if(strcmp(proc , "glCallLists") == 0) return glDrv_glCallLists;
  if(strcmp(proc , "glClear") == 0) return glDrv_glClear;
  if(strcmp(proc , "glClearAccum") == 0) return glDrv_glClearAccum;
  if(strcmp(proc , "glClearColor") == 0) return glDrv_glClearColor;
  if(strcmp(proc , "glClearDepth") == 0) return glDrv_glClearDepth;
  if(strcmp(proc , "glClearIndex") == 0) return glDrv_glClearIndex;
  if(strcmp(proc , "glClearStencil") == 0) return glDrv_glClearStencil;
  if(strcmp(proc , "glClipPlane") == 0) return glDrv_glClipPlane;
  if(strcmp(proc , "glColor3b") == 0) return glDrv_glColor3b;
  if(strcmp(proc , "glColor3bv") == 0) return glDrv_glColor3bv;
  if(strcmp(proc , "glColor3d") == 0) return glDrv_glColor3d;
  if(strcmp(proc , "glColor3dv") == 0) return glDrv_glColor3dv;
  if(strcmp(proc , "glColor3f") == 0) return glDrv_glColor3f;
  if(strcmp(proc , "glColor3fv") == 0) return glDrv_glColor3fv;
  if(strcmp(proc , "glColor3i") == 0) return glDrv_glColor3i;
  if(strcmp(proc , "glColor3iv") == 0) return glDrv_glColor3iv;
  if(strcmp(proc , "glColor3s") == 0) return glDrv_glColor3s;
  if(strcmp(proc , "glColor3sv") == 0) return glDrv_glColor3sv;
  if(strcmp(proc , "glColor3ub") == 0) return glDrv_glColor3ub;
  if(strcmp(proc , "glColor3ubv") == 0) return glDrv_glColor3ubv;
  if(strcmp(proc , "glColor3ui") == 0) return glDrv_glColor3ui;
  if(strcmp(proc , "glColor3uiv") == 0) return glDrv_glColor3uiv;
  if(strcmp(proc , "glColor3us") == 0) return glDrv_glColor3us;
  if(strcmp(proc , "glColor3usv") == 0) return glDrv_glColor3usv;
  if(strcmp(proc , "glColor4b") == 0) return glDrv_glColor4b;
  if(strcmp(proc , "glColor4bv") == 0) return glDrv_glColor4bv;
  if(strcmp(proc , "glColor4d") == 0) return glDrv_glColor4d;
  if(strcmp(proc , "glColor4dv") == 0) return glDrv_glColor4dv;
  if(strcmp(proc , "glColor4f") == 0) return glDrv_glColor4f;
  if(strcmp(proc , "glColor4fv") == 0) return glDrv_glColor4fv;
  if(strcmp(proc , "glColor4i") == 0) return glDrv_glColor4i;
  if(strcmp(proc , "glColor4iv") == 0) return glDrv_glColor4iv;
  if(strcmp(proc , "glColor4s") == 0) return glDrv_glColor4s;
  if(strcmp(proc , "glColor4sv") == 0) return glDrv_glColor4sv;
  if(strcmp(proc , "glColor4ub") == 0) return glDrv_glColor4ub;
  if(strcmp(proc , "glColor4ubv") == 0) return glDrv_glColor4ubv;
  if(strcmp(proc , "glColor4ui") == 0) return glDrv_glColor4ui;
  if(strcmp(proc , "glColor4uiv") == 0) return glDrv_glColor4uiv;
  if(strcmp(proc , "glColor4us") == 0) return glDrv_glColor4us;
  if(strcmp(proc , "glColor4usv") == 0) return glDrv_glColor4usv;
  if(strcmp(proc , "glColorMask") == 0) return glDrv_glColorMask;
  if(strcmp(proc , "glColorMaterial") == 0) return glDrv_glColorMaterial;
  if(strcmp(proc , "glCopyPixels") == 0) return glDrv_glCopyPixels;
  if(strcmp(proc , "glCullFace") == 0) return glDrv_glCullFace;
  if(strcmp(proc , "glDeleteLists") == 0) return glDrv_glDeleteLists;
  if(strcmp(proc , "glDepthFunc") == 0) return glDrv_glDepthFunc;
  if(strcmp(proc , "glDepthMask") == 0) return glDrv_glDepthMask;
  if(strcmp(proc , "glDepthRange") == 0) return glDrv_glDepthRange;
  if(strcmp(proc , "glDisable") == 0) return glDrv_glDisable;
  if(strcmp(proc , "glDrawBuffer") == 0) return glDrv_glDrawBuffer;
  if(strcmp(proc , "glDrawPixels") == 0) return glDrv_glDrawPixels;
  if(strcmp(proc , "glEdgeFlag") == 0) return glDrv_glEdgeFlag;
  if(strcmp(proc , "glEdgeFlagv") == 0) return glDrv_glEdgeFlagv;
  if(strcmp(proc , "glEnable") == 0) return glDrv_glEnable;
  if(strcmp(proc , "glEnd") == 0) return glDrv_glEnd;
  if(strcmp(proc , "glEndList") == 0) return glDrv_glEndList;
  if(strcmp(proc , "glEvalCoord1d") == 0) return glDrv_glEvalCoord1d;
  if(strcmp(proc , "glEvalCoord1dv") == 0) return glDrv_glEvalCoord1dv;
  if(strcmp(proc , "glEvalCoord1f") == 0) return glDrv_glEvalCoord1f;
  if(strcmp(proc , "glEvalCoord1fv") == 0) return glDrv_glEvalCoord1fv;
  if(strcmp(proc , "glEvalCoord2d") == 0) return glDrv_glEvalCoord2d;
  if(strcmp(proc , "glEvalCoord2dv") == 0) return glDrv_glEvalCoord2dv;
  if(strcmp(proc , "glEvalCoord2f") == 0) return glDrv_glEvalCoord2f;
  if(strcmp(proc , "glEvalCoord2fv") == 0) return glDrv_glEvalCoord2fv;
  if(strcmp(proc , "glEvalMesh1") == 0) return glDrv_glEvalMesh1;
  if(strcmp(proc , "glEvalMesh2") == 0) return glDrv_glEvalMesh2;
  if(strcmp(proc , "glEvalPoint1") == 0) return glDrv_glEvalPoint1;
  if(strcmp(proc , "glEvalPoint2") == 0) return glDrv_glEvalPoint2;
  if(strcmp(proc , "glFeedbackBuffer") == 0) return glDrv_glFeedbackBuffer;
  if(strcmp(proc , "glFinish") == 0) return glDrv_glFinish;
  if(strcmp(proc , "glFlush") == 0) return glDrv_glFlush;
  if(strcmp(proc , "glFogf") == 0) return glDrv_glFogf;
  if(strcmp(proc , "glFogfv") == 0) return glDrv_glFogfv;
  if(strcmp(proc , "glFogi") == 0) return glDrv_glFogi;
  if(strcmp(proc , "glFogiv") == 0) return glDrv_glFogiv;
  if(strcmp(proc , "glFrontFace") == 0) return glDrv_glFrontFace;
  if(strcmp(proc , "glFrustum") == 0) return glDrv_glFrustum;
  if(strcmp(proc , "glGenLists") == 0) return glDrv_glGenLists;
  if(strcmp(proc , "glGetBooleanv") == 0) return glDrv_glGetBooleanv;
  if(strcmp(proc , "glGetClipPlane") == 0) return glDrv_glGetClipPlane;
  if(strcmp(proc , "glGetDoublev") == 0) return glDrv_glGetDoublev;
  if(strcmp(proc , "glGetError") == 0) return glDrv_glGetError;
  if(strcmp(proc , "glGetFloatv") == 0) return glDrv_glGetFloatv;
  if(strcmp(proc , "glGetIntegerv") == 0) return glDrv_glGetIntegerv;
  if(strcmp(proc , "glGetLightfv") == 0) return glDrv_glGetLightfv;
  if(strcmp(proc , "glGetLightiv") == 0) return glDrv_glGetLightiv;
  if(strcmp(proc , "glGetMapdv") == 0) return glDrv_glGetMapdv;
  if(strcmp(proc , "glGetMapfv") == 0) return glDrv_glGetMapfv;
  if(strcmp(proc , "glGetMapiv") == 0) return glDrv_glGetMapiv;
  if(strcmp(proc , "glGetMaterialfv") == 0) return glDrv_glGetMaterialfv;
  if(strcmp(proc , "glGetMaterialiv") == 0) return glDrv_glGetMaterialiv;
  if(strcmp(proc , "glGetPixelMapfv") == 0) return glDrv_glGetPixelMapfv;
  if(strcmp(proc , "glGetPixelMapuiv") == 0) return glDrv_glGetPixelMapuiv;
  if(strcmp(proc , "glGetPixelMapusv") == 0) return glDrv_glGetPixelMapusv;
  if(strcmp(proc , "glGetPolygonStipple") == 0) return glDrv_glGetPolygonStipple;
  if(strcmp(proc , "glGetString") == 0) return glDrv_glGetString;
  if(strcmp(proc , "glGetTexEnvfv") == 0) return glDrv_glGetTexEnvfv;
  if(strcmp(proc , "glGetTexEnviv") == 0) return glDrv_glGetTexEnviv;
  if(strcmp(proc , "glGetTexGendv") == 0) return glDrv_glGetTexGendv;
  if(strcmp(proc , "glGetTexGenfv") == 0) return glDrv_glGetTexGenfv;
  if(strcmp(proc , "glGetTexGeniv") == 0) return glDrv_glGetTexGeniv;
  if(strcmp(proc , "glGetTexImage") == 0) return glDrv_glGetTexImage;
  if(strcmp(proc , "glGetTexLevelParameterfv") == 0) return glDrv_glGetTexLevelParameterfv;
  if(strcmp(proc , "glGetTexLevelParameteriv") == 0) return glDrv_glGetTexLevelParameteriv;
  if(strcmp(proc , "glGetTexParameterfv") == 0) return glDrv_glGetTexParameterfv;
  if(strcmp(proc , "glGetTexParameteriv") == 0) return glDrv_glGetTexParameteriv;
  if(strcmp(proc , "glHint") == 0) return glDrv_glHint;
  if(strcmp(proc , "glIndexMask") == 0) return glDrv_glIndexMask;
  if(strcmp(proc , "glIndexd") == 0) return glDrv_glIndexd;
  if(strcmp(proc , "glIndexdv") == 0) return glDrv_glIndexdv;
  if(strcmp(proc , "glIndexf") == 0) return glDrv_glIndexf;
  if(strcmp(proc , "glIndexfv") == 0) return glDrv_glIndexfv;
  if(strcmp(proc , "glIndexi") == 0) return glDrv_glIndexi;
  if(strcmp(proc , "glIndexiv") == 0) return glDrv_glIndexiv;
  if(strcmp(proc , "glIndexs") == 0) return glDrv_glIndexs;
  if(strcmp(proc , "glIndexsv") == 0) return glDrv_glIndexsv;
  if(strcmp(proc , "glInitNames") == 0) return glDrv_glInitNames;
  if(strcmp(proc , "glIsEnabled") == 0) return glDrv_glIsEnabled;
  if(strcmp(proc , "glIsList") == 0) return glDrv_glIsList;
  if(strcmp(proc , "glLightModelf") == 0) return glDrv_glLightModelf;
  if(strcmp(proc , "glLightModelfv") == 0) return glDrv_glLightModelfv;
  if(strcmp(proc , "glLightModeli") == 0) return glDrv_glLightModeli;
  if(strcmp(proc , "glLightModeliv") == 0) return glDrv_glLightModeliv;
  if(strcmp(proc , "glLightf") == 0) return glDrv_glLightf;
  if(strcmp(proc , "glLightfv") == 0) return glDrv_glLightfv;
  if(strcmp(proc , "glLighti") == 0) return glDrv_glLighti;
  if(strcmp(proc , "glLightiv") == 0) return glDrv_glLightiv;
  if(strcmp(proc , "glLineStipple") == 0) return glDrv_glLineStipple;
  if(strcmp(proc , "glLineWidth") == 0) return glDrv_glLineWidth;
  if(strcmp(proc , "glListBase") == 0) return glDrv_glListBase;
  if(strcmp(proc , "glLoadIdentity") == 0) return glDrv_glLoadIdentity;
  if(strcmp(proc , "glLoadMatrixd") == 0) return glDrv_glLoadMatrixd;
  if(strcmp(proc , "glLoadMatrixf") == 0) return glDrv_glLoadMatrixf;
  if(strcmp(proc , "glLoadName") == 0) return glDrv_glLoadName;
  if(strcmp(proc , "glLogicOp") == 0) return glDrv_glLogicOp;
  if(strcmp(proc , "glMap1d") == 0) return glDrv_glMap1d;
  if(strcmp(proc , "glMap1f") == 0) return glDrv_glMap1f;
  if(strcmp(proc , "glMap2d") == 0) return glDrv_glMap2d;
  if(strcmp(proc , "glMap2f") == 0) return glDrv_glMap2f;
  if(strcmp(proc , "glMapGrid1d") == 0) return glDrv_glMapGrid1d;
  if(strcmp(proc , "glMapGrid1f") == 0) return glDrv_glMapGrid1f;
  if(strcmp(proc , "glMapGrid2d") == 0) return glDrv_glMapGrid2d;
  if(strcmp(proc , "glMapGrid2f") == 0) return glDrv_glMapGrid2f;
  if(strcmp(proc , "glMaterialf") == 0) return glDrv_glMaterialf;
  if(strcmp(proc , "glMaterialfv") == 0) return glDrv_glMaterialfv;
  if(strcmp(proc , "glMateriali") == 0) return glDrv_glMateriali;
  if(strcmp(proc , "glMaterialiv") == 0) return glDrv_glMaterialiv;
  if(strcmp(proc , "glMatrixMode") == 0) return glDrv_glMatrixMode;
  if(strcmp(proc , "glMultMatrixd") == 0) return glDrv_glMultMatrixd;
  if(strcmp(proc , "glMultMatrixf") == 0) return glDrv_glMultMatrixf;
  if(strcmp(proc , "glNewList") == 0) return glDrv_glNewList;
  if(strcmp(proc , "glNormal3b") == 0) return glDrv_glNormal3b;
  if(strcmp(proc , "glNormal3bv") == 0) return glDrv_glNormal3bv;
  if(strcmp(proc , "glNormal3d") == 0) return glDrv_glNormal3d;
  if(strcmp(proc , "glNormal3dv") == 0) return glDrv_glNormal3dv;
  if(strcmp(proc , "glNormal3f") == 0) return glDrv_glNormal3f;
  if(strcmp(proc , "glNormal3fv") == 0) return glDrv_glNormal3fv;
  if(strcmp(proc , "glNormal3i") == 0) return glDrv_glNormal3i;
  if(strcmp(proc , "glNormal3iv") == 0) return glDrv_glNormal3iv;
  if(strcmp(proc , "glNormal3s") == 0) return glDrv_glNormal3s;
  if(strcmp(proc , "glNormal3sv") == 0) return glDrv_glNormal3sv;
  if(strcmp(proc , "glOrtho") == 0) return glDrv_glOrtho;
  if(strcmp(proc , "glPassThrough") == 0) return glDrv_glPassThrough;
  if(strcmp(proc , "glPixelMapfv") == 0) return glDrv_glPixelMapfv;
  if(strcmp(proc , "glPixelMapuiv") == 0) return glDrv_glPixelMapuiv;
  if(strcmp(proc , "glPixelMapusv") == 0) return glDrv_glPixelMapusv;
  if(strcmp(proc , "glPixelStoref") == 0) return glDrv_glPixelStoref;
  if(strcmp(proc , "glPixelStorei") == 0) return glDrv_glPixelStorei;
  if(strcmp(proc , "glPixelTransferf") == 0) return glDrv_glPixelTransferf;
  if(strcmp(proc , "glPixelTransferi") == 0) return glDrv_glPixelTransferi;
  if(strcmp(proc , "glPixelZoom") == 0) return glDrv_glPixelZoom;
  if(strcmp(proc , "glPointSize") == 0) return glDrv_glPointSize;
  if(strcmp(proc , "glPolygonMode") == 0) return glDrv_glPolygonMode;
  if(strcmp(proc , "glPolygonStipple") == 0) return glDrv_glPolygonStipple;
  if(strcmp(proc , "glPopAttrib") == 0) return glDrv_glPopAttrib;
  if(strcmp(proc , "glPopMatrix") == 0) return glDrv_glPopMatrix;
  if(strcmp(proc , "glPopName") == 0) return glDrv_glPopName;
  if(strcmp(proc , "glPushAttrib") == 0) return glDrv_glPushAttrib;
  if(strcmp(proc , "glPushMatrix") == 0) return glDrv_glPushMatrix;
  if(strcmp(proc , "glPushName") == 0) return glDrv_glPushName;
  if(strcmp(proc , "glRasterPos2d") == 0) return glDrv_glRasterPos2d;
  if(strcmp(proc , "glRasterPos2dv") == 0) return glDrv_glRasterPos2dv;
  if(strcmp(proc , "glRasterPos2f") == 0) return glDrv_glRasterPos2f;
  if(strcmp(proc , "glRasterPos2fv") == 0) return glDrv_glRasterPos2fv;
  if(strcmp(proc , "glRasterPos2i") == 0) return glDrv_glRasterPos2i;
  if(strcmp(proc , "glRasterPos2iv") == 0) return glDrv_glRasterPos2iv;
  if(strcmp(proc , "glRasterPos2s") == 0) return glDrv_glRasterPos2s;
  if(strcmp(proc , "glRasterPos2sv") == 0) return glDrv_glRasterPos2sv;
  if(strcmp(proc , "glRasterPos3d") == 0) return glDrv_glRasterPos3d;
  if(strcmp(proc , "glRasterPos3dv") == 0) return glDrv_glRasterPos3dv;
  if(strcmp(proc , "glRasterPos3f") == 0) return glDrv_glRasterPos3f;
  if(strcmp(proc , "glRasterPos3fv") == 0) return glDrv_glRasterPos3fv;
  if(strcmp(proc , "glRasterPos3i") == 0) return glDrv_glRasterPos3i;
  if(strcmp(proc , "glRasterPos3iv") == 0) return glDrv_glRasterPos3iv;
  if(strcmp(proc , "glRasterPos3s") == 0) return glDrv_glRasterPos3s;
  if(strcmp(proc , "glRasterPos3sv") == 0) return glDrv_glRasterPos3sv;
  if(strcmp(proc , "glRasterPos4d") == 0) return glDrv_glRasterPos4d;
  if(strcmp(proc , "glRasterPos4dv") == 0) return glDrv_glRasterPos4dv;
  if(strcmp(proc , "glRasterPos4f") == 0) return glDrv_glRasterPos4f;
  if(strcmp(proc , "glRasterPos4fv") == 0) return glDrv_glRasterPos4fv;
  if(strcmp(proc , "glRasterPos4i") == 0) return glDrv_glRasterPos4i;
  if(strcmp(proc , "glRasterPos4iv") == 0) return glDrv_glRasterPos4iv;
  if(strcmp(proc , "glRasterPos4s") == 0) return glDrv_glRasterPos4s;
  if(strcmp(proc , "glRasterPos4sv") == 0) return glDrv_glRasterPos4sv;
  if(strcmp(proc , "glReadBuffer") == 0) return glDrv_glReadBuffer;
  if(strcmp(proc , "glReadPixels") == 0) return glDrv_glReadPixels;
  if(strcmp(proc , "glRectd") == 0) return glDrv_glRectd;
  if(strcmp(proc , "glRectdv") == 0) return glDrv_glRectdv;
  if(strcmp(proc , "glRectf") == 0) return glDrv_glRectf;
  if(strcmp(proc , "glRectfv") == 0) return glDrv_glRectfv;
  if(strcmp(proc , "glRecti") == 0) return glDrv_glRecti;
  if(strcmp(proc , "glRectiv") == 0) return glDrv_glRectiv;
  if(strcmp(proc , "glRects") == 0) return glDrv_glRects;
  if(strcmp(proc , "glRectsv") == 0) return glDrv_glRectsv;
  if(strcmp(proc , "glRenderMode") == 0) return glDrv_glRenderMode;
  if(strcmp(proc , "glRotated") == 0) return glDrv_glRotated;
  if(strcmp(proc , "glRotatef") == 0) return glDrv_glRotatef;
  if(strcmp(proc , "glScaled") == 0) return glDrv_glScaled;
  if(strcmp(proc , "glScalef") == 0) return glDrv_glScalef;
  if(strcmp(proc , "glScissor") == 0) return glDrv_glScissor;
  if(strcmp(proc , "glSelectBuffer") == 0) return glDrv_glSelectBuffer;
  if(strcmp(proc , "glShadeModel") == 0) return glDrv_glShadeModel;
  if(strcmp(proc , "glStencilFunc") == 0) return glDrv_glStencilFunc;
  if(strcmp(proc , "glStencilMask") == 0) return glDrv_glStencilMask;
  if(strcmp(proc , "glStencilOp") == 0) return glDrv_glStencilOp;
  if(strcmp(proc , "glTexCoord1d") == 0) return glDrv_glTexCoord1d;
  if(strcmp(proc , "glTexCoord1dv") == 0) return glDrv_glTexCoord1dv;
  if(strcmp(proc , "glTexCoord1f") == 0) return glDrv_glTexCoord1f;
  if(strcmp(proc , "glTexCoord1fv") == 0) return glDrv_glTexCoord1fv;
  if(strcmp(proc , "glTexCoord1i") == 0) return glDrv_glTexCoord1i;
  if(strcmp(proc , "glTexCoord1iv") == 0) return glDrv_glTexCoord1iv;
  if(strcmp(proc , "glTexCoord1s") == 0) return glDrv_glTexCoord1s;
  if(strcmp(proc , "glTexCoord1sv") == 0) return glDrv_glTexCoord1sv;
  if(strcmp(proc , "glTexCoord2d") == 0) return glDrv_glTexCoord2d;
  if(strcmp(proc , "glTexCoord2dv") == 0) return glDrv_glTexCoord2dv;
  if(strcmp(proc , "glTexCoord2f") == 0) return glDrv_glTexCoord2f;
  if(strcmp(proc , "glTexCoord2fv") == 0) return glDrv_glTexCoord2fv;
  if(strcmp(proc , "glTexCoord2i") == 0) return glDrv_glTexCoord2i;
  if(strcmp(proc , "glTexCoord2iv") == 0) return glDrv_glTexCoord2iv;
  if(strcmp(proc , "glTexCoord2s") == 0) return glDrv_glTexCoord2s;
  if(strcmp(proc , "glTexCoord2sv") == 0) return glDrv_glTexCoord2sv;
  if(strcmp(proc , "glTexCoord3d") == 0) return glDrv_glTexCoord3d;
  if(strcmp(proc , "glTexCoord3dv") == 0) return glDrv_glTexCoord3dv;
  if(strcmp(proc , "glTexCoord3f") == 0) return glDrv_glTexCoord3f;
  if(strcmp(proc , "glTexCoord3fv") == 0) return glDrv_glTexCoord3fv;
  if(strcmp(proc , "glTexCoord3i") == 0) return glDrv_glTexCoord3i;
  if(strcmp(proc , "glTexCoord3iv") == 0) return glDrv_glTexCoord3iv;
  if(strcmp(proc , "glTexCoord3s") == 0) return glDrv_glTexCoord3s;
  if(strcmp(proc , "glTexCoord3sv") == 0) return glDrv_glTexCoord3sv;
  if(strcmp(proc , "glTexCoord4d") == 0) return glDrv_glTexCoord4d;
  if(strcmp(proc , "glTexCoord4dv") == 0) return glDrv_glTexCoord4dv;
  if(strcmp(proc , "glTexCoord4f") == 0) return glDrv_glTexCoord4f;
  if(strcmp(proc , "glTexCoord4fv") == 0) return glDrv_glTexCoord4fv;
  if(strcmp(proc , "glTexCoord4i") == 0) return glDrv_glTexCoord4i;
  if(strcmp(proc , "glTexCoord4iv") == 0) return glDrv_glTexCoord4iv;
  if(strcmp(proc , "glTexCoord4s") == 0) return glDrv_glTexCoord4s;
  if(strcmp(proc , "glTexCoord4sv") == 0) return glDrv_glTexCoord4sv;
  if(strcmp(proc , "glTexEnvf") == 0) return glDrv_glTexEnvf;
  if(strcmp(proc , "glTexEnvfv") == 0) return glDrv_glTexEnvfv;
  if(strcmp(proc , "glTexEnvi") == 0) return glDrv_glTexEnvi;
  if(strcmp(proc , "glTexEnviv") == 0) return glDrv_glTexEnviv;
  if(strcmp(proc , "glTexGend") == 0) return glDrv_glTexGend;
  if(strcmp(proc , "glTexGendv") == 0) return glDrv_glTexGendv;
  if(strcmp(proc , "glTexGenf") == 0) return glDrv_glTexGenf;
  if(strcmp(proc , "glTexGenfv") == 0) return glDrv_glTexGenfv;
  if(strcmp(proc , "glTexGeni") == 0) return glDrv_glTexGeni;
  if(strcmp(proc , "glTexGeniv") == 0) return glDrv_glTexGeniv;
  if(strcmp(proc , "glTexImage1D") == 0) return glDrv_glTexImage1D;
  if(strcmp(proc , "glTexImage2D") == 0) return glDrv_glTexImage2D;
  if(strcmp(proc , "glTexParameterf") == 0) return glDrv_glTexParameterf;
  if(strcmp(proc , "glTexParameterfv") == 0) return glDrv_glTexParameterfv;
  if(strcmp(proc , "glTexParameteri") == 0) return glDrv_glTexParameteri;
  if(strcmp(proc , "glTexParameteriv") == 0) return glDrv_glTexParameteriv;
  if(strcmp(proc , "glTranslated") == 0) return glDrv_glTranslated;
  if(strcmp(proc , "glTranslatef") == 0) return glDrv_glTranslatef;
  if(strcmp(proc , "glVertex2d") == 0) return glDrv_glVertex2d;
  if(strcmp(proc , "glVertex2dv") == 0) return glDrv_glVertex2dv;
  if(strcmp(proc , "glVertex2f") == 0) return glDrv_glVertex2f;
  if(strcmp(proc , "glVertex2fv") == 0) return glDrv_glVertex2fv;
  if(strcmp(proc , "glVertex2i") == 0) return glDrv_glVertex2i;
  if(strcmp(proc , "glVertex2iv") == 0) return glDrv_glVertex2iv;
  if(strcmp(proc , "glVertex2s") == 0) return glDrv_glVertex2s;
  if(strcmp(proc , "glVertex2sv") == 0) return glDrv_glVertex2sv;
  if(strcmp(proc , "glVertex3d") == 0) return glDrv_glVertex3d;
  if(strcmp(proc , "glVertex3dv") == 0) return glDrv_glVertex3dv;
  if(strcmp(proc , "glVertex3f") == 0) return glDrv_glVertex3f;
  if(strcmp(proc , "glVertex3fv") == 0) return glDrv_glVertex3fv;
  if(strcmp(proc , "glVertex3i") == 0) return glDrv_glVertex3i;
  if(strcmp(proc , "glVertex3iv") == 0) return glDrv_glVertex3iv;
  if(strcmp(proc , "glVertex3s") == 0) return glDrv_glVertex3s;
  if(strcmp(proc , "glVertex3sv") == 0) return glDrv_glVertex3sv;
  if(strcmp(proc , "glVertex4d") == 0) return glDrv_glVertex4d;
  if(strcmp(proc , "glVertex4dv") == 0) return glDrv_glVertex4dv;
  if(strcmp(proc , "glVertex4f") == 0) return glDrv_glVertex4f;
  if(strcmp(proc , "glVertex4fv") == 0) return glDrv_glVertex4fv;
  if(strcmp(proc , "glVertex4i") == 0) return glDrv_glVertex4i;
  if(strcmp(proc , "glVertex4iv") == 0) return glDrv_glVertex4iv;
  if(strcmp(proc , "glVertex4s") == 0) return glDrv_glVertex4s;
  if(strcmp(proc , "glVertex4sv") == 0) return glDrv_glVertex4sv;
  if(strcmp(proc , "glViewport") == 0) return glDrv_glViewport;
  if(strcmp(proc , "glAreTexturesResident") == 0) return glDrv_glAreTexturesResident;
  if(strcmp(proc , "glArrayElement") == 0) return glDrv_glArrayElement;
  if(strcmp(proc , "glBindTexture") == 0) return glDrv_glBindTexture;
  if(strcmp(proc , "glColorPointer") == 0) return glDrv_glColorPointer;
  if(strcmp(proc , "glCopyTexImage1D") == 0) return glDrv_glCopyTexImage1D;
  if(strcmp(proc , "glCopyTexImage2D") == 0) return glDrv_glCopyTexImage2D;
  if(strcmp(proc , "glCopyTexSubImage1D") == 0) return glDrv_glCopyTexSubImage1D;
  if(strcmp(proc , "glCopyTexSubImage2D") == 0) return glDrv_glCopyTexSubImage2D;
  if(strcmp(proc , "glDeleteTextures") == 0) return glDrv_glDeleteTextures;
  if(strcmp(proc , "glDisableClientState") == 0) return glDrv_glDisableClientState;
  if(strcmp(proc , "glDrawArrays") == 0) return glDrv_glDrawArrays;
  if(strcmp(proc , "glDrawElements") == 0) return glDrv_glDrawElements;
  if(strcmp(proc , "glEdgeFlagPointer") == 0) return glDrv_glEdgeFlagPointer;
  if(strcmp(proc , "glEnableClientState") == 0) return glDrv_glEnableClientState;
  if(strcmp(proc , "glGenTextures") == 0) return glDrv_glGenTextures;
  if(strcmp(proc , "glGetPointerv") == 0) return glDrv_glGetPointerv;
  if(strcmp(proc , "glIsTexture") == 0) return glDrv_glIsTexture;
  if(strcmp(proc , "glIndexPointer") == 0) return glDrv_glIndexPointer;
  if(strcmp(proc , "glIndexub") == 0) return glDrv_glIndexub;
  if(strcmp(proc , "glIndexubv") == 0) return glDrv_glIndexubv;
  if(strcmp(proc , "glInterleavedArrays") == 0) return glDrv_glInterleavedArrays;
  if(strcmp(proc , "glNormalPointer") == 0) return glDrv_glNormalPointer;
  if(strcmp(proc , "glPolygonOffset") == 0) return glDrv_glPolygonOffset;
  if(strcmp(proc , "glPopClientAttrib") == 0) return glDrv_glPopClientAttrib;
  if(strcmp(proc , "glPrioritizeTextures") == 0) return glDrv_glPrioritizeTextures;
  if(strcmp(proc , "glPushClientAttrib") == 0) return glDrv_glPushClientAttrib;
  if(strcmp(proc , "glTexCoordPointer") == 0) return glDrv_glTexCoordPointer;
  if(strcmp(proc , "glTexSubImage1D") == 0) return glDrv_glTexSubImage1D;
  if(strcmp(proc , "glTexSubImage2D") == 0) return glDrv_glTexSubImage2D;
  if(strcmp(proc , "glVertexPointer") == 0) return glDrv_glVertexPointer;
  if(strcmp(proc , "glDrawRangeElements") == 0) return glDrv_glDrawRangeElements;
  if(strcmp(proc , "glTexImage3D") == 0) return glDrv_glTexImage3D;
  if(strcmp(proc , "glTexSubImage3D") == 0) return glDrv_glTexSubImage3D;
  if(strcmp(proc , "glCopyTexSubImage3D") == 0) return glDrv_glCopyTexSubImage3D;
  if(strcmp(proc , "glActiveTexture") == 0) return glDrv_glActiveTexture;
  if(strcmp(proc , "glSampleCoverage") == 0) return glDrv_glSampleCoverage;
  if(strcmp(proc , "glCompressedTexImage3D") == 0) return glDrv_glCompressedTexImage3D;
  if(strcmp(proc , "glCompressedTexImage2D") == 0) return glDrv_glCompressedTexImage2D;
  if(strcmp(proc , "glCompressedTexImage1D") == 0) return glDrv_glCompressedTexImage1D;
  if(strcmp(proc , "glCompressedTexSubImage3D") == 0) return glDrv_glCompressedTexSubImage3D;
  if(strcmp(proc , "glCompressedTexSubImage2D") == 0) return glDrv_glCompressedTexSubImage2D;
  if(strcmp(proc , "glCompressedTexSubImage1D") == 0) return glDrv_glCompressedTexSubImage1D;
  if(strcmp(proc , "glGetCompressedTexImage") == 0) return glDrv_glGetCompressedTexImage;
  if(strcmp(proc , "glClientActiveTexture") == 0) return glDrv_glClientActiveTexture;
  if(strcmp(proc , "glMultiTexCoord1d") == 0) return glDrv_glMultiTexCoord1d;
  if(strcmp(proc , "glMultiTexCoord1dv") == 0) return glDrv_glMultiTexCoord1dv;
  if(strcmp(proc , "glMultiTexCoord1f") == 0) return glDrv_glMultiTexCoord1f;
  if(strcmp(proc , "glMultiTexCoord1fv") == 0) return glDrv_glMultiTexCoord1fv;
  if(strcmp(proc , "glMultiTexCoord1i") == 0) return glDrv_glMultiTexCoord1i;
  if(strcmp(proc , "glMultiTexCoord1iv") == 0) return glDrv_glMultiTexCoord1iv;
  if(strcmp(proc , "glMultiTexCoord1s") == 0) return glDrv_glMultiTexCoord1s;
  if(strcmp(proc , "glMultiTexCoord1sv") == 0) return glDrv_glMultiTexCoord1sv;
  if(strcmp(proc , "glMultiTexCoord2d") == 0) return glDrv_glMultiTexCoord2d;
  if(strcmp(proc , "glMultiTexCoord2dv") == 0) return glDrv_glMultiTexCoord2dv;
  if(strcmp(proc , "glMultiTexCoord2f") == 0) return glDrv_glMultiTexCoord2f;
  if(strcmp(proc , "glMultiTexCoord2fv") == 0) return glDrv_glMultiTexCoord2fv;
  if(strcmp(proc , "glMultiTexCoord2i") == 0) return glDrv_glMultiTexCoord2i;
  if(strcmp(proc , "glMultiTexCoord2iv") == 0) return glDrv_glMultiTexCoord2iv;
  if(strcmp(proc , "glMultiTexCoord2s") == 0) return glDrv_glMultiTexCoord2s;
  if(strcmp(proc , "glMultiTexCoord2sv") == 0) return glDrv_glMultiTexCoord2sv;
  if(strcmp(proc , "glMultiTexCoord3d") == 0) return glDrv_glMultiTexCoord3d;
  if(strcmp(proc , "glMultiTexCoord3dv") == 0) return glDrv_glMultiTexCoord3dv;
  if(strcmp(proc , "glMultiTexCoord3f") == 0) return glDrv_glMultiTexCoord3f;
  if(strcmp(proc , "glMultiTexCoord3fv") == 0) return glDrv_glMultiTexCoord3fv;
  if(strcmp(proc , "glMultiTexCoord3i") == 0) return glDrv_glMultiTexCoord3i;
  if(strcmp(proc , "glMultiTexCoord3iv") == 0) return glDrv_glMultiTexCoord3iv;
  if(strcmp(proc , "glMultiTexCoord3s") == 0) return glDrv_glMultiTexCoord3s;
  if(strcmp(proc , "glMultiTexCoord3sv") == 0) return glDrv_glMultiTexCoord3sv;
  if(strcmp(proc , "glMultiTexCoord4d") == 0) return glDrv_glMultiTexCoord4d;
  if(strcmp(proc , "glMultiTexCoord4dv") == 0) return glDrv_glMultiTexCoord4dv;
  if(strcmp(proc , "glMultiTexCoord4f") == 0) return glDrv_glMultiTexCoord4f;
  if(strcmp(proc , "glMultiTexCoord4fv") == 0) return glDrv_glMultiTexCoord4fv;
  if(strcmp(proc , "glMultiTexCoord4i") == 0) return glDrv_glMultiTexCoord4i;
  if(strcmp(proc , "glMultiTexCoord4iv") == 0) return glDrv_glMultiTexCoord4iv;
  if(strcmp(proc , "glMultiTexCoord4s") == 0) return glDrv_glMultiTexCoord4s;
  if(strcmp(proc , "glMultiTexCoord4sv") == 0) return glDrv_glMultiTexCoord4sv;
  if(strcmp(proc , "glLoadTransposeMatrixf") == 0) return glDrv_glLoadTransposeMatrixf;
  if(strcmp(proc , "glLoadTransposeMatrixd") == 0) return glDrv_glLoadTransposeMatrixd;
  if(strcmp(proc , "glMultTransposeMatrixf") == 0) return glDrv_glMultTransposeMatrixf;
  if(strcmp(proc , "glMultTransposeMatrixd") == 0) return glDrv_glMultTransposeMatrixd;
  if(strcmp(proc , "glLockArrays") == 0) return glDrv_glLockArrays;
  if(strcmp(proc , "glUnlockArrays") == 0) return glDrv_glUnlockArrays;
  if(strcmp(proc , "glLockArraysEXT") == 0) return glDrv_glLockArrays;
  if(strcmp(proc , "glUnlockArraysEXT") == 0) return glDrv_glUnlockArrays;
  if(strcmp(proc , "wglChoosePixelFormat") == 0) return glDrv_wglChoosePixelFormat;
  if(strcmp(proc , "wglCopyContext") == 0) return glDrv_wglCopyContext;
  if(strcmp(proc , "wglCreateContext") == 0) return glDrv_wglCreateContext;
  if(strcmp(proc , "wglCreateLayerContext") == 0) return glDrv_wglCreateLayerContext;
  if(strcmp(proc , "wglDeleteContext") == 0) return glDrv_wglDeleteContext;
  if(strcmp(proc , "wglDescribeLayerPlane") == 0) return glDrv_wglDescribeLayerPlane;
  if(strcmp(proc , "wglDescribePixelFormat") == 0) return glDrv_wglDescribePixelFormat;
  if(strcmp(proc , "wglGetCurrentContext") == 0) return glDrv_wglGetCurrentContext;
  if(strcmp(proc , "wglGetCurrentDC") == 0) return glDrv_wglGetCurrentDC;
  if(strcmp(proc , "wglGetLayerPaletteEntries") == 0) return glDrv_wglGetLayerPaletteEntries;
  if(strcmp(proc , "wglGetPixelFormat") == 0) return glDrv_wglGetPixelFormat;
  if(strcmp(proc , "wglGetProcAddress") == 0) return glDrv_wglGetProcAddress;
  if(strcmp(proc , "wglMakeCurrent") == 0) return glDrv_wglMakeCurrent;
  if(strcmp(proc , "wglRealizeLayerPalette") == 0) return glDrv_wglRealizeLayerPalette;
  if(strcmp(proc , "wglSetLayerPaletteEntries") == 0) return glDrv_wglSetLayerPaletteEntries;
  if(strcmp(proc , "wglSetPixelFormat") == 0) return glDrv_wglSetPixelFormat;
  if(strcmp(proc , "wglShareLists") == 0) return glDrv_wglShareLists;
  if(strcmp(proc , "wglSwapBuffers") == 0) return glDrv_wglSwapBuffers;
  if(strcmp(proc , "wglSwapLayerBuffers") == 0) return glDrv_wglSwapLayerBuffers;
  if(strcmp(proc , "wglUseFontBitmapsA") == 0) return glDrv_wglUseFontBitmapsA;
  if(strcmp(proc , "wglUseFontBitmapsW") == 0) return glDrv_wglUseFontBitmapsW;
  if(strcmp(proc , "wglUseFontOutlinesA") == 0) return glDrv_wglUseFontOutlinesA;
  if(strcmp(proc , "wglUseFontOutlinesW") == 0) return glDrv_wglUseFontOutlinesW;
  if(strcmp(proc , "wglSetDeviceGammaRamp") == 0) return glDrv_wglSetDeviceGammaRamp;
  if(strcmp(proc , "wglGetDeviceGammaRamp") == 0) return glDrv_wglGetDeviceGammaRamp;
  if(strcmp(proc , "wglGetExtensionsString") == 0) return glDrv_wglGetExtensionsString;
  return glDrv_wglGetProcAddress(proc);

}


int DUMMY_VideoInit(_THIS, SDL_PixelFormat *vformat)
{
	/*
	f_printf(stderr, "WARNING: You are using the SDL dummy video driver!\n");
	*/

	/* Determine the screen depth (use default 8-bit depth) */
	/* we change this during the SDL_SetVideoMode implementation... */
	vformat->BitsPerPixel = 24;
	vformat->BytesPerPixel = 3;

  switch (vformat->BitsPerPixel) {
    case 15:
      vformat->Rmask = 0x00007c00;
      vformat->Gmask = 0x000003e0;
      vformat->Bmask = 0x0000001f;
      vformat->BitsPerPixel = 16;
      break;
    case 16:
      vformat->Rmask = 0x0000f800;
      vformat->Gmask = 0x000007e0;
      vformat->Bmask = 0x0000001f;
      break;
    case 24:
    case 32:
      /* GDI defined as 8-8-8 */
      vformat->Rmask = 0x00ff0000;
      vformat->Gmask = 0x0000ff00;
      vformat->Bmask = 0x000000ff;
      break;
    default:
      break;
  }

  this->info.current_w = 800;
  this->info.current_h = 480;
  this->info.wm_available = 0;

  HDC hdc = glDrv_wglGetCurrentDC();
  HGLRC context = glDrv_wglCreateContext(hdc);
  glDrv_wglMakeCurrent(hdc, context);

	/* We're done! */
	return(0);
}

SDL_Rect **DUMMY_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags)
{
   	 return (SDL_Rect **) -1;
}

SDL_Surface *DUMMY_SetVideoMode(_THIS, SDL_Surface *current,
				int width, int height, int bpp, Uint32 flags)
{
	if ( this->hidden->buffer ) {
		SDL_free( this->hidden->buffer );
	}

	this->hidden->buffer = SDL_malloc(width * height * (bpp / 8));
	if ( ! this->hidden->buffer ) {
		SDL_SetError("Couldn't allocate buffer for requested mode");
		return(NULL);
	}

/* 	printf("Setting mode %dx%d\n", width, height); */

	SDL_memset(this->hidden->buffer, 0, width * height * (bpp / 8));

	/* Allocate the new pixel format for the screen */
	if ( ! SDL_ReallocFormat(current, bpp, 0, 0, 0, 0) ) {
		SDL_free(this->hidden->buffer);
		this->hidden->buffer = NULL;
		SDL_SetError("Couldn't allocate new pixel format for requested mode");
		return(NULL);
	}

	/* Set up the new mode framebuffer */
	current->flags = flags;
	this->hidden->w = current->w = width;
	this->hidden->h = current->h = height;
	current->pitch = current->w * (bpp / 8);
	current->pixels = this->hidden->buffer;

	/* We're done */
	return(current);
}

/* We don't actually allow hardware surfaces other than the main one */
static int DUMMY_AllocHWSurface(_THIS, SDL_Surface *surface)
{
	return(-1);
}
static void DUMMY_FreeHWSurface(_THIS, SDL_Surface *surface)
{
	return;
}

/* We need to wait for vertical retrace on page flipped displays */
static int DUMMY_LockHWSurface(_THIS, SDL_Surface *surface)
{
	return(0);
}

static void DUMMY_UnlockHWSurface(_THIS, SDL_Surface *surface)
{
	return;
}

static void DUMMY_UpdateRects(_THIS, int numrects, SDL_Rect *rects)
{
	/* do nothing. */
}

int DUMMY_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors)
{
	/* do nothing of note. */
	return(1);
}

/* Note:  If we are terminated, this could be called in the middle of
   another SDL video routine -- notably UpdateRects.
*/
void DUMMY_VideoQuit(_THIS)
{
	if (this->screen->pixels != NULL)
	{
		SDL_free(this->screen->pixels);
		this->screen->pixels = NULL;
	}
}
