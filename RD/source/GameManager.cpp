/*
	class GameManager: takes charge of the game objects. Keeps track of the
		game process.
*/
#include <iostream>

#include "Globals.h"
#include "GameManager.h"
#include "PlayerVehicle.h"
#include "Player.h"


namespace RecklessDriver {

	//default Constructor
	GameManager::GameManager(){}

	//default Destructor
	GameManager::~GameManager(){}

	//Getter to _cash. This cash is the total cash that the player has accumulated.
	int GameManager::GetCash() const
	{
		return this->_cash;
	}

	//Add some amount to the total cash.
	void GameManager::AddCash(int amount)
	{
		this->_cash += amount;
	}

	//This will generate the new game. Here there is the main logic of the game.
	void GameManager::NewGame()
	{
		//Choose a vehicle
		PlayerVehicle * pVehicle = new PlayerVehicle(
			"Sedan", Globals::SEDAN_HANDLING, Globals::SEDAN_TOPSPEED, Globals::SEDAN_STRENGTH);
		//Create a player object
		Player *pPlayer = new Player(Globals::PLAYER_INIT_HEALTH, pVehicle);
		//Prepare te scenary (Scene Object?)

		//Run a loop
		while (pPlayer->IsAlive())
		{
			//Generate objects (side, traffic...)

			//Collisions
				//with side object
				//with traffic vehicle
		}
		//Until health is lower or equal than zero.

		//Destroy the Scene and the objects.

		//End of the game (run the EndGame() function)

		//Show result

		//Play again?

		return;
	}

	//This print out the scores info once the game is over.
	void GameManager::EndGame()
	{
		std::cout << "Total cash accumulated: " << this->GetCash() << std::endl;
	}
}
