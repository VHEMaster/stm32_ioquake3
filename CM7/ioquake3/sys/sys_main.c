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

#include <signal.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

//TODO WHOLE FIL

#ifndef VCMODS_NOSDL
#ifndef DEDICATED
#ifdef USE_LOCAL_HEADERS
#	include "SDL.h"
#	include "SDL_cpuinfo.h"
#else
#	include <SDL.h>
#	include <SDL_cpuinfo.h>
#endif
#endif
#endif

#include "sys_local.h"
#include "sys_loadlib.h"

#include "../qcommon/q_shared.h"
#include "../qcommon/qcommon.h"

#include "ui_public.h"
#include "g_public.h"
#include "cg_public.h"

static char binaryPath[ MAX_OSPATH ] = { 0 };
static char installPath[ MAX_OSPATH ] = { 0 };
static int mymain( int argc, char **argv );

typedef enum
{
  MOD_INVALID = 0,
  MOD_UI,
  MOD_QAGAME,
  MOD_CGAME

} eModuleHandle;

/*
=================
Sys_SetBinaryPath
=================
*/
void Sys_SetBinaryPath(const char *path)
{
	Q_strncpyz(binaryPath, path, sizeof(binaryPath));
}

/*
=================
Sys_BinaryPath
=================
*/
char *Sys_BinaryPath(void)
{
	return binaryPath;
}

/*
=================
Sys_SetDefaultInstallPath
=================
*/
void Sys_SetDefaultInstallPath(const char *path)
{
	Q_strncpyz(installPath, path, sizeof(installPath));
}

/*
=================
Sys_DefaultAppPath
=================
*/
char *Sys_DefaultAppPath(void)
{
	return Sys_BinaryPath();
}

/*
=================
Sys_DefaultInstallPath
=================
*/
char *Sys_DefaultInstallPath(void)
{
  if (*installPath)
    return installPath;
  else
    return "";
}
/*
=================
Sys_In_Restart_f

Restart the input subsystem
=================
*/
void Sys_In_Restart_f( void )
{
	IN_Restart( );
}

/*
=================
Sys_ConsoleInput

Handle new console input
=================
*/
char *Sys_ConsoleInput(void)
{
  //TODO console input
	//return CON_Input( );
  return 0;
}

/*
=================
Sys_Exit

Single exit point (regular exit or in case of error)
=================
*/
void Sys_Exit( int ex )
{
	//CON_Shutdown( );

#ifndef DEDICATED
#ifndef VCMODS_NOSDL
	SDL_Quit( );
#endif
#endif

#ifdef NDEBUG
	exit( ex );
#else
	// Cause a backtrace on error exits
	assert( ex == 0 );
	exit( ex );
#endif
}

/*
=================
Sys_Quit
=================
*/
void Sys_Quit( void )
{
	CL_Shutdown( );
	Sys_Exit( 0 );
}

/*
=================
Sys_GetProcessorFeatures
=================
*/
cpuFeatures_t Sys_GetProcessorFeatures( void )
{
	cpuFeatures_t features = 0;

#ifndef DEDICATED
#ifndef VCMODS_NOSDL
   if( SDL_HasRDTSC( ) )    features |= CF_RDTSC;
	if( SDL_HasMMX( ) )      features |= CF_MMX;
	if( SDL_Has3DNow( ) )    features |= CF_3DNOW;
	if( SDL_HasSSE( ) )      features |= CF_SSE;
	if( SDL_HasSSE2( ) )     features |= CF_SSE2;
	if( SDL_HasAltiVec( ) )  features |= CF_ALTIVEC;
#endif
#endif

	return features;
}

/*
=================
Sys_Init
=================
*/
void Sys_Init(void)
{
	Cmd_AddCommand( "in_restart", Sys_In_Restart_f );
	Cvar_Set( "arch", OS_STRING " " ARCH_STRING );
	Cvar_Set( "username", Sys_GetCurrentUser( ) );
}

