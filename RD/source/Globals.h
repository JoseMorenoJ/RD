#pragma once
/*
	Globals.h: This header file contains the parameters required for the game.
		It will allow to not use hard-typed numbers.
*/

//We store them in a separate namespace to avoid name clash.
namespace Globals {
	// Player Atributes
	int PLAYER_INIT_HEALTH = 100;

	// Traffic Car Types
	int SEDAN_HANDLING = 5;
	int SEDAN_TOPSPEED = 70;
	int SEDAN_STRENGTH = 4;

}