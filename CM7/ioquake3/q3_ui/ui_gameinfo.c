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
//
//
// gameinfo.c
//

#include "ui_local.h"


//
// arena and bot info
//

#define POOLSIZE	128 * 1024

int				ui_numBots;
static char		*ui_botInfos[MAX_BOTS];

static int		ui_numArenas;
static char		*ui_arenaInfos[MAX_ARENAS];

static int		ui_numSinglePlayerArenas;
static int		ui_numSpecialSinglePlayerArenas;

static char		memoryPool[POOLSIZE];
static int		allocPoint, outOfMemory;


/*
===============
Q3UI_Alloc
===============
*/
void *Q3UI_Alloc( int size ) {
	char	*p;

	if ( allocPoint + size > POOLSIZE ) {
		outOfMemory = qtrue;
		return NULL;
	}

	p = &memoryPool[allocPoint];

	allocPoint += ( size + 31 ) & ~31;

	return p;
}

/*
===============
Q3UI_InitMemory
===============
*/
void Q3UI_InitMemory( void ) {
	allocPoint = 0;
	outOfMemory = qfalse;
}

/*
===============
Q3UI_ParseInfos
===============
*/
int Q3UI_ParseInfos( char *buf, int max, char *infos[] ) {
	char	*token;
	int		count;
	char	key[MAX_TOKEN_CHARS];
	char	info[MAX_INFO_STRING];

	count = 0;

	while ( 1 ) {
		token = COM_Parse( &buf );
		if ( !token[0] ) {
			break;
		}
		if ( strcmp( token, "{" ) ) {
			Q3UI_Com_Printf( "Missing { in info file\n" );
			break;
		}

		if ( count == max ) {
			Q3UI_Com_Printf( "Max infos exceeded\n" );
			break;
		}

		info[0] = '\0';
		while ( 1 ) {
			token = COM_ParseExt( &buf, qtrue );
			if ( !token[0] ) {
				Q3UI_Com_Printf( "Unexpected end of info file\n" );
				break;
			}
			if ( !strcmp( token, "}" ) ) {
				break;
			}
			Q_strncpyz( key, token, sizeof( key ) );

			token = COM_ParseExt( &buf, qfalse );
			if ( !token[0] ) {
				strcpy( token, "<NULL>" );
			}
			Info_SetValueForKey( info, key, token );
		}
		//NOTE: extra space for arena number
		infos[count] = Q3UI_Alloc(strlen(info) + strlen("\\num\\") + strlen(va("%d", MAX_ARENAS)) + 1);
		if (infos[count]) {
			strcpy(infos[count], info);
			count++;
		}
	}
	return count;
}

/*
===============
Q3UI_LoadArenasFromFile
===============
*/
static void Q3UI_LoadArenasFromFile( char *filename ) {
	int				len;
	fileHandle_t	f;
	char			buf[MAX_ARENAS_TEXT];

	len = UI_trap_FS_FOpenFile( filename, &f, FS_READ );
	if ( !f ) {
		UI_trap_Print( va( S_COLOR_RED "file not found: %s\n", filename ) );
		return;
	}
	if ( len >= MAX_ARENAS_TEXT ) {
		UI_trap_Print( va( S_COLOR_RED "file too large: %s is %i, max allowed is %i", filename, len, MAX_ARENAS_TEXT ) );
		UI_trap_FS_FCloseFile( f );
		return;
	}

	UI_trap_FS_Read( buf, len, f );
	buf[len] = 0;
	UI_trap_FS_FCloseFile( f );

	ui_numArenas += Q3UI_ParseInfos( buf, MAX_ARENAS - ui_numArenas, &ui_arenaInfos[ui_numArenas] );
}

