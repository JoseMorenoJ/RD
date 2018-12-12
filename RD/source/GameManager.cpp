/*
	class GameManager: takes charge of the game objects. Keeps track of the
		game process.
*/
#include <iostream>

#include "GameManager.h"
#include "PlayerVehicle.h"
#include "Player.h"

namespace RecklessDriver {

	//default Constructor
	GameManager::GameManager()
	{}

	//default Destructor
	GameManager::~GameManager()
	{
	}

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
		PlayerVehicle * pVehicle = new PlayerVehicle("Sedan", 5, 70, 4);
		//create a player object
		Player *pPlayer = new Player(100, pVehicle);
		//prepare te scenary

		//Run a loop
		while (pPlayer->IsAlive())
		{
			//Generate objects (side, traffic...)

			//collisions
		}
		//Until health is lower or equal than zero.

		//End of the game (run the EndGame() function)

		return;
	}

	//This print out the scores info once the game is over.
	void GameManager::EndGame()
	{
		std::cout << "Total cash accumulated: " << this->_cash << std::endl;
	}
}
