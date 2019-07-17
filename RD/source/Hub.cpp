/*
	class Hub: it displays the game information after every iteration.

*/

#include <vector>
#include <random>
#include <iostream>
#include <thread>

#include "Hub.h"
#include "GameManager.h"
#include "SideObject.h"
#include "System.h"

//**************************************************************************************
//default Constructor
Hub::Hub(){}

//**************************************************************************************
//default Destructor
Hub::~Hub(){}

//**************************************************************************************
//Rewrite the screen with the new info.
void Hub::refresh(ObjectPool &pool, Player &player)
{
    //Clear the screen
    System::clear();
	displayGameObjects(pool);

	//Show the cash from the GM and the health from the player
	showStats(player);

	return;
}

//**************************************************************************************
//Shows that the player is driving on the screen.
void Hub::driving() const
{
	std::cout << "\nPlayer is driving\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::cout << std::endl;
}

//**************************************************************************************
//Screen called after the game is over, it shows the total points obtained.
void Hub::showEndGame(int tCash) const
{
	//TODO: show a list of the crashes

	std::cout << "Total cash accumulated: $" << tCash << std::endl;
}

//**************************************************************************************
//Display all the objects in the pool.
//TODO: Display them for real, in a position.
void Hub::displayGameObjects(ObjectPool& pool)
{
	for (const auto *p : pool.getvGameObjects())
	{
		if (p != nullptr) //check that the Game Object is valid.
		{
            if (p->isActive()) std::cout << "\t[O]";
            else               std::cout << "\t[X]";
            std::cout << "x:" << p->getX() << "y:" << p->getY();
            std::cout << p->getName();
		}
        std::cout << std::endl;
	}
	return;
}

//**************************************************************************************
//Show the health points and the accumulated money of the player in the screen.
void Hub::showStats(const Player &player)
{
	std::cout << "\n***************************************** Cash: $";
	std::cout << GameManager::getInstance().getCash() << "\tHealth: ";
	std::cout << std::max(player.getHealth(), 0) << std::endl; //Never print less than 0
    std::cout << "pos (" << player.getX() << "," << player.getX() << ")" << std::endl;
}