/*
===============
Q3UI_LoadArenas
===============
*/
static void Q3UI_LoadArenas( void ) {
	int			numdirs;
	vmCvar_t	arenasFile;
	char		filename[128];
	char		dirlist[1024];
	char*		dirptr;
	int			i, n;
	int			dirlen;
	char		*type;
	char		*tag;
	int			singlePlayerNum, specialNum, otherNum;

	ui_numArenas = 0;

	UI_trap_Cvar_Register( &arenasFile, "g_arenasFile", "", CVAR_INIT|CVAR_ROM );
	if( *arenasFile.string ) {
		Q3UI_LoadArenasFromFile(arenasFile.string);
	}
	else {
		Q3UI_LoadArenasFromFile("scripts/arenas.txt");
	}

	// get all arenas from .arena files
	numdirs = UI_trap_FS_GetFileList("scripts", ".arena", dirlist, 1024 );
	dirptr  = dirlist;
	for (i = 0; i < numdirs; i++, dirptr += dirlen+1) {
		dirlen = strlen(dirptr);
		strcpy(filename, "scripts/");
		strcat(filename, dirptr);
		Q3UI_LoadArenasFromFile(filename);
	}
	UI_trap_Print( va( "%i arenas parsed\n", ui_numArenas ) );
	if (outOfMemory) UI_trap_Print(S_COLOR_YELLOW"WARNING: not anough memory in pool to load all arenas\n");

	// set initial numbers
	for( n = 0; n < ui_numArenas; n++ ) {
		Info_SetValueForKey( ui_arenaInfos[n], "num", va( "%i", n ) );
	}

	// go through and count single players levels
	ui_numSinglePlayerArenas = 0;
	ui_numSpecialSinglePlayerArenas = 0;
	for( n = 0; n < ui_numArenas; n++ ) {
		// determine type
		type = Info_ValueForKey( ui_arenaInfos[n], "type" );

		// if no type specified, it will be treated as "ffa"
		if( !*type ) {
			continue;
		}

		if( strstr( type, "single" ) ) {
			// check for special single player arenas (training, final)
			tag = Info_ValueForKey( ui_arenaInfos[n], "special" );
			if( *tag ) {
				ui_numSpecialSinglePlayerArenas++;
				continue;
			}

			ui_numSinglePlayerArenas++;
		}
	}

	n = ui_numSinglePlayerArenas % ARENAS_PER_TIER;
	if( n != 0 ) {
		ui_numSinglePlayerArenas -= n;
		UI_trap_Print( va( "%i arenas ignored to make count divisible by %i\n", n, ARENAS_PER_TIER ) );
	}

	// go through once more and assign number to the levels
	singlePlayerNum = 0;
	specialNum = singlePlayerNum + ui_numSinglePlayerArenas;
	otherNum = specialNum + ui_numSpecialSinglePlayerArenas;
	for( n = 0; n < ui_numArenas; n++ ) {
		// determine type
		type = Info_ValueForKey( ui_arenaInfos[n], "type" );

		// if no type specified, it will be treated as "ffa"
		if( *type ) {
			if( strstr( type, "single" ) ) {
				// check for special single player arenas (training, final)
				tag = Info_ValueForKey( ui_arenaInfos[n], "special" );
				if( *tag ) {
					Info_SetValueForKey( ui_arenaInfos[n], "num", va( "%i", specialNum++ ) );
					continue;
				}

				Info_SetValueForKey( ui_arenaInfos[n], "num", va( "%i", singlePlayerNum++ ) );
				continue;
			}
		}

		Info_SetValueForKey( ui_arenaInfos[n], "num", va( "%i", otherNum++ ) );
	}
}

/*
===============
Q3UI_GetArenaInfoByNumber
===============
*/
const char *Q3UI_GetArenaInfoByNumber( int num ) {
	int		n;
	char	*value;

	if( num < 0 || num >= ui_numArenas ) {
		UI_trap_Print( va( S_COLOR_RED "Invalid arena number: %i\n", num ) );
		return NULL;
	}

	for( n = 0; n < ui_numArenas; n++ ) {
		value = Info_ValueForKey( ui_arenaInfos[n], "num" );
		if( *value && atoi(value) == num ) {
			return ui_arenaInfos[n];
		}
	}

	return NULL;
}


/*
===============
Q3UI_GetArenaInfoByNumber
===============
*/
const char *Q3UI_GetArenaInfoByMap( const char *map ) {
	int			n;

	for( n = 0; n < ui_numArenas; n++ ) {
		if( Q_stricmp( Info_ValueForKey( ui_arenaInfos[n], "map" ), map ) == 0 ) {
			return ui_arenaInfos[n];
		}
	}

	return NULL;
}


/*
===============
Q3UI_GetSpecialArenaInfo
===============
*/
const char *Q3UI_GetSpecialArenaInfo( const char *tag ) {
	int			n;

	for( n = 0; n < ui_numArenas; n++ ) {
		if( Q_stricmp( Info_ValueForKey( ui_arenaInfos[n], "special" ), tag ) == 0 ) {
			return ui_arenaInfos[n];
		}
	}

	return NULL;
}

