//===========================================================================
//
// Name:			cadaver_c.c
// Function:		cadaver, rank 2
// Programmer:		MrElusive (MrElusive@idsoftware.com)
// version:			1
// Tab Size:		4 (real tabs)
//===========================================================================

#include "chars.h"

skill 1
{
	CHARACTERISTIC_NAME							"Cadaver"
	CHARACTERISTIC_GENDER						"male"
	CHARACTERISTIC_ATTACK_SKILL					0.5
	CHARACTERISTIC_WEAPONWEIGHTS				"bots/cadaver_w.c"
	CHARACTERISTIC_AIM_SKILL					0.5
	CHARACTERISTIC_AIM_ACCURACY					0.5
	CHARACTERISTIC_VIEW_FACTOR					0.5
	CHARACTERISTIC_VIEW_MAXCHANGE				180
	CHARACTERISTIC_REACTIONTIME					2.5

	CHARACTERISTIC_CHAT_FILE					"bots/cadaver_t.c"
	CHARACTERISTIC_CHAT_NAME					"cadaver"
	CHARACTERISTIC_CHAT_CPM						400
	CHARACTERISTIC_CHAT_INSULT					0.5
	CHARACTERISTIC_CHAT_MISC					0.5
	CHARACTERISTIC_CHAT_STARTENDLEVEL			0.5
	CHARACTERISTIC_CHAT_ENTEREXITGAME			0.5
	CHARACTERISTIC_CHAT_KILL					0.5
	CHARACTERISTIC_CHAT_DEATH					0.5
	CHARACTERISTIC_CHAT_ENEMYSUICIDE			0.5
	CHARACTERISTIC_CHAT_HITTALKING				0.5
	CHARACTERISTIC_CHAT_HITNODEATH				0.5
	CHARACTERISTIC_CHAT_HITNOKILL				0.5
	CHARACTERISTIC_CHAT_RANDOM					0.5
	CHARACTERISTIC_CHAT_REPLY					0.5

	CHARACTERISTIC_CROUCHER						0.5
	CHARACTERISTIC_JUMPER						0.5
	CHARACTERISTIC_WEAPONJUMPING				0.5
	CHARACTERISTIC_GRAPPLE_USER					0.5

	CHARACTERISTIC_ITEMWEIGHTS					"bots/cadaver_i.c"
	CHARACTERISTIC_AGGRESSION					0.5
	CHARACTERISTIC_SELFPRESERVATION				0.5
	CHARACTERISTIC_VENGEFULNESS					0.5
	CHARACTERISTIC_CAMPER						0.5

	CHARACTERISTIC_EASY_FRAGGER					0.5
	CHARACTERISTIC_ALERTNESS					0.5
}