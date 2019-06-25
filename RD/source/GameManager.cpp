/*
	class GameManager: takes charge of the game objects. Keeps track of the
		game process.
*/
#include <iostream>

#include "GameManager.h"
#include "ObjectPool.h"
#include "Scene.h"
#include "Hub.h"


//**************************************************************************************
//default Constructor
GameManager::GameManager(){}

//**************************************************************************************
//default Destructor
GameManager::~GameManager(){}

//**************************************************************************************
//Getter to _cash. This cash is the total cash that the player has accumulated.
int GameManager::GetCash() const { return this->_cashAccum; }

//**************************************************************************************
//Get the instance of the game manager to be able to accumulate the cash.
GameManager& GameManager::GetInstance()
{
	//Singleton: Structure that assure only one instance of the class.
	//Meyer's Singleton:
	static GameManager *instance = new GameManager;
	return *instance;
}

//**************************************************************************************
//Add some amount to the total cash.
void GameManager::AddCash(int amount) { this->_cashAccum += amount; }

//**************************************************************************************
//Generates the new game. The main loop and logic of the game.
void GameManager::NewGame()
{	
	//Choose a vehicle //TODO: give a choice, actually
	PlayerVehicle  vehicle = PlayerVehicle();
		
	//Create a player object
	Player player(vehicle);

	//Create the pool object
	ObjectPool *pPool = new ObjectPool();
	
	//Prepare te scenary 
	Scene scene(pPool, &player);

	//Create the Hub object
	Hub HUB;

	//Set initial cash to 0
	ResetCash();

	//Run the loop
	while (player.IsAlive())
	{
		//Generate a new object (side, traffic...)
 		pPool->GenerateNewPoolObject();

		//Update the HUB info
		HUB.Update(pPool, player);

		HUB.Driving();
		scene.Collide();

	} //Game over

	//Destroy the Scene and the objects.
	this->EndGame();

	//Show result
	HUB.Update(pPool, player);
	HUB.ShowEndGame( GetCash() );

	return;
}

//**************************************************************************************
//Prints out the scores info once the game is over.
void GameManager::EndGame()
{
	//TODO Implement this function
	//Erase the instances to erase //Makes no sense to destroy it if we will play again...

	//Call every process necessary to show in screen the results of the game

	//Maybe prepare a record list

}

//**************************************************************************************
//Asks the player to play again.
bool GameManager::PlayAgain() //TODO Integrate the question in the HUB/Graphics
{
	char answer;

	//Ask and get the answer in a char
	std::cout << "Would you like to play again? (y/n):";
	std::cin >> answer;

	if (answer == 'y' || answer == 'Y')
		return true;
	if (answer == 'n' || answer == 'N')
		return false;
}

//**************************************************************************************
//Set cash to 0 when a new game starts.
void GameManager::ResetCash() { this->_cashAccum = 0; }