/*
===============
Q3UI_LoadBotsFromFile
===============
*/
static void Q3UI_LoadBotsFromFile( char *filename ) {
	int				len;
	fileHandle_t	f;
	char			buf[MAX_BOTS_TEXT];

	len = UI_trap_FS_FOpenFile( filename, &f, FS_READ );
	if ( !f ) {
		UI_trap_Print( va( S_COLOR_RED "file not found: %s\n", filename ) );
		return;
	}
	if ( len >= MAX_BOTS_TEXT ) {
		UI_trap_Print( va( S_COLOR_RED "file too large: %s is %i, max allowed is %i", filename, len, MAX_BOTS_TEXT ) );
		UI_trap_FS_FCloseFile( f );
		return;
	}

	UI_trap_FS_Read( buf, len, f );
	buf[len] = 0;
	UI_trap_FS_FCloseFile( f );

	ui_numBots += Q3UI_ParseInfos( buf, MAX_BOTS - ui_numBots, &ui_botInfos[ui_numBots] );
	if (outOfMemory) UI_trap_Print(S_COLOR_YELLOW"WARNING: not anough memory in pool to load all bots\n");
}

/*
===============
Q3UI_LoadBots
===============
*/
static void Q3UI_LoadBots( void ) {
	vmCvar_t	botsFile;
	int			numdirs;
	char		filename[128];
	char		dirlist[1024];
	char*		dirptr;
	int			i;
	int			dirlen;

	ui_numBots = 0;

	UI_trap_Cvar_Register( &botsFile, "g_botsFile", "", CVAR_INIT|CVAR_ROM );
	if( *botsFile.string ) {
		Q3UI_LoadBotsFromFile(botsFile.string);
	}
	else {
		Q3UI_LoadBotsFromFile("scripts/bots.txt");
	}

	// get all bots from .bot files
	numdirs = UI_trap_FS_GetFileList("scripts", ".bot", dirlist, 1024 );
	dirptr  = dirlist;
	for (i = 0; i < numdirs; i++, dirptr += dirlen+1) {
		dirlen = strlen(dirptr);
		strcpy(filename, "scripts/");
		strcat(filename, dirptr);
		Q3UI_LoadBotsFromFile(filename);
	}
	UI_trap_Print( va( "%i bots parsed\n", ui_numBots ) );
}


/*
===============
Q3UI_GetBotInfoByNumber
===============
*/
char *Q3UI_GetBotInfoByNumber( int num ) {
	if( num < 0 || num >= ui_numBots ) {
		UI_trap_Print( va( S_COLOR_RED "Invalid bot number: %i\n", num ) );
		return NULL;
	}
	return ui_botInfos[num];
}


/*
===============
Q3UI_GetBotInfoByName
===============
*/
char *Q3UI_GetBotInfoByName( const char *name ) {
	int		n;
	char	*value;

	for ( n = 0; n < ui_numBots ; n++ ) {
		value = Info_ValueForKey( ui_botInfos[n], "name" );
		if ( !Q_stricmp( value, name ) ) {
			return ui_botInfos[n];
		}
	}

	return NULL;
}


//
// single player game info
//

/*
===============
Q3UI_GetBestScore

Returns the player's best finish on a given level, 0 if the have not played the level
===============
*/
void Q3UI_GetBestScore( int level, int *score, int *skill ) {
	int		n;
	int		skillScore;
	int		bestScore;
	int		bestScoreSkill;
	char	arenaKey[16];
	char	scores[MAX_INFO_VALUE];

	if( !score || !skill ) {
		return;
	}

	if( level < 0 || level > ui_numArenas ) {
		return;
	}

	bestScore = 0;
	bestScoreSkill = 0;

	for( n = 1; n <= 5; n++ ) {
		UI_trap_Cvar_VariableStringBuffer( va( "g_spScores%i", n ), scores, MAX_INFO_VALUE );

		Com_sprintf( arenaKey, sizeof( arenaKey ), "l%i", level );
		skillScore = atoi( Info_ValueForKey( scores, arenaKey ) );

		if( skillScore < 1 || skillScore > 8 ) {
			continue;
		}

		if( !bestScore || skillScore <= bestScore ) {
			bestScore = skillScore;
			bestScoreSkill = n;
		}
	}

	*score = bestScore;
	*skill = bestScoreSkill;
}


