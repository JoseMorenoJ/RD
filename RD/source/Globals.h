#pragma once
/*
	Globals.h: This header file contains the parameters required for the game.
		It will allow to not use hard-typed numbers.
*/

//We store them in a separate namespace to avoid name clash.
namespace Globals {

	// System
	int N_TRAFFIC_TYPES = 2; //Sedan, Van
	int N_SIDEOBJECT_TYPES = 2; //Fire Hydrant, Letter Box

	// Player Atributes
	int PLAYER_INIT_HEALTH = 100;

	// Traffic Car Types
	int SEDAN_HANDLING = 5;
	int SEDAN_TOPSPEED = 70;
	int SEDAN_STRENGTH = 4;
	int SEDAN_DAMAGE = 10;
	int SEDAN_CASH = 20;

	int VAN_HANDLING = 3;
	int VAN_TOPSPEED = 60;
	int VAN_STRENGTH = 7;
	int VAN_DAMAGE = 15;
	int VAN_CASH = 25;

	// Side Objects
	int FIREHYDRANT_DAMAGE = 10;
	int FIREHYDRANT_CASH = 10;

	int LETTERBOX_DAMAGE = 11;
	int LETTERBOX_CASH = 13;
}