/*
=================
Sys_AnsiColorPrint

Transform Q3 colour codes to ANSI escape sequences
=================
*/
void Sys_AnsiColorPrint( const char *msg )
{
	static char buffer[ MAXPRINTMSG ];
	int         length = 0;
	static int  q3ToAnsi[ 8 ] =
	{
		30, // COLOR_BLACK
		31, // COLOR_RED
		32, // COLOR_GREEN
		33, // COLOR_YELLOW
		34, // COLOR_BLUE
		36, // COLOR_CYAN
		35, // COLOR_MAGENTA
		0   // COLOR_WHITE
	};

	while( *msg )
	{
		if( Q_IsColorString( msg ) || *msg == '\n' )
		{
			// First empty the buffer
			if( length > 0 )
			{
				buffer[ length ] = '\0';
				fputs( buffer, stderr );
				length = 0;
			}

			if( *msg == '\n' )
			{
				// Issue a reset and then the newline
				fputs( "\033[0m\n", stderr );
				msg++;
			}
			else
			{
				// Print the color code
				Com_sprintf( buffer, sizeof( buffer ), "\033[%dm",
						q3ToAnsi[ ColorIndex( *( msg + 1 ) ) ] );
				fputs( buffer, stderr );
				msg += 2;
			}
		}
		else
		{
			if( length >= MAXPRINTMSG - 1 )
				break;

			buffer[ length ] = *msg;
			length++;
			msg++;
		}
	}

	// Empty anything still left in the buffer
	if( length > 0 )
	{
		buffer[ length ] = '\0';
		fputs( buffer, stderr );
	}
}

/*
=================
Sys_Print
=================
*/
void Sys_Print( const char *msg )
{
#if defined(VCMODS_MISC)&&defined(_WIN32)
   OutputDebugString(msg);
#endif

	CON_LogWrite( msg );
	//CON_Print( msg );
}

/*
=================
Sys_Error
=================
*/
void Sys_Error( const char *error, ... )
{
	va_list argptr;
	char    string[1024];

	CL_Shutdown ();

	va_start (argptr,error);
	Q_vsnprintf (string, sizeof(string), error, argptr);
	va_end (argptr);

	Sys_ErrorDialog( string );

	Sys_Exit( 1 );
}

/*
=================
Sys_Warn
=================
*/
void Sys_Warn( char *warning, ... )
{
	va_list argptr;
	char    string[1024];

	va_start (argptr,warning);
	Q_vsnprintf (string, sizeof(string), warning, argptr);
	va_end (argptr);

	CON_Print( va( "Warning: %s", string ) );
}

/*
============
Sys_FileTime

returns -1 if not present
============
*/
int Sys_FileTime( char *path )
{
	struct stat buf;

	if (stat (path,&buf) == -1)
		return -1;

	return buf.st_mtime;
}

/*
=================
Sys_UnloadDll
=================
*/
void Sys_UnloadDll( void *dllHandle )
{
	if( !dllHandle )
	{
		Com_Printf("Sys_UnloadDll(NULL)\n");
		return;
	}
}

/*
=================
Sys_LoadDll

Used to load a development dll instead of a virtual machine
#1 look down current path
#2 look in fs_homepath
#3 look in fs_basepath
=================
*/

void *Sys_LoadDll( const char *name, char *fqpath ,
	intptr_t (**entryPoint)(int, ...),
	intptr_t (*systemcalls)(intptr_t, ...) )
{
	void  *libHandle = NULL;
	void  (*dllEntry)( intptr_t (*syscallptr)(intptr_t, ...) );
	char  fname[MAX_OSPATH];
	char  *basepath;
	char  *homepath;
	char  *gamedir;

	assert( name );

	Q_snprintf (fname, sizeof(fname), "%s" ARCH_STRING DLL_EXT, name);

	// TODO: use fs_searchpaths from files.c
	basepath = Cvar_VariableString( "fs_basepath" );
	homepath = Cvar_VariableString( "fs_homepath" );
	gamedir = Cvar_VariableString( "fs_game" );


  if(strcmp(name, "cgame") == 0)
  {
    libHandle = (void*)MOD_CGAME;
    dllEntry = CG_dllEntry;
    *entryPoint = (intptr_t (*)(int, ...))CG_vmMain;
  }
  else if(strcmp(name, "qagame") == 0)
  {
    libHandle = (void*)MOD_QAGAME;
    dllEntry = G_dllEntry;
    *entryPoint = (intptr_t (*)(int, ...))G_vmMain;
  }
  else if(strcmp(name, "ui") == 0)
  {
    libHandle = (void*)MOD_UI;
    dllEntry = UI_dllEntry;
    //*entryPoint = (intptr_t (*)(int, ...))UI_vmMain;
    *entryPoint = (intptr_t (*)(int, ...))Q3UI_vmMain;
  }

	if(libHandle == NULL) {
		Com_Printf ( "Sys_LoadDll(%s) failed to load library\n", name );
		return NULL;
	}

	Com_Printf ( "Sys_LoadDll(%s) found vmMain function at %p\n", name, *entryPoint );
	dllEntry( systemcalls );

	return libHandle;
}