/*
===============
Q3UI_SetBestScore

Set the player's best finish for a level
===============
*/
void Q3UI_SetBestScore( int level, int score ) {
	int		skill;
	int		oldScore;
	char	arenaKey[16];
	char	scores[MAX_INFO_VALUE];

	// validate score
	if( score < 1 || score > 8 ) {
		return;
	}

	// validate skill
	skill = (int)UI_trap_Cvar_VariableValue( "g_spSkill" );
	if( skill < 1 || skill > 5 ) {
		return;
	}

	// get scores
	UI_trap_Cvar_VariableStringBuffer( va( "g_spScores%i", skill ), scores, MAX_INFO_VALUE );

	// see if this is better
	Com_sprintf( arenaKey, sizeof( arenaKey ), "l%i", level );
	oldScore = atoi( Info_ValueForKey( scores, arenaKey ) );
	if( oldScore && oldScore <= score ) {
		return;
	}

	// update scores
	Info_SetValueForKey( scores, arenaKey, va( "%i", score ) );
	UI_trap_Cvar_Set( va( "g_spScores%i", skill ), scores );
}


/*
===============
Q3UI_LogAwardData
===============
*/
void Q3UI_LogAwardData( int award, int data ) {
	char	key[16];
	char	awardData[MAX_INFO_VALUE];
	int		oldValue;

	if( data == 0 ) {
		return;
	}

	if( award > AWARD_PERFECT ) {
		UI_trap_Print( va( S_COLOR_RED "Bad award %i in Q3UI_LogAwardData\n", award ) );
		return;
	}

	UI_trap_Cvar_VariableStringBuffer( "g_spAwards", awardData, sizeof(awardData) );

	Com_sprintf( key, sizeof(key), "a%i", award );
	oldValue = atoi( Info_ValueForKey( awardData, key ) );

	Info_SetValueForKey( awardData, key, va( "%i", oldValue + data ) );
	UI_trap_Cvar_Set( "g_spAwards", awardData );
}


/*
===============
Q3UI_GetAwardLevel
===============
*/
int Q3UI_GetAwardLevel( int award ) {
	char	key[16];
	char	awardData[MAX_INFO_VALUE];

	UI_trap_Cvar_VariableStringBuffer( "g_spAwards", awardData, sizeof(awardData) );

	Com_sprintf( key, sizeof(key), "a%i", award );
	return atoi( Info_ValueForKey( awardData, key ) );
}


/*
===============
Q3UI_TierCompleted
===============
*/
int Q3UI_TierCompleted( int levelWon ) {
	int			level;
	int			n;
	int			tier;
	int			score;
	int			skill;
	const char	*info;

	tier = levelWon / ARENAS_PER_TIER;
	level = tier * ARENAS_PER_TIER;

	if( tier == Q3UI_GetNumSPTiers() ) {
		info = Q3UI_GetSpecialArenaInfo( "training" );
		if( levelWon == atoi( Info_ValueForKey( info, "num" ) ) ) {
			return 0;
		}
		info = Q3UI_GetSpecialArenaInfo( "final" );
		if( !info || levelWon == atoi( Info_ValueForKey( info, "num" ) ) ) {
			return tier + 1;
		}
		return -1;
	}

	for( n = 0; n < ARENAS_PER_TIER; n++, level++ ) {
		Q3UI_GetBestScore( level, &score, &skill );
		if ( score != 1 ) {
			return -1;
		}
	}
	return tier + 1;
}


/*
===============
Q3UI_ShowTierVideo
===============
*/
qboolean Q3UI_ShowTierVideo( int tier ) {
	char	key[16];
	char	videos[MAX_INFO_VALUE];

	if( tier <= 0 ) {
		return qfalse;
	}

	UI_trap_Cvar_VariableStringBuffer( "g_spVideos", videos, sizeof(videos) );

	Com_sprintf( key, sizeof(key), "tier%i", tier );
	if( atoi( Info_ValueForKey( videos, key ) ) ) {
		return qfalse;
	}

	Info_SetValueForKey( videos, key, va( "%i", 1 ) );
	UI_trap_Cvar_Set( "g_spVideos", videos );

	return qtrue;
}


/*
===============
Q3UI_CanShowTierVideo
===============
*/
qboolean Q3UI_CanShowTierVideo( int tier ) {
	char	key[16];
	char	videos[MAX_INFO_VALUE];

	if( !tier ) {
		return qfalse;
	}

	if( uis.demoversion && tier != 8 ) {
		return qfalse;
	}

	UI_trap_Cvar_VariableStringBuffer( "g_spVideos", videos, sizeof(videos) );

	Com_sprintf( key, sizeof(key), "tier%i", tier );
	if( atoi( Info_ValueForKey( videos, key ) ) ) {
		return qtrue;
	}

	return qfalse;
}


