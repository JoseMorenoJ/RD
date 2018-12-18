/*
	class GameManager: takes charge of the game objects. Keeps track of the
		game process.
*/
#include <iostream>
#include <thread>

//#include "Globals.h" //int RecklessDriver::Globals::N_TRAFFIC_TYPES" (?N_TRAFFIC_TYPES@Globals@RecklessDriver@@3HA) déjà défini(e) dans GameManager.obj
#include "GameManager.h"
#include "PlayerVehicle.h"
#include "Player.h"
#include "Scene.h"
#include "Hub.h"


namespace RecklessDriver {

	//default Constructor
	GameManager::GameManager(){}

	//default Destructor
	GameManager::~GameManager(){}

	//Getter to _cash. This cash is the total cash that the player has accumulated.
	int GameManager::GetCash() const { return this->_cash; }

	//Get the instance of the game manager to be able to accumulate the cash.
	GameManager& GameManager::GetInstance()
	{
		//Meyer's Singleton
		static GameManager instance;
		return instance;
	}

	//Add some amount to the total cash.
	void GameManager::AddCash(int amount) { this->_cash += amount; }

	//This will generate the new game. Here there is the main logic of the game.
	void GameManager::NewGame()
	{
		//TODO: Redesign the Global variables thing.
		const int SEDAN_HANDLING = 5;
		const int SEDAN_TOPSPEED = 70;
		const int SEDAN_STRENGTH = 4;
		const int PLAYER_INIT_HEALTH = 100;
		
		//Choose a vehicle
		PlayerVehicle * pVehicle = new PlayerVehicle(
			"Sedan", SEDAN_HANDLING, SEDAN_TOPSPEED, SEDAN_STRENGTH);
		
		//Create a player object
		Player *pPlayer = new Player(PLAYER_INIT_HEALTH, pVehicle);

		//Create the pool object
		ObjectPool *pPool = new ObjectPool;
		
		//Prepare te scenary 
		Scene scene(pPool, pPlayer);
		scene.Start(pPlayer); //TODO: Redundant

		//Create the Hub object
		Hub HUB;

		//Run a loop
		while (pPlayer->IsAlive())
		{
			//Generate objects (side, traffic...)
			pPool->GenerateNPCs();
			this->Drive();
			
			//Generate the collisions
			scene.Collide();

			//Update the HUB info
			HUB.update(pPool, pPlayer);
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

	//Show the health points and the accumulated money of the player in the screen.
	void GameManager::ShowStats(Player * pPlayer)
	{
		std::cout << "\n***************************************** Cash: ";
		std::cout << this->_cash << "$\tHealth: " << pPlayer->GetHealth() << std::endl;
	}
	void GameManager::Drive()
	{
		std::cout << "\nPlayer is driving\n";
		for (int i = 0; i<8; ++i)
		{
			std::cout << ".";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		std::cout << std::endl;
	}
}