/*
=================
Sys_ParseArgs
=================
*/
void Sys_ParseArgs( int argc, char **argv )
{
	if( argc == 2 )
	{
		if( !strcmp( argv[1], "--version" ) ||
				!strcmp( argv[1], "-v" ) )
		{
			const char* date = __DATE__;
#ifdef DEDICATED
			printf( Q3_VERSION " dedicated server (%s)\n", date );
#else
			printf( Q3_VERSION " client (%s)\n", date );
#endif
			Sys_Exit(0);
		}
	}
}

#ifndef DEFAULT_BASEDIR
#	ifdef MACOS_X
#		define DEFAULT_BASEDIR Sys_StripAppBundle(Sys_BinaryPath())
#	else
#		define DEFAULT_BASEDIR Sys_BinaryPath()
#	endif
#endif

/*
=================
Sys_SigHandler
=================
*/
void Sys_SigHandler( int signal )
{
	static qboolean signalcaught = qfalse;

	if( signalcaught )
	{
		printf( "DOUBLE SIGNAL FAULT: Received signal %d, exiting...\n",
			signal );
	}
	else
	{
		signalcaught = qtrue;
		printf("Received signal %d, exiting...\n", signal );
#ifndef DEDICATED
		CL_Shutdown();
#endif
		SV_Shutdown( "Signal caught" );
	}

	Sys_Exit( 0 ); // Exit with 0 to avoid recursive signals
}

#if 0
void Sys_SigAction(int sig, siginfo_t *info, void *v)
{
	ucontext_t *uc = (ucontext_t *)v;

	f_printf(stderr, "arm_pc = 0x%08x\n", uc->uc_mcontext.arm_pc);
	f_printf(stderr, "arm_lr = 0x%08x\n", uc->uc_mcontext.arm_lr);

	Sys_SigHandler(sig);
}
#endif

/*
=================
main
=================
*/

int Q3_main( int argc, char **argv )
{
   //Used on RPI???
   //bcm_host_init();
   return mymain(argc, argv);
}


int mymain( int argc, char **argv )
{
	int   i;
	char  commandLine[ MAX_STRING_CHARS ] = { 0 };

#ifndef DEDICATED
#ifndef VCMODS_NOSDL
	// SDL version check

	// Compile time
#	if !SDL_VERSION_ATLEAST(MINSDL_MAJOR,MINSDL_MINOR,MINSDL_PATCH)
#		error A more recent version of SDL is required
#	endif

	// Run time
	const SDL_version *ver = SDL_Linked_Version( );

#define STRING(s) #s
#define XSTRING(s) STRING(s)
#define MINSDL_VERSION \
	XSTRING(MINSDL_MAJOR) "." \
	XSTRING(MINSDL_MINOR) "." \
	XSTRING(MINSDL_PATCH)

	if( SDL_VERSIONNUM( ver->major, ver->minor, ver->patch ) <
			SDL_VERSIONNUM( MINSDL_MAJOR, MINSDL_MINOR, MINSDL_PATCH ) )
	{
		Sys_Print( "SDL version " MINSDL_VERSION " or greater required\n" );
		Sys_Exit( 1 );
	}
#endif
#endif

	Sys_PlatformInit( );

	// Set the initial time base
	Sys_Milliseconds( );

	Sys_ParseArgs( argc, argv );
  Sys_SetBinaryPath(argv[0]);
	Sys_SetDefaultInstallPath( DEFAULT_BASEDIR );

	// Concatenate the command line for passing to Com_Init
	for( i = 1; i < argc; i++ )
	{
		Q_strcat( commandLine, sizeof( commandLine ), argv[ i ] );
		Q_strcat( commandLine, sizeof( commandLine ), " " );
	}

	Com_Init( commandLine );
	NET_Init( );

	//CON_Init( );

	signal( SIGILL, Sys_SigHandler );
	signal( SIGFPE, Sys_SigHandler );
	signal( SIGSEGV, Sys_SigHandler );
	signal( SIGTERM, Sys_SigHandler );

#if 0
		struct sigaction action;

		memset(&action, 0, sizeof(action));

		action.sa_sigaction = Sys_SigAction;
		action.sa_flags = SA_SIGINFO;

		sigaction(SIGFPE, &action, NULL);
#endif
	while( 1 )
	{
#ifndef DEDICATED
#ifndef VCMODS_NOSDL
		int appState = SDL_GetAppState( );

		Cvar_SetValue( "com_unfocused",	!( appState & SDL_APPINPUTFOCUS ) );
		Cvar_SetValue( "com_minimized", !( appState & SDL_APPACTIVE ) );
#endif
#endif

		IN_Frame( );
		Com_Frame( );
	}

	return 0;
}