/*
===============
Q3UI_GetCurrentGame

Returns the next level the player has not won
===============
*/
int Q3UI_GetCurrentGame( void ) {
	int		level;
	int		rank;
	int		skill;
	const char *info;

	info = Q3UI_GetSpecialArenaInfo( "training" );
	if( info ) {
		level = atoi( Info_ValueForKey( info, "num" ) );
		Q3UI_GetBestScore( level, &rank, &skill );
		if ( !rank || rank > 1 ) {
			return level;
		}
	}

	for( level = 0; level < ui_numSinglePlayerArenas; level++ ) {
		Q3UI_GetBestScore( level, &rank, &skill );
		if ( !rank || rank > 1 ) {
			return level;
		}
	}

	info = Q3UI_GetSpecialArenaInfo( "final" );
	if( !info ) {
		return -1;
	}
	return atoi( Info_ValueForKey( info, "num" ) );
}


/*
===============
Q3UI_NewGame

Clears the scores and sets the difficutly level
===============
*/
void Q3UI_NewGame( void ) {
	UI_trap_Cvar_Set( "g_spScores1", "" );
	UI_trap_Cvar_Set( "g_spScores2", "" );
	UI_trap_Cvar_Set( "g_spScores3", "" );
	UI_trap_Cvar_Set( "g_spScores4", "" );
	UI_trap_Cvar_Set( "g_spScores5", "" );
	UI_trap_Cvar_Set( "g_spAwards", "" );
	UI_trap_Cvar_Set( "g_spVideos", "" );
}


/*
===============
Q3UI_GetNumArenas
===============
*/
int Q3UI_GetNumArenas( void ) {
	return ui_numArenas;
}


/*
===============
Q3UI_GetNumSPArenas
===============
*/
int Q3UI_GetNumSPArenas( void ) {
	return ui_numSinglePlayerArenas;
}


/*
===============
Q3UI_GetNumSPTiers
===============
*/
int Q3UI_GetNumSPTiers( void ) {
	return ui_numSinglePlayerArenas / ARENAS_PER_TIER;
}


/*
===============
Q3UI_GetNumBots
===============
*/
int Q3UI_GetNumBots( void ) {
	return ui_numBots;
}


/*
===============
Q3UI_SPUnlock_f
===============
*/
void Q3UI_SPUnlock_f( void ) {
	char	arenaKey[16];
	char	scores[MAX_INFO_VALUE];
	int		level;
	int		tier;

	// get scores for skill 1
	UI_trap_Cvar_VariableStringBuffer( "g_spScores1", scores, MAX_INFO_VALUE );

	// update scores
	for( level = 0; level < ui_numSinglePlayerArenas + ui_numSpecialSinglePlayerArenas; level++ ) {
		Com_sprintf( arenaKey, sizeof( arenaKey ), "l%i", level );
		Info_SetValueForKey( scores, arenaKey, "1" );
	}
	UI_trap_Cvar_Set( "g_spScores1", scores );

	// unlock cinematics
	for( tier = 1; tier <= 8; tier++ ) {
		Q3UI_ShowTierVideo( tier );
	}

	UI_trap_Print( "All levels unlocked at skill level 1\n" );

	Q3UI_SPLevelMenu_ReInit();
}


/*
===============
Q3UI_SPUnlockMedals_f
===============
*/
void Q3UI_SPUnlockMedals_f( void ) {
	int		n;
	char	key[16];
	char	awardData[MAX_INFO_VALUE];

	UI_trap_Cvar_VariableStringBuffer( "g_spAwards", awardData, MAX_INFO_VALUE );

	for( n = 0; n < 6; n++ ) {
		Com_sprintf( key, sizeof(key), "a%i", n );
		Info_SetValueForKey( awardData, key, "100" );
	}

	UI_trap_Cvar_Set( "g_spAwards", awardData );

	UI_trap_Print( "All levels unlocked at 100\n" );
}


/*
===============
Q3UI_InitGameinfo
===============
*/
void Q3UI_InitGameinfo( void ) {

	Q3UI_InitMemory();
	Q3UI_LoadArenas();
	Q3UI_LoadBots();

	uis.demoversion = qfalse;
}
