#pragma once

/*
	params.h: This header file contains the parameters required for the game.
		It will allow to not use hard-typed numbers.
*/
namespace params {
	// System
	const int N_TRAFFIC_TYPES = 2; //Sedan, Van
	const int N_SIDEOBJECT_TYPES = 2; //Fire Hydrant, Letter Box
    const int N_TOTAL_TYPES = 4;
	const int POOL_SIZE = 10; //Max number of Game Objects at a time in the pool.
    
    const int SCREEN_HOR = 5; //Horizontal size of the screen grid
    const int SCREEN_VER = 15; //Vertical size of the screen grid

	// Player Atributes
	const int PLAYER_INIT_HEALTH = 100;

	// Traffic Car Types
	const int SEDAN_HANDLING = 5;
	const int SEDAN_TOPSPEED = 70;
	const int SEDAN_STRENGTH = 4;
	const int SEDAN_DAMAGE = 10;
	const int SEDAN_CASH = 20;

	const int VAN_HANDLING = 3;
	const int VAN_TOPSPEED = 60;
	const int VAN_STRENGTH = 7;
	const int VAN_DAMAGE = 15;
	const int VAN_CASH = 25;

	// Side Objects
	const int FIREHYDRANT_DAMAGE = 10;
	const int FIREHYDRANT_CASH = 10;

	const int LETTERBOX_DAMAGE = 11;
	const int LETTERBOX_CASH = 13;
} //namespace params