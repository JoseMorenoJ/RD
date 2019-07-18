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
//getter to _cash. This cash is the total cash that the player has accumulated.
int GameManager::getCash() const { return this->_cashAccum; }

int GameManager::CLOCK()
{
    return getInstance()._clock;
}

//**************************************************************************************
//get the instance of the game manager to be able to accumulate the cash.
GameManager& GameManager::getInstance()
{
	//Singleton: Structure that assure only one instance of the class.
	//Meyer's Singleton:
	static GameManager *instance = new GameManager;
	return *instance;
}

//**************************************************************************************
//Add some amount to the total cash.
void GameManager::addCash(int amount) { this->_cashAccum += amount; }

//**************************************************************************************
//Generates the new game. The main loop and logic of the game.
void GameManager::newGame()
{	
	//Choose a vehicle //TODO: give a choice, actually
	PlayerVehicle  vehicle = PlayerVehicle();
    
	//Create a player object
	Player player(vehicle);

	//Create the pool object
    ObjectPool pool{};
	
	//Prepare te scenary 
	Scene scene(&pool, &player);

	//Create the Hub object
	Hub HUB;

	//set initial cash to 0
	resetCash();

	//Run the loop
	while (player.isAlive())
	{
        //keep track of the clock
        ++_clock;
        
		//Generate a new object (side, traffic...)
        if (CLOCK() % params::OBJ_FREQ == 0)
            scene.addObject();
        
        //Update the objects
        pool.updateObjects();
        
            player.update();

		//Update the HUB info
		HUB.refresh(pool, player);
                
	} //Game over

	//Destroy the Scene and the objects.
	this->endGame();

	//Show result
	HUB.refresh(pool, player);
	HUB.showEndGame( getCash() );
    
}

//**************************************************************************************
//Prints out the scores info once the game is over.
void GameManager::endGame()
{
	//TODO Implement this function
	//Erase the instances to erase //Makes no sense to destroy it if we will play again...

	//Call every process necessary to show in screen the results of the game

	//Maybe prepare a record list

}

//**************************************************************************************
//Asks the player to play again.
bool GameManager::playAgain() //TODO Integrate the question in the HUB/Graphics
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
void GameManager::resetCash() { this->_cashAccum = 0; }
